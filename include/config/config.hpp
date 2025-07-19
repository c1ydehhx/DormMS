#ifndef CONFIGURATION_HPP
#define CONFIGURATION_HPP

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <string>

class Configuration {
  private:
    std::string admin_data_path;
    std::string student_data_path;
    std::string dorm_data_path;
    Configuration() {}

  public:
    static Configuration &get_instance() {
        static Configuration configuration;
        return configuration;
    }

    std::string get_admin_data_path() { return admin_data_path; }

    std::string get_student_data_path() { return student_data_path; }

    std::string get_dorm_data_path() { return dorm_data_path; }

    void load_configuration(std::string path) {
        std::ifstream f(path);
        nlohmann::json data = nlohmann::json::parse(f);

        admin_data_path = data["admin_data"];

        std::cout << "Load admin data by path: " << admin_data_path
                  << std::endl;

        student_data_path = data["student_data"];

        std::cout << "Load student data by path: " << student_data_path
                  << std::endl;

        dorm_data_path = data["dorm_data"];

        std::cout << "Load dorm data by path: " << dorm_data_path << std::endl;

        std::cout << std::endl;
    }
};

#endif