#include <conio.h>
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
#include <functional>
#include "Box.h"
#include "Input.h"
#include "InputBox.h"
#include "LabelBox.h"
#include "ButtonBox.h"
#include "InputTextBox.h"
#include <fstream>

using namespace std;


// void test02() {
//     Box root   = Box(nullptr, 1, 1, 80, 25, 0, "root") ;
//     Box child1 = Box(&root, 1, 1, 40, 25, 0, "child1") ;
//     Box child2 = Box(&root, 41, 1, 40, 25, 0, "child2");
//     root.clear();
//     child1.draw(BLUE, DOUBLE, DOUBLE, BLUE, BOLD);
//     child2.draw(RED , DOUBLE, DOUBLE, RED , BOLD);

//     InputBox input = InputBox(&child1, 2, 2, 38, 23, 0, "");
//     input.setActivedStyle(RED, DOUBLE, DOUBLE, RED, BOLD);
//     input.setStyle(BLUE, DOUBLE, DOUBLE, BLUE, BOLD);
//     input.draw();
//     // string s = "\u251c \u2523 \u2560 \u253c \u254b \u256c";
//     // cout << s << endl;
//     unsigned  c;
//     while (c = getKey()) {
//         if (c == KEY_RETURN) {
//             input.setActived(!input.isActived());
//         }
//         if (c == KEY_ESC) {
//             break;
//         }
//     }
// }



// void test01() {
//     Box root   = Box(nullptr, 1, 1, 80, 25, 0, "root") ;
    
//     ButtonBox btnLeft = ButtonBox(&root, 1, 1, 40, 25, 0, "left");
//     btnLeft.setLabel("Enter to move right!", 1, 13, 40, 1);
//     btnLeft.setStyle(WHITE, DOUBLE, DOUBLE, WHITE, BOLD);
//     btnLeft.setActivedStyle(GREEN, DOUBLE, DOUBLE, GREEN, BOLD);
//     btnLeft.setLabelStyle(NORMAL_INTENSITY, WHITE);
//     btnLeft.setLabelActiveStyle(BOLD, GREEN);
    

//     ButtonBox btnRight = ButtonBox(&root, 41, 1, 40, 25, 0, "right");
//     btnRight.setLabel("Enter to move left!", 41, 13, 40, 1);
//     btnRight.setStyle(WHITE, DOUBLE, DOUBLE, WHITE, BOLD);
//     btnRight.setActivedStyle(GREEN, DOUBLE, DOUBLE, GREEN, BOLD);
//     btnRight.setLabelStyle(NORMAL_INTENSITY, WHITE);
//     btnRight.setLabelActiveStyle(BOLD, GREEN);

//     btnRight.setCallEvent([&btnLeft](){
//         activeBox->setActived(false);
//         activeBox = &btnLeft;
//         activeBox->setActived(true);
//     });
//     btnLeft.setCallEvent([&btnRight](){
//         activeBox->setActived(false);
//         activeBox = &btnRight;
//         activeBox->setActived(true);
//     });

//     activeBox = &btnLeft;

//     root.clear();
//     btnLeft.draw();
//     btnRight.draw();

//     activeBox->setActived(true);
//     unsigned  c;
//     while (c = getKey()) {
//         if (c == KEY_RETURN) {
//             activeBox->pressEnter();
//         }
//         if (c == KEY_ESC) {
//             break;
//         }
//     }
// }

map<unsigned, function<void()>> keybind;
InputBox *activeBox = nullptr;
vector<Box*> showList;
void makeShowList(Box *box) {
    if (box->getParent() == nullptr) {
        showList.clear();
    }
    if (box->isVisible()) {
        showList.push_back(box);
        for (auto &b : box->getChildList()) {
            makeShowList(b);
        }
    }
    if (box->getParent() == nullptr) {
        sort(showList.begin(), showList.end(), [](Box *a, Box *b) {
            return a->getDepth() < b->getDepth();
        });
    }
}
void showAll() {
    for (auto &b : showList) {
        b->draw();
    }
}

Box root = Box(nullptr, 1, 1, 120, 30, 0, "root");
Box welcomePage = Box(&root, 1, 1, 120, 30, 1, "");

Box welcome = Box(&root, 46, 8, 30, 16, 2, "Welcome");
ButtonBox btnLogin = ButtonBox(&welcome, 51, 11, 20, 5, 3, "");
ButtonBox btnRegister = ButtonBox(&welcome, 51, 16, 20, 5, 3, "");

Box login = Box(&root, 46, 8, 30, 16, 2, "Login");
LabelBox labelUsername = LabelBox(&login, 48, 11, 26, 1, 3, "");
InputTextBox inputUsername = InputTextBox(&login, 48, 12, 26, 3, 3, "");
LabelBox labelPassword = LabelBox(&login, 48, 16, 26, 1, 3, "");
InputTextBox inputPassword = InputTextBox(&login, 48, 17, 26, 3, 3, "");

void loginPageInit();
void welcomePageInit();

void run()
{
    root.setBorder(false);
    welcomePageInit();

    while (true) {
        unsigned c = getKey();
        if (c == KEY_ESC) {
            break;
        }
        activeBox->input(c);
        if (keybind.find(c) != keybind.end()) {
            keybind[c]();
        }
    }
}

int main()
{
    run();
    return 0;
}

void loginPageInit() {

    labelUsername.setText("Enter your username");
    labelUsername.setStyle(WHITE, NORMAL_INTENSITY);
    labelUsername.setBorder(false);
    inputUsername.setPlaceholder(string(24, '_'));
    inputUsername.setStyle(WHITE, LIGHT, LIGHT, WHITE, NORMAL_INTENSITY);
    inputUsername.setActivedStyle(WHITE, HEAVY, HEAVY, WHITE, NORMAL_INTENSITY);
    labelPassword.setText("Enter your password");
    labelPassword.setStyle(WHITE, NORMAL_INTENSITY);
    labelPassword.setBorder(false);
    inputPassword.setPlaceholder(string(24, '_'));
    inputPassword.setStyle(WHITE, LIGHT, LIGHT, WHITE, NORMAL_INTENSITY);
    inputPassword.setActivedStyle(WHITE, HEAVY, HEAVY, WHITE, NORMAL_INTENSITY);
    inputPassword.setHideText(true);

    keybind[KEY_UP] = [&](){
        activeBox->setActived(false);
        activeBox = &inputUsername;
        inputUsername.setActived(true);
    };
    keybind[KEY_DOWN] = [&](){
        activeBox->setActived(false);
        activeBox = &inputPassword;
        inputPassword.setActived(true);
    };
    keybind[KEY_TAB] = [&](){
        activeBox->setActived(false);
        activeBox = activeBox == &inputUsername ? &inputPassword : &inputUsername;
        activeBox->setActived(true);
    };

    inputUsername.setCallEvent([&](){
        activeBox->setActived(false);
        activeBox = &inputPassword;
        inputPassword.setActived(true);
    });

    inputPassword.setCallEvent([&](){
        
    });

    root.clear();
    makeShowList(&root);
    showAll();
    activeBox = &inputUsername;
    activeBox->setActived(true);
}

void welcomePageInit() {
    welcomePage.setStyle(WHITE, DOUBLE, DOUBLE, WHITE, BOLD);
    // welcome.setStyle(WHITE, DOUBLE, DOUBLE, WHITE, BOLD);
    
    btnLogin.setStyle(WHITE, DOUBLE, DOUBLE, WHITE, BOLD);
    btnLogin.setActivedStyle(GREEN, DOUBLE, DOUBLE, GREEN, BOLD);
    btnLogin.setLabel("Login", 51, 13, 20, 1);
    btnLogin.setLabelStyle(NORMAL_INTENSITY, WHITE);
    btnLogin.setLabelActiveStyle(BOLD, GREEN);
    btnLogin.setCallEvent([&](){
        welcome.setVisible(false);
        login.setVisible(true);
        loginPageInit();
    });

    btnRegister.setStyle(WHITE, DOUBLE, DOUBLE, WHITE, BOLD);
    btnRegister.setActivedStyle(GREEN, DOUBLE, DOUBLE, GREEN, BOLD);
    btnRegister.setLabel("Register", 51, 18, 20, 1);
    btnRegister.setLabelStyle(NORMAL_INTENSITY, WHITE);
    btnRegister.setLabelActiveStyle(BOLD, GREEN);

    keybind[KEY_UP] = [&](){
        activeBox->setActived(false);
        activeBox = &btnLogin;
        btnLogin.setActived(true);
    };
    keybind[KEY_DOWN] = [&](){
        activeBox->setActived(false);
        activeBox = &btnRegister;
        btnRegister.setActived(true);
    };
    keybind[KEY_RETURN] = [&](){
        activeBox->pressEnter();
    };
    keybind[KEY_TAB] = [&](){
        activeBox->setActived(false);
        activeBox = activeBox == &btnLogin ? &btnRegister : &btnLogin;
        activeBox->setActived(true);
    };

    root.clear();
    makeShowList(&root);
    showAll();
    activeBox = &btnLogin;
    activeBox->setActived(true);
}
