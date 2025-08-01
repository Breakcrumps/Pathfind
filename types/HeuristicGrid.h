#pragma once

#include "Grid.h"

namespace Pathfind
{
  class HeuristicGrid : public Grid
  {
  public:
    int Heuristic(const Pos& pos) const;

  };
}
