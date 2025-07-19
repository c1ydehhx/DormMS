#ifndef CURRENT_LOGIN_USER_HPP
#define CURRENT_LOGIN_USER_HPP

#include "user/user.hpp"
#include <memory>

class CurrentLoginUser {

  private:
    std::shared_ptr<User> current_user;

    CurrentLoginUser() {}

  public:
    static CurrentLoginUser &get_instance() {
        static CurrentLoginUser current_login_user;
        return current_login_user;
    }
    void set_current_user(std::shared_ptr<User> user) {
        this->current_user = user;
    }
    std::shared_ptr<User> get_user() { return current_user; }
};

#endif