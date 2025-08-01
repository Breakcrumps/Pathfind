#include "filework.h"

#include <fstream>
#include <iostream>

std::vector<std::string> Pathfind::read_field_file(const std::string& filename)
{
  std::vector<std::string> field;

  std::ifstream file("testing/fields/" + filename + ".txt");

  if (!file.is_open())
  {
    std::cerr << "Error printing file!" << '\n';
    return {};
  }

  std::string buffer;

  while (std::getline(file, buffer))
  {
    field.push_back(buffer);
  }

  file.close();

  return field;

}
