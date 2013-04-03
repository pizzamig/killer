#include "cell.h"
#include <cassert>
#include <iostream>

using namespace std;

Coordinate::Coordinate(uint8_t X, uint8_t Y) : m_X( X ), m_Y( Y )
{
  assert( m_X < 9 );
  assert( m_Y < 9 );
}

Coordinate::Dial_e Coordinate::getDial() const
{
  if( m_X < 3 &&
    m_Y < 3 )
    return Q11;
  if( m_X < 3 &&
    m_Y < 6 && m_Y >= 3 )
    return Q12;
  if( m_X < 3 &&
    m_Y >= 6 )
    return Q13;
  if( m_X < 6 && m_X >= 3 &&
    m_Y < 3 )
    return Q21;
  if( m_X < 6 && m_X >= 3 &&
    m_Y < 6 && m_Y >= 3 )
    return Q22;
  if( m_X < 6 && m_X >= 3 &&
    m_Y >= 6 )
    return Q23;
  if( m_X >= 6 &&
    m_Y < 3 )
    return Q31;
  if( m_X >= 6 &&
    m_Y < 6 && m_Y >= 3 )
    return Q32;
  if( m_X >= 6 &&
    m_Y >= 6 )
    return Q33;
}

Cell::Cell(const Coordinate& C) : m_coord( C ), possibles(), constraints()
{
  for( uint8_t i = 0; i < 9; ++i ) {
    possibles.insert(i+1);
  }
}

Cell::Cell(const uint8_t x, const uint8_t y) : m_coord(x, y), possibles(), constraints()
{
  for( uint8_t i = 0; i < 9; ++i ) {
    possibles.insert(i+1);
  }
}

bool Cell::applyPossibles(const set< uint8_t >& p)
{
  for( set< uint8_t >::iterator i = possibles.begin(); i != possibles.end(); ++i ) {
    if ( p.find( *i ) == p.end() ) {
      possibles.erase( *i );
    }
  }
  if( possibles.empty() ) {
    return false;
  } else {
    return true;
  }
}

void Cell::show() const
{
  for( set< uint8_t >::iterator i = possibles.begin(); i != possibles.end(); ++i ) {
    if( i != possibles.begin() ) {
      cout << " - ";
    }
    cout << (int)*i ;
  }
  cout << endl;
}

void Cell::addConstraint( Constraint * c )
{
  constraints.insert( c );
}

set< uint8_t >& Cell::getPossibles()
{
  possibles.clear();
  if( constraints.empty() ) {
    for( uint8_t i = 0; i < 9; ++i ) {
      possibles.insert(i+1);
    }
    return possibles;
  }
  set< uint8_t >::iterator j = constraints.begin();
  possibles = (*j)->getPossibles();
  for( ++j, j!=constraints.end(); j!=constraints.end(); ++j ) {
    // fare intersezione
  }
}
