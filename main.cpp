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
  
//   Addends a(17,3);
//   std::set< uint8_t > with;
//   with.insert( 3 );
//   with.insert( 5 );
//   a.pushAddendsW( with );
//   
//   a.show();
  
  return 0;
}
