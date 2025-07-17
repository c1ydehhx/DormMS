#ifndef LOGIN_MENU_HPP
#define LOGIN_MENU_HPP

#include <string>
#include <unistd.h>

class LoginPortal {
private:
    static void authenticate(std::string name, std::string password);
public:
    static void login();
};

#endif