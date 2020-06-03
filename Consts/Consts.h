#ifndef CONSTS_H
#define CONSTS_H
#include <string>
#include "../User/User.h"
namespace vars {
    static const std::string DB_USER_PATH = "C:\\Users\\kotik\\Desktop\\proga\\CLion\\Password Manager v2\\DB\\dbUser.csv";
    static const std::string DB_PASS_PATH = "C:\\Users\\kotik\\Desktop\\proga\\CLion\\Password Manager v2\\DB\\dbPass.csv";
    static const int KEY = 138510;
    static std::map<std::string, User> user_map;
    static const string divisor = "--------------------";
}
enum Mode {
    DEBUG,
    NORMAL
};
#endif