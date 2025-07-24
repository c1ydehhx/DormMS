#ifndef ROOM_MANAGE_ROOM_HPP
#define ROOM_MANAGE_ROOM_HPP

#include "system/room_manage/room_manage.hpp"
#include <iostream>

class RoomManageMenu {
  private:
    static void enter_list_room_procedure() {
        RoomManageSystem::get_instance().list_rooms();
        std::cout << std::endl;
    }

    static void enter_add_room_procedure() {
        std::string room_id;
        int room_capacity = 999;

        std::cout << "<1/2> Please enter room ID: ";
        std::cin >> room_id;

        while (room_capacity > 6 || room_capacity < 1) {
            std::cout << "<2/2> Please enter bed capacity (Max: 6): ";
            std::cin >> room_capacity;
        }

        RoomManageSystem::get_instance().add_room(room_id, room_capacity);

        std::cout << "Room " << room_id << " with " << room_capacity
                  << " bed(s) created." << std::endl
                  << std::endl;
    }

    static void enter_delete_room_procedure() {
        std::string room_id;
        std::string sure;

        std::cout << "<1/2> Please enter room ID: ";
        std::cin >> room_id;

        std::cout << "<2/2> Are you sure? (y/n): ";
        std::cin >> sure;

        if (sure == "y" || sure == "Y") {
            RoomManageSystem::get_instance().delete_room(room_id);
            std::cout << "Room " << room_id << " deleted." << std::endl;
        } else {
            std::cout << "Exit procedure." << std::endl << std::endl;
            return;
        }
    }

  public:
    static void enter_room_manage_system() {
        int choice = 0;

        while (true) {
            std::cout << "Room Manage System" << std::endl;
            std::cout
                << "------------------------------------------------------"
                << std::endl;
            std::cout << "Please select function:" << std::endl;
            std::cout << " - [1] Add Room" << std::endl;
            std::cout << " - [2] Delete Room" << std::endl;
            std::cout << " - [3] List Room" << std::endl;
            std::cout << " - [4] Register student into room" << std::endl;
            std::cout << " - [5] Commit" << std::endl;
            std::cout << " - [0] Back to Main Menu" << std::endl;
            std::cout << std::endl;
            std::cout << "Enter your choice: ";

            std::cin >> choice;

            switch (choice) {
            case 0:
                return;
            case 1:
                enter_add_room_procedure();
                break;
            case 2:
                enter_delete_room_procedure();
                break;
            case 3:
                enter_list_room_procedure();
                break;
            default:
                std::cout << "Please, select function in the list" << std::endl;
                break;
            }

            choice = 0;
        }
    }
};

#endif