#pragma once
#include <sys/types.h>
#include <vector>
#include <set>
#include "cell.h"

class Constraint
{
public:
  Constraint( const uint8_t sum, std::vector< Cell * > * s );
  void link();
  std::set< uint8_t > & getPossibles() { return m_possibles; }
private:
  uint8_t m_sum;
  std::vector< Cell * > * m_cells;
  std::set< uint8_t > m_possibles;
};
