#include <fstream>
#include <vector>

#include <bitsery/adapter/buffer.h>
#include <bitsery/bitsery.h>
#include <bitsery/traits/string.h>
#include <bitsery/traits/vector.h>

#include "system/student_manage/student.hpp"
#include "system/student_manage/student_id.hpp"

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

inline void serialize(std::vector<Student> &students, std::string path) {
    std::vector<uint8_t> buffer;

    std::vector<StudentData> student_data;

    for (Student student : students) {
        student_data.push_back({student.get_student_id().to_string(),
                                student.get_name(), student.get_password(),
                                student.get_gender()});
    }

    bitsery::Serializer<bitsery::OutputBufferAdapter<std::vector<uint8_t>>> ser(
        buffer);
    ser.container(student_data, 1000);

    std::ofstream ofs(path, std::ios::binary);
    ofs.write(reinterpret_cast<const char *>(buffer.data()), buffer.size());
}

inline std::vector<Student> deserialize(std::string path) {
    std::ifstream ifs(path, std::ios::binary);
    std::vector<uint8_t> buffer((std::istreambuf_iterator<char>(ifs)), {});

    std::vector<StudentData> student_data;
    bitsery::Deserializer<bitsery::InputBufferAdapter<std::vector<uint8_t>>>
        des(buffer.begin(), buffer.end());
    des.container(student_data, 1000);

    std::vector<Student> students;

    for (StudentData data : student_data) {
        students.push_back(Student(StudentID(data.student_id), data.name,
                                   data.gender, data.password));
    }

    return students;
}