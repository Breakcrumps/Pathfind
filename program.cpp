#include "IO/filework.h"
#include "IO/print.h"
#include "types/Grid.h"
#include "solution/strategies/BasicPathfinder.h"
#include "solution/strategies/AStar.h"
#include "testing/benchmark.h"

int main()
{
  const std::vector<std::string> field = Pathfind::read_field_file("field2");

  Pathfind::log_field(field);

  Pathfind::Grid grid(field);

  Pathfind::log_grid(grid);

  std::vector<Pathfind::Pos> basic_path = Pathfind::benchmark_get_path(Pathfind::BasicPathfinder(), grid);

  Pathfind::log_path(basic_path);

  return 0;
  
}
