#include "benchmark.h"

#include "../solution/Pathfinder.h"

#include <chrono>
#include <iostream>
#include <iomanip>

double Pathfind::Benchmark::LogPathfinder(
  const Pathfinder* pathfinder,
  const Grid& grid,
  int cycles,
  double baselineTime
)
{
  auto start = std::chrono::steady_clock::now();

  for (int i = 0; i < cycles; i++)
  {
    pathfinder->GetPath(grid);
  }

  std::chrono::duration<double, std::milli> elapsed = std::chrono::steady_clock::now() - start;
  double time = elapsed.count();

  double rel = (baselineTime > 0.) ? time / baselineTime * 100 : 100;

  std::cout << std::left << std::setw(30) << typeid(*pathfinder).name() << std::setw(20) << time / cycles << std::setw(20) << time
    << rel << "%\n";

  return time;

}

std::vector<Pathfind::Pos> Pathfind::Benchmark::BenchmarkGetPath(
  const Pathfinder& pathfinder,
  const Grid& grid,
  int cycles
)
{
  auto start = std::chrono::steady_clock::now();

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

void Pathfind::Benchmark::BenchmarkGetPaths(
  const std::vector<Pathfinder*>& pathfinders,
  const Grid& grid,
  int cycles,
  int baseline_index
)
{
  std::cout << "\n----------\nTesting: " ;

  for (Pathfinder* pathfinder : pathfinders)
  {
    std::cout << typeid(*pathfinder).name() << ' ';
  }

  std::cout << "\n\nNumber of cycles: " << cycles << "\n\n";

  std::cout << std::left << std::setw(30) << "Pathfinder" << std::setw(20) << "Mean, ms" << std::setw(20) << "Total, ms" << "Rel\n";
  
  double baseline_time = LogPathfinder(pathfinders[baseline_index], grid, cycles);

  for (int i = 0; i < pathfinders.size(); i++)
  {
    if (i == baseline_index)
      continue;
    
    LogPathfinder(pathfinders[i], grid, cycles, baseline_time);
    
  }

  std::cout << "\n----------\n";
}
