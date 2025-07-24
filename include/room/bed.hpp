#ifndef BED_HPP
#define BED_HPP

#include "user/student.hpp"
#include <memory>

class Room;

class Bed {
  private:
    std::shared_ptr<Student> owner;
    std::string room_id;
    std::string bed_id;

  public:
    Bed() = delete;
    Bed(std::string bed_id, std::string room_id) {
        this->bed_id = bed_id;
        this->room_id = room_id;
    }
    std::string get_id() { return bed_id; }
    std::string get_room_id() { return room_id; }
    void register_bed(std::shared_ptr<Student> owner) { this->owner = owner; }
};

#endif