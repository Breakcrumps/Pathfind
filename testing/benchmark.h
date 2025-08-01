#pragma once

#include "../types/Pos.h"

#include <vector>

namespace Pathfind
{
  class Benchmark
  {
  private:
    static double LogPathfinder(
      const class Pathfinder* pathfinder,
      const class Grid& grid,
      int cycles,
      double baselineTime = -1.
    );

  public:
    static std::vector<Pathfind::Pos> BenchmarkGetPath(
      const Pathfinder& pathfinder,
      const Grid& grid,
      int cycles = 60
    );
  
    static void BenchmarkGetPaths(
      const std::vector<Pathfinder*>& pathfinders,
      const Grid& grid,
      int cycles = 60,
      int baselineIndex = 0
    );

  };
}
