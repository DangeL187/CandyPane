#include <QCheckBox>
#include <QPainter>
#include <QStyle>
#include <QStyleOption>

#include "Draggable/DraggableWidget.hpp"
#include "Draggable/OverlayDraggableWidget.hpp"

OverlayDraggableWidget::OverlayDraggableWidget(DraggableWidget& draggable_widget): QDialog(nullptr) {
    setWindowOpacity(0.7);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    setFixedSize(draggable_widget.size());
    initLayout(draggable_widget.getLayout());
}

void OverlayDraggableWidget::initLayout(QHBoxLayout& layout) {
    _layout = std::make_shared<QHBoxLayout>();
    _layout->setContentsMargins(layout.contentsMargins());
    for (int i = 0; i < layout.count(); i++) {
        if (layout.itemAt(i)->controlTypes() == QSizePolicy::Label) {
            auto* original = qobject_cast<QLabel*>(layout.itemAt(i)->widget());
            auto* label = new QLabel(this);
            label->setFont(original->font());
            label->setText(original->text());
            label->setStyleSheet(original->styleSheet());
            label->setFixedSize(original->size());
            label->setAlignment(original->alignment());
            label->setContentsMargins(original->contentsMargins());
            label->setVisible(original->isVisible());
            _layout->addWidget(label);
        } else if (layout.itemAt(i)->controlTypes() == QSizePolicy::CheckBox) {
            auto* original = qobject_cast<QCheckBox*>(layout.itemAt(i)->widget());
            auto* checkbox = new QCheckBox(this);
            checkbox->setStyleSheet(original->styleSheet());
            checkbox->setFixedSize(original->size());
            checkbox->setVisible(original->isVisible());
            checkbox->setCheckState(original->checkState());
            _layout->addWidget(checkbox);
        } else {
            auto* original = layout.itemAt(i)->widget();
            auto* widget = new QWidget(this);
            widget->setFixedSize(original->size());
            widget->setStyleSheet(original->styleSheet());
            widget->setVisible(original->isVisible());
            _layout->addWidget(widget);
        }
    }
    setLayout(_layout.get());
}

void OverlayDraggableWidget::paintEvent(QPaintEvent* event) {
    QPainter p(this);
    QRectF rect(QPointF(0, 0), size());
    p.setRenderHint(QPainter::Antialiasing);
    p.setPen(Qt::NoPen);
    p.setBrush(QColor(49, 49, 49));
    p.drawRoundedRect(rect, 6, 6, Qt::AbsoluteSize);
    p.end();
}
