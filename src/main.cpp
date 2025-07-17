#include "auth/login.hpp"
#include "config/config.hpp"
#include "menu/main_menu.hpp"
#include "system/student_manage/student_manage.hpp"

int main(int argc, char* argv[]){
    Configuration::get_instance().load_configuration(argv[1]);
    StudentManageSystem::get_instance().read_students();

    LoginPortal::login();

    MainMenu::enter_main_menu();
}