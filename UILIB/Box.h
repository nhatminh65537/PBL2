#ifndef __BOX__
#define __BOX__

#include <iostream>
#include <vector>
#include <string>

#define MOVEXY(x, y)       std::cout << "\x1b[" << y << ";" << x << "H"
#define CUU(n)             std::cout << "\x1b[" << n << "A"
#define CUD(n)             std::cout << "\x1b[" << n << "B"
#define CUF(n)             std::cout << "\x1b[" << n << "C"
#define CUB(n)             std::cout << "\x1b[" << n << "D"
#define FILLXY(x, y, c)    MOVEXY(x, y); std::cout << c
#define FG_256(n)          std::cout << "\x1b[38;5;" << n << "m"
#define FG_RGB(r, g, b)    std::cout << "\x1b[38;2;" << r << ";" << g << ";" << b << "m]"
#define BG_256(n)          std::cout << "\x1b[48;5;" << n << "m"
#define BG_RGB(r, g, b)    std::cout << "\x1b[48;2;" << r << ";" << g << ";" << b << "m]"
#define CSI(n)             std::cout << "\x1b[" << n << "m"
#define SAVE_CURSOR        std::cout << "\x1b[s"
#define RESTORE_CURSOR     std::cout << "\x1b[u"
#define HIDE_CURSOR        std::cout << "\x1b[?25l"
#define SHOW_CURSOR        std::cout << "\x1b[?25h"

extern std::string boxhline [];
extern std::string boxvline [];
extern std::string boxcorner[];
extern std::string splitline[];
extern std::string intersect[];

enum Color{
    BLACK, RED, GREEN, YELLOW, BLUE, MAGENTA, CYAN, WHITE, GRAY,
    BRED, BGREEN, BYELLOW, BBLUE, BMAGENTA, BCYAN, BWHITE,
};
enum BoxStyle{
    LIGHT , HEAVY , DOUBLE, CURVE , L4DASH = 3, 
    H4DASH, L3DASH, H3DASH, L2DASH, H2DASH
};
enum BoxCorner{
    TOPRIGHT, TOPLEFT, BOTTOMLEFT, BOTTOMRIGHT
};
enum CSI{
    RESET, BOLD, DIM, ITALIC, UNDERLINE, BLINK, INVERSE = 7,
    INVISIBLE, STRIKEOUT, DOUBLE_UNDERLINE = 21, OVERLINE = 53,
    NORMAL_INTENSITY = 22, NOT_ITALIC, NOT_UNDERLINE, NOT_BLINK,
    NOT_INVERSE = 27, NOT_INVISIBLE, NOT_STRIKEOUT, NOT_OVERLINE = 55,
    DEFAULT_FG = 39, DEFAULT_BG = 49
};
enum LayoutType{
    FLEXX,
    FLEXY,
    GRID,
    FIX,
    ABS,
};
enum GridType{
    INNER,
    CONNECT,
    SPLIT
};

class Box
{
    private:
        int width;
        int height;
        int depth;
        int x;
        int y;
        bool visible;
        bool border;
        std::string title;
        Box *parent;
        std::vector<Box*> child;
        
        bool isStyleSet;
        BoxStyle style;
        BoxStyle cornerStyle;
        Color lineColor;
        Color titleColor;
        CSI titleStyle;

    public:
        Box(Box *parent, int x, int y, int width, int height, int depth, const std::string& title);
        ~Box();
        void setX(int x);
        void setY(int y);
        void setWidth(int width);
        void setHeight(int height);
        void setDepth(int depth);
        void setTitle(const std::string& title);
        void setStyle(Color LineColor, BoxStyle LineStyle, BoxStyle cornerStyle, Color titleColor, CSI titleStyle);
        void setParent(Box *parent);
        void addChild(Box *child);
        void setVisible(bool visible);
        void setBorder(bool border);
        int getX();
        int getY();
        int getWidth();
        int getHeight();
        int getDepth();
        char *getTitle();
        std::vector<Box*> getChildList();
        BoxStyle getStyle();
        Box *getParent();
        Box *getChild(int index);
        bool isVisible();
        bool hasBorder();
        virtual void draw();
        void draw(Color LineColor, BoxStyle LineStyle, BoxStyle cornerStyle, Color titleColor, CSI titleStyle);
        void clear();
        virtual void pressEnter() {}
};

#endif // __BOX__