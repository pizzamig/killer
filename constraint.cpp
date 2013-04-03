#include "constraint.h"
#include "addends.h"

using namespace std;

Constraint::Constraint(const uint8_t sum, vector< Cell* > * s ) : m_sum( sum ), m_cells( s )
{
  Addends a(m_sum, m_cells->size());
  a.pushAddends();
  m_possibles = a.getPossibles();
}

void Constraint::link()
{
  for( vector< Cell * >::iterator i = m_cells->begin(); i != m_cells->end(); ++i) {
    (*i)->addConstraint( this );
  }
}
