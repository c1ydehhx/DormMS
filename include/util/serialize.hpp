#ifndef SERIALIZE_HPP
#define SERIALIZE_HPP

#include <fstream>
#include <memory>
#include <vector>

#include <bitsery/adapter/buffer.h>
#include <bitsery/bitsery.h>
#include <bitsery/traits/string.h>
#include <bitsery/traits/vector.h>

#include "room/room.hpp"
#include "user/student.hpp"
#include "user/student_id.hpp"

struct StudentData {
    std::string student_id;
    std::string name;
    std::string password;
    bool gender;

    template <typename S> void serialize(S &s) {
        s.text1b(student_id, 100);
        s.text1b(name, 100);
        s.text1b(password, 100);
        s.value1b(gender);
    };
};

struct RoomData {
    std::string room_id;
    int bed_count;
    std::vector<std::string> bed_owners;

    template <typename S> void serialize(S &s) {
        s.text1b(room_id, 100);
        s.value4b(bed_count);
        s.container(bed_owners, bed_count,
                    [](S &s, std::string &str) { s.text1b(str, 100); });
    }
};

struct AdminData {
    std::string password;

    template <typename S> void serialize(S &s) { s.text1b(password, 100); };
};

inline void serialize(std::vector<std::shared_ptr<Student>> &students,
                      std::string path) {
    std::vector<uint8_t> buffer;

    std::vector<StudentData> student_data;

    for (std::shared_ptr<Student> student : students) {
        student_data.push_back(
            {student->get_student_id().to_string(), student->get_name(),
             student->get_password(),
             student->get_gender() == GenderType::FEMALE ? true : false});
    }

    bitsery::Serializer<bitsery::OutputBufferAdapter<std::vector<uint8_t>>> ser(
        buffer);
    ser.container(student_data, 1000);

    std::ofstream ofs(path, std::ios::binary);
    ofs.write(reinterpret_cast<const char *>(buffer.data()), buffer.size());
}

inline void serialize(std::vector<std::shared_ptr<Room>> &rooms,
                      std::string path) {
    std::vector<uint8_t> buffer;

    std::vector<RoomData> room_data;

    for (std::shared_ptr<Room> room : rooms) {
        std::vector<std::string> student_ids;

        for (int i = 0; i < room->get_capacity(); i++) {
            std::shared_ptr<Student> owner = room->get_bed(i)->get_owner();
            if (owner == nullptr) {
                student_ids.push_back("");
            } else {
                student_ids.push_back(owner->get_student_id().to_string());
            }
        }

        room_data.push_back(
            {room->get_id(), (int)room->get_capacity(), student_ids});
    }

    bitsery::Serializer<bitsery::OutputBufferAdapter<std::vector<uint8_t>>> ser(
        buffer);
    ser.container(room_data, 4096);

    std::ofstream ofs(path, std::ios::binary);
    ofs.write(reinterpret_cast<const char *>(buffer.data()), buffer.size());
}

inline void serialize(AdminData admin_data, std::string path) {
    std::vector<uint8_t> buffer;

    bitsery::Serializer<bitsery::OutputBufferAdapter<std::vector<uint8_t>>> ser(
        buffer);
    ser.object(admin_data);

    std::ofstream ofs(path, std::ios::binary);
    ofs.write(reinterpret_cast<const char *>(buffer.data()), buffer.size());
}

inline std::vector<std::shared_ptr<Student>> deserialize(std::string path) {
    std::ifstream ifs(path, std::ios::binary);
    std::vector<uint8_t> buffer((std::istreambuf_iterator<char>(ifs)), {});

    std::vector<StudentData> student_data;
    bitsery::Deserializer<bitsery::InputBufferAdapter<std::vector<uint8_t>>>
        des(buffer.begin(), buffer.end());
    des.container(student_data, 1000);

    std::vector<std::shared_ptr<Student>> students;

    for (StudentData data : student_data) {
        students.push_back(std::make_shared<Student>(
            StudentID(data.student_id), data.name,
            data.gender == 0 ? GenderType::MALE : GenderType::FEMALE,
            data.password));
    }

    return students;
}

inline AdminData deserialize_admin_data(std::string path) {
    std::ifstream ifs(path, std::ios::binary);
    std::vector<uint8_t> buffer((std::istreambuf_iterator<char>(ifs)), {});

    AdminData admin_data;

    bitsery::Deserializer<bitsery::InputBufferAdapter<std::vector<uint8_t>>>
        des(buffer.begin(), buffer.end());

    des.object(admin_data);

    return admin_data;
}

inline std::vector<RoomData> deserialize_room_data(std::string path) {
    std::ifstream ifs(path, std::ios::binary);
    std::vector<uint8_t> buffer((std::istreambuf_iterator<char>(ifs)), {});

    std::vector<RoomData> room_datas;
    bitsery::Deserializer<bitsery::InputBufferAdapter<std::vector<uint8_t>>>
        des(buffer.begin(), buffer.end());
    des.container(room_datas, 4096);

    return room_datas;
}

#endif