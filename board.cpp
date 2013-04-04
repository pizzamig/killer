#include "board.h"
#include "constraint.h"
#include <iostream>

Board::Board() : iterations(0)
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
  /* dial constraint */
  vector< Cell * > * tmp11 = new vector< Cell *>();
  vector< Cell * > * tmp12 = new vector< Cell *>();
  vector< Cell * > * tmp13 = new vector< Cell *>();
  vector< Cell * > * tmp21 = new vector< Cell *>();
  vector< Cell * > * tmp22 = new vector< Cell *>();
  vector< Cell * > * tmp23 = new vector< Cell *>();
  vector< Cell * > * tmp31 = new vector< Cell *>();
  vector< Cell * > * tmp32 = new vector< Cell *>();
  vector< Cell * > * tmp33 = new vector< Cell *>();
  for ( vector< Cell * >::iterator i = _board.begin(); i != _board.end(); ++i ) {
    switch( (*i)->getDial()) {
      case Coordinate::Q11:
	tmp11->push_back( (*i) );
	break;
      case Coordinate::Q12:
	tmp12->push_back( (*i) );
	break;
      case Coordinate::Q13:
	tmp13->push_back( (*i) );
	break;
      case Coordinate::Q21:
	tmp21->push_back( (*i) );
	break;
      case Coordinate::Q22:
	tmp22->push_back( (*i) );
	break;
      case Coordinate::Q23:
	tmp23->push_back( (*i) );
	break;
      case Coordinate::Q31:
	tmp31->push_back( (*i) );
	break;
      case Coordinate::Q32:
	tmp32->push_back( (*i) );
	break;
      case Coordinate::Q33:
	tmp33->push_back( (*i) );
	break;
    }
  }
  Constraint * c11 = new Constraint( 45, tmp11 );
  c11->link();
  Constraint * c12 = new Constraint( 45, tmp12 );
  c12->link();
  Constraint * c13 = new Constraint( 45, tmp13 );
  c13->link();
  Constraint * c21 = new Constraint( 45, tmp21 );
  c21->link();
  Constraint * c22 = new Constraint( 45, tmp22 );
  c22->link();
  Constraint * c23 = new Constraint( 45, tmp23 );
  c23->link();
  Constraint * c31 = new Constraint( 45, tmp31 );
  c31->link();
  Constraint * c32 = new Constraint( 45, tmp32 );
  c32->link();
  Constraint * c33 = new Constraint( 45, tmp33 );
  c33->link();

  {
    Cell * c1 = getCell( 1, 7 );
    Cell * c2 = getCell( 1, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 7, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 2, 5 );
    Cell * c2 = getCell( 2, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 11, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 6, 5 );
    Cell * c2 = getCell( 6, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 7, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 7, 7 );
    Cell * c2 = getCell( 7, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 14, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 0, 0 );
    Cell * c2 = getCell( 1, 0 );
    Cell * c3 = getCell( 1, 1 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 24, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 0, 5 );
    Cell * c2 = getCell( 1, 5 );
    Cell * c3 = getCell( 1, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 18, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 0, 6 );
    Cell * c2 = getCell( 0, 7 );
    Cell * c3 = getCell( 0, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 15, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 2, 7 );
    Cell * c2 = getCell( 2, 8 );
    Cell * c3 = getCell( 3, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 9, tmp );
    cc1->link();
  }

  {
    Cell * c1 = getCell( 5, 8 );
    Cell * c2 = getCell( 6, 7 );
    Cell * c3 = getCell( 6, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 21, tmp );
    cc1->link();
  }

  {
    Cell * c1 = getCell( 7, 0 );
    Cell * c2 = getCell( 7, 1 );
    Cell * c3 = getCell( 8, 0 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 18, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 7, 5 );
    Cell * c2 = getCell( 7, 6 );
    Cell * c3 = getCell( 8, 5 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 15, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 8, 6 );
    Cell * c2 = getCell( 8, 7 );
    Cell * c3 = getCell( 8, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 6, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 2, 0 );
    Cell * c2 = getCell( 2, 1 );
    Cell * c3 = getCell( 3, 1 );
    Cell * c4 = getCell( 3, 2 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    Constraint * cc1 = new Constraint( 21, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 3, 0 );
    Cell * c2 = getCell( 4, 0 );
    Cell * c3 = getCell( 4, 1 );
    Cell * c4 = getCell( 5, 0 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    Constraint * cc1 = new Constraint( 11, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 5, 1 );
    Cell * c2 = getCell( 5, 2 );
    Cell * c3 = getCell( 6, 0 );
    Cell * c4 = getCell( 6, 1 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    Constraint * cc1 = new Constraint( 21, tmp );
    cc1->link();
  }

  {
    Cell * c1 = getCell( 0, 1 );
    Cell * c2 = getCell( 0, 2 );
    Cell * c3 = getCell( 0, 3 );
    Cell * c4 = getCell( 0, 4 );
    Cell * c5 = getCell( 1, 4 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    tmp->push_back( c5 );
    Constraint * cc1 = new Constraint( 19, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 1, 2 );
    Cell * c2 = getCell( 1, 3 );
    Cell * c3 = getCell( 2, 2 );
    Cell * c4 = getCell( 2, 3 );
    Cell * c5 = getCell( 2, 4 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    tmp->push_back( c5 );
    Constraint * cc1 = new Constraint( 28, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 3, 7 );
    Cell * c2 = getCell( 4, 6 );
    Cell * c3 = getCell( 4, 7 );
    Cell * c4 = getCell( 4, 8 );
    Cell * c5 = getCell( 5, 7 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    tmp->push_back( c5 );
    Constraint * cc1 = new Constraint( 30, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 6, 2 );
    Cell * c2 = getCell( 6, 3 );
    Cell * c3 = getCell( 6, 4 );
    Cell * c4 = getCell( 7, 2 );
    Cell * c5 = getCell( 7, 3 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    tmp->push_back( c5 );
    Constraint * cc1 = new Constraint( 25, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 7, 4 );
    Cell * c2 = getCell( 8, 1 );
    Cell * c3 = getCell( 8, 2 );
    Cell * c4 = getCell( 8, 3 );
    Cell * c5 = getCell( 8, 4 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    tmp->push_back( c5 );
    Constraint * cc1 = new Constraint( 27, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 3, 3 );
    Cell * c2 = getCell( 3, 4 );
    Cell * c3 = getCell( 4, 2 );
    Cell * c4 = getCell( 4, 3 );
    Cell * c5 = getCell( 5, 3 );
    Cell * c6 = getCell( 5, 4 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    tmp->push_back( c5 );
    tmp->push_back( c6 );
    Constraint * cc1 = new Constraint( 22, tmp );
    cc1->link();
  }
  {
    Cell * c1 = getCell( 3, 5 );
    Cell * c2 = getCell( 3, 6 );
    Cell * c3 = getCell( 4, 4 );
    Cell * c4 = getCell( 4, 5 );
    Cell * c5 = getCell( 5, 5 );
    Cell * c6 = getCell( 5, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    tmp->push_back( c5 );
    tmp->push_back( c6 );
    Constraint * cc1 = new Constraint( 36, tmp );
    cc1->link();
  }

}

Cell* Board::getCell(uint8_t x, uint8_t y)
{
  for( vector< Cell * >::iterator i = _board.begin(); i != _board.end(); ++i ) {
    if( (*i)->getRow() == x && (*i)->getColumn() == y ) {
      return (*i);
    }
  }
  return NULL;
}

void Board::show()
{
  for( vector< Line * >::iterator i = _rows.begin(); i != _rows.end(); ++i ) {
    for( vector< Cell * >::iterator j = (*i)->begin(); j != (*i)->end(); ++j ) {
      cout << (int)(*j)->getValue() << " ";
    }
    cout << endl;
  }
  cout << "iterations: " << dec << iterations << endl;
}

void Board::solve()
{
  if( _solve( _board.begin() ) ) {
    cout << "Finish" << endl;
  } else {
    cout << "Failed" << endl;
  }
  show();
}


bool Board::_solve( std::vector< Cell* >::iterator i )
{
  if( i == _board.end() ) {
    return true;
  }
  ++iterations;
  if( iterations % 5000 == 0 ) {
    show();
  }
  set< uint8_t > p = (*i)->getPossibles();
  if( p.empty() ) {
    return false;
  }
  for( set< uint8_t >::iterator j = p.begin(); j != p.end(); ++j ) {
//     ++iterations;
    (*i)->setValue( *j );
    ++i;
    if( _solve( i ) == true ) {
      return true;
    }
    (*i)->setValue( 0 );
    --i;
  }
  return false;
}
