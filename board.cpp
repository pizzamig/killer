#include "board.h"
#include "constraint.h"
#include <iostream>

Board::Board() : iterations(0), iterationsMax(1), m_usingOptiBoard( false )
{
  for ( int i = 0; i < 9; ++i ) {
    Line * tmpR = new Line();
    Line * tmpC = new Line();
    Line * tmpD = new Line();
    _rows.push_back( tmpR );
    _columns.push_back( tmpC );
    _dials.push_back( tmpD );
  }
  for ( int i = 0; i < 9; ++i ) {
    for ( int j = 0; j < 9; ++j ) {
      Cell * tmp = new Cell(i, j);
      _board.push_back( tmp );
      _rows[i]->push_back( tmp );;
      _columns[j]->push_back( tmp );
      _dials[ tmp->getDial() ]->push_back( tmp );
    }
  }
  _setDefaultCostraints();
  _setBoard3();
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
    _costraints.push_back( c );
  }
  /* column constraint */
  for( vector< Line * >::iterator i = _columns.begin(); i != _columns.end(); ++i ) {
    vector< Cell * > * tmp = new vector< Cell *>();
    for( Line::iterator j = (*i)->begin(); j != (*i)->end(); ++j ) {
      tmp->push_back( *j );
    }
    Constraint * c = new Constraint( 45, tmp );
    c->link();
    _costraints.push_back( c );
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
  _costraints.push_back( c11 );
  _costraints.push_back( c12 );
  _costraints.push_back( c13 );
  _costraints.push_back( c21 );
  _costraints.push_back( c22 );
  _costraints.push_back( c23 );
  _costraints.push_back( c31 );
  _costraints.push_back( c32 );
  _costraints.push_back( c33 );
}

void Board::_removeFromCostraint(Board::Line* l, Constraint* c)
{
  _removeFromCostraint( l, c, c->getPossibles() );
}

void Board::_removeFromCostraint(Board::Line* l, Constraint* c, set<uint8_t> & solution )
{
  for( Line::iterator i = l->begin(); i != l->end(); ++i ) {
    if( c->hasCell( (*i) ) == false ) {
      for( set<uint8_t>::iterator j = solution.begin(); j != solution.end(); ++j ) {
	(*i)->addNotPossibles( (*j) );
      }
    }
  }
}

/* This optimization look for costraints that have only one admittable solution
 * If the costraint fit a row or a column and/or a dial, this solution is removed from the possibles
 * solutions of the other cell (of the same row, column or cell)
 */
void Board::_optimize1()
{
  for( vector< Constraint * >::iterator i = _costraints.begin(); i != _costraints.end(); ++i ) {
    if( (*i)->getSize() != 9 && (*i)->hasOneSolution() ) {
      if( (*i)->hasSameColumn() ) {
	Line * l = _columns.at( (*i)->getColumn() );
	_removeFromCostraint( l, (*i) );
      }
      if( (*i)->hasSameRow() ) {
	Line * l = _rows.at( (*i)->getRow() );
	_removeFromCostraint( l, (*i) );
      }
      if( (*i)->hasSameDial() ) {
	Line * l = _dials.at( (*i)->getDial() );
	_removeFromCostraint( l, (*i) );
      }
    }
  }
}

/* This optimization look for costraints that have mandatory elements
 * If the costraint fit a row or a column and/or a dial, these elements are removed from the possibles
 * solutions of the other cell (of the same row, column or cell)
 */
void Board::_optimize2()
{
  for( vector< Constraint * >::iterator i = _costraints.begin(); i != _costraints.end(); ++i ) {
    set< uint8_t > tmp;
    if( (*i)->getSize() != 9 && (*i)->hasMandatoryElements( tmp ) ) {
      if( (*i)->hasSameColumn() ) {
	Line * l = _columns.at( (*i)->getColumn() );
	_removeFromCostraint( l, (*i), tmp );
      }
      if( (*i)->hasSameRow() ) {
	Line * l = _rows.at( (*i)->getRow() );
	_removeFromCostraint( l, (*i), tmp );
      }
      if( (*i)->hasSameDial() ) {
	Line * l = _dials.at( (*i)->getDial() );
	_removeFromCostraint( l, (*i), tmp );
      }
    }
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
  float iSpeed = 0.;
  time_t elapsed = time(0) - startTime;
  iSpeed = (float)iterations / (float)elapsed;
  cout << "iterations: " << iterations << "  speed :" << iSpeed << endl;
  cout << "elapsed time: " << elapsed << endl;
}

void Board::_optimize()
{
  double preEstimation = 1; // to force the first run
  double postEstimation = iterationsMax;
  while( preEstimation != postEstimation ) {
    preEstimation = postEstimation;
    _optimize1();
    _optimize2();
    for( vector< Cell *>::iterator i = _board.begin(); i != _board.end(); ++i ) {
      postEstimation *= (*i)->getPossibles().size();
    }
  }
}

bool Board::_buildOptiboard()
{
  vector< Constraint * > tmp = _costraints;
  for( vector< Constraint *>::iterator i = tmp.begin(); i != tmp.end(); ++i ) {
    if( (*i)->getSize() == 9 ) {
      tmp.erase( i );
      --i;
    } else {
      if( (*i)->hasOneSolution() ) {
	vector< Cell * > * c = (*i)->getCells();
	for( vector< Cell * >::iterator j = c->begin(); j != c->end(); ++j ) {
	  _optiBoard.push_back( (*j) );
	}
	tmp.erase( i );
	--i;
      }
    }
  }
  for( vector< Constraint *>::iterator i = tmp.begin(); i != tmp.end(); ++i ) {
    if( (*i)->getSize() == 9 ) {
      continue;
    }
    vector< Cell * > * c = (*i)->getCells();
    for( vector< Cell * >::iterator j = c->begin(); j != c->end(); ++j ) {
      _optiBoard.push_back( (*j) );
    }
  }
  if ( _optiBoard.size() == 81 ) {
    return true;
  } else { /* 9-element costraints create a problem */
    return false;
  }
}

bool Board::_isImpossible(Cell* c)
{
  Coordinate::Dial_e dial = c->getDial();
  uint8_t row = c->getRow();
  uint8_t column = c->getColumn();
  set< Cell * > tmp;
  for( Line::iterator i = _dials[ dial ]->begin(); i != _dials[ dial ]->end(); ++i ) {
    if((*i)->hasValue()) {
      continue;
    }
    tmp.insert( *i );
  }
  for( Line::iterator i = _rows[ row ]->begin(); i != _rows[ row ]->end(); ++i ) {
    if((*i)->hasValue()) {
      continue;
    }
    tmp.insert( *i );
  }
  for( Line::iterator i = _columns[ column ]->begin(); i != _columns[ column ]->end(); ++i ) {
    if((*i)->hasValue()) {
      continue;
    }
    tmp.insert( *i );
  }
  if( tmp.size() > 7 ) {
    return false;
  } else {
    for( set< Cell * >::iterator i = tmp.begin(); i != tmp.end(); ++i ) {
      if( (*i)->isPossiblesEmpty() ) {
	return true;
      }
    }
  }
  return false;
}

void Board::solve()
{
  iterationsMax = 1;
  for( vector< Cell *>::iterator i = _board.begin(); i != _board.end(); ++i ) {
    set< uint8_t > p = (*i)->getPossibles();
    iterationsMax *= p.size();
  }
  cout << "Iterations MAX (overestimation): " << iterationsMax << endl;
  _optimize();
  double iterationsMax1 = 1.;
  for( vector< Cell *>::iterator i = _board.begin(); i != _board.end(); ++i ) {
    iterationsMax1 *= (*i)->getPossibles().size();
  }
  cout << "Iterations MAX after preoptimization (overestimation): " << iterationsMax1 << endl;
//   m_usingOptiBoard = _buildOptiboard();
  startTime = time(0);
  if( m_usingOptiBoard ) {
    cout << "Using Optimized board" << endl;
    if( _solve( _optiBoard.begin() ) ) {
      cout << "Finish" << endl;
    } else {
      cout << "Failed" << endl;
    }
  } else {
    cout << "Using standard board" << endl;
    if( _solve( _board.begin() ) ) {
      cout << "Finish" << endl;
    } else {
      cout << "Failed" << endl;
    }
  }
  show();
}

bool Board::_solve( std::vector< Cell* >::iterator i )
{
  if( m_usingOptiBoard ) {
    if( i == _optiBoard.end() ) {
      return true;
    }
  } else {
    if( i == _board.end() ) {
      return true;
    }
  }
  ++iterations;
  if( iterations % 50000 == 0 ) {
    show();
  }
  uSet p = (*i)->getPossibles();
  if( p.empty() ) {
    return false;
  }
  for( uSet::iterator j = p.begin(); j != p.end(); ++j ) {
    (*i)->setValue( *j );
    if( _isImpossible( (*i) ) ) {
      ++iterations;
      if( iterations % 50000 == 0 ) {
	show();
      }
      (*i)->setValue( 0 );
      continue;
    }
    ++i;
    if( _solve( i ) == true ) {
      return true;
    }
    --i;
    (*i)->setValue( 0 );
  }
  return false;
}
