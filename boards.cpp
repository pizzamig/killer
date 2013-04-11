#include "board.h"
#include "constraint.h"

void Board::_setBoard1()
{
  {
    Cell * c1 = getCell( 1, 7 );
    Cell * c2 = getCell( 1, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 7, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 2, 5 );
    Cell * c2 = getCell( 2, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 11, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 6, 5 );
    Cell * c2 = getCell( 6, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 7, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 7, 7 );
    Cell * c2 = getCell( 7, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 14, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
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
    _costraints.push_back( cc1 );
  }
}

void Board::_setBoard2()
{
  {
    Cell * c1 = getCell( 0, 0 );
    Cell * c2 = getCell( 0, 1 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 9, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 0, 2 );
    Cell * c2 = getCell( 0, 3 );
    Cell * c3 = getCell( 0, 4 );
    Cell * c4 = getCell( 1, 3 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    Constraint * cc1 = new Constraint( 19, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 0, 5 );
    Cell * c2 = getCell( 0, 6 );
    Cell * c3 = getCell( 1, 5 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 20, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 0, 7 );
    Cell * c2 = getCell( 0, 8 );
    Cell * c3 = getCell( 1, 7 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 12, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 1, 0 );
    Cell * c2 = getCell( 1, 1 );
    Cell * c3 = getCell( 1, 2 );
    Cell * c4 = getCell( 2, 1 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    Constraint * cc1 = new Constraint( 20, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 1, 4 );
    Cell * c2 = getCell( 2, 4 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 8, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 1, 6 );
    Cell * c2 = getCell( 2, 6 );
    Cell * c3 = getCell( 3, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 13, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 1, 8 );
    Cell * c2 = getCell( 2, 8 );
    Cell * c3 = getCell( 3, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 14, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 2, 0 );
    Cell * c2 = getCell( 3, 0 );
    Cell * c3 = getCell( 4, 0 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 7, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 2, 2 );
    Cell * c2 = getCell( 2, 3 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 13, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 2, 5 );
    Cell * c2 = getCell( 3, 5 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 15, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 2, 7 );
    Cell * c2 = getCell( 3, 7 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 13, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 3, 1 );
    Cell * c2 = getCell( 4, 1 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 10, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 3, 2 );
    Cell * c2 = getCell( 4, 2 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 6, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 3, 3 );
    Cell * c2 = getCell( 3, 4 );
    Cell * c3 = getCell( 4, 3 );
    Cell * c4 = getCell( 4, 4 );
    Cell * c5 = getCell( 4, 5 );
    Cell * c6 = getCell( 5, 4 );
    Cell * c7 = getCell( 5, 5 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    tmp->push_back( c5 );
    tmp->push_back( c6 );
    tmp->push_back( c7 );
    Constraint * cc1 = new Constraint( 35, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 4, 6 );
    Cell * c2 = getCell( 5, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 7, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 4, 7 );
    Cell * c2 = getCell( 5, 7 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 10, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 4, 8 );
    Cell * c2 = getCell( 5, 8 );
    Cell * c3 = getCell( 6, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 16, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 5, 0 );
    Cell * c2 = getCell( 6, 0 );
    Cell * c3 = getCell( 7, 0 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 20, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 5, 1 );
    Cell * c2 = getCell( 6, 1 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 11, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 5, 2 );
    Cell * c2 = getCell( 6, 2 );
    Cell * c3 = getCell( 7, 2 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 19, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 5, 3 );
    Cell * c2 = getCell( 6, 3 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 5, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 6, 4 );
    Cell * c2 = getCell( 7, 4 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 17, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 6, 5 );
    Cell * c2 = getCell( 6, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 5, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 6, 7 );
    Cell * c2 = getCell( 7, 6 );
    Cell * c3 = getCell( 7, 7 );
    Cell * c4 = getCell( 7, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    Constraint * cc1 = new Constraint( 20, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 7, 1 );
    Cell * c2 = getCell( 8, 0 );
    Cell * c3 = getCell( 8, 1 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 16, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 7, 3 );
    Cell * c2 = getCell( 8, 2 );
    Cell * c3 = getCell( 8, 3 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 15, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 7, 5 );
    Cell * c2 = getCell( 8, 4 );
    Cell * c3 = getCell( 8, 5 );
    Cell * c4 = getCell( 8, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    Constraint * cc1 = new Constraint( 18, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 8, 7 );
    Cell * c2 = getCell( 8, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 12, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
}

void Board::_setBoard3()
{
  {
    Cell * c1 = getCell( 0, 0 );
    Cell * c2 = getCell( 0, 1 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 15, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 0, 2 );
    Cell * c2 = getCell( 1, 2 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 10, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 0, 3 );
    Cell * c2 = getCell( 0, 4 );
    Cell * c3 = getCell( 0, 5 );
    Cell * c4 = getCell( 1, 3 );
    Cell * c5 = getCell( 1, 4 );
    Cell * c6 = getCell( 1, 5 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    tmp->push_back( c5 );
    tmp->push_back( c6 );
    Constraint * cc1 = new Constraint( 33, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 0, 6 );
    Cell * c2 = getCell( 1, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 14, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 0, 7 );
    Cell * c2 = getCell( 0, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 4, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 1, 0 );
    Cell * c2 = getCell( 1, 1 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 5, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 1, 7 );
    Cell * c2 = getCell( 1, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 9, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 2, 0 );
    Cell * c2 = getCell( 3, 0 );
    Cell * c3 = getCell( 4, 0 );
    Cell * c4 = getCell( 5, 0 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    Constraint * cc1 = new Constraint( 19, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 2, 1 );
    Cell * c2 = getCell( 2, 2 );
    Cell * c3 = getCell( 3, 1 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 10, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 2, 3 );
    Cell * c2 = getCell( 3, 2 );
    Cell * c3 = getCell( 3, 3 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 12, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 2, 4 );
    Cell * c2 = getCell( 3, 4 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    Constraint * cc1 = new Constraint( 17, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 2, 5 );
    Cell * c2 = getCell( 3, 5 );
    Cell * c3 = getCell( 3, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 14, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 2, 6 );
    Cell * c2 = getCell( 2, 7 );
    Cell * c3 = getCell( 3, 7 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 15, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 2, 8 );
    Cell * c2 = getCell( 3, 8 );
    Cell * c3 = getCell( 4, 8 );
    Cell * c4 = getCell( 5, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    Constraint * cc1 = new Constraint( 20, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 4, 1 );
    Cell * c2 = getCell( 5, 1 );
    Cell * c3 = getCell( 6, 0 );
    Cell * c4 = getCell( 6, 1 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    Constraint * cc1 = new Constraint( 22, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 4, 2 );
    Cell * c2 = getCell( 4, 3 );
    Cell * c3 = getCell( 4, 4 );
    Cell * c4 = getCell( 4, 5 );
    Cell * c5 = getCell( 4, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    tmp->push_back( c5 );
    Constraint * cc1 = new Constraint( 21, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 4, 7 );
    Cell * c2 = getCell( 5, 7 );
    Cell * c3 = getCell( 6, 7 );
    Cell * c4 = getCell( 6, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    Constraint * cc1 = new Constraint( 23, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 5, 2 );
    Cell * c2 = getCell( 5, 3 );
    Cell * c3 = getCell( 6, 2 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 22, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 5, 4 );
    Cell * c2 = getCell( 6, 3 );
    Cell * c3 = getCell( 6, 4 );
    Cell * c4 = getCell( 6, 5 );
    Cell * c5 = getCell( 7, 3 );
    Cell * c6 = getCell( 7, 5 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    tmp->push_back( c5 );
    tmp->push_back( c6 );
    Constraint * cc1 = new Constraint( 27, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 5, 5 );
    Cell * c2 = getCell( 5, 6 );
    Cell * c3 = getCell( 6, 6 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 8, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 7, 0 );
    Cell * c2 = getCell( 7, 1 );
    Cell * c3 = getCell( 8, 0 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 15, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 7, 2 );
    Cell * c2 = getCell( 8, 1 );
    Cell * c3 = getCell( 8, 2 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 13, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 7, 4 );
    Cell * c2 = getCell( 8, 3 );
    Cell * c3 = getCell( 8, 4 );
    Cell * c4 = getCell( 8, 5 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    tmp->push_back( c4 );
    Constraint * cc1 = new Constraint( 20, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 7, 6 );
    Cell * c2 = getCell( 8, 6 );
    Cell * c3 = getCell( 8, 7 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 18, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
  {
    Cell * c1 = getCell( 7, 7 );
    Cell * c2 = getCell( 7, 8 );
    Cell * c3 = getCell( 8, 8 );
    vector< Cell * > * tmp = new vector< Cell * >();
    tmp->push_back( c1 );
    tmp->push_back( c2 );
    tmp->push_back( c3 );
    Constraint * cc1 = new Constraint( 19, tmp );
    cc1->link();
    _costraints.push_back( cc1 );
  }
}

//   {
//     Cell * c1 = getCell( 3, 5 );
//     Cell * c2 = getCell( 3, 6 );
//     Cell * c3 = getCell( 4, 4 );
//     Cell * c4 = getCell( 4, 5 );
//     Cell * c5 = getCell( 5, 5 );
//     Cell * c6 = getCell( 5, 6 );
//     vector< Cell * > * tmp = new vector< Cell * >();
//     tmp->push_back( c1 );
//     tmp->push_back( c2 );
//     tmp->push_back( c3 );
//     tmp->push_back( c4 );
//     tmp->push_back( c5 );
//     tmp->push_back( c6 );
//     Constraint * cc1 = new Constraint( 36, tmp );
//     cc1->link();
//     _costraints.push_back( cc1 );
//   }
