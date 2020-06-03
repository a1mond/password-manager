#ifndef INTERFACE_H
#define INTERFACE_H

#include <string>
#include "../Consts/Consts.h"

void listUsers();
void startMenu();
void start(const Mode& m);
void signUp();
void signInCheck(const std::string& u);
#endif
