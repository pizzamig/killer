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
  void _removeFromCostraint( Board::Line* l, Constraint* c );
  void _removeFromCostraint( Board::Line* l, Constraint* c, set< uint8_t >& solution );
  void _optimize();
  void _optimize1();
  void _optimize2();
  bool _solve( std::vector< Cell* >::iterator );
  bool _buildOptiboard();
  bool _isImpossible( Cell * c );
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
