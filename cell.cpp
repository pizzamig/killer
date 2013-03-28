#include "cell.h"
using namespace std;

Coordinate::Coordinate(uint8_t X, uint8_t Y) : m_X( X ), m_Y( Y )
{
  if( X == 0 )
    m_X = 1;
  if( X > 9 )
    m_X = 9;
  if( Y == 0 )
    m_Y = 1;
  if( Y > 9 )
    m_Y = 9;
}

Coordinate::Dial_e Coordinate::getDial() const
{
  if( m_X <= 3 &&
    m_Y <= 3 )
    return Q11;
  if( m_X <= 3 &&
    m_Y <= 6 && m_Y > 3 )
    return Q12;
  if( m_X <= 3 &&
    m_Y > 6 )
    return Q13;
  if( m_X <= 6 && m_X > 3 &&
    m_Y <= 3 )
    return Q21;
  if( m_X <= 6 && m_X > 3 &&
    m_Y <= 6 && m_Y > 3 )
    return Q22;
  if( m_X <= 6 && m_X > 3 &&
    m_Y > 6 )
    return Q23;
  if( m_X > 6 &&
    m_Y <= 3 )
    return Q31;
  if( m_X > 6 &&
    m_Y <= 6 && m_Y > 3 )
    return Q32;
  if( m_X > 6 &&
    m_Y > 6 )
    return Q33;
}
#include <iostream>


Cell::Cell(const Coordinate& C) : m_coord( C ), possibles()
{
  for( uint8_t i = 0; i < 9; ++i ) {
    possibles.insert(i+1);
  }
}

Cell::Cell(const uint8_t x, const uint8_t y) : m_coord(x, y), possibles()
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
    cout << " - " << (int)*i ;
  }
  cout << endl;
}
