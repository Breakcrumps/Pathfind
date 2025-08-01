#pragma once

#include <vector>

namespace Pathfind
{
  template <typename, typename>
  class UnorderedMap;

  class Pathfinder
  {
  private:
    virtual std::vector<struct Pos> ReconstructPath(const class Grid& grid, const UnorderedMap<Pos, Pos>& cameFrom) const = 0;

  public:
    virtual int ComputeSteps(const Grid& grid) const = 0;

    virtual std::vector<Pos> GetPath(const Grid& grid) const = 0;

    virtual ~Pathfinder() {}

  };

}
