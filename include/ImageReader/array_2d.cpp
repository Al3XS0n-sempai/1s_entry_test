#include "array_2d.hpp"

namespace img {

    bool Array2D::Tracker::PossiblePosition(int x, int y) const {
        bool result = false;
        const int dx[] = {-1, 0, 1, 0};
        const int dy[] = {0, -1, 0, 1};
        for (size_t i = 0; i < 4; ++i) {
            if (correctPosition(x + dx[i], y + dy[i])) {
                result = (result || (data_.Get(x + dx[i], y + dy[i]) == 0));
            } else {
                result = true;
            }
        }
        return (result && correctPosition(x, y));
    }

    bool Array2D::Tracker::correctPosition(int x, int y) const {
        return !(x < 0 || y < 0 || x >= data_.width_ || y >= data_.height_);
    }

    bool Array2D::Tracker::TryToMove(int new_x, int new_y) {
        if (PossiblePosition(new_x, new_y)) {
            x_ = new_x, y_ = new_y;
            return true;
        }
        return false;
    }

    int Array2D::Tracker::GetX() const {
        return x_;
    }

    int Array2D::Tracker::GetY() const {
        return y_;
    }

    void Array2D::Set(size_t x, size_t y, size_t value) {
        data_[y][x] = value;
    }

    size_t Array2D::Get(size_t x, size_t y) {
        return data_[y][x];
    }

    Array2D::Tracker Array2D::GetTracker(int x, int y) {
        return Tracker(*this, x, y);
    }
};