#include <iostream>
#include <unistd.h>

#include "auth/login.hpp"

void LoginPortal::authenticate(std::string username, std::string password){
    
}

void LoginPortal::login(){
    std::cout << "DormMS v0.1" << std::endl;

    while(true){
        std::string account;

        std::cout << "Username: ";
        std::cin >> account;

        std::cout << "Password: ";
        char *password = getpass("Password: ");

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