#ifndef CANDYPANE_SIZE_HPP
#define CANDYPANE_SIZE_HPP

struct SIZE {
    int width, height;

    explicit SIZE(int width_ = 0, int height_ = 0): width(width_), height(height_) {}

    bool operator==(const SIZE& other) const {
        return (width == other.width && height == other.height);
    }
};

#endif //CANDYPANE_SIZE_HPP
