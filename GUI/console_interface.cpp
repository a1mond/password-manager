#include "console_interface.h"
#include <string>
#include "../ReadWriteManager/rwmanager.h"
#include "../Debug/debug.h"
#include <iostream>
using namespace std;
void listUsers() {
    cout << vars::divisor << endl;
    if (!vars::user_map.empty()) {
        for (const auto &elem : vars::user_map) {
            cout << "   *** " << elem.second.getLogin() << " ***" << endl;
        }
    } else {
        cout << "No records were found for users" << endl;
    }
    cout << vars::divisor;
}
bool checkUser(const string& u) {
    return vars::user_map.count(u);
}
bool signInPassLoop(const string& u) {
    if (checkUser(u)) {
        int count = 0;
        string p;
        cout << "Type here your password (or 0 for exit): " << endl;
        while (count < 3) {
            cin >> p;
            if (vars::user_map.at(u).checkPass(p)) {
                return true;
            } else if (p == "0") {
                return false;
            }
            ++count;
            cout << "Invalid password" << endl;
        }
        cout << "Too many attempts of logging" << endl;
    } else {
        cout << "User \"" << u << "\" is not found" << endl;
        return false;
    }
    return false;
}
void authorized(const string& u) {
    char ui;
    cout << "1 - List all passwords" << endl
         << "2 - Add new password" << endl
         << "3 - Start menu" << endl;
    cout << vars::divisor << endl;
    cin >> ui;
    if (ui == '1') {
        cout << vars::divisor << endl;
        vars::user_map.at(u).printPasswords();
        cout << vars::divisor << endl;
        authorized(u);
    } else if (ui == '2') {
        string app, pass;
        cout << "Type the app, you want to link in the password, and the password (separated by password)" << endl;
        cin >> app >> pass;
        vars::user_map.at(u).addPassword(app, pass);
        try {
            appendPass(u,app,pass);
        } catch (exception& e) {
            cout << e.what() << endl;
        }
        cout << "Successfully added!" << endl
             << vars::divisor << endl;
        authorized(u);
    } else if (ui == '3') {
        cout << vars::divisor << endl;
        startMenu();
    } else {
        cout << vars::divisor << endl;
        authorized(u);
    }
}
void signInCheck(const string& u) {
    if (signInPassLoop(u)) {
        cout << vars::divisor << endl;
        authorized(u);
    } else {
        cout << vars::divisor << endl;
        startMenu();
    }
}
void signUp() {
    string l, p;
    cout << "Type your login and password for signing up (separated by space): ";
    cin >> l >> p;
    vars::user_map.try_emplace(l, User{l,p});
    try {
        appendUser({l, p});
    } catch (exception& e) {
        cout << e.what() << endl;
    }
    cout << "Successfully added!" << endl;
    cout << vars::divisor << endl;
    startMenu();
}
void startMenu() {
    char x;
    cout << "1 - List all users in database" << endl
         << "2 - Sign in" << endl
         << "3 - Sign up" << endl
         << "0 - Exit app" << endl
         << vars::divisor << endl;
    cin >> x;
    if (x == '1') {
        listUsers();
        cout << endl;
        startMenu();
    } else if (x == '2') {
        string u;
        cout << "Type in login to authorize: " << endl;
        cin >> u;
        signInCheck(u);
    } else if (x == '3') {
        signUp();
    } else if (x == '0') {
        cout << "___.                     ___.                 \n"
                "\\_ |__ ___.__. ____      \\_ |__ ___.__. ____  \n"
                " | __ <   |  |/ __ \\      | __ <   |  |/ __ \\ \n"
                " | \\_\\ \\___  \\  ___/      | \\_\\ \\___  \\  ___/ \n"
                " |___  / ____|\\___  >     |___  / ____|\\___  >\n"
                "     \\/\\/         \\/          \\/\\/         \\/ " << endl;
        exit(2);
    } else {
        cout << "Bad input, try again" << endl
             << vars::divisor << endl;
    }
}
void start(const Mode& m) {
    if (m == DEBUG) {
        debugEntries();
        startMenu();
    } else if (m == NORMAL) {
        try {
            readUser();
            readPass();
        } catch (exception& e) {
            cout << e.what() << endl;
            exit(3);
        }
        startMenu();
    }
}