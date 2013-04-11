#pragma once
#include <sys/types.h>
#include <vector>
#include <set>
#include "cell.h"
#include "util.h"

class Constraint
{
public:
  Constraint( const uint8_t sum, std::vector< Cell * > * s );
  void link();
  uSet & getPossibles();
  bool hasMandatoryElements( uSet & e );
  int getSize() const { return m_cells->size(); }
  bool hasSameDial();
  bool hasSameRow();
  bool hasSameColumn();
  bool hasOneSolution() const { return m_uniqueSolution; }
  bool hasCell( Cell * c );
  std::vector< Cell * > * getCells() { return m_cells; }
  uint8_t getColumn();
  uint8_t getRow();
  Coordinate::Dial_e getDial();
private:
  uint8_t m_sum;
  std::vector< Cell * > * m_cells;
  uSet m_possibles;
  bool m_uniqueSolution;
};
