#pragma once

#include <vector>
#include <string>

namespace Pathfind
{
  void log_field(const std::vector<std::string>& field);

  void log_grid(const class Grid& grid);

  void log_path(const std::vector<struct Pos>& path);

}
