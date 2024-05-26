#pragma once

#ifndef FILE_STORAGE_HELPER_HPP
#define FILE_STORAGE_HELPER_HPP

#include <string>
#include <fstream>

namespace FileStorage {
  static bool exists(std::string filename) {
    std::ifstream file(filename);

    if (!file.is_open()) {
      file.close();

      return false;
    }

    file.close();

    return true;
  }

  static bool create(std::string filename) {
    std::ofstream file(filename);

    if (!file.is_open()) {
      file.close();

      return false;
    }

    file.close();

    return true;
  }

  static std::string read(std::string filename) {
    std::ifstream file(filename);

    std::string line, content = "";

    if (!file.is_open()) {
      file.close();

      return content;
    }

    while (std::getline(file, line)) {
      content += line + "\n";
    }

    file.close();

    return content;
  }

  static bool write(std::string filename, std::string content) {
    std::ofstream file(filename);

    if (!file.is_open()) {
      file.close();

      return false;
    }

    file << content;

    file.close();

    return true;
  }

  static bool remove(std::string filename) {
    if (!exists(filename)) return false;

    return std::remove(filename.c_str()) == 0;
  }
};

#endif // FILE_STORAGE_HELPER_HPP
