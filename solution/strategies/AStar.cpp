#include "AStar.h"

#include "../../types/HeuristicGrid.h"
#include "../../types/HeuristicPos.h"
#include "../../types/HeuristicNode.h"
#include "../../extensions/HeuristicComparator.h"
#include "../../wrappers/UnorderedMap.h"

#include <queue>
#include <algorithm>

std::vector<Pathfind::Pos> Pathfind::AStar::ReconstructPath(const Grid& grid, const UnorderedMap<Pos, Pos>& cameFrom) const
{
  std::vector<Pos> path;

  Pos current_pos = grid.Finish;
  path.push_back(current_pos);

  while (current_pos != grid.Start)
  {
    current_pos = cameFrom.At(current_pos);
    path.push_back(current_pos);

  }

  std::reverse(path.begin(), path.end());

  return path;
}

int Pathfind::AStar::ComputeSteps(const Grid& grid) const
{
  return 0;
}

std::vector<Pathfind::Pos> Pathfind::AStar::GetPath(const Grid& grid) const
{
  HeuristicGrid heuristicGrid = static_cast<const HeuristicGrid&>(grid);

  std::priority_queue<HeuristicPos, std::vector<HeuristicPos>, HeuristicComparator> frontier;
  frontier.push({ grid.Start, 0 });

  UnorderedMap<Pos, Pos> came_from;

  UnorderedMap<Pos, int> cost_so_far;
  cost_so_far[grid.Start] = 0;

  while (!frontier.empty())
  {
    HeuristicPos current = frontier.top();

    if (current.Pos == grid.Finish)
      return ReconstructPath(grid, came_from);

    frontier.pop();

    for (Pos next : grid.Neighbours(current.Pos))
    {
      int next_cost = cost_so_far.At(current.Pos) + 1;

      if (
        cost_so_far.Contains(next)
        && cost_so_far.At(next) <= next_cost
      )
        continue;

      came_from[next] = current.Pos;
      cost_so_far[next] = next_cost;

      frontier.push({ next, heuristicGrid.Heuristic(next) });

    }

  }

  return {};

}
