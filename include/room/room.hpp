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

    bool register_bed(std::shared_ptr<Student> student, std::string bed_id) {
        for (std::shared_ptr<Bed> bed : beds) {
            if (bed->get_id() == bed_id) {
                bed->register_bed(student);
                return true;
            }
        }
        return false;
    }

    std::string get_id() { return room_id; }

    size_t get_capacity() { return beds.size(); }

    size_t get_using_count() {
        int count = 0;

        for (std::shared_ptr<Bed> bed : beds) {
            count += (bed->is_used());
        }

        return count;
    }

    std::shared_ptr<Bed> get_last_unused_bed() {
        for (std::shared_ptr<Bed> bed : beds) {
            if (!bed->is_used()) {
                return bed;
            }
        }
        return nullptr;
    }

    std::shared_ptr<Bed> get_bed(int index) { return beds[index]; }
};

#endif