#ifndef __BUTTONBOX__
#define __BUTTONBOX__

#include <string>
#include <functional>
#include "InputBox.h"
#include "LabelBox.h"

class ButtonBox: public InputBox
{
    private:
        bool isLabelSet;
        LabelBox label;
        CSI labelStyle;
        Color labelColor;
        CSI labelActiveStyle;
        Color labelActiveColor;
        std::function<void()> callEvent;

    public:
        ButtonBox(Box *parent, int x, int y, int width, int height, int depth, const std::string& title);
        ~ButtonBox();
        void setLabel(std::string label, int x, int y, int width, int height);
        void setLabelStyle(CSI labelStyle, Color labelColor);
        void setLabelActiveStyle(CSI labelActiveStyle, Color labelActiveColor);
        std::string getLabel();
        void draw();
        void drawActive();
        void pressEnter();
        void setCallEvent(std::function<void()> callEvent);
};

#endif