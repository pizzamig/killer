#include <set>

typedef std::set< uint8_t > uSet;

/** Integer fractal
 * the limit is n == 12, 13! doesn't fit in 32bit
 */
int iFractal( int n );

/** Double fractal
 */
double dFractal( double n );

/** Set intersection
 * @param a The first set
 * @param b The second set
 * @param r The result set
 */
void intersectSets( uSet & a, uSet & b, uSet & r );

