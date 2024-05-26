#pragma once

#ifndef GPA_MENU_HPP
#define GPA_MENU_HPP

#include <iostream>

#include "../controllers/gpa_controller.hpp"

class GPAMenu {
private:
  GPAController handler;

  void showAllGpas() {
    handler.showGPAs();
  }

  void addGpa() {
    handler.addGPA();
  }

  void calculateGpa() {
    handler.calculateGPA();
  }

public:
  GPAMenu() {
    handler = GPAController();
  }

  void showMenu() {
    int choice, isRunning = 1;

    do {
      system("cls");

      std::cout << "==== GPA Menu ====" << std::endl;
      std::cout << "==================" << std::endl;
      std::cout << "1. Show GPAs" << std::endl;
      std::cout << "2. Add GPA" << std::endl;
      std::cout << "3. Calculate GPA" << std::endl;
      std::cout << "4. Exit" << std::endl;
      std::cout << "==================" << std::endl;
      std::cout << "Enter your choice: ";
      std::cin >> choice;

      switch (choice) {
      case 1:
        showAllGpas();
        break;
      case 2:
        addGpa();
        break;
      case 3:
        calculateGpa();
        break;
      case 4:
        std::cout << "Exiting..." << std::endl;
        isRunning = 0;
        break;
      default:
        std::cout << "Invalid choice. Please try again." << std::endl;
        break;
      }

      system("pause");
    } while (isRunning);
  }
};

#endif // GPA_MENU_HPP
