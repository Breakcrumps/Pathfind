#include "BasicPathfinder.h"

#include "../../types/Grid.h"
#include "../../types/StepNode.h"
#include "../../wrappers/UnorderedMap.h"

#include <queue>
#include <iostream>
#include <algorithm>

std::vector<Pathfind::Pos> Pathfind::BasicPathfinder::ReconstructPath(const Grid& grid, const UnorderedMap<Pos, Pos>& cameFrom) const
{
  std::vector<Pos> path;

  Pos current_pos = grid.Finish;
  path.push_back(current_pos);

  while (current_pos != grid.Start)
  {
    current_pos = cameFrom.At(current_pos);
    path.push_back(current_pos);

  }

  return path;
}

int Pathfind::BasicPathfinder::ComputeSteps(const Grid &grid) const
{
  std::queue<StepNode> frontier;
  frontier.push({ grid.Start, 0 });

  UnorderedMap<Pos, Pos> came_from;

  while (!frontier.empty())
  {
    StepNode current = frontier.front();
    frontier.pop();

    if (current.Pos == grid.Finish)
      return current.Step;

    for (Pos next_pos : grid.Neighbours(current.Pos))
    {
      if (came_from.Contains(next_pos))
        continue;

      frontier.push({ next_pos, current.Step + 1 });
      came_from[next_pos] = current.Pos;

    }

  }

  return -1;
}

std::vector<Pathfind::Pos> Pathfind::BasicPathfinder::GetPath(const Grid &grid) const
{
  std::queue<Pos> frontier;
  frontier.push(grid.Start);

  UnorderedMap<Pos, Pos> came_from;

  while (!frontier.empty())
  {
    Pos current_pos = frontier.front();

    if (current_pos == grid.Finish)
      return ReconstructPath(grid, came_from);

    frontier.pop();

    for (Pos next_pos : grid.Neighbours(current_pos))
    {
      if (came_from.Contains(next_pos))
        continue;

      frontier.push(next_pos);
      came_from[next_pos] = current_pos;

    }

  }

  return ReconstructPath(grid, came_from);
  
}
