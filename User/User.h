#ifndef USER_H
#define USER_H

#include <map>
#include <string>
using namespace std;
class User {
private:
    string login;
    string pass;
    map<string, string> passwords;
public:
    User(const string& l, const string& p);
    void addPassword(const string& app, const string& pass);
    void printPasswords();
    bool checkPass(const string& p);
    const string& getLogin() const;
    const string& getPass() const;
    const map<string, string>& getPasswords() const;
};

#endif