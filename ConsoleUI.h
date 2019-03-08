//
// Created by Horatiu on 03-Mar-19.
//

#ifndef LAB1OPTIONAL_CONSOLEUI_H
#define LAB1OPTIONAL_CONSOLEUI_H


#include "Controller.h"

class ConsoleUI
{
private:
    Controller controller;
public:
    explicit ConsoleUI(const Controller &controller);

    void run();
};


#endif //LAB1OPTIONAL_CONSOLEUI_H
