#include <iostream>
#include <string>
#include "grid.h"
using namespace std;

int main() {
  cin.exceptions(ios::eofbit|ios::failbit);
  string cmd, aux;
  Grid g;
  int moves = 0;
  try 
  {
    int n, x = 0, y = 0;
    while (true) 
    {
      cin >> cmd;
      if (cmd == "new") 
      {
        cin >> n; 
        g.init( n ); 
      }
      else if (cmd == "init") 
      {
        while ( true )
        {
          cin >> x >> y;
          if ( x == -1 && y == -1 ) break;
          g.turnOn( x , y );
        }
        cout << g;
      }
      else if (cmd == "game") 
      {
        cin >> moves;
         if ( moves == 1 ) cout << "1 move left" << endl;
         else cout << moves << " moves left" << endl; 
         if ( moves == 0 ) 
        {
          if ( g.isWon() ) cout << "Won" << endl;
          else cout << "Lost" << endl;
          break;
        }
      }
      else if (cmd == "switch") 
      {
        int r = 0, c = 0;
        cin >> r >> c;
        g.toggle( r, c );
        cout << g;
        --moves;
        if ( moves == 1 ) cout << "1 move left" <<endl;
        else cout << moves << " moves left" <<endl;
        if ( moves == 0 )
        {
          if ( g.isWon() ) cout << "Won" << endl;
          else cout << "Lost" << endl;
          break;
        }
      }
    }
  }
  catch (ios::failure &) {}
}
