#include "HeuristicComparator.h"

#include "../types/HeuristicPos.h"
#include "../types/HeuristicNode.h"

bool Pathfind::HeuristicComparator::operator()(const HeuristicPos& left, const HeuristicPos& right) const
{
  return left.Heuristic > right.Heuristic;
}

bool Pathfind::HeuristicComparator::operator()(const HeuristicNode& left, const HeuristicNode& right) const
{
  return left.Heuristic > right.Heuristic;
}
