#include "Draggable/WidgetBackground.hpp"

WidgetBackground::WidgetBackground(QWidget* parent): QWidget(parent) {}

void WidgetBackground::select(bool value) {
    if (value) setStyleSheet((color + "border-radius: 6px;").c_str());
    else setStyleSheet((off_color + "border-radius: 6px;").c_str());
}

void WidgetBackground::setColor(unsigned short r, unsigned short g, unsigned short b) {
    color = "background-color: rgb(" + std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + ");";
}

void WidgetBackground::setOffColor() {
    off_color = "background-color: transparent;";
}

void WidgetBackground::setOffColor(unsigned short r, unsigned short g, unsigned short b) {
    off_color = "background-color: rgb(" + std::to_string(r) + ", " + std::to_string(g) + ", " + std::to_string(b) + ");";
}