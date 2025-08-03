#include "print.h"

#include "../types/Grid.h"

#include <iostream>
#include <fstream>

void Pathfind::log_field(const std::vector<std::string> &field)
{
  for (std::string line : field)
  {
    std::cout << line << '\n';
  }

  std::cout << '\n';

}

void Pathfind::log_grid(const Grid &grid)
{
  std::cout << "Start: " << grid.Start.Format() << '\n';
  std::cout << "Finish: " << grid.Finish.Format() << "\n\n";

}

void Pathfind::log_path(const std::vector<Pos>& path)
{
  if (path.empty())
  {
    std::cout << "No path found!\n\n";
    return;
  }

  std::cout << path[path.size() - 1].Format() << " (start)";

  for (int i = path.size() - 2; i > 0; i--)
  {
    std::cout << " --> " << path[i].Format();
  }

  std::cout << " --> " << path[0].Format() << " (finish)\n\n"
    << path.size() - 1 << " steps in total.\n\n";

}

void Pathfind::draw_path(
  const std::vector<Pos>& path,
  const std::vector<std::string> field,
  const std::string& filename
)
{
  std::vector<std::string> path_field(field);

  for (int i = 1; i < path.size() - 1; i++)
  {
    path_field[path[i].Y][path[i].X] = i % 10 + 48;
  }

  std::ofstream file("output/" + filename + ".txt");

  for (std::string line : path_field)
  {
    file << line << '\n';
  }

  file.close();
}
