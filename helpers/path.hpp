#pragma once

#ifndef PATH_HELPER_HPP
#define PATH_HELPER_HPP

#include <string>

std::string basePath = __FILE__;

namespace Path {
  static std::string get() {
    if (basePath == __FILE__) {
      return "";
    }

    return basePath;
  }

  static void set(std::string path) {
    size_t lastBackslashPos = path.find_last_of("\\/");

    if (lastBackslashPos != std::string::npos) path = path.substr(0, lastBackslashPos);

    basePath = path;
  }
};

#endif // PATH_HELPER_HPP
