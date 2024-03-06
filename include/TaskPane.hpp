#ifndef CANDYPANE_TASKPANE_HPP
#define CANDYPANE_TASKPANE_HPP

#include <string>
#include <vector>
#include "POINT.hpp"
#include "SIZE.hpp"

class TaskPane {
public:
    TaskPane() = default;
protected:
    void resize(int width, int height);
    void resize(const SIZE& new_size);
    void setName(const std::string& new_name);
    void setPosition(int x, int y);
    void setPosition(const POINT& new_position);
    void setText(const std::string& text);
    [[nodiscard]] std::string getName() const;
    [[nodiscard]] POINT getPosition() const;
    [[nodiscard]] SIZE getSize() const;
    [[nodiscard]] std::string getText() const;

    bool operator==(const TaskPane& other) const {
        return (_name == other.getName() && _text == other.getText() && _size == other.getSize() && _position == other.getPosition());
    }
private:
    std::string _name;
    POINT       _position;
    SIZE        _size;
    std::string _text;
    int         _transparency = 255; // TODO: alpha?
};

#endif //CANDYPANE_TASKPANE_HPP
