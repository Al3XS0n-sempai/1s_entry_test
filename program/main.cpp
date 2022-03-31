#include <iostream>
#include <image_reader.hpp>
#include <cassert>

void makeConture(img::Array2D& data, img::Array2D& buffer, int& h, int& w) {
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            if (data.Get(x, y) == 0) {
                buffer.Set(x, y, 0);
            } else if (buffer.Get(x, y) == 0) {
                img::Array2D::Tracker tracker = data.GetTracker(x, y);

                if (tracker.PossiblePosition(x, y)) {
                    buffer.Set(x, y, 1);
                }
            }
        }
    }
}

int main(int argc, char** argv) {
    assert(argc > 1);
    std::cout << "Input file is: [" << argv[1] << "]" << std::endl;

    img::ImageReader reader;
    reader.ReadImage(argv[1]);

    img::Array2D data = reader.ConvertImage();

    int h = reader.GetImageHeight();
    int w = reader.GetImageWidth();

    img::Array2D data1(h, w);

    makeConture(data, data1, h, w);

    freopen("../../result", "w", stdout);
    for (int y = 0; y < h; ++y) {
        for (int x = 0; x < w; ++x) {
            std::cout << (data1.Get(x, y) == 1 ? '1' : '0');
        }
        std::cout << std::endl;
    }
    return 0;
}
