#include "auth/login.hpp"
#include "menu/main_menu.hpp"

int main(){
    LoginPortal::Login();

    MainMenu::enter_main_menu();
}