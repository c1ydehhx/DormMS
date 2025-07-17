#ifndef ADMIN_HPP
#define ADMIN_HPP

#include <fstream>
#include <unistd.h>

#include "config/config.hpp"
#include "user/user.hpp"

#include "util/serialize.hpp"

class Admin : public User {
  private:
    Admin(std::string password) : User("admin", password, RoleType::ADMIN) {}

  public:
    static Admin &get_instance() {
        std::string admin_path =
            Configuration::get_instance().get_admin_data_path();

        AdminData admin_data = deserialize_admin_data(admin_path);

        static Admin admin(admin_data.password);

        return admin;
    }

    static void initialize_admin() {
        std::string admin_path =
            Configuration::get_instance().get_admin_data_path();

        std::ifstream f(admin_path.c_str());

        if (!f.good()) {
            std::cout << "Hi, Welcome to DormMS." << std::endl;
            std::cout << "Seems we don't have admin now, maybe we create a "
                         "admin first."
                      << std::endl;

            while (true) {
                std::string pass1 =
                    std::string(getpass("Please enter password for admin: "));
                std::string pass2 = std::string(
                    getpass("Please enter password for admin again: "));

                if (pass1 == pass2) {
                    serialize(AdminData{sha256(pass1)}, admin_path);
                    std::cout << "Nice. Please re-open this system. Bye."
                              << std::endl;
                    exit(0);
                } else {
                    std::cout << "Password mismatch, try again." << std::endl;
                }
            }
        }
    }
};

#endif