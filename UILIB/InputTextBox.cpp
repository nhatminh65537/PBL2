#include "InputTextBox.h"
#include "Input.h"
#include <fstream>

InputTextBox::InputTextBox(Box *parent, int x, int y, int width, int height, int depth, const std::string& title)
    : InputBox(parent, x, y, width, height, depth, title)
{
    this->cursor = 0;
    this->inputText = "";
    this->placeholder = "";
    this->text = "";
    this->hideText = false;
    this->isPlaceholderSet = false;
    this->textColor = WHITE;
    this->textStyle = RESET;
    this->textAcitvedColor = WHITE;
    this->textActivedStyle = BOLD;
}

InputTextBox::~InputTextBox()
{
}

void InputTextBox::setPlaceholder(std::string placeholder)
{
    this->placeholder = placeholder;
    this->isPlaceholderSet = true;
}

std::string InputTextBox::getPlaceholder()
{
    return this->placeholder;
}

void InputTextBox::setText(std::string text)
{
    this->text = text;
}

std::string InputTextBox::getText()
{
    return this->text;
}

void InputTextBox::setTextStyle(Color textColor, CSI textStyle)
{
    this->textColor = textColor;
    this->textStyle = textStyle;
}

void InputTextBox::setTextActivedStyle(Color textColor, CSI textStyle)
{
    this->textAcitvedColor = textColor;
    this->textActivedStyle = textStyle;
}

void InputTextBox::setHideText(bool hideText)
{
    this->hideText = hideText;
}

bool InputTextBox::isHideText()
{
    return this->hideText;
}

void InputTextBox::input(unsigned c)
{
    HIDE_CURSOR;
    int limit;
    if (this->hasBorder()) {
        limit = (this->getWidth() - 2)*(this->getHeight() - 2);
    } else {
        limit = this->getWidth()*this->getHeight();
    }
    if (c == KEY_BACKSPACE) {
        if (this->cursor > 0) {
            this->inputText.erase(this->cursor - 1, 1);
            this->cursor--;
        }
    } else if (c == KEY_DEL) {
        if (this->cursor < this->inputText.length()) {
            this->inputText.erase(this->cursor, 1);
        }
    } else if (c == KEY_LEFT) {
        if (this->cursor > 0) {
            this->cursor--;
        }
    } else if (c == KEY_RIGHT) {
        if (this->cursor < this->inputText.length()) {
            this->cursor++;
        }
    } else if (c == KEY_HOME) {
        this->cursor = 0;
    } else if (c == KEY_END) {
        this->cursor = this->inputText.length();
    } else if (c >= 32 && c <= 126) {
        if (this->inputText.length() < limit) {
            this->inputText.insert(this->cursor, 1, (char) c);
            this->cursor++;
        }
    }
    this->write();
}

void InputTextBox::draw()
{
    if (!this->isVisible()) {
        return;
    }
    if (this->hasBorder()) {
        InputBox::draw();
    }
    this->write();
}

void InputTextBox::drawActive()
{
    if (!this->isVisible()) {
        return;
    }
    if (this->hasBorder()) {
        InputBox::drawActive();
    }
    this->write();
}

void InputTextBox::write()
{
    std::string buff = this->inputText;
    if (this->hideText) {
        buff = std::string(buff.length(), '*');
    }
    if (this->isPlaceholderSet and buff.length() < this->placeholder.length()) {
        buff += this->placeholder.substr(buff.length());
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
    if (this->isActived()) {
        CSI(this->textActivedStyle);
        FG_256(this->textAcitvedColor);
    } else {
        CSI(this->textStyle);
        FG_256(this->textColor);
    }
    for (int i = 0; i < buff.length();) {
        std::string line = buff.substr(i, writeWidth);
        i += writeWidth;
        MOVEXY(writeLeft, writeTop + lineNumber);
        std::cout << line;
        lineNumber++;
    }

    int cursorX = this->cursor % writeWidth + writeLeft;
    int cursorY = this->cursor / writeWidth + writeTop;
    if (this->cursor == writeWidth*(writeBottom - writeTop + 1)) {
        cursorX = writeRight;
        cursorY = writeBottom;
    }
    MOVEXY(cursorX, cursorY);
    CSI(RESET);
    SHOW_CURSOR;
}

void InputTextBox::setCallEvent(std::function<void()> callEvent)
{
    this->callEvent = callEvent;
}

void InputTextBox::pressEnter()
{
    
    if (this->callEvent != nullptr) {
        this->callEvent();
    }
}

void InputTextBox::setActived(bool actived)
{
    HIDE_CURSOR;
    InputBox::setActived(actived);
}