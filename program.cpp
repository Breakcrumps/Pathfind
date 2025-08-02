#include "IO/filework.h"
#include "IO/print.h"
#include "types/Grid.h"
#include "solution/strategies/BasicPathfinder.h"
#include "solution/strategies/AStar.h"
#include "testing/benchmark.h"
#include "libs/include/nanobench.h"

int main()
{
  std::vector<std::string> field = Pathfind::read_field_file("field2");

  Pathfind::Grid grid(field);

  Pathfind::BasicPathfinder basic_pathfinder;

  ankerl::nanobench::Bench().minEpochIterations(1618).run("GetPath", [&]
  {
    basic_pathfinder.GetPath(grid);
  });
}
