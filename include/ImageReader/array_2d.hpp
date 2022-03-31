#pragma once

#include <vector>

namespace img {
    class Array2D {
        typedef std::vector<std::vector<size_t>> array_t;

    public:
        class Tracker {
        public:
            Tracker() = delete;

            explicit Tracker(Array2D& data, int x, int y) : data_(data), x_(x), y_(y) {}

            bool TryToMove(int new_x, int new_y);

            [[nodiscard]] int GetX() const;

            [[nodiscard]] int GetY() const;

            [[nodiscard]] bool PossiblePosition(int x, int y) const;

        private:
            [[nodiscard]] bool correctPosition(int x, int y) const;

        private:
            Array2D& data_;
            int x_, y_;
        };

        Array2D(size_t height, size_t width)
            : data_(height, std::vector<size_t>(width, 0)), height_(height), width_(width) {
        }

        void Set(size_t x, size_t y, size_t value);

        Tracker GetTracker(int x, int y);

        size_t Get(size_t x, size_t y);

    private:
        array_t data_;
        size_t height_;
        size_t width_;
    };
};