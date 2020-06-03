#include <vector>
#include <string>
#include <iostream>
#include "User.h"
using namespace std;
    User::User(const string& l, const string& p) {
        login = l;
        pass = p;
    }
    void User::printPasswords() {
        if (!getPasswords().empty()) {
            for (const auto &elem : passwords) {
                cout << "      " << elem.first << ": " << elem.second << endl;
            }
        } else {
            cout << "No records were found" << endl;
        }
    }
    void User::addPassword(const string &app, const string& p) {
        passwords.try_emplace(app, p);
    }
    bool User::checkPass(const string& p) {
        return !pass.compare(p);
    }
    const string& User::getLogin() const {
        return login;
    }
    const string& User::getPass() const {
        return pass;
    }
    const map<string, string>& User::getPasswords() const {
        return passwords;
    }
