#pragma once

#ifndef GPA_MODEL_HPP
#define GPA_MODEL_HPP

#include <string>
#include <vector>
#include <sstream>

#include "../helpers/path.hpp"
#include "../structs/gpa_struct.hpp"
#include "../helpers/file_storage.hpp"

class GPAModel {
private:
  std::string filename;
  std::vector<GPA> gpas;

public:
  GPAModel() {
    filename = Path::get() + "/gpas.csv";

    if (!FileStorage::exists(filename)) {
      FileStorage::create(filename);
    }

    std::string content = FileStorage::read(filename);
    if (content == "") return;

    std::string line;

    std::vector<GPA> data;

    std::vector<std::string> row;

    std::stringstream ss(content);

    while (std::getline(ss, line, '\n')) {
      row.clear();

      std::stringstream ss(line);

      while (std::getline(ss, line, ',')) {
        row.push_back(line);
      }

      GPA gpa(row[0], std::stoi(row[1]), std::stod(row[2]));

      gpas.push_back(gpa);
    }
  }

  std::vector<GPA> getGPAs() {
    return gpas;
  }

  void addGPA(std::string student_id, int credit_hours, double grade_points) {
    std::string content = "";

    GPA gpa(student_id, credit_hours, grade_points);

    gpas.push_back(gpa);

    for (GPA gpa : gpas) {
      content += student_id + "," + std::to_string(gpa.credit_hours) + "," + std::to_string(gpa.grade_points) + "\n";
    }

    if (FileStorage::exists(filename)) FileStorage::remove(filename);

    FileStorage::write(filename, content);
  }

  void removeGPA(int index) {
    gpas.erase(gpas.begin() + index);

    std::string content = "";

    for (GPA gpa : gpas) {
      content += gpa.student_id + "," + std::to_string(gpa.credit_hours) + "," + std::to_string(gpa.grade_points) + "\n";
    }

    if (FileStorage::exists(filename)) FileStorage::remove(filename);

    FileStorage::write(filename, content);
  }

  void clearGPAs() {
    gpas.clear();

    if (FileStorage::exists(filename)) FileStorage::remove(filename);

    FileStorage::create(filename);
  }

  void updateGPA(int index, std::string student_id, int credit_hours, double grade_points) {
    gpas[index].setGPA(student_id, credit_hours, grade_points);

    std::string content = "";

    for (GPA gpa : gpas) {
      content += gpa.student_id + "," + std::to_string(gpa.credit_hours) + "," + std::to_string(gpa.grade_points) + "\n";
    }

    if (FileStorage::exists(filename)) FileStorage::remove(filename);

    FileStorage::write(filename, content);
  }
};

#endif // GPA_MODEL_HPP
