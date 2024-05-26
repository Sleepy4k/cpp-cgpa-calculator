//=================================================================================
// Simple project using C++ to handle cumulative grade point average.
//---------------------------------------------------------------------------------
// Built with C++11 standard. this project is a simple console application that
// allows the user to add, calculate, and display cumulative grade point averages
// (GPAs) for students. The project uses a Model-View-Controller (MVC) design
// pattern to separate the data, user interface, and business logic.
//---------------------------------------------------------------------------------
// Project structure:
// .
// ├── main.cpp
// ├── run.bat
// └── README.md
// ├── controllers
// │   └── gpa_controller.hpp
// ├── helpers
// │   ├── file_storage.hpp
// │   └── path.hpp
// ├── models
// │   └── gpa_model.hpp
// ├── structs
// │   └── gpa_struct.hpp
// └── views
//     └── gpa_menu.hpp
//---------------------------------------------------------------------------------
// To run the project, execute the following command:
//     ./run.bat
//---------------------------------------------------------------------------------
// Version: 1.0.0
// Date: 2024-05-26
// License: Unlicense
// Environment: Console
// OS: Windows
// Language: C++
// Email: sarahpalastrin@gmail.com
//---------------------------------------------------------------------------------

#include "helpers/path.hpp"
#include "views/gpa_menu.hpp"

int main(int argc, char const *argv[]) {
  Path::set(argv[0]);

  GPAMenu menu;

  menu.showMenu();

  return 0;
}
