#include "hash.h"

std::size_t std::hash<Pathfind::Pos>::operator()(Pathfind::Pos pos) const
{
  return (
    pos.X >= pos.Y
    ? (pos.X * pos.X) + pos.X + pos.Y
    : (pos.Y * pos.Y) + pos.X
  );
}
