#include "Grid.h"

#include "../types/Pos.h"

Pathfind::Grid::Grid(const std::vector<std::string>& field)
  : _width(field[0].length()), _height(field.size())
{
  MapSpecialCells(field);

}

std::array<Pathfind::Pos, 4> Pathfind::Grid::Dirs
{
  Pathfind::Pos { 0, 1 }, { 0, -1 },
  { 1, 0 }, { -1, 0 }
};

bool Pathfind::Grid::InBounds(Pos pos) const
{
  return (
    0 <= pos.X && pos.X < _width
    && 0 <= pos.Y && pos.Y < _height
  );
}

void Pathfind::Grid::MapSpecialCells(const std::vector<std::string>& field)
{
  for (int y = 0; y < _height; y++)
  {
    for (int x = 0; x < _width; x++)
    {
      if (field[y][x] == '#')
        Walls.Insert({ x, y });
      else if (field[y][x] == 'A')
        Start = { x, y };
      else if (field[y][x] == 'F')
        Finish = { x, y };

    }
  }
}

bool Pathfind::Grid::Passable(Pos pos) const
{
  return !Walls.Contains(pos);
}

std::array<Pathfind::Pos, 4> Pathfind::Grid::Neighbours(Pos pos) const
{
  std::array<Pathfind::Pos, 4> neighbours { pos, pos, pos, pos };

  for (int i = 0; i < 4; i++)
  {
    Pos next = pos + Dirs[i];

    if (InBounds(next) && Passable(next))
      neighbours[i] = next;
  }

  return neighbours;
  
}
