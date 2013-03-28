#include "constraint.h"
#include "addends.h"

Constraint::Constraint(const uint8_t sum, std::set< Cell >& s ) : m_sum( sum ), m_cells( s )
{
  Addends a(m_sum, m_cells.size());
  a.pushAddends();
  std::set< uint8_t > possibles = a.getPossibles();
  
}
