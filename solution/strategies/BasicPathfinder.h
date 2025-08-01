#pragma once

#include "../Pathfinder.h"

namespace Pathfind
{
  class BasicPathfinder : public Pathfinder
  {
  private:
    std::vector<Pos> ReconstructPath(const Grid& grid, const UnorderedMap<Pos, Pos>& cameFrom) const override;
    
  public:
    int ComputeSteps(const Grid& grid) const override;

    std::vector<Pos> GetPath(const Grid& grid) const override;
    
  };

}
