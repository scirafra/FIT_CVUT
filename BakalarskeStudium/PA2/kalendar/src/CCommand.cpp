
using namespace std;
#include<map>
#include "CCommand.h"
#include <memory>

unsigned CCommand::read_number ( string text, unsigned min, unsigned max, bool menu )
{
	bool good;
	string str;
	unsigned number;
	while ( 1 )
	{
		str = "";
		good = true;
		cout << text;
		if ( max > 1 && menu )
		{
			cout << " ( " << min << " - " << max << " ). To return to menu type MENU." << endl;
		}
		else if ( menu )
		{
			cout << "To return to menu type MENU." << endl;
		}
		else
		{
			cout << " ( " << min << " - " << max << " )" << endl;
		}
		while ( cin ) 
		{
			getline ( cin, str );
			break;
		}
		if ( str == "MENU" )
		{
			if ( min > 0 )
			{
				return 0;
			}
			return ( max + 1 );
		}
		for ( size_t i = 0; i < str . size ( ); i ++)
		{
			if ( str [ i ] < '0' || str [ i ] > '9' )
			{
				good = false;
				break;
			}
		}
		if ( good )
		{
			stringstream num ( str ); 
			num >> number;
			if ( min <= number && number <= max )
			{
				return number;
			}
			else
			{
				cout << "Wrong Number\n" << endl;
			}
		}
		else
		{
			cout<<"Wrong Input\n"<<endl;
		}
	}
}

string CCommand::read_string ( string text, unsigned max )
{
	string str;
	while ( 1 )
	{	
		str = "";
		cout << text;
		if ( max > 0 )
		{
			cout << " ( max " << max << " chars ). To return to menu type MENU." << endl;
		}
		else
		{
			cout << ". To return to menu type MENU." << endl;
		}
		while ( cin ) 
		{
			getline ( cin, str );
			break;
		}
		if ( str . size ( ) == 0 )
		{
			cout << "Too Short Input\n" << endl;
		}
		else if ( str . size ( ) < ( max + 1 ) )
		{
			if ( str == "MENU" )
			{
				return "";
			}
			return str;
		}
		else
		{
			cout << "Too Long Input\n" << endl;
		}
	}
}

string CCommand::read_file_name ( string text, unsigned max )
{
	string str;
	while ( 1 )
	{
		str = "";
		cout << text;
		if ( max > 0 )
		{
			cout << "( max " << max << " chars ). To return to menu type MENU." << endl;
		}
		else
		{
			cout << ". To return to menu type MENU." << endl;
		}
		while ( cin ) 
		{
			getline ( cin, str );
			break;
		}
		bool good = true;
		for ( size_t i = 0; i < str . size ( ); i ++)
		{
			if (str [ i ] < '0' || ( str [ i ] > '9' && str [ i ] < 'A' ) || ( str [ i ] > 'Z' && str [ i ] < 'a' ) || str [ i ] > 'z' )
			{
				good = false;
				break;
			}
		}
		if ( str . size ( ) == 0 )
		{
			cout << "Too Short Input\n" << endl;
		}
		else if ( good == false )
		{
			cout << "Wrong Input\n" << endl;
		}
		else if ( str . size ( ) < ( max + 1 ) )
		{
			if ( str == "MENU" )
			{
				return "";
			}
			return str + ".txt";
		}
		else
		{
			cout << "Too Long Input\n" << endl;
		}
	}
}

unsigned CCommand::read_day ( unsigned year, unsigned month )
{
	unsigned max;
	CTime time ( year, month, 28, 0, 0 );
	for ( max = 28; max < 33; max ++ )
	{
		time . shift ( 1 );
		if ( time . month ( ) != month )
		{
			break;
		}
	}
	unsigned day = read_number ( "Type Day", 1, max, true );
	return day;
}


int CCommand::run ( void )
{
	CCalendar a;

	map < int, shared_ptr < CDisplay > > displayManager = 
	{
		{ 3, make_shared < CEventDisplay > ( ) },
		{ 2, make_shared < CDailyDisplay > ( ) },
		{ 1, make_shared < CWeeklyDisplay > ( ) },
		{ 0, make_shared < CMonthlyDisplay > ( ) },
	};
	
	while ( 1 )
	{
		cout  <<  "0: Show Month\n1: Show Week\n2: Show Day\n3: Add Event\n4: Delete Event\n5: Shift Event\n6: Edit Event Name\n7: Edit Event Place\n8: Edit Event Time\n9: Edit Event Repeat\n10: Add Person To Event\n11: Delete Person From Event\n12: Search By Name\n13: Search by Place\n14: Export Calendar\n15: Import Calendar\n16: Quit\n"  <<  endl;
		unsigned option = read_number ( "Choose", 0, 16, false );
		if ( option == 17 )
		{
			break;
		}
		string name, place;
		unsigned year, month, day, hour, minute, hour_end, minute_end, shift, repeat, id_event, id_person, event, collision;
		if ( option < 12 )
		{
			unsigned o = option;
			if ( o > 3 )
			{
				o = 3;
			}
			auto iter = displayManager . find ( o );
			shared_ptr < CDisplay > display ( iter -> second );
					
			switch ( option )
			{
				case 0:
						//showing of month
						year = read_number ( "Type Year", 1, 9999, true );
						if ( year == 0 )
						{
							break;
						}
						month = read_number ( "Type Month", 1, 12, true );
						if ( month == 0 )
						{
							break;
						}
						display -> print ( a . get ( ), year, month, 1 );
						break;
								
				case 1:
						//showing of week
						year = read_number ( "Type Year", 1, 9999, true );
						if ( year == 0 )
						{
							break;
						}
						month = read_number ( "Type Month", 1, 12, true );
						if ( month == 0 )
						{
							break;
						}
						day = read_day ( year, month );
						if ( day == 0 )
						{
							break;
						}
						display -> print ( a . get ( ), year, month, day );
						break;
				case 2:
						//showing of day
						year = read_number ( "Type Year", 1, 9999, true );
						if ( year == 0 )
						{
							break;
						}
						month = read_number ( "Type Month", 1, 12, true );
						if ( month == 0 )
						{
							break;
						}
						day = read_day ( year, month );
						if ( day == 0 )
						{
							break;
						}
						display -> print ( a . get ( ), year, month, day );
						break;
				case 3:
						//adds event
						name = read_string ( "Type Name", 14 );
						if ( name == "" )
						{
							break;
						}
						place = read_string ( "Type Place", 14 );
						if ( place == "" )
						{
							break;
						}
						year = read_number ( "Type Year", 1, 9999, true );
						if ( year == 0 )
						{
							break;
						}
						month = read_number ( "Type Month", 1, 12, true );
						if ( month == 0 )
						{
							break;
						}
						day = read_day ( year, month );
						if ( day == 0 )
						{
							break;
						}
						hour = read_number ( "Type Hour When Event Starts", 0, 23, true );
						if ( hour == 24 )
						{
							break;
						}
						minute = read_number ( "Type Minute  When Event Starts", 0, 59, true );
						if ( minute == 60 )
						{
							break;
						}
						hour_end = read_number ( "Type Hour When Event Ends", hour, 23, true );
						if ( hour_end == 24 )
						{
							break;
						}
						else if ( hour > 0 && hour_end == 0 )
						{
							break;
						}
						if ( hour == hour_end )
						{
							minute_end = read_number ( "Type Minute  When Event Ends", minute, 59, true );
							if ( minute_end == 60 )
							{
								break;
							}
							else if ( minute > 0 && minute_end == 0 )
							{
								break;
							}
						}
						else
						{
							minute_end = read_number ( "Type Minute  When Event Ends", 0, 59, true );
							if ( minute_end == 60 )
							{
								break;
							}
						}
						repeat = read_number ( "Type Number of Repeats", 0, 9999, true );
						if ( repeat == 10000 )
						{
							break;
						}
						if ( repeat > 0 )
						{
							shift = read_number ( "Type After How Many Days Is Event Taking Place Again", 1, 9999, true );
							if ( shift == 0 )
							{
								break;
							}
						}
						else
						{
							shift = 0;
						}
						collision = a . check ( CTime ( year, month, day, hour, minute ), CTime ( year, month, day, hour_end, minute_end ), shift, repeat );
						if ( collision > 0 )
						{
							cout << "Number of Collisions: " << collision << endl;
							event = read_number ( "If You Want to Continue Anyway Press 0. ", 0, 0, true );
							if ( event > 0 )
							{
								break;
							}
						}
						a . add ( year, month, day, hour, minute, hour_end, minute_end, name, place, shift, repeat );
						break;
				case 4:
						//deletes event
						if ( a . size ( ) > 0 )
						{
							display -> print ( a . get ( ), year, month, day );
							id_event = read_number ( "Type ID of Event. ", 0, a . size ( ) - 1, true );
							if ( id_event == a . size ( ) )
							{
								break;
							}
							a . delete_event ( id_event );
						}
						else
						{
							cout << "There are 0 events.\n" << endl;
						}
						break;
				case 5:
						//shifts event ( edits date )
						if ( a . size ( ) > 0 )
						{
							display -> print ( a . get ( ), year, month, day );
							id_event = read_number ( "Type ID of Event. ", 0, a . size ( ) - 1, true );
							if ( id_event == a . size () )
							{
								break;
							}
							day = read_number ( "If You Want To Shift Event To Next Possible Date Press 0. Otherwise Type Number of Days", 0, 9999, true );
							if ( day == 10000 )
							{
								break;
							}
							if ( day == 0 )
							{
								collision = 1;
								while ( collision )
								{
									day ++;
									collision = a . check ( id_event, day );
								}
							}
							collision = a . check ( id_event, day );
							if ( collision > 0 )
							{
								cout << "Number of Collisions: " << collision << endl;
								event = read_number ( "If You Want to Continue Anyway Press 0. ", 0, 0, true );
								if ( event > 0 )
								{
									break;
								}
							}
							a . shift_date ( day, id_event );
						}
						else
						{
							cout << "There are 0 events.\n" << endl;
						}
						break;
				case 6:
						//edits name of event
						if ( a . size ( ) > 0 )
						{
							display -> print ( a . get ( ), year, month, day );
							id_event = read_number ( "Type ID of Event. ", 0, a . size ( ) - 1, true );
							if ( id_event == a . size () )
							{
								break;
							}
							name = read_string ( "Type Name", 14 );
							if ( name == "" )
							{
								break;
							}
							a . edit_name ( name, id_event );
						}
						else
						{
							cout << "There are 0 events.\n" << endl;
						}
						break;
				case 7:
						//edits place where event takes place
						if ( a . size ( ) > 0 )
						{
							display -> print ( a . get ( ), year, month, day );
							id_event = read_number ( "Type ID of Event. ", 0, a . size ( ) - 1, true );
							if ( id_event == a . size () )
							{
								break;
							}
							place = read_string ( "Type Place", 14 );
							if ( place == "" )
							{
								break;
							}
							a . edit_place ( place, id_event );
						}
						else
						{
							cout << "There are 0 events.\n" << endl;
						}
						break;
				case 8:
						//edits time of event ( houres and minutes )
						if ( a . size ( ) > 0 )
						{
							bool end = false;
							event = 3;
							display -> print ( a . get ( ), year, month, day );
							while ( event > 2 )
							{
								id_event = read_number ( "Type ID of Event. ", 0, a . size ( ) - 1, true );
								if ( id_event == a . size () )
								{
									end = true;
									break;
								}
								event = read_number ( "Decide if You Want to Change Start or End of Event\n0: Start\n1: End\n", 0, 1, true );
								if ( event == 2 )
								{
									end = true;
									break;
								}
								hour = read_number ( "Type Hour", 0, 23, true );
								if ( hour == 24 )
								{
									end = true;
									break;
								}
								minute = read_number ( "Type Minute", 0, 59, true );
								if ( minute == 60 )
								{
									end = true;
									break;
								}
								collision = a . check ( id_event, hour, minute, event );
							}
							if ( end )
							{
								break;
							}
							if ( collision > 0 )
							{
								cout << "Number of Collisions: " << collision << endl;
								event = read_number ( "If You Want to Continue Anyway Press 0. ", 0, 0, true );
								if ( event > 0 )
								{
									break;
								}
							}
							a . edit_time ( hour, minute, id_event, event );	
						}
						else
						{
							cout << "There are 0 events.\n" << endl;
						}
						break;
				case 9:
						//edits how often event repeats
						if ( a . size ( ) > 0 )
						{
							display -> print ( a . get ( ), year, month, day );
							id_event = read_number ( "Type ID of Event. ", 0, a . size ( ) - 1, true );
							if ( id_event == a . size ( ) )
							{
								break;
							}
							repeat = read_number ( "Type Number of Repeats", 0, 9999, true );
							if ( repeat == 10000 )
							{
								break;
							}
							if ( repeat > 0 )
							{
								shift = read_number ("Type After How Many Days Is Event Taking Place Again", 1, 9999, true );
								if ( shift == 0 )
								{
									break;
								}
								collision = a . check ( id_event, shift, repeat );
								if ( collision > 0 )
								{
									cout << "Number of Collisions: " << collision << endl;
									event = read_number ( "If You Want to Continue Anyway Press 0. ", 0, 0, true );
									if ( event > 0 )
									{
										break;
									}
								}
							}
							else
							{
								shift = 0;
							}
							a . edit_repeat ( repeat, id_event );
						}
						else
						{
							cout << "There are 0 events.\n" << endl;
						}
						break;
				case 10:
						//adds person to an event
						if ( a . size ( ) > 0 )
						{
							display -> print ( a . get ( ), year, month, day );
							id_event = read_number ( "Type ID of Event. ", 0, a . size ( ) - 1, true );
							if ( id_event == a . size ( ) )
							{
								break;
							}
							name = read_string ( "Type Name of Person", 14 );
							if ( name == "" )
							{
								break;
							}
							a . add_person_id ( name, id_event );
						}
						else
						{
							cout << "There are 0 events.\n" << endl;
						}
						break;
				case 11:
						//deletes person from an event
						if ( a . size ( ) > 0 )
						{
							display -> print ( a . get ( ), year, month, day );
							id_event = read_number ( "Type ID of Event. ", 0, a . size ( ) - 1, true );
							if ( id_event == a . size ( ) )
							{
								break;
							}
							if ( a . people_number ( id_event ) > 0 )
							{
								id_person = read_number ( "Type ID of Person. ", 0, a . people_number ( id_event ) - 1, true );
								if ( id_person == a . people_number ( id_event ) )
								{
									break;
								}
								a . delete_person_id ( id_person, id_event );
							}
							else
							{
								cout << "There are 0 people at the event.\n" << endl;
							}
						}
						else
						{
							cout << "There are 0 events.\n" << endl;
						}
				break;
			}
		}
		switch ( option )  
		{
			case 12:
					//searches and prints events by name
					if ( a . size ( ) > 0 )
					{
						name = read_string ( "Type Name", 14 );
						if ( name == "" )
						{
							break;
						}
						a . find_by_name ( name );
					}
					else
					{
						cout << "There are 0 events.\n" << endl;
					}
					break;
			case 13:
					//searches and prints events by place
					if ( a . size ( ) > 0 )
					{
						place = read_string ( "Type Place", 14 );
						if ( place == "" )
						{
							break;
						}
						a . find_by_place ( place );
					}
					else
					{
						cout << "There are 0 events.\n" << endl;
					}
					break;
			case 14:
					//exports calendar to file
					name = read_file_name ( "Type Name Of File ( .txt will be filled and accepts only numbers and alphabet )\nDon't Type The PATH. ", 14 );
					if ( name == "" )
					{
						break;
					}
					a . export_calendar ( name );
					break;
			case 15:
					//imports calendar from file
					name = read_file_name ( "Type Name Of File ( .txt will be filled and accepts only numbers and alphabet )\nDon't Type The PATH.\nWARNING!!! It Will Delete All Your Events From Current Calendar If File Is Found\n", 14 );
					if ( name == "" )
					{
						break;
					}
					a . import_calendar ( name );
					break;
			case 16:
					//exits the program
					return 0;
		}	
	}
	return 0;
}