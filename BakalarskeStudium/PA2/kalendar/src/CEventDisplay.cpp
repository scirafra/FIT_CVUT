#include "CEventDisplay.h"

void CEventDisplay :: print (vector < CEvent >& all_events,  int year, unsigned month, unsigned day )
{
	//writes out all events with their properties and their ID
	for ( size_t i = 0; i < all_events . size ( ); i ++ )
	{
		cout << "ID: " << i << " " << all_events [ i ] . print ( ) << endl;
	}
}