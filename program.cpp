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
  Pathfind::AStar a_star;

  // ankerl::nanobench::Bench().minEpochIterations(60).run("Basic", [&grid, &basic_pathfinder]
  // {
  //   basic_pathfinder.GetPath(grid);
  // });

  // ankerl::nanobench::Bench().minEpochIterations(60).run("AStar", [&grid, &a_star]
  // {
  //   a_star.GetPath(grid);
  // });

  std::vector<Pathfind::Pos> path = a_star.GetPath(grid);

  Pathfind::draw_path(path, field);

}
