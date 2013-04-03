#include "board.h"
#include "constraint.h"

Board::Board()
{
  for ( int i = 0; i < 9; ++i ) {
    Line * tmpR = new Line();
    Line * tmpC = new Line();
    _rows.push_back( tmpR );
    _columns.push_back( tmpC );
  }
  for ( int i = 0; i < 9; ++i ) {
    for ( int j = 0; j < 9; ++j ) {
      Cell * tmp = new Cell(i, j);
      _board.push_back( tmp );
      _rows[i]->push_back( tmp );;
      _columns[j]->push_back( tmp );
    }
  }
  _setDefaultCostraints();
}

void Board::_setDefaultCostraints()
{
  /* row constraint */
  for( vector< Board::Line * >::iterator i = _rows.begin(); i != _rows.end(); ++i ) {
    vector< Cell * > * tmp = new vector< Cell * >();
    for( Line::iterator j = (*i)->begin(); j != (*i)->end(); ++j ) {
      tmp->push_back( *j );
    }
    Constraint * c = new Constraint(45, tmp);
    c->link();
  }
  /* column constraint */
  for( vector< Line * >::iterator i = _columns.begin(); i != _columns.end(); ++i ) {
    vector< Cell * > * tmp = new vector< Cell *>();
    for( Line::iterator j = (*i)->begin(); j != (*i)->end(); ++j ) {
      tmp->push_back( *j );
    }
    Constraint * c = new Constraint( 45, tmp );
    c->link();
  }
}

void Board::solve()
{
  _solve( _board.begin() );
}

bool Board::_solve( std::vector< Cell* >::iterator i )
{
  if( i == _board.end() ) {
    return true;
  }
  
  
}
