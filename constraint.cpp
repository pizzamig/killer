#include "constraint.h"
#include "addends.h"

using namespace std;

Constraint::Constraint(const uint8_t sum, vector< Cell* > * s ) : m_sum( sum ), m_cells( s )
{
}

void Constraint::link()
{
  for( vector< Cell * >::iterator i = m_cells->begin(); i != m_cells->end(); ++i) {
    (*i)->addConstraint( this );
  }
}

set< uint8_t >& Constraint::getPossibles()
{
  Addends a(m_sum, m_cells->size());
  a.pushAddends();
  m_possibles = a.getPossibles();
  set< uint8_t > with;
  for( vector< Cell * >::iterator i = m_cells->begin(); i != m_cells->end(); ++i) {
    if( (*i)->hasValue() ) {
      with.insert( (*i)->getValue() );
    }
  }
  if( with.empty() == false ) {
    a.pushAddendsW( with );
    m_possibles = a.getPossibles();
    for( set< uint8_t >::iterator i = with.begin(); i != with.end(); ++i ) {
      m_possibles.erase((*i));
    }
  }
  return m_possibles;
}
