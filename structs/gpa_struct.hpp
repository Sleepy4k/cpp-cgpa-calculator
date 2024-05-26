#pragma once

#ifndef GPA_STRUCT_HPP
#define GPA_STRUCT_HPP

#include <string>
#include <iostream>

struct GPA {
  std::string student_id;
  int credit_hours;
  double grade_points;
  double gpa;

  GPA() {
    student_id = "-";
    credit_hours = 0;
    grade_points = 0;
    gpa = 0;
  }

  GPA(std::string student_id, int credit_hours, double grade_points) {
    this->student_id = student_id;
    this->credit_hours = credit_hours;
    this->grade_points = grade_points;
    this->gpa = grade_points / credit_hours;
  }

  void setGPA(std::string student_id, int credit_hours, double grade_points) {
    this->student_id = student_id;
    this->credit_hours = credit_hours;
    this->grade_points = grade_points;
    this->gpa = grade_points / credit_hours;
  }

  void setGPA(double gpa) {
    this->gpa = gpa;
  }

  void setStudentID(std::string student_id) {
    this->student_id = student_id;
  }

  void setCreditHours(int credit_hours) {
    this->credit_hours = credit_hours;
  }

  void setGradePoints(double grade_points) {
    this->grade_points = grade_points;
  }

  void display() {
    std::cout << "Student ID: " << student_id << std::endl;
    std::cout << "Credit Hours: " << credit_hours << std::endl;
    std::cout << "Grade Points: " << grade_points << std::endl;
    std::cout << "GPA: " << gpa << std::endl;
  }
};

#endif // GPA_STRUCT_HPP
