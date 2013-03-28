#include <iostream>
#include <set>
#include "cell.h"
#include "addends.h"


int main(int argc, char **argv) {
  Cell c(0,0);
  Addends a( 8, 2 );
  a.pushAddends();
  a.show();
  c.show();
  c.applyPossibles( a.getPossibles() );
  c.show();
  return 0;
}
