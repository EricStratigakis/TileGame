#include <utility>
#include "subject.h"
#include "observer.h"
#include "cell.h"
#include "subscriptions.h"
#include "info.h"

Cell::Cell() : isOn{isOn}, r{r}, c{c} {}

bool Cell::getState() const { return isOn; }

Info Cell::getInfo() const 
{
  Info i{ this->r, this->c, this->isOn };
  return i;  
}

void Cell::setOn() 
{ 
  isOn = true; 
  notifyObservers( SubscriptionType::SwitchOnly );
}

void Cell::toggle() 
{
  if ( isOn ) isOn = false;
  else isOn = true;
}

void Cell::setCoords(int r, int c) { this->r = r; this->c = c; }

void Cell::notify(Subject &whoNotified)
{ 
  toggle(); 
  notifyObservers( SubscriptionType::SwitchOnly );
}

SubscriptionType Cell::subType() const { return SubscriptionType::SwitchOnly; }
