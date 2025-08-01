#include "Pos.h"

bool Pathfind::Pos::operator==(Pos otherPos) const
{
  return X == otherPos.X && Y == otherPos.Y; 
}

bool Pathfind::Pos::operator!=(Pos otherPos) const
{
  return !operator==(otherPos);
}

Pathfind::Pos Pathfind::Pos::operator+(Pos otherPos) const
{
  return { X + otherPos.X, Y + otherPos.Y };
}

std::string Pathfind::Pos::Format() const
{
  return std::to_string(X + 1) + ' ' + std::to_string(Y + 1);
}
