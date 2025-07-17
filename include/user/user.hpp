#ifndef USER_HPP
#define USER_HPP

#include <string>

#include "util/sha256.hpp"

enum class RoleType { ADMIN, STUDENT };

class User {
  private:
    std::string account;
    std::string password;

    RoleType role;

  public:
    User(std::string account, std::string password, RoleType role)
        : account(account), password(password), role(role) {}

    std::string get_password() { return password; }

    void set_password(std::string password) {
        this->password = sha256(password);
    }

    bool authenticate(std::string password) {
        return this->password == sha256(password);
    }
};

#endif