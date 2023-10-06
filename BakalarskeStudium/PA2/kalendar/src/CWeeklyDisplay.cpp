/*#include<iostream>
#include<cassert>
#include<cstring>
using namespace std;

#include<vector>
#include <fstream>
#include "CDisplay.h"*/
#include "CWeeklyDisplay.h"
//#include <iomanip>

void CWeeklyDisplay :: print (vector < CEvent > & all_events,  int year, unsigned month, unsigned day )
{
	//sets limits of date
	CTime min ( year, month, day - 1, 23, 59 );
	CTime max ( year, month, day + 7, 0, 0 );
	min . shift ( 0 );
	max . shift ( 0 );
	//selects valid events
	vector < size_t > selected_events;
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
	cout<<selected_events.size()<<endl;
	//place event into right day
	vector < vector < int > > event_week;
	event_week.resize ( 7 );
	CTime max_day ( year, month, day, 0, 0 );
	min . shift ( -1 );
	for ( unsigned d = 0; d < 7; d++ )
	{
		min . shift ( 1 );
		max_day . shift ( 1 );
		for ( size_t i = 0; i < selected_events . size ( ); i ++ )
		{
			if ( all_events [ selected_events [ i ] ] . Compare ( min ) == 1 && all_events [ selected_events [ i ] ] . Compare ( max_day ) == -1 )
			{
				event_week [ d ] . push_back ( selected_events [ i ] );
			}
			else if ( all_events [ selected_events [ i ] ] . Compare ( min ) == -1 && all_events [ selected_events [ i ] ] . repeat ( ) > 0 )
			{
				unsigned count = 0;
				while ( all_events [ selected_events [ i ] ] . Compare ( min ) == -1 && count < all_events [ selected_events [ i ] ] . repeat ( )  )
				{
					all_events [ selected_events [ i ] ] . edit_date ( all_events [ selected_events [ i ] ] . shift ( ) );
					count ++;
				}
				if ( all_events [selected_events [ i ] ] . Compare ( min ) == 1 && all_events [ selected_events [ i ] ] . Compare ( max_day ) == -1 )
				{
					event_week [ d ] . push_back ( selected_events [ i ] );
				}
				all_events [ selected_events [ i ] ] . edit_date ( all_events [ selected_events [ i ] ] . shift ( ) * count * -1 );
			}
		}
		cout<<event_week [ d ].size()<<endl;
	}
	//orders events
	vector < vector < int > > e;
	e . resize ( 7 );
	for ( unsigned d = 0; d < 7; d++ )
	{
		if ( event_week [ d ] . size ( ) > 0 )
		{
			while ( event_week [ d ] . size ( ) > 1 )
			{
				int smallest=0;
				for ( size_t i = 1; i < event_week [ d ] . size ( ); i ++ )
				{
					if ( all_events [ event_week [ d ] [ smallest ] ] . CompareTime ( all_events [ event_week [ d ] [ i ] ] . time_start() ) == 1 )
					{
						smallest = i;
					}
				}
				e [ d ] . push_back ( event_week [ d ] [ smallest ] );
				event_week [ d ] . erase ( event_week [ d ] . begin ( ) + smallest );
			}
			e [ d ] . push_back ( event_week [ d ] [ 0 ] );
			event_week [ d ] . erase ( event_week [ d ] . begin ( ) );
		}
	}
	//prints events
	min . shift ( -5 );
	cout << "+--------------+--------------+--------------+--------------+--------------+" << endl;
	for ( unsigned w = 0; w < 2; w ++ )
	{
		unsigned week = 5;
		if ( w == 1 )
		{
			week = 2;
		}
		for ( unsigned i = 0; i < week; i  ++ )
		{
			cout << "|";
			if ( min . weekday ( ) == "Sat" || min . weekday ( ) == "Sun" )
			{
				cout << "\u001b[41m" << min.weekday ( ) << "\u001b[0m " << min . date ( );
			}
			else
			{
				cout << min . weekday ( ) << " " << min . date ( );
			}
			for ( unsigned j = 0; j < 13 - ( min . date ( ) . size ( ) + min . weekday ( ) . size ( ) ); j++ )
			{
				cout<<" ";
			}
			min . shift ( 1 );
		}
		cout << "|" << endl;
		for ( unsigned i = 0; i < 3; i++ )
		{
			for ( unsigned d = 0; d < week; d++ )
			{
				cout<<"|              ";
			}
			cout << "|" << endl;
			for ( unsigned d = 0; d < week; d++ )
			{
				cout << "|";
				if ( e [ w * 5 + d ] . size ( ) > i )
				{
					cout << "\u001b[32m" << all_events [ e [ w * 5 + d ] [ i ] ] . start_time ( ) << " - " <<  all_events [ e [ w * 5 + d ] [ i ] ] . end_time ( ) << "\u001b[0m ";
				}
				else
				{
					cout << "              ";
				}
			}
			cout << "|" << endl;
			for ( unsigned d = 0; d < week; d++ )
			{
				cout << "|";
				if ( e [ w * 5 + d ] . size ( ) > i )
				{
					if ( all_events [ e [ w * 5 + d ] [ i ] ] . name ( ) . size ( ) > 14 )
					{
						for (  unsigned j = 8; j < all_events [ e [ w * 5 + d ] [ i ] ] . name ( ) . size ( ); j++ )
						{
							cout << all_events [ e [ w * 5 + d ] [ i ] ] . name ( ) [ j ];
						}
						for (  unsigned j = all_events [ e [ w * 5 + d ] [ i ] ] . name ( ) . size ( ); j < 22; j++ )
						{
							cout << " ";
						}
					}
					else
					{
						cout << all_events [ e [ w * 5 + d ] [ i ] ] . name ( );
						for (  int j = all_events [ e [ w * 5 + d ] [ i ] ] . name ( ) . size ( ); j < 14; j++ )
						{
							cout << " ";
						}
					}
				}
				else
				{
					cout << "              ";
				}
			}
			cout << "|" << endl;
			for ( unsigned d = 0; d < week; d++ )
			{
				cout << "|";
				if ( e [ w * 5 + d ] . size ( ) > i )
				{
				
					cout<<all_events [ e [ w * 5 + d ] [ i ] ] . place ( );
					for (  unsigned j = all_events [ e [ w * 5 + d ] [ i ] ] . place ( ) . size ( ); j < 14; j++ )
					{
						cout << " ";
					}
				
				}
				else
				{
					cout << "              ";
				}
			}
			cout << "|" << endl;
			for ( unsigned d = 0; d < week; d++ )
			{
				cout << "|";
				if ( e [ w * 5 + d ] . size ( ) > i )
				{
					vector < string > persons;
					persons = all_events [ e [ w * 5 + d ] [ i ] ] . people_export ( );
					cout<<persons.size()<<" People";
					for (  unsigned j = to_string ( persons . size ( ) ) . size ( ); j < 7; j++ )
					{
						cout << " ";
					}
				
				}
				else
				{
					cout << "              ";
				}
			}
			cout << "|" << endl;
		}
		for ( unsigned d = 0; d < week; d++ )
		{
			if ( e [ w * 5 + d ] . size ( ) > 3 )
			{
				cout << "|+";
				cout << to_string ( e [ w * 5 + d ] . size ( ) - 3 ) << " events";
				for ( int i = 1 + to_string ( e [ w * 5 + d ] . size ( ) - 3 ) . size ( ); i < 7; i++ )
				{
					cout << " ";
				}
			}
			else
			{
				cout << "|              ";
			}
		}
		cout << "|" << endl;
		for ( unsigned i = 0; i < week; i++ )
		{
			cout << "+--------------";
		}
		cout << "+" << endl;
		
	}
	cout << endl;
}