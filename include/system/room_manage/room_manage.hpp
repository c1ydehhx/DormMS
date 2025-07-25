#ifndef ROOM_MANAGE_HPP
#define ROOM_MANAGE_HPP

#include <memory>
#include <optional>
#include <stdexcept>
#include <string>
#include <vector>

#include "room/room.hpp"
#include "system/student_manage/student_manage.hpp"
#include "user/student.hpp"

class RoomManageSystem {

  private:
    std::vector<std::shared_ptr<Room>> rooms;
    RoomManageSystem() {}

  public:
    static RoomManageSystem &get_instance() {
        static RoomManageSystem room_manage_system;
        return room_manage_system;
    }

    void add_room(std::string room_id, int capacity) {
        rooms.push_back(std::make_shared<Room>(room_id, capacity));
    }

    void delete_room(std::string room_id) {
        for (auto it = rooms.begin(); it != rooms.end(); it++) {
            if ((*it)->get_id() == room_id) {
                rooms.erase(it);
                break;
            }
        }
    }

    std::shared_ptr<Room> get_room(std::string room_id) {
        for (auto it = rooms.begin(); it != rooms.end(); it++) {
            if ((*it)->get_id() == room_id) {
                return (*it);
            }
        }
        return nullptr;
    }

    void register_stduent_into_room(std::string room_id, std::string bed_id,
                                    std::string student_id) {
        std::shared_ptr<Room> room = get_room(room_id);
        std::shared_ptr<Student> student =
            StudentManageSystem::get_instance().get_student(student_id);

        bool is_register_success = room->register_bed(student, bed_id);

        if (!is_register_success) {
            throw std::runtime_error("Register bed failed");
        }
    }

    void list_rooms() {
        tabulate::Table table;
        table.format().multi_byte_characters(true);

        table.add_row({"ID", "Capacity", "Using"});

        for (std::shared_ptr<Room> room : rooms) {
            table.add_row({room->get_id(), std::to_string(room->get_capacity()),
                           std::to_string(room->get_using_count())});
        }

        table.print(std::cout);
        std::cout << std::endl;
    }
};

#endif