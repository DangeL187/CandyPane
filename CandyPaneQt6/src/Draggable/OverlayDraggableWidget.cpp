#include <QCheckBox>
#include <QPainter>
#include <QStyle>
#include <QStyleOption>
#include <iostream>

#include "Draggable/DraggableWidget.hpp"
#include "Draggable/OverlayDraggableWidget.hpp"

OverlayDraggableWidget::OverlayDraggableWidget(DraggableWidget& draggable_widget): QDialog(nullptr) {
    setWindowOpacity(0.7);
    setWindowFlags(Qt::FramelessWindowHint);
    setAttribute(Qt::WA_TranslucentBackground);

    setFixedSize(draggable_widget.size());
    initLayout(draggable_widget.getLayout());
}

QLayout* OverlayDraggableWidget::copyLayout(QLayout* layout, bool return_hbox_layout) { //todo: wrap in separate func, priority: extremely low
    QLayout* new_layout;
    if (return_hbox_layout) {
        new_layout = new QHBoxLayout();
    } else {
        new_layout = new QVBoxLayout();
    }
    for (int i = 0; i < layout->count(); i++) {
        if (layout->itemAt(i)->controlTypes() == QSizePolicy::DefaultType) {
            auto* spacer = dynamic_cast<QSpacerItem*>(layout->itemAt(i));
            if (spacer) {
                auto* spacer_item = new QSpacerItem(0, 0, QSizePolicy::Expanding, QSizePolicy::Minimum);
                spacer_item->setAlignment(Qt::AlignRight);
                new_layout->addItem(spacer_item);
                new_layout->setSpacing(5);
                continue;
            }
            auto* hbox = dynamic_cast<QHBoxLayout*>(layout->itemAt(i)->widget()->layout());
            auto* vbox = dynamic_cast<QVBoxLayout*>(layout->itemAt(i)->widget()->layout());
            if (vbox) {
                auto* copied_layout = copyLayout(vbox, false);
                copied_layout->setContentsMargins(vbox->contentsMargins());
                new_layout->addItem(copied_layout);
            } else if (hbox) {
                auto* copied_layout = copyLayout(hbox, true);
                copied_layout->setContentsMargins(hbox->contentsMargins());
                new_layout->addItem(copied_layout);
            } else {
                auto* original = layout->itemAt(i)->widget();
                auto* widget = new QWidget(this);
                widget->setFixedSize(original->size());
                widget->setStyleSheet(original->styleSheet());
                widget->setVisible(original->isVisible());
                new_layout->addWidget(widget);
            }
        } else {
            auto* hbox = dynamic_cast<QHBoxLayout*>(layout->itemAt(i)->layout());
            auto* vbox = dynamic_cast<QVBoxLayout*>(layout->itemAt(i)->layout());
            if (vbox) {
                auto* copied_layout = copyLayout(vbox, false);
                copied_layout->setContentsMargins(vbox->contentsMargins());
                new_layout->addItem(copied_layout);
            } else if (hbox) {
                auto* copied_layout = copyLayout(hbox, true);
                copied_layout->setContentsMargins(hbox->contentsMargins());
                new_layout->addItem(copied_layout);
            } else if (layout->itemAt(i)->controlTypes() == QSizePolicy::Label) {
                auto* original = qobject_cast<QLabel*>(layout->itemAt(i)->widget());
                auto* label = new QLabel(this);
                label->setFont(original->font());
                label->setText(original->text());
                label->setStyleSheet(original->styleSheet());
                label->setFixedSize(original->size());
                label->setAlignment(original->alignment());
                label->setContentsMargins(original->contentsMargins());
                label->setVisible(original->isVisible());
                label->setWordWrap(original->wordWrap());
                new_layout->addWidget(label);
            } else if (layout->itemAt(i)->controlTypes() == QSizePolicy::CheckBox) {
                auto* original = qobject_cast<QCheckBox*>(layout->itemAt(i)->widget());
                auto* checkbox = new QCheckBox(this);
                checkbox->setStyleSheet(original->styleSheet());
                checkbox->setFixedSize(original->size());
                checkbox->setVisible(original->isVisible());
                checkbox->setCheckState(original->checkState());
                new_layout->addWidget(checkbox);
            } else {
                auto* original = layout->itemAt(i)->widget();
                auto* widget = new QWidget(this);
                widget->setFixedSize(original->size());
                widget->setStyleSheet(original->styleSheet());
                widget->setVisible(original->isVisible());
                new_layout->addWidget(widget);
            }
        }
    }
    return new_layout;
}

void OverlayDraggableWidget::initLayout(QHBoxLayout& layout) {
    _layout = std::make_shared<QHBoxLayout>();
    _layout->setContentsMargins(layout.contentsMargins());
    _layout->addLayout(copyLayout(&layout, true));
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
