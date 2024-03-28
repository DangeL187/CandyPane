#ifndef CANDYPANEQT_WIDGETBACKGROUND_HPP
#define CANDYPANEQT_WIDGETBACKGROUND_HPP

#include <QWidget>

class WidgetBackground: public QWidget {
public:
    explicit WidgetBackground(QWidget* parent);
    void select(bool value);
    void setColor(unsigned short r, unsigned short g, unsigned short b);
    void setOffColor();
    void setOffColor(unsigned short r, unsigned short g, unsigned short b);

private:
    std::string color = "background-color: transparent;";
    std::string off_color = "background-color: transparent;";
};

#endif //CANDYPANEQT_WIDGETBACKGROUND_HPP
