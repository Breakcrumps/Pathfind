#include "IO/filework.h"
#include "IO/print.h"
#include "types/Grid.h"
#include "solution/strategies/BasicPathfinder.h"
#include "solution/strategies/AStar.h"
#include "testing/benchmark.h"

int main()
{
  const std::vector<std::string> field = Pathfind::read_field_file("field2");

  Pathfind::Grid grid(field);

  Pathfind::BasicPathfinder basic_pathfinder;
  Pathfind::AStar astar_pathfinder;

  std::vector<Pathfind::Pathfinder*> pathfinders = { &basic_pathfinder, &astar_pathfinder }; 

  Pathfind::Benchmark::BenchmarkGetPaths(pathfinders, grid);

  return 0;
  
}
