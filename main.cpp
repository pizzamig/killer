#include <iostream>
#include <set>
#include "cell.h"
#include "addends.h"
#include "board.h"


int main(int argc, char **argv) {
//   Cell c(0,0);
//   Addends a( 45, 9 );
//   a.pushAddends();
//   a.show();
//   c.show();
//   c.applyPossibles( a.getPossibles() );
//   c.show();
  
  Board b;
  b.solve();

//   Addends a(19,5);
//   a.pushAddends();
//   a.show();
//   a.pushAddendsW( 1 );
//   a.show();
//   std::set< uint8_t > with;
//   with.insert( 1 );
//   with.insert( 4 );
//   a.pushAddendsW( with );
//   a.show();
//   with.insert( 3 );
//   a.pushAddendsW( with );
//   a.show();
  
  
  return 0;
}
