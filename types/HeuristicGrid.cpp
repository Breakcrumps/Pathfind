#include "HeuristicGrid.h"

int Pathfind::HeuristicGrid::Heuristic(const Pos& pos) const
{
  return std::abs(Finish.X - pos.X) + std::abs(Finish.Y - pos.Y);
}
