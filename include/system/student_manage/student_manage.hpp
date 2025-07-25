#ifndef STUDENT_MANAGE_SYSTEM_HPP
#define STUDENT_MANAGE_SYSTEM_HPP

#include <iostream>
#include <memory>
#include <optional>
#include <string>
#include <tabulate/table.hpp>
#include <vector>

#include "config/config.hpp"
#include "room/bed.hpp"
#include "room/room.hpp"
#include "user/student.hpp"
#include "util/serialize.hpp"

class StudentManageSystem {
  private:
    std::vector<std::shared_ptr<Student>> students;
    StudentManageSystem() {}

  public:
    static StudentManageSystem &get_instance() {
        static StudentManageSystem instance;
        return instance;
    }

    std::shared_ptr<Student> get_student(std::string ID) {
        for (int i = 0; i < students.size(); i++) {
            if (students[i]->get_student_id().to_string() == ID) {
                return students[i];
            }
        }
        return nullptr;
    }

    void add_student(std::shared_ptr<Student> student) {
        students.push_back(student);
    }

    void delete_student(std::string ID) {
        auto it = students.begin();

        for (int i = 0; it != students.end(); it++) {
            if ((*it)->get_student_id().to_string() == ID) {
                break;
            }
        }

        if (it != students.end()) {
            students.erase(it);
        }
    }

    void list_students() {
        tabulate::Table table;
        table.format().multi_byte_characters(true);

        table.add_row({"ID", "Name", "Gender", "Room", "Bed", "Password"});

        for (std::shared_ptr<Student> student : students) {
            std::shared_ptr<Bed> bed = nullptr;

            std::string bed_id = "---";
            std::string room_id = "---";

            if (bed != nullptr) {
                bed_id = bed->get_id();
                room_id = bed->get_room_id();
            }

            table.add_row(
                {student->get_student_id().to_string(), student->get_name(),
                 student->get_gender() == GenderType::FEMALE ? "Female"
                                                             : "Male",
                 room_id, bed_id, student->get_password()});
        }

        table.print(std::cout);
        std::cout << std::endl;
    }

    void commit() {
        std::string path =
            Configuration::get_instance().get_student_data_path();
        serialize(students, path);
    }

    void read_students() {
        std::string path =
            Configuration::get_instance().get_student_data_path();
        students = deserialize(path);
    }
};

#endif