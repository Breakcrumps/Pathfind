#pragma once

#include "../types/Pos.h"
#include "../types/HeuristicPos.h"

#include <functional>

template <>
struct std::hash<Pathfind::Pos>
{
  std::size_t operator()(Pathfind::Pos pos) const;

};
