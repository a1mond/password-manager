#include <iostream>
#include <string>
#include "../User/User.h"
#include "../Consts/Consts.h"
#include "rwmanager.h"
#include <fstream>
#include <vector>

void appendUser(const User& u) {
    ofstream file(vars::DB_USER_PATH, ofstream::out | ofstream::app);
    if (file) {
        file << u.getLogin() << " " << encryptDecrypt(u.getPass()) << endl;
    } else {
        throw exception("DB USER FILE NOT FOUND");
    }
    file.close();
}
void appendPass(const basic_string<char>& u, const string& app, const string& p) {
    ofstream file(vars::DB_PASS_PATH, ofstream::out | ofstream::app);
    if (file) {
        file << u << " " << app << " " << encryptDecrypt(p) << endl;
    } else {
        throw exception("DB PASS FILE NOT FOUND");
    }
    file.close();
}