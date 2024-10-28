#ifndef __LABELBOX__
#define __LABELBOX__

#include <string>
#include "Box.h"

class LabelBox : public Box
{
    private:
        std::string text;
        CSI textStyle;
        Color textColor;
        
    public:
        LabelBox(Box* parent, int x, int y, int width, int height, int depth, const std::string& title);
        void setText(std::string text);
        void setStyle(Color textColor, CSI textStyle);
        std::string getText();
        void write();
        void draw();
};

#endif