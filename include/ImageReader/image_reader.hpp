#pragma once

#include <string>
#include <vector>
#include <array_2d.hpp>

namespace img {
    #define RGBA_DATA_LENGTH 4
    #define RGB_DATA_LENGTH 3

    class ImageReader {
    public:
        ImageReader() = default;

        [[nodiscard]] int GetImageHeight() const;

        [[nodiscard]] int GetImageWidth() const;

        void ReadImage(const std::string& filename, int chunk_sz = RGB_DATA_LENGTH);

        Array2D ConvertImage();

    private:
        std::string image_name_{"../../"};
        std::vector<unsigned char> image_data_;
        int image_width_{0};
        int image_height_{0};
        int chunk_size_{0};
    };
} // namespace img
