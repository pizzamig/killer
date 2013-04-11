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

//   Addends a(15,3);
//   a.pushAddends();
//   a.show();
//   std::set< uint8_t > with;
//   with.insert( 9 );
//   with.insert( 5 );
//   a.pushAddendsW( 9 );
//   a.show();
  
  return 0;
}
