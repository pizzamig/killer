#include "addends.h"
#include <iostream>
#include <cassert>

using namespace std;

Addends::Addends(uint8_t sum, uint8_t an) : m_sum(sum) , m_an(an), S(), m_possibles()
{
  assert( m_sum >= MIN_SUM );
  assert( m_an >= MIN_ADDENDS_NUMBER );
  if( m_an == 2 ) {
    assert( m_sum <= MAX_SUM_2 );
  }
  if( m_an == 3 ) {
    assert( m_sum >= MIN_SUM_3 );
    assert( m_sum <= MAX_SUM_3 );
  }
}

bool Addends::hasMandatoryElements(uSet& e)
{
  bool rc = false;
  set< uint8_t > first = *(S.begin());
  for ( set< uint8_t >::iterator i = first.begin(); i != first.end(); ++i ) {
    set< set<uint8_t> >::iterator k = S.begin();
    
    for( ++k; k != S.end(); ++k ) {
      if( (*k).find( *i ) == (*k).end() ) {
	break; /* this element is not mandatory */
      }
    }
    if( k == S.end() ) {
      rc = true;
      e.insert( *i );
    }
  }
  return rc;
}

void Addends::_updatePossibles()
{
  m_possibles.clear();
  for( set< set<uint8_t> >::iterator i = S.begin(); i != S.end(); ++i ) {
    for( set<uint8_t>::iterator j = (*i).begin(); j != (*i).end(); ++j ) {
      m_possibles.insert( (*j));
    }
  }
}

void Addends::pushAddendsW(const uint8_t W)
{
  if( m_an == 9 && m_sum == 45 ) {
    uSet tmp;
    for( uint8_t i = 1; i <= 9; ++i ) {
      tmp.insert( i );
      m_possibles.insert( i );
    }
    S.insert( tmp );
    return;
  }
  pushAddends();
  set< uSet > tmp = S;
  for( set< uSet >::iterator i = tmp.begin(); i != tmp.end(); ++i ) {
    if( (*i).find( W ) == (*i).end() ) {
      S.erase( *i );
    }
  }
  _updatePossibles();
}

void Addends::pushAddendsW(const uSet& W)
{
  if( m_an == 9 && m_sum == 45 ) {
    uSet tmp;
    for( uint8_t i = 1; i <= 9; ++i ) {
      tmp.insert( i );
      m_possibles.insert( i );
    }
    S.insert( tmp );
    return;
  }
  pushAddends();
  set< uSet > tmp = S;
  for( set< uint8_t >::iterator j = W.begin(); j != W.end(); ++j ) {
    for( set< uSet >::iterator i = tmp.begin(); i != tmp.end(); ++i ) {
      if( (*i).find( (*j) ) == (*i).end() ) {
	S.erase( (*i) );
      }
    }
  }
  _updatePossibles();
}

void Addends::pushAddends()
{
  if( m_an == 9 && m_sum == 45 ) {
    uSet tmp;
    for( uint8_t i = 1; i <= 9; ++i ) {
      tmp.insert( i );
      m_possibles.insert( i );
    }
    S.insert( tmp );
    return;
  }
  S.clear();
  for( uint8_t i = 1; i <= 9; ++i ) {
    set< uint8_t > tmp;
    tmp.insert(i);
    _oneMore( tmp, i );
  }
  _updatePossibles();
}

bool Addends::_oneMore(uSet& ws, uint8_t last)
{
  uint8_t tmp = _sum( ws );
  if( tmp > m_sum ) return false;
  if( ws.size() == m_an ) {
    return tmp == m_sum;
  }
  if( last >= 9 ) {
    return false;
  }
  for( uint8_t i = last+1; i <= 9; ++i ) {
    ws.insert( i );
    if( _oneMore( ws, i) ) {
      S.insert( ws );
    }
    ws.erase(i);
  }
  return false;
}

uint8_t Addends::_sum(uSet& ws)
{
  if( ws.empty() ) {
    return 0;
  }
  uint8_t rc = 0;
  for( set<uint8_t>::iterator i = ws.begin(); i!=ws.end(); ++i ) {
    rc += *i;
  }
  return rc;
}

void Addends::_show(const uSet& ws)
{
  for( set<uint8_t>::iterator i = ws.begin(); i!=ws.end(); ++i ) {
    if( i != ws.begin() ) {
      cout << " - ";
    }
    cout << (int)*i;
  }
  cout << endl;
}

void Addends::show()
{
  cout << "Solutions" << endl;
  for( set< set< uint8_t > >::iterator i = S.begin(); i != S.end(); ++i ) {
    _show( *i );
  }
  cout << "Possible values" << endl;
  for( set<uint8_t>::iterator j = m_possibles.begin(); j!=m_possibles.end(); ++j ) {
    if( j != m_possibles.begin() ) {
      cout << " - ";
    }
    cout << (int)*j;
  }
  cout << endl;
}
