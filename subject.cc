#include "subject.h"
#include "observer.h"
#include "subscriptions.h"

Subject::~Subject() {}

void Subject::attach(Observer *o) { observers.emplace_back( o );  }

void Subject::notifyObservers( SubscriptionType t ) 
{
  switch( t )
  {
    case SubscriptionType::All:
    for ( auto it = observers.begin(); it != observers.end(); ++it ) (*it)->notify( *this );
    case SubscriptionType::SwitchOnly:
    for ( auto it = observers.begin(); it != observers.end(); ++it ) 
    {
      (*it)->notify( *this );
      break;
    }
  }
}
