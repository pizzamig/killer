#pragma once
#include <sys/types.h>
#include <set>

class Addends
{
public:
  Addends( uint8_t sum, uint8_t an );
  void pushAddends();
  void show();
  std::set< uint8_t > & getPossibles() { return m_possibles; }
//   void pushAddendsWo( std::set< std::set<uint8_t> > & S, const std::set<uint8_t> & WO ); // without variant
//   void pushAddendsWo( std::set< std::set<uint8_t> > & S, const uint8_t WO ); // without variant
//   void pushAddendsW( std::set< std::set<uint8_t> > & S, const std::set<uint8_t> & W ); // with variant
//   void pushAddendsW( std::set< std::set<uint8_t> > & S, const uint8_t & W ); // with variant
//   void pushAddendsWWo( std::set< std::set<uint8_t> > & S, const std::set<uint8_t> & W, const std::set<uint8_t> & WO ); // with and without variant
//   void pushAddendsWWo( std::set< std::set<uint8_t> > & S, const uint8_t & W, const std::set<uint8_t> & WO ); // with and without variant
//   void pushAddendsWWo( std::set< std::set<uint8_t> > & S, const std::set<uint8_t> & W, const uint8_t & WO ); // with and without variant
//   void pushAddendsWWo( std::set< std::set<uint8_t> > & S, const uint8_t & W, const uint8_t & WO ); // with and without variant
  enum LIMITS { MIN_SUM = 3, MIN_ADDENDS_NUMBER = 2,
    MAX_SUM_2 = 17, MIN_SUM_3 = 6, MAX_SUM_3 = 24
  };
private:
  
  bool _oneMore(std::set< uint8_t >& ws, uint8_t last );
  uint8_t _sum( std::set<uint8_t> & ws );
  void _show( const std::set< uint8_t >& ws );
  uint8_t m_sum;
  uint8_t m_an; // addends numbers
  std::set< std::set<uint8_t> > S; // solutions
  std::set<uint8_t> m_possibles;
};
