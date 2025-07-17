#include "auth/login.hpp"
#include "config/config.hpp"
#include "menu/main_menu.hpp"

int main(int argc, char* argv[]){
    Configuration::get_instance().load_configuration(argv[1]);
    
    LoginPortal::login();

    MainMenu::enter_main_menu();
}