#include "image_reader.hpp"

extern "C" {
    #define STB_IMAGE_IMPLEMENTATION
    #include "stb_image.h"
}

#include <iostream>
#include <cassert>

#include <unistd.h>

namespace img {

    int ImageReader::GetImageHeight() const {
        return image_height_;
    }

    int ImageReader::GetImageWidth() const {
        return image_width_;
    }

    void ImageReader::ReadImage(const std::string& filename, int chunk_sz)  {
        image_name_ += filename;
        chunk_size_ = chunk_sz;

        int n = 0;
        unsigned char* data = stbi_load(image_name_.c_str(),
                                        &image_width_, &image_height_,
                                        &n, chunk_size_);
        if (data != nullptr) {
            image_data_ = std::vector<unsigned char>(data, data + image_width_ * image_height_ * chunk_size_);
        } else {
            assert(false && "Can't read file");
        }
        stbi_image_free(data);

        std::cout << "Image height : " << image_height_ << ", Image width: " << image_width_ << std::endl;
    }

    Array2D ImageReader::ConvertImage() {
        Array2D result(image_height_, image_width_);
        for (size_t y = 0; y < image_height_; ++y) {
            for (size_t x = 0; x < image_width_; ++x) {
                size_t index = chunk_size_ * (y * image_width_ + x);
                size_t value = static_cast<int>(image_data_[index + 0]) +
                        static_cast<int>(image_data_[index + 1]) +
                        static_cast<int>(image_data_[index + 2]);
                result.Set(x, y, (value == 0));
            }
        }
        return result;
    }

}; // namespace img
