#pragma once
#include "cell.h"
#include <vector>

#include <time.h>

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
  void _removeFromCostraint( Line * l, Constraint * c );
  void _optimize();
  void _optimize1();
  bool _solve( std::vector< Cell* >::iterator );
  bool _buildOptiboard();
  vector< Cell * > _board;
  vector< Cell * > _optiBoard;
  vector< Line * > _rows;
  vector< Line * > _columns;
  vector< Line * > _dials;
  vector< Constraint * > _costraints;
  
  long long iterations;
  double iterationsMax;
  time_t startTime;
  bool m_usingOptiBoard;
};
