#pragma once

namespace Pathfind
{
  struct HeuristicComparator
  {
    bool operator()(const struct HeuristicPos& left, const HeuristicPos& right) const;

    bool operator()(const struct HeuristicNode& left, const HeuristicNode& right) const;
  };
}
