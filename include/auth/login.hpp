#ifndef LOGIN_MENU_HPP
#define LOGIN_MENU_HPP

#include "user/user.hpp"
#include <memory>
#include <string>
#include <unistd.h>

class LoginPortal {
  private:
    static std::shared_ptr<User> get_user_by_account(std::string account);
    static void authenticate(std::string name, std::string password);

  public:
    static void login();
};

#endif