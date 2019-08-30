#include "grid.h"
#include "subscriptions.h"
#include "subject.h"
using namespace std;

Grid::Grid() : td{nullptr} {}

Grid::~Grid() {  clearGrid(); }

void Grid::clearGrid() 
{ 
  gridSize = 0;
  theGrid.clear();
  delete td;
}

bool Grid::isWon() const 
{
  for ( int i = 0; i < gridSize; ++ i )
  {
    for ( int j = 0; j < gridSize; ++j )
    {
      if ( theGrid.at( i ).at( j ).getState() == true ) return false;
    }
  }
  return true;
}

void Grid::init( int n ) 
{
  clearGrid();
  gridSize = n;
  td = new TextDisplay( gridSize ); 
  for ( int i = 0; i < gridSize; ++i )
  {
    vector<Cell> vec;
    theGrid.emplace_back( vec );
    for ( int j = 0; j < gridSize; ++j )
    {
      Cell cell;
      cell.setCoords( i, j );
      theGrid.at( i ).emplace_back( cell );
    }
  }
  for ( int x = 0; x < n; ++x )
  {
    for ( int y = 0; y < n; ++y )
    {
      theGrid.at( x ).at( y ).attach( td );
      if ( x != 0 ) theGrid.at( x ).at( y ).attach( &theGrid.at( x - 1 ).at( y ) );
      if ( y != 0 ) theGrid.at( x ).at( y ).attach( &theGrid.at( x ).at( y - 1 ) );
      if ( x != n - 1 ) theGrid.at( x ).at( y ).attach( &theGrid.at( x + 1 ).at( y ) );
      if ( y != n - 1 ) theGrid.at( x ).at( y ).attach( &theGrid.at( x ).at( y + 1 ) );
    }
  } 
}

void Grid::turnOn(int r, int c) { theGrid.at( r ).at( c ).setOn(); }

void Grid::toggle(int r, int c) 
{ 
  theGrid.at( r ).at( c ).toggle(); 
  theGrid.at( r ).at( c ).notifyObservers( SubscriptionType::SwitchOnly );
  theGrid.at( r ).at( c ).notifyObservers( SubscriptionType::All );
}

void Grid::init(int r, int c)  
{ 
  theGrid.at( r ).at( c ).toggle(); 
}

ostream &operator<<(ostream &out, const Grid &g) 
{
  out << *g.td;
  return out;
}
