#include "ButtonBox.h"

ButtonBox::ButtonBox(Box *parent, int x, int y, int width, int height, int depth, const std::string& title)
    : InputBox(parent, x, y, width, height, depth, title), label(LabelBox(nullptr, 0, 0, 0, 0, 0, ""))
{
    this->isLabelSet = false;
    this->callEvent = nullptr;
}

ButtonBox::~ButtonBox()
{
}

void ButtonBox::setLabel(std::string label, int x, int y, int width, int height)
{
    if (!this->isLabelSet) {
        this->label = LabelBox(nullptr, x, y, width, height, 0, "");
        this->label.setBorder(false);
        this->label.setText(label);
        this->isLabelSet = true;
        return;
    }
    this->label.setText(label);
    this->label.setX(x);
    this->label.setY(y);
    this->label.setWidth(width);
    this->label.setHeight(height);
}

std::string ButtonBox::getLabel()
{
    return this->label.getText();
}

void ButtonBox::draw()
{
    if (!this->isVisible()) {
        return;
    }

    InputBox::draw();
    if (this->isLabelSet) {
        this->label.setStyle(this->labelColor, this->labelStyle);
        this->label.write();
    }
}

void ButtonBox::drawActive()
{
    if (!this->isVisible()) {
        return;
    }

    InputBox::drawActive();
    if (this->isLabelSet) {
        this->label.setStyle(this->labelActiveColor, this->labelActiveStyle);
        this->label.write();
    }
}


void ButtonBox::setCallEvent(std::function<void()> callEvent)
{
    this->callEvent = callEvent;
}

void ButtonBox::pressEnter()
{
    
    if (this->callEvent != nullptr) {
        this->callEvent();
    }
}

void ButtonBox::setLabelStyle(CSI labelStyle, Color labelColor)
{
    this->labelStyle = labelStyle;
    this->labelColor = labelColor;
}

void ButtonBox::setLabelActiveStyle(CSI labelActiveStyle, Color labelActiveColor)
{
    this->labelActiveStyle = labelActiveStyle;
    this->labelActiveColor = labelActiveColor;
}