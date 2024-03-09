#ifndef CANDYPANE_TASKPANE_HPP
#define CANDYPANE_TASKPANE_HPP

#include <string>
#include <vector>
#include "POINT.hpp"
#include "SIZE.hpp"

/*! @class candypane::TaskPane
    @brief FFFFF
*/
/*! @fn void candypane::ListPane::resize(int width, int height)
    @brief FFFFF
    @param width FFFFFFF
    @param height FFFFFF
*/
/*! @fn void candypane::ListPane::resize(const SIZE& new_size)
    @brief FFFFF
    @param new_size FFFFFFF
*/
/*! @fn void candypane::ListPane::setName(const std::string& new_name)
    @brief FFFFF
    @param new_name FFFFFFF
*/
/*! @fn void candypane::ListPane::void setPosition(int x, int y)
    @brief FFFFF
    @param x FFFFFFF
    @param y FFFFFFF
*/
/*! @fn void candypane::ListPane::setPosition(const POINT& new_position)
    @brief FFFFF
    @param new_position FFFFFFF
*/
/*! @fn void candypane::ListPane::setText(const std::string& text)
    @brief FFFFF
    @param text FFFFFFF
*/


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
