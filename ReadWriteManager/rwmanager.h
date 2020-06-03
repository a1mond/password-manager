#ifndef RWMANAGER_H
#define RWMANAGER_H

#include <fstream>
#include <vector>
#include <iostream>
void appendUser(const User& u);
void appendPass(const basic_string<char>& u, const string& app, const string& p);

static string encryptDecrypt(const string& pass) {
    string output = pass;
    for (int i = 0; i < pass.size(); i++) {
        output[i] = pass[i] ^ vars::KEY;
    }
    return output;
}
static void split(const string& s, char c, vector<string>& v) {
    string::size_type i = 0;
    string::size_type j = s.find(c);

    while (j != string::npos) {
        v.push_back(s.substr(i, j-i));
        i = ++j;
        j = s.find(c, j);

        if (j == string::npos)
            v.push_back(s.substr(i, s.length()));
    }
}
static void readUser() {
    ifstream file(vars::DB_USER_PATH);
    if (file) {
        while (file.good()) {
            string line;
            getline(file,line);

            vector<string> data;
            split(line,' ',data);

            if (!data.empty()) {
                vars::user_map.insert_or_assign(data[0], User{data[0], encryptDecrypt(data[1])});
                data.clear();
            }
        }
    } else {
        throw exception("DB USER FILE NOT FOUND");
    }
    file.close();
}
static void readPass() {
    ifstream file(vars::DB_PASS_PATH);
    if (file) {
        while (file.good()) {
            string line;
            getline(file,line);

            vector<string> data;
            split(line,' ',data);

            if (!data.empty()) {
                vars::user_map.at(data[0]).addPassword(data[1], encryptDecrypt(data[2]));
                data.clear();
            }
        }
    } else {
        throw exception("DB PASS FILE NOT FOUND");
    }
    file.close();
}
#endif