#pragma once
#include "cell.h"
#include <vector>
class Constraint;

using namespace std;

class Board
{
public:
  Board();
  void solve();
  void show();
  Cell * getCell( uint8_t x, uint8_t y );
private:
  typedef vector< Cell * > Line;
  void _setDefaultCostraints();
  
  bool _solve( std::vector< Cell* >::iterator );
  vector< Cell * > _board;
  vector< Line * > _rows;
  vector< Line * > _columns;
  
  vector< Constraint * > _costraints;
  long long iterations;
};
