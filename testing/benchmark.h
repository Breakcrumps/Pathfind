#pragma once

#include "../types/Pos.h"

#include <vector>

namespace Pathfind
{
  std::vector<Pathfind::Pos> benchmark_get_path(
    const class Pathfinder& pathfinder,
    const class Grid& grid,
    int cycles = 60
  );
}
