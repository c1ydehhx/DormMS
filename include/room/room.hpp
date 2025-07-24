#ifndef ROOM_HPP
#define ROOM_HPP

#include <memory>
#include <stdexcept>
#include <vector>

#include "room/bed.hpp"
#include "user/student.hpp"

class Room {
  private:
    std::vector<std::shared_ptr<Bed>> beds;
    std::string room_id;

  public:
    Room(std::string room_id, int bed_count) : room_id(room_id) {
        for (int i = 0; i < bed_count; i++) {
            beds.push_back(
                std::make_shared<Bed>(std::to_string(i + 1), room_id));
        }
    }

    void register_bed(std::shared_ptr<Student> student, int bed_id) {
        if (bed_id < 1 || bed_id > beds.size()) {
            throw std::invalid_argument("Specific ID of bed is absent");
        }
        beds[bed_id - 1]->register_bed(student);
        student->set_bed(beds[bed_id - 1]);
    }

    std::string get_id() { return room_id; }
    size_t get_capacity() { return beds.size(); }
};

#endif