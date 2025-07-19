#include "auth/login.hpp"
#include "config/config.hpp"
#include "menu/main_menu.hpp"
#include "user/admin.hpp"

int main(int argc, char *argv[]) {
    // System Init Phase
    Configuration::get_instance().load_configuration(argv[1]);
    Admin::initialize_admin();
    StudentManageSystem::get_instance().read_students();

    // Login
    LoginPortal::login();

    // Enter main menu
    // TODO: RBAC to control the menu.
    MainMenu::enter_main_menu();
}