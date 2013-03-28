#include "addends.h"
#include <iostream>
using namespace std;

Addends::Addends(uint8_t sum, uint8_t an) : m_sum(sum) , m_an(an), m_possibles()
{
  if( m_sum < MIN_SUM ) {
    m_sum = MIN_SUM;
  }
  if( m_an < MIN_ADDENDS_NUMBER ) {
    m_an = MIN_ADDENDS_NUMBER;
  }
}

void Addends::pushAddends()
{
  for( uint8_t i = 1; i <= 9; ++i ) {
    set< uint8_t > tmp;
    tmp.insert(i);
    _oneMore( tmp, i );
  }
}

bool Addends::_oneMore(set< uint8_t >& ws, uint8_t last)
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
      for( set<uint8_t>::iterator j = ws.begin(); j!=ws.end(); ++j ) {
	m_possibles.insert( *j );
      }
    }
    ws.erase(i);
  }
  return false;
}

uint8_t Addends::_sum(set< uint8_t >& ws)
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

void Addends::_show(const set< uint8_t >& ws)
{
  for( set<uint8_t>::iterator i = ws.begin(); i!=ws.end(); ++i ) {
    cout << " - " << (int)*i;
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
    cout << " - " << (int)*j;
  }
  cout << endl;
}
