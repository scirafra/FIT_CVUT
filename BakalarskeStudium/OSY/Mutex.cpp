#ifndef __PROGTEST__
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cstdint>
#include <climits>
#include <cfloat>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <numeric>
#include <string>
#include <vector>
#include <array>
#include <iterator>
#include <set>
#include <list>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <stack>
#include <deque>
#include <memory>
#include <functional>
#include <thread>
#include <mutex>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <pthread.h>
#include <semaphore.h>
#include "progtest_solver.h"
#include "sample_tester.h"
using namespace std;
#endif /* __PROGTEST__ */ 
struct boat
{ 
  AShip sh;
  bool end;
  vector<CCargo> car;
  };
class CCargoPlanner
{
  public:
    static int               SeqSolver                     ( const vector<CCargo> & cargo,
                                                             int               maxWeight,
                                                             int               maxVolume,
                                                             vector<CCargo>  & load );
    void                     Start                         ( int               sales,
                                                             int               workers );
    void                     Stop                          ( void );
  
    void                     sale                          ( void );
  
    void                     work                         ( void );

    void                     Customer                      ( ACustomer         customer );
    void                     Ship                          ( AShip             ship );
  private:
    queue<boat> ships;
    queue<boat> shipstoload;
    vector <ACustomer> cust;
  vector<thread>   thrw;
  vector<thread>   thrs;


  int workery,salery;
  bool end=false,send=false;

 mutex g_Mtx1;
  mutex g_Mtx2;

  condition_variable wor,sal;
};  
int CCargoPlanner::SeqSolver ( const vector<CCargo> & cargo, int maxWeight, int maxVolume, vector<CCargo>  & load )
{
  return ProgtestSolver( cargo, maxWeight, maxVolume, load );
}
void CCargoPlanner::Start ( int sales, int workers )
{
    for ( int i = 0; i < workers; i++ )
    thrw.emplace_back( &CCargoPlanner::work, this );
workery=workers;
  for ( int i = 0; i < sales; i++ )
    thrs.emplace_back( &CCargoPlanner::sale, this );
salery=sales;
}


void CCargoPlanner::Stop ( void )
{
// end=true;
   boat s;
    s.end=true;


  
  for ( int i = 0; i < salery; i++ )
  {
    unique_lock<std::mutex> m1(g_Mtx1);
    ships.push(s);
    m1.unlock();
  }
    sal.notify_all();
    for ( auto & x : thrs )
    x . join ();

  for ( int i = 0; i < workery; i++ )
  {
    unique_lock<std::mutex> m2(g_Mtx2);
    shipstoload.push(s);
    m2.unlock();
  }
  wor.notify_all();
    for ( auto & x : thrw )
    x . join ();
  
  
  
  
} 
    
    


void CCargoPlanner::sale ( void )
{
  while(1){
  unique_lock<std::mutex> m1(g_Mtx1);
  while (ships.size()==0)
  sal.wait(m1);
 boat s=ships.front();
  ships.pop();
  m1.unlock();
if (s.end)
{
   // printf("sale\n");
    break;
  }
  
  for (size_t i=0;i<cust.size();i++)
  {
      vector<CCargo> newcgo;
      cust[i].get()->Quote(s.sh.get()->Destination(),newcgo);
      s.car.insert(s.car.end(),newcgo.begin(),newcgo.end());
  }

  unique_lock<std::mutex> m2(g_Mtx2);
  shipstoload.push(s);
  m2.unlock();
  wor.notify_one();
}
}




void CCargoPlanner::work ( void )
{
  while(1){

  unique_lock<std::mutex> m2(g_Mtx2);
  while (shipstoload.size()==0)
   wor.wait(m2);
  boat s=shipstoload.front();
  shipstoload.pop();
  m2.unlock();
  
if (s.end)
{
 //  printf("work\n");
  break;
  }
  
  vector<CCargo>  loa;
  
  SeqSolver(s.car, s.sh->MaxWeight(),s.sh->MaxVolume(),loa);

  s.sh->Load(loa);
}
}




void CCargoPlanner::Customer ( ACustomer customer )
{
    cust.push_back(customer);
    
}

void CCargoPlanner::Ship ( AShip ship )
{
  boat s;
  s.sh=ship;
  s.end=false;
  unique_lock<std::mutex> m1(g_Mtx1);
  ships.push(s);
  m1.unlock();
  sal.notify_one();
  
}
// TODO: CCargoPlanner implementation goes here
//-------------------------------------------------------------------------------------------------
#ifndef __PROGTEST__
int                main                                    ( void )
{
  CCargoPlanner  test;
  vector<AShipTest> ships;
  vector<ACustomerTest> customers { make_shared<CCustomerTest> (), make_shared<CCustomerTest> () };
  
  ships . push_back ( g_TestExtra[0] . PrepareTest ( "New York", customers ) );
  //this_thread::sleep_for(chrono::milliseconds(2000));
  ships . push_back ( g_TestExtra[1] . PrepareTest ( "Barcelona", customers ) );
// this_thread::sleep_for(chrono::milliseconds(5000));
  ships . push_back ( g_TestExtra[2] . PrepareTest ( "Kobe", customers ) );
//this_thread::sleep_for(chrono::milliseconds(3000));
  ships . push_back ( g_TestExtra[8] . PrepareTest ( "Perth", customers ) );

 /* ships . push_back ( g_TestExtra[3] . PrepareTest ( "York", customers ) );
 this_thread::sleep_for(chrono::milliseconds(6000));
  ships . push_back ( g_TestExtra[4] . PrepareTest ( "Yor", customers ) );
  ships . push_back ( g_TestExtra[5] . PrepareTest ( "Yo", customers ) );
  ships . push_back ( g_TestExtra[6] . PrepareTest ( "Y", customers ) );
  ships . push_back ( g_TestExtra[7] . PrepareTest ( "Yorky", customers ) );
 ships . push_back ( g_TestExtra[9] . PrepareTest ( "a", customers ) );
  ships . push_back ( g_TestExtra[10] . PrepareTest ( "b", customers ) );
  ships . push_back ( g_TestExtra[11] . PrepareTest ( "c", customers ) );
  ships . push_back ( g_TestExtra[12] . PrepareTest ( "d", customers ) );
  ships . push_back ( g_TestExtra[13] . PrepareTest ( "e", customers ) );
  ships . push_back ( g_TestExtra[14] . PrepareTest ( "f", customers ) );
  ships . push_back ( g_TestExtra[15] . PrepareTest ( "g", customers ) );
  ships . push_back ( g_TestExtra[16] . PrepareTest ( "h", customers ) );
  ships . push_back ( g_TestExtra[17] . PrepareTest ( "i", customers ) );
  ships . push_back ( g_TestExtra[18] . PrepareTest ( "j", customers ) );
  ships . push_back ( g_TestExtra[19] . PrepareTest ( "l", customers ) );
  ships . push_back ( g_TestExtra[20] . PrepareTest ( "m", customers ) );
  ships . push_back ( g_TestExtra[21] . PrepareTest ( "n", customers ) );
  ships . push_back ( g_TestExtra[22] . PrepareTest ( "o", customers ) );
  ships . push_back ( g_TestExtra[23] . PrepareTest ( "p", customers ) );
  ships . push_back ( g_TestExtra[24] . PrepareTest ( "q", customers ) );
  ships . push_back ( g_TestExtra[25] . PrepareTest ( "r", customers ) );
  ships . push_back ( g_TestExtra[26] . PrepareTest ( "s", customers ) );
  ships . push_back ( g_TestExtra[27] . PrepareTest ( "t", customers ) );
  ships . push_back ( g_TestExtra[28] . PrepareTest ( "u", customers ) );
  this_thread::sleep_for(chrono::milliseconds(7000));
  ships . push_back ( g_TestExtra[29] . PrepareTest ( "v", customers ) );
  ships . push_back ( g_TestExtra[30] . PrepareTest ( "w", customers ) );
  ships . push_back ( g_TestExtra[31] . PrepareTest ( "x", customers ) );
  ships . push_back ( g_TestExtra[32] . PrepareTest ( "y", customers ) );
  ships . push_back ( g_TestExtra[33] . PrepareTest ( "z", customers ) );
  ships . push_back ( g_TestExtra[34] . PrepareTest ( "aa", customers ) );
  ships . push_back ( g_TestExtra[35] . PrepareTest ( "ab", customers ) );
  ships . push_back ( g_TestExtra[36] . PrepareTest ( "ac", customers ) );
  ships . push_back ( g_TestExtra[37] . PrepareTest ( "ad", customers ) );
  ships . push_back ( g_TestExtra[38] . PrepareTest ( "ae", customers ) );
  ships . push_back ( g_TestExtra[39] . PrepareTest ( "af", customers ) );*/

  // add more ships here
  
  for ( auto x : customers )
    test . Customer ( x );
  
  test . Start ( 3, 2 );
  
  for ( auto x : ships )
    test . Ship ( x );

  test . Stop  ();

  for ( auto x : ships )
    cout << x -> Destination () << ": " << ( x -> Validate () ? "ok" : "fail" ) << endl;
  return 0;  
}
#endif /* __PROGTEST__ */ 
