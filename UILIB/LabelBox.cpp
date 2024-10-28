#include "LabelBox.h"
#include <fstream>

LabelBox::LabelBox(Box* parent, int x, int y, int width, int height, int depth, const std::string& title)
    : Box(parent, x, y, width, height, depth, title)
{
    this->text = "";
    this->textStyle = RESET;
    this->textColor = WHITE;
}

void LabelBox::setText(std::string text)
{
    this->text = text;
}

std::string LabelBox::getText()
{
    return this->text;
}

void LabelBox::setStyle(Color textColor, CSI textStyle)
{
    this->textColor = textColor;
    this->textStyle = textStyle;
}

void LabelBox::write()
{
    if (!this->isVisible()) {
        return;
    }

    int writeTop, writeLeft, writeBottom, writeRight;

    if (!this->hasBorder()) {
        writeTop = this->getY();
        writeLeft = this->getX();
        writeBottom = this->getY() + this->getHeight() - 1;
        writeRight = this->getX() + this->getWidth() - 1;
    } else {
        writeTop = this->getY() + 1;
        writeLeft = this->getX() + 1;
        writeBottom = this->getY() + this->getHeight() - 2;
        writeRight = this->getX() + this->getWidth() - 2;
    }

    int writeWidth = writeRight - writeLeft + 1;
    int lineNumber = 0;
    CSI(textStyle);
    FG_256(textColor);
    for (int i = 0; i < this->text.length();) {
        std::string line = this->text.substr(i, writeWidth);
        i += writeWidth;
        int offset = (writeWidth - line.length()) / 2;
        MOVEXY(writeLeft + offset, writeTop + lineNumber);
        std::cout << line;
        lineNumber++;
    }
    CSI(RESET);
}

void LabelBox::draw()
{
    if (!this->isVisible()) {
        return;
    }
    if (this->hasBorder()) {
        Box::draw();
    }
    this->write();
}