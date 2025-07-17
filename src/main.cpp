#include "auth/login.hpp"
#include "config/config.hpp"
#include "menu/main_menu.hpp"
#include "user/admin.hpp"

int main(int argc, char *argv[]) {
    Configuration::get_instance().load_configuration(argv[1]);

    Admin::initialize_admin();

    StudentManageSystem::get_instance().read_students();

    LoginPortal::login();

    MainMenu::enter_main_menu();
}