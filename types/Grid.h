#pragma once

#include "../extensions/hash.h"
#include "../wrappers/UnorderedSet.h"

#include <string>

namespace Pathfind
{
  class Grid
  {
  private:
    static std::array<Pos, 4> Dirs;
  
    int _width, _height;
  
    void MapSpecialCells(const std::vector<std::string>& field);

  public:
    Pos Start, Finish;

    UnorderedSet<Pos> Walls;
    
    Grid(const std::vector<std::string>& field);

    std::vector<Pos> Neighbours(Pos pos) const;

    bool InBounds(Pos pos) const, Passable(Pos pos) const;

  };

}
