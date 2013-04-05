#pragma once
#include <set>

class Constraint;

class Coordinate
{
public:
  enum Dial_e { Q11, Q12, Q13, Q21, Q22, Q23, Q31, Q32, Q33 };
  Coordinate( uint8_t X, uint8_t Y );
  Dial_e getDial() const;
  uint8_t getRow() const { return m_X; }
  uint8_t getColumn() const { return m_Y; }
private:
  uint8_t m_X;
  uint8_t m_Y;
};

class Cell
{
public:
  Cell( const Coordinate &C );
  Cell( const uint8_t x, const uint8_t y );
  std::set< uint8_t > & getPossibles();
  bool applyPossibles( const std::set< uint8_t > & p );
  void addNotPossibles( uint8_t n );
  void show() const;
  uint8_t getRow() const { return m_coord.getRow(); }
  uint8_t getColumn() const { return m_coord.getColumn(); }
  Coordinate::Dial_e getDial() const { return m_coord.getDial(); }
  void addConstraint( Constraint * );
  bool hasValue() const { return m_value != 0; }
  void setValue( uint8_t v ) { m_value = v; }
  uint8_t getValue() const { return m_value; }
private:
  void _intersectPossible( std::set< uint8_t >& p );
  std::set< uint8_t > possibles;
  std::set< uint8_t > notPossibles;
  Coordinate m_coord;
  std::set< Constraint * > constraints;
  uint8_t m_value;
};
