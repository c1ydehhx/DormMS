#ifndef ROOM_MANAGE_HPP
#define ROOM_MANAGE_HPP

#include <memory>
#include <optional>
#include <vector>

#include "room/room.hpp"
#include "system/student_manage/student_manage.hpp"
#include "user/student.hpp"

class RoomManageSystem {

  private:
    std::vector<std::shared_ptr<Room>> room;
    RoomManageSystem() {}

  public:
    static RoomManageSystem &get_instance() {
        static RoomManageSystem room_manage_system;
        return room_manage_system;
    }

    void add_room(std::string room_id, int capacity) {
        room.push_back(std::make_shared<Room>(room_id, capacity));
    }

    void delete_room(std::string room_id) {
        for (auto it = room.begin(); it != room.end(); it++) {
            if ((*it)->get_id() == room_id) {
                room.erase(it);
                break;
            }
        }
    }

    std::shared_ptr<Room> get_room(std::string room_id) {
        for (auto it = room.begin(); it != room.end(); it++) {
            if ((*it)->get_id() == room_id) {
                return (*it);
            }
        }
        return nullptr;
    }

    void register_stduent_into_room(std::string room_id, int bed_id,
                                    std::string student_id) {
        std::shared_ptr<Room> room = get_room(room_id);
        std::shared_ptr<Student> student =
            StudentManageSystem::get_instance().get_student(student_id);

        room->register_bed(student, bed_id);
    }
};

#endif