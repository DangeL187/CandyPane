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
    _layout->setContentsMargins(0, 0, 0, 0);
    for (int i = 0; i < layout.count(); i++) {
        if (layout.itemAt(i)->controlTypes() == QSizePolicy::Label) {
            auto* label = new QLabel(this);
            label->setFont(qobject_cast<QLabel*>(layout.itemAt(i)->widget())->font());
            label->setText(qobject_cast<QLabel*>(layout.itemAt(i)->widget())->text());
            label->setStyleSheet(qobject_cast<QLabel*>(layout.itemAt(i)->widget())->styleSheet());
            label->setFixedSize(qobject_cast<QLabel*>(layout.itemAt(i)->widget())->size());
            label->setAlignment(qobject_cast<QLabel*>(layout.itemAt(i)->widget())->alignment());
            label->setContentsMargins(qobject_cast<QLabel*>(layout.itemAt(i)->widget())->contentsMargins());
            label->setVisible(qobject_cast<QLabel*>(layout.itemAt(i)->widget())->isVisible());
            _layout->addWidget(label);
        } else {
            auto* widget = new QWidget(this);
            widget->setFixedSize(layout.itemAt(i)->widget()->size());
            widget->setStyleSheet(layout.itemAt(i)->widget()->styleSheet());
            widget->setVisible(layout.itemAt(i)->widget()->isVisible());
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
