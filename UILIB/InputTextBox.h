#ifndef __INPUTTEXTBOX__
#define __INPUTTEXTBOX__

#include "InputBox.h"
#include <functional>

class InputTextBox: public InputBox
{
    private:
        std::string inputText;
        std::string placeholder;
        std::string text;
        unsigned cursor;
        bool hideText;
        bool isPlaceholderSet;
        Color textColor;
        CSI textStyle;
        Color textAcitvedColor;
        CSI textActivedStyle;
        std::function<void()> callEvent;

    public:
        InputTextBox(Box *parent, int x, int y, int width, int height, int depth, const std::string& title);
        ~InputTextBox();
        void setPlaceholder(std::string placeholder);
        std::string getPlaceholder();
        void setText(std::string text);
        std::string getText();
        void setTextStyle(Color textColor, CSI textStyle);
        void setTextActivedStyle(Color textColor, CSI textStyle);
        void setHideText(bool hideText);
        void setActived(bool actived);
        bool isHideText();
        void input(unsigned c);
        void draw();
        void drawActive();
        void write();
        void setCallEvent(std::function<void()> callEvent);
        void pressEnter();
};

#endif