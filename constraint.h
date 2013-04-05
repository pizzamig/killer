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
  std::set< uint8_t > & getPossibles();
  int getSize() const { return m_cells->size(); }
  bool hasSameDial();
  bool hasSameRow();
  bool hasSameColumn();
  bool hasOneSolution() const { return m_uniqueSolution; }
  bool hasCell( Cell * c );
  
  uint8_t getColumn();
  uint8_t getRow();
  Coordinate::Dial_e getDial();
private:
  uint8_t m_sum;
  std::vector< Cell * > * m_cells;
  std::set< uint8_t > m_possibles;
  bool m_uniqueSolution;
};
