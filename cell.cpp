#include "cell.h"
#include <cassert>
#include <iostream>
#include "constraint.h"

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

Cell::Cell(const Coordinate& C) : m_coord( C ), possibles(), constraints(), m_value(0), notPossibles()
{
  for( uint8_t i = 0; i < 9; ++i ) {
    possibles.insert(i+1);
  }
}

Cell::Cell(const uint8_t x, const uint8_t y) : m_coord(x, y), possibles(), constraints(), m_value(0), notPossibles()
{
  for( uint8_t i = 0; i < 9; ++i ) {
    possibles.insert(i+1);
  }
}

bool Cell::applyPossibles(const uSet& p)
{
  for( set< uint8_t >::iterator i = possibles.begin(); i != possibles.end(); ++i ) {
    if ( p.find( *i ) == p.end() ) {
      possibles.erase( *i );
      --i;
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
  cout << " Cell (" << (int)getRow() << "," << (int)getColumn() << ") : ";
  if( hasValue() ) {
    cout << (int)m_value << endl;
    return;
  }
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

void Cell::_intersectPossible(uSet & p)
{
  if( possibles.empty() || p.empty() ) return;
  uSet tmp(possibles);
  for( uSet::iterator i = tmp.begin(); i != tmp.end(); ++i ) {
    if( p.find( *i ) == p.end() ) {
      possibles.erase( *i );
    }
  }
}
void Cell::_updatePossibles()
{
  possibles.clear();
  for( uint8_t i = 0; i < 9; ++i ) {
    possibles.insert(i+1);
  }
  if( constraints.empty() ) {
    return;
  }
  for( set< Constraint * >::iterator j = constraints.begin(); j!=constraints.end(); ++j ) {
//     if( (*j)->getSize() == 9 ) {
//       continue;
//     }
    _intersectPossible( (*j)->getPossibles() );
  }
  for( uSet::iterator k = notPossibles.begin(); k != notPossibles.end(); ++k ) {
    possibles.erase( (*k) );
  }
}

bool Cell::isPossiblesEmpty()
{
  _updatePossibles();
  return possibles.empty();
}

uSet& Cell::getPossibles()
{
  _updatePossibles();
  return possibles;
}

void Cell::addNotPossibles(uint8_t n)
{
  notPossibles.insert( n );
}
