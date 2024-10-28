#ifndef __INPUTBOX__
#define __INPUTBOX__

#include "Box.h"

class InputBox : public Box
{
    private:
        bool active;

        bool isActivedStyleSet;
        BoxStyle activedStyle;
        BoxStyle activedCornerStyle;
        Color activedLineColor;
        Color activedTitleColor;
        CSI activedTitleStyle;
    
    public:
        InputBox(Box *parent, int x, int y, int width, int height, int depth, const std::string& title);
        ~InputBox();
        void setActivedStyle(Color LineColor, BoxStyle LineStyle, BoxStyle cornerStyle, Color titleColor, CSI titleStyle);
        virtual void setActived(bool actived);
        bool isActived();
        virtual void drawActive();
        virtual void input(unsigned c) {}
};

#endif