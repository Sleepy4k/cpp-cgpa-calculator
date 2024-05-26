#pragma once

#ifndef GPA_CONTROLLER_HPP
#define GPA_CONTROLLER_HPP

#include <string>
#include <vector>
#include <iomanip>
#include <iostream>

#include "../models/gpa_model.hpp"

class GPAController {
private:
  GPAModel model;

public:
  GPAController() {
    model = GPAModel();
  }

  std::vector<GPA> getGPAs() {
    return model.getGPAs();
  }

  void showGPAs() {
    std::vector<GPA> gpas = getGPAs();

    if (gpas.size() < 1) {
      std::cout << "No GPAs found." << std::endl;

      return;
    }

    std::cout << std::setw(15) << std::left << "Student ID" << std::setw(15) << std::left << "Credit Hours" << std::setw(15) << std::left << "Grade Points" << std::setw(15) << std::left << "GPA" << std::endl;

    for (GPA gpa : gpas) {
      std::cout << std::setw(15) << std::left << gpa.student_id << std::setw(15) << std::left << gpa.credit_hours << std::setw(15) << std::left << gpa.grade_points << std::setw(15) << std::left << gpa.gpa << std::endl;
    }
  }

  void addGPA() {
    std::string student_id;

    std::cout << "Enter the student ID: ";
    std::cin >> student_id;

    int num_courses = 0;

    std::cout << "Enter the number of courses: ";
    std::cin >> num_courses;

    int total_credit_hours = 0;
    double total_grade_points = 0;

    for (int i = 0; i < num_courses; i++) {
      int credit_hours;
      double grade_points;

      std::cout << "Enter the credit hours for course " << i + 1 << ": ";
      std::cin >> credit_hours;

      std::cout << "Enter the grade points for course " << i + 1 << ": ";
      std::cin >> grade_points;

      total_credit_hours += credit_hours;
      total_grade_points += grade_points;
    }

    model.addGPA(student_id, total_credit_hours, total_grade_points);
  }

  void calculateGPA() {
    std::vector<GPA> gpas = getGPAs();

    if (gpas.size() < 1) {
      std::cout << "No GPAs found." << std::endl;

      return;
    }

    std::string student_id;

    std::cout << "Enter the student ID: ";
    std::cin >> student_id;

    std::cout << "===================" << std::endl;
    std::cout << "Calculating GPA for student " << student_id << std::endl;
    std::cout << "===================" << std::endl;

    int total_credit_hours = 0;
    double total_grade_points = 0;

    for (GPA gpa : gpas) {
      if (gpa.student_id == student_id) {
        total_credit_hours += gpa.credit_hours;
        total_grade_points += gpa.grade_points;
      }
    }

    double gpa = total_grade_points / total_credit_hours;

    GPA calculated_gpa(student_id, total_credit_hours, total_grade_points);
    calculated_gpa.display();
  }

  void removeGPA() {
    showGPAs();

    int index;

    std::cout << "Enter the index of the GPA you want to remove: ";
    std::cin >> index;

    model.removeGPA(index);
  }
};


#endif // GPA_CONTROLLER_HPP
