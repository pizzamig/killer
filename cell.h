#pragma once
#include <set>

class Coordinate
{
public:
  enum Dial_e { Q11, Q12, Q13, Q21, Q22, Q23, Q31, Q32, Q33 };
  Coordinate( uint8_t X, uint8_t Y );
  Dial_e getDial() const;
private:
  uint8_t m_X;
  uint8_t m_Y;
};

class Cell
{
public:
  Cell( const Coordinate &C );
  Cell( const uint8_t x, const uint8_t y );
  bool applyPossibles( const std::set< uint8_t > & p );
  void show() const;
private:
  std::set< uint8_t > possibles;
  Coordinate m_coord;
  
};
