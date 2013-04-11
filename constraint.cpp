#include "constraint.h"
#include "addends.h"

using namespace std;

Constraint::Constraint(const uint8_t sum, vector< Cell* > * s ) : m_sum( sum ), m_cells( s ), m_uniqueSolution(false)
{
  getPossibles();
}

void Constraint::link()
{
  for( vector< Cell * >::iterator i = m_cells->begin(); i != m_cells->end(); ++i) {
    (*i)->addConstraint( this );
  }
}

uSet& Constraint::getPossibles()
{
  Addends a(m_sum, m_cells->size());
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
  } else {
    a.pushAddends();
    m_possibles = a.getPossibles();
  }
  m_uniqueSolution = a.hasUniqueSolution();
  return m_possibles;
}

bool Constraint::hasMandatoryElements(uSet& e)
{
  if( hasOneSolution() ) {
    for( set< uint8_t >::iterator i = m_possibles.begin(); i != m_possibles.end(); ++i ) {
      e.insert( *i );
    }
    return true;
  }
  Addends a(m_sum, m_cells->size());
  a.pushAddends();
  set< uint8_t > with;
  for( vector< Cell * >::iterator i = m_cells->begin(); i != m_cells->end(); ++i) {
    if( (*i)->hasValue() ) {
      with.insert( (*i)->getValue() );
    }
  }
  if( with.empty() == false ) {
    a.pushAddendsW( with );
  }
  return a.hasMandatoryElements( e );
}

bool Constraint::hasSameDial()
{
  vector< Cell * >::iterator i = m_cells->begin();
  Coordinate::Dial_e currDial = (*i)->getDial();
  for( ++i; i != m_cells->end(); ++i ) {
    if( (*i)->getDial() != currDial ) {
      return false;
    }
  }
  return true;
}

bool Constraint::hasSameRow()
{
  vector< Cell * >::iterator i = m_cells->begin();
  uint8_t row = (*i)->getRow();
  for( ++i; i != m_cells->end(); ++i ) {
    if( (*i)->getRow() != row ) {
      return false;
    }
  }
  return true;
}

bool Constraint::hasSameColumn()
{
  vector< Cell * >::iterator i = m_cells->begin();
  uint8_t column = (*i)->getColumn();
  for( ++i; i != m_cells->end(); ++i ) {
    if( (*i)->getColumn() != column ) {
      return false;
    }
  }
  return true;
}

bool Constraint::hasCell(Cell* c)
{
  for( vector< Cell * >::iterator i = m_cells->begin(); i != m_cells->end(); ++i ) {
    if( (*i) == c ) return true;
  }
  return false;
}

uint8_t Constraint::getRow()
{
  return m_cells->at(0)->getRow();
}

uint8_t Constraint::getColumn()
{
  return m_cells->at(0)->getColumn();
}

Coordinate::Dial_e Constraint::getDial()
{
  return m_cells->at(0)->getDial();
}
