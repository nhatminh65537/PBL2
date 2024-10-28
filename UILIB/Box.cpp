#include "Box.h"

std::string boxhline [] = {
    "\u2500", "\u2501", "\u2550", "\u2508", "\u2509", "\u2504", "\u2505", "\u254c", "\u254d"
};
std::string boxvline [] = {
    "\u2502", "\u2503", "\u2551", "\u250a", "\u250b", "\u2506", "\u2507", "\u254e", "\u254f"
};
std::string boxcorner[] = {
    "\u2510", "\u2513", "\u2557", "\u256e",
    "\u250c", "\u250f", "\u2554", "\u256d",
    "\u2514", "\u2517", "\u255a", "\u2570",
    "\u2518", "\u251b", "\u255d", "\u256f"
};
std::string splitline[] = {
    "\u2534", "\u253b", "\u2569",
    "\u2524", "\u252b", "\u2563",
    "\u252c", "\u2533", "\u2566",
    "\u251c", "\u2523", "\u2560"
};
std::string intersect[] = {
    "\u253c", "\u254b", "\u256c"
};

Box::Box(Box *parent, int x, int y, int width, int height, int depth, const std::string& title)
{
    this->parent = parent;
    this->x = x;
    this->y = y;
    this->width = width;
    this->height = height;
    this->depth = depth;
    this->title = title;
    this->visible = true;
    this->border = true;

    if (parent != nullptr) {
        parent->addChild(this);
    }
}

Box::~Box()
{
    for (auto &b : child) {
        delete b;
    }
}

void Box::setX(int x)
{
    this->x = x;
}

void Box::setY(int y)
{
    this->y = y;
}

void Box::setWidth(int width)
{
    this->width = width;
}

void Box::setHeight(int height)
{
    this->height = height;
}

void Box::setDepth(int depth)
{
    this->depth = depth;
}

void Box::setTitle(const std::string& title)
{
    this->title = title;
}

void Box::setStyle(Color LineColor, BoxStyle LineStyle, BoxStyle cornerStyle, Color titleColor, CSI titleStyle)
{
    this->isStyleSet = true;
    this->lineColor = LineColor;
    this->style = LineStyle;
    this->cornerStyle = cornerStyle;
    this->titleColor = titleColor;
    this->titleStyle = titleStyle;
}

void Box::setParent(Box *parent)
{
    this->parent = parent;
}

void Box::addChild(Box *child)
{
    this->child.push_back(child);
}

void Box::setVisible(bool visible)
{
    this->visible = visible;
}

void Box::setBorder(bool border)
{
    this->border = border;
}

int Box::getX()
{
    return x;
}

int Box::getY()
{
    return y;
}

int Box::getWidth()
{
    return width;
}

int Box::getHeight()
{
    return height;
}

int Box::getDepth()
{
    return depth;
}

char *Box::getTitle()
{
    return (char *)title.c_str();
}

BoxStyle Box::getStyle()
{
    return style;
}

Box *Box::getParent()
{
    return parent;
}

Box *Box::getChild(int index)
{
    return child[index];
}

bool Box::isVisible()
{
    return visible;
}

bool Box::hasBorder()
{
    return border;
}

void Box::draw()
{
    if (!isStyleSet) {
        return;
    }
    draw(lineColor, style, cornerStyle, titleColor, titleStyle);
}

void Box::clear()
{
    int top = this->y;
    int left = this->x;
    int right = this->x + this->width - 1;
    int bottom = this->y + this->height - 1;
    std::string spaceLine = std::string(right - left + 1, ' ');
    for (int i = top; i <= bottom; i++) {
        MOVEXY(left, i);
        std::cout << spaceLine;
    }
}

void Box::draw(Color LineColor, BoxStyle LineStyle, BoxStyle cornerStyle, Color titleColor, CSI titleStyle)
{
    if (!visible) {
        return;
    }
    int top = this->y;
    int left = this->x;
    int right = this->x + this->width - 1;
    int bottom = this->y + this->height - 1;
    FG_256(LineColor);
    FILLXY(right, top   , boxcorner[ 0 + cornerStyle]);
    FILLXY(left , top   , boxcorner[ 4 + cornerStyle]);
    FILLXY(left , bottom, boxcorner[ 8 + cornerStyle]);
    FILLXY(right, bottom, boxcorner[12 + cornerStyle]);
    for (int i = left + 1; i < right; i++) {
        FILLXY(i, top   , boxhline[LineStyle]);
        FILLXY(i, bottom, boxhline[LineStyle]);
    }
    for (int i = top + 1; i < bottom; i++) {
        FILLXY(left , i, boxvline[LineStyle]);
        FILLXY(right, i, boxvline[LineStyle]);
    }
    MOVEXY(left + 2, top);
    CSI(RESET);
    FG_256(titleColor);
    CSI(titleStyle);
    std::cout << title;
    CSI(RESET);
    HIDE_CURSOR;
}

std::vector<Box*> Box::getChildList()
{
    return child;
}