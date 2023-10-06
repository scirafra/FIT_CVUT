#include "CDailyDisplay.h"

void CDailyDisplay :: print (vector < CEvent >& all_events,  int year, unsigned month, unsigned day )
{
	//sets limits of date
	CTime min ( year, month, day - 1, 23, 59 );
	CTime max ( year, month, day + 1, 0, 0 );
	min . shift ( 0 );
	max . shift ( 0 );
	vector < size_t > selected_events;
	//search for valid events
	for ( size_t i = 0; i < all_events . size ( ); i ++ )
	{
		if ( all_events [ i ] . Compare ( min ) == 1 && all_events [ i ] . Compare ( max ) == -1 )
		{
			selected_events . push_back ( i );
		}
		else if ( all_events [ i ] . Compare ( min ) == -1 && all_events [ i ] . repeat ( ) > 0 )
		{
			unsigned count = 0;
			while ( all_events [ i ] . Compare ( min ) == -1 && count < all_events [ i ] . repeat ( ) )
			{
				all_events [ i ] . edit_date ( all_events [ i ] . shift ( ) );
				count ++;
			}
			if ( all_events [ i ] . Compare ( min ) == 1 && all_events [ i ] . Compare ( max ) == -1 )
			{
				selected_events . push_back ( i );
			}
			all_events [ i ] . edit_date ( all_events [ i ] . shift ( ) * count * -1 );
		}
	}
	//places events in order
	vector < int > e;
	if ( selected_events.size ( ) > 0 )
	{
		while ( selected_events . size ( ) > 1 )
		{
			int smallest=0;
			for ( size_t i = 1; i < selected_events . size ( ); i ++ )
			{
				if ( all_events [ selected_events [ smallest ] ] . CompareTime ( all_events [ selected_events [ i ] ] . time_start ( ) ) == 1 )
				{
					smallest = i;
				}
			}
			e.push_back ( selected_events [ smallest ] );
			selected_events . erase ( selected_events . begin ( ) + smallest );
		}
		e.push_back ( selected_events [ 0 ] );
		selected_events . erase ( selected_events . begin ( ) );
	}
	//prints event
	min . shift ( 1 );
	cout << min . weekday ( ) << " " << min . date ( ) << endl;
	for ( size_t i = 0; i < e . size ( ); i ++ )
	{
		cout << "Time: " << all_events [ e [ i ] ] . start_time ( ) << " - " << all_events [ e [ i ] ] . end_time ( ) << endl;
		cout << "Name: " << all_events [ e [ i ] ] . name ( ) << endl;
		cout << "Place: " << all_events [ e [ i ] ] . place ( ) << endl;
		vector < string > people = all_events [ e [ i ] ] . people_export ( );
		if ( people . size ( ) > 0 )
		{
			cout << "People:" << endl;
			
			for ( size_t p = 0; p < people . size ( ); p ++ )
			{
				cout << people [ p ] << endl;
			}
		}
		cout << endl;
	}
	cout << endl;
}