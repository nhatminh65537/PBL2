#include "InputBox.h"

InputBox::InputBox(Box *parent, int x, int y, int width, int height, int depth, const std::string& title)
    : Box(parent, x, y, width, height, depth, title)
{
    this->active = false;
    this->isActivedStyleSet = false;
}

InputBox::~InputBox()
{
}

void InputBox::setActivedStyle(Color LineColor, BoxStyle LineStyle, BoxStyle cornerStyle, Color titleColor, CSI titleStyle)
{
    this->activedLineColor = LineColor;
    this->activedStyle = LineStyle;
    this->activedCornerStyle = cornerStyle;
    this->activedTitleColor = titleColor;
    this->activedTitleStyle = titleStyle;
    this->isActivedStyleSet = true;
}

void InputBox::setActived(bool actived)
{
    this->active = actived;
    if (!this->isActivedStyleSet) return;
    if (actived) {
        drawActive();
    } else {
        draw();
    }
}

bool InputBox::isActived()
{
    return this->active;
}

void InputBox::drawActive()
{
    draw(activedLineColor, activedStyle, activedCornerStyle, activedTitleColor, activedTitleStyle);
}