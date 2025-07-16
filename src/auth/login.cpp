#include "auth/login.hpp"

void LoginPortal::Login(){
    std::cout << "DormMS v0.1" << std::endl;

    while(true){
        std::string account;
        std::string password;

        std::cout << "Username: ";
        std::cin >> account;

        // TODO: Secure password input. But since it's platform specific, skip it.
        std::cout << "Password: ";
        std::cin >> password;

        if(account == "admin" && std::string(password) == "admin"){
            std::cout << "Login Success." << std::endl;
            std::cout << std::endl;
            break;
        }else{
            std::cout << "Try again." << std::endl;
            std::cout << std::endl;
        }
    }
}