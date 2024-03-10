#ifndef CANDYPANE_POINT_HPP
#define CANDYPANE_POINT_HPP

struct POINT {
    int x, y;

    explicit POINT(int x_ = 0, int y_ = 0): x(x_), y(y_) {}

    POINT operator+(const POINT& other) const {
        return POINT(x + other.x, y + other.y);
    }
    POINT operator-(const POINT& other) const {
        return POINT(x - other.x, y - other.y);
    }
    bool operator==(const POINT& other) const {
        return (x == other.x && y == other.y);
    }
};

#endif //CANDYPANE_POINT_HPP
