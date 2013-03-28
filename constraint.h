#pragma once
#include <sys/types.h>
#include <set>
#include "cell.h"

class Constraint
{
public:
  Constraint( const uint8_t sum, std::set< Cell > & s );
private:
  uint8_t m_sum;
  std::set< Cell > m_cells;
};
