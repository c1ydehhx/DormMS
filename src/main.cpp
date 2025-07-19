#include "auth/login.hpp"
#include "config/config.hpp"
#include "menu/main_menu.hpp"
#include "user/admin.hpp"
#include "user/current_user.hpp"
#include "user/user.hpp"
#include <memory>

int main(int argc, char *argv[]) {
    // System Init Phase
    Configuration::get_instance().load_configuration(argv[1]);
    Admin::initialize_admin();
    StudentManageSystem::get_instance().read_students();

    // Login
    LoginPortal::login();

    // Enter menu by user's role.
    std::shared_ptr<User> user = CurrentLoginUser::get_instance().get_user();

    if (user->get_role() == RoleType::ADMIN) {
        MainMenu::enter_main_menu();
    } else {
        std::cout << "Hi, " << user->get_account() << ". Welcome to DormMS."
                  << std::endl;
    }
}