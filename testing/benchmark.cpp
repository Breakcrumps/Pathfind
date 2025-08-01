#include "benchmark.h"

#include "../solution/Pathfinder.h"

#include <chrono>
#include <iostream>

std::vector<Pathfind::Pos> Pathfind::benchmark_get_path(
  const Pathfinder& pathfinder,
  const Grid& grid,
  int cycles
)
{
  const auto start = std::chrono::steady_clock::now();

  for (int i = 0; i < cycles - 1; i++)
  {
    pathfinder.GetPath(grid);
  }

  std::vector<Pos> path = pathfinder.GetPath(grid);

  std::chrono::duration<double, std::milli> elapsed = std::chrono::steady_clock::now() - start;

  std::cout << cycles << " cycles of GetPath have run for " << elapsed.count() << "ms on " << typeid(pathfinder).name()
    << "\nThe average time of execution was " << elapsed.count() / cycles << "ms\n\n";

  return path;

}
