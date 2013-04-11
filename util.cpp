#include "util.h"

using namespace std;

int iFractal(int n)
{
  if( n == 0 ) return 0;
  if( n == 1 ) return 1;
  if( n == 2 ) return 2;
  if( n == 3 ) return 6; /* optimization */
  if( n >= 13 ) return -1;
  return n * iFractal( n - 1 );
}

double dFractal(double n)
{
  if( n == 0 ) return 0;
  if( n == 1 ) return 1;
  if( n == 2 ) return 2;
  return n * dFractal( n - 1 );
}

void intersectSets(uSet& a, uSet& b, uSet& r)
{
  set< uint8_t > * f, * s;
  if( a.size() < b.size() ) {
    f = &a;
    s = &b;
  } else {
    f = &b;
    s = &a;
  }
  for( uSet::iterator i = f->begin(); i != f->end(); ++i ) {
    if( s->find( *i ) != s->end() ) {
      r.insert( (*i) );
    }
  }
}
