#pragma once

#include <string>

namespace Pathfind
{
  struct Pos
  {
    int X, Y;

    bool operator==(Pos otherPos) const;

    bool operator!=(Pos otherPos) const;

    Pos operator+(Pos otherPos) const;

    /// @brief Format Pos object for output.
    /// @return Pos object formatted as std::string.
    std::string Format() const;

  };

}
