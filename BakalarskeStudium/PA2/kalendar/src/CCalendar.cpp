#include "CCalendar.h"

size_t CCalendar::size ( void )
{
	return number_of_events;
}

//adds new event into vector of events ( if it is valid )
bool CCalendar::add ( unsigned year, unsigned month, unsigned  day, unsigned  hour_start, unsigned minute_start, unsigned  hour_end, unsigned minute_end, string name, string place, unsigned shift, unsigned repeat )
{
	CTime time_start ( year, month, day, hour_start, minute_start );
	CTime time_end ( year, month, day, hour_end, minute_end );
	time_start . shift ( 0 );
	time_end . shift ( 0 );
	if ( time_start . month ( ) == month &&  time_start . year ( ) == year && time_end . month ( ) == month &&  time_end . year ( ) == year )
	{
		events . push_back ( CEvent ( CTime ( year, month, day, hour_start, minute_start ), CTime ( year, month, day, hour_end, minute_end ), name, place, shift, repeat ) );
		number_of_events ++;
		cout << "Succesfully added event\n" << endl;
		return true;
	}
	cout << "Wrong Date" << endl;
	return false;
}
//checks collisions based on start, end, repeat and shift of event
unsigned CCalendar::check ( CTime start, CTime end, unsigned shift, unsigned repeat )
{
	unsigned collisions = 0; 
	for ( unsigned i = 0; i < number_of_events; i ++ )
	{
		if ( events [ i ] . collision ( start, end, shift, repeat ) )
		{
			collisions ++;
		}
	}
	return collisions;
}
//checks collisions based on  shift days
unsigned CCalendar::check ( unsigned id, unsigned days )
{
	events [ id ] . edit_date ( days ); 
	unsigned collisions = 0; 
	for ( unsigned i = 0; i < number_of_events; i ++ )
	{
		if ( i != id )
		{
			if ( events [ i ] . collision ( events [ id ] . time_start ( ), events [ id ] . time_end ( ), events [ id ] . shift ( ), events [ id ] . repeat ( ) ) )
			{
				collisions ++;
			}
		}
		
	}
	events [ id ] . edit_date ( days * -1 ); 
	return collisions;
}
//checks collisions based on  shift and repeat of event
unsigned CCalendar::check ( unsigned id, unsigned shift, unsigned repeat )
{
	unsigned collisions = 0; 
	for ( unsigned i = 0; i < number_of_events; i ++ )
	{
		if ( i != id )
		{
			if ( events [ i ] . collision ( events [ id ] . time_start ( ), events [ id ] . time_end ( ), shift, repeat ) )
			{
				collisions ++;
			}
		}
		
	}
	return collisions;
}
//checks collisions based on time of event
unsigned CCalendar::check ( unsigned id, unsigned hour, unsigned minute, unsigned & event )
{
	CTime time ( int ( events [ id ] . time_start ( ) . year ( ) ) , events [ id ] . time_start ( ) . month ( ), events [ id ] . time_start ( ) . day ( ), hour, minute );
	if ( event == 0 )
	{
		if (  time . CompareTime ( events [ id ] . time_end ( ) ) == 1 )
		{
			cout << "Can't begin after end.\n" << endl;
			event += 3;
			return 0;
		}
	}
	else
	{
		if (  time . CompareTime ( events [ id ] . time_start ( ) ) == -1 )
		{
			cout << "Can't end before start.\n" << endl;
			event += 3;
			return 0;
		}
	}
	unsigned collisions = 0; 
	for ( unsigned i = 0; i < number_of_events; i++ )
	{
		if ( i != id )
		{
			if ( event == 0 )
			{
				if ( events [ i ] . collision ( time, events [ id ] . time_end ( ), events [ id ] . shift ( ), events [ id ] . repeat ( ) ) )
				{
					collisions ++;
				}
			}
			else
			{
				if ( events [ i ] . collision ( events [ id ] . time_start ( ), time, events [ id ] . shift ( ), events [ id ] . repeat ( ) ) )
				{
					collisions ++;
				}
			}
		}
		
	}
	return collisions;
}

unsigned CCalendar::people_number ( unsigned id )
{
	return events [ id ] . people_number ( );
}

//deletes event from vector of events by id ( if valid )
void CCalendar::delete_event ( unsigned id )
{
	if ( id >= 0 && id < number_of_events )
	{
		events . erase ( events . begin ( ) + id );
		cout << "Succesfully Deleted\n" << endl;
		number_of_events --;
	}
	else
	{
		cout << "Wrong ID\n" << endl;
	}
}

void CCalendar::find_by_name ( string name )
{
	unsigned found = 0;
	for ( unsigned i = 0; i < number_of_events; i++ )
	{
		if ( name == events [ i ] . name ( ) )
		{
			found ++;
			cout << "ID: " << i << " " << events [ i ] . print ( ) << endl;
		}
	}
	if ( found == 0 )
	{
		cout << "Nothing was found\n" << endl; 
	}
}

void CCalendar::find_by_place ( string place )
{
	unsigned found = 0;
	for ( unsigned i = 0; i < number_of_events; i++ )
	{
		if ( place == events [ i ] . place ( ) )
		{
			found ++;
			cout << "ID: " << i << " " << events [ i ] . print ( ) << endl;
		}
	}
	if ( found == 0 )
	{
		cout << "Nothing was found\n" << endl; 
	}
}

//edits name of an event
void CCalendar::edit_name ( string name, unsigned id )
{
	if ( id >= 0 && id < number_of_events  )
	{
		events [ id ] . edit_name ( name );
		cout << "Succesfully edited\n" << endl;
	}
	else
	{
		cout << "Edit wasn't succesful\n" << endl;
	}
}

//edits place where event takes place
void CCalendar::edit_place ( string place, unsigned id )
{
	if ( id >= 0 && id < number_of_events  )
	{
		events [ id ] . edit_place ( place );
		cout << "Succesfully edited\n" << endl;
	}
	else
	{
		cout << "Edit wasn't succesful\n" << endl;
	}
}

//edits time ( houres and minutes ) of event
void CCalendar::edit_time ( unsigned hour, unsigned minute, unsigned id, unsigned event )
{
	
	events [ id ] . edit_time ( hour, minute, event );
	cout << "Succesfully edited\n" << endl;
}

//shifts date by days ( 1.5.2020 shifted by 8 is 9.5.2020) ( edits date of event )
void CCalendar::shift_date ( unsigned days, unsigned id )
{
	if ( id >= 0 && id < number_of_events  )
	{
		events [ id ] . edit_date ( days );
		cout << "Succesfully shifted\n" << endl;
	}
	else
	{
		cout << "Shift wasn't succesful\n" << endl;
	}
}

//edits how often is event repeating
void CCalendar::edit_repeat ( unsigned repeat, unsigned id )
{
	if ( id >= 0 && id < number_of_events  )
	{
		events [ id ] . edit_repeat ( repeat );
		cout << "Succesfully edited\n" << endl;
	}
	else
	{
		cout << "Edit wasn't succesful\n" << endl;
	}
}

//adds person to an event
void CCalendar::add_person_id ( string person, unsigned id )
{
	
	if ( id >= 0 && id < number_of_events  )
	{
		events [ id ] . add_person ( person );
		cout << "Succesfully added person\n" << endl;
	}
	else
	{
		cout << "Adding person wasn't succesful\n" << endl;
	}	
}
CTime CCalendar::time_start ( unsigned id )
{
	return events [ id ] . time_start ( );
}
CTime CCalendar::time_end ( unsigned id )
{
	return events [ id ] . time_end ( );
}
//deletes person from event
void CCalendar::delete_person_id ( unsigned id_person, unsigned id )
{
	
	if ( id >= 0 && id < number_of_events  )
	{
		events [ id ] . delete_person ( id_person );
	}
	else
	{
		cout << "Delete wasn't succesful\n" << endl;
	}
}

//exports calendar into file
bool CCalendar::export_calendar ( string file )
{
	string str = "";
	str += to_string ( number_of_events );
	str += '\n';
	for ( size_t i = 0; i < number_of_events; i ++ )
	{
		str += events [ i ] . export_event ( );
	}
	ofstream out ( file, ios::out );
	if ( out.good ( ) )
	{
		out << str;
		if ( out . good ( ) )
		{
			cout << "Export Was Succesful\n" << endl;
			out . close ( );
			return true;
		}
	}
	cout << "Export Wasn't Succesful\n" << endl;
	out . close ( );
	return false;
}

//imports calendar from file, deletes previous calendar and tests if file is valid
bool CCalendar::import_calendar ( string file )
{
	size_t new_events;
	string line, str = "";
	string  import_name = "",  import_place = "",  import_type = "",  import_person = "";
	int import_year;
	unsigned  import_month,  import_day,  import_hour,  import_minute,  import_hour_end,  import_minute_end, import_shift;
	unsigned  import_repeat, import_people;
	ifstream fin ( file, ios::in );
	
	if ( getline ( fin, line ) . good ( ) )
	{
		events . erase ( events . begin ( ), events.end ( ) );
		number_of_events = 0;
		for ( size_t i = 0; i < line . size ( ); i ++)
		{
			if ( line [ i ] < '0' || line [ i ] > '9' )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
		}
		stringstream number ( line ); 
		number >> new_events;
		for ( size_t e = 0; e < new_events; e ++ )
		{
			if ( ! getline ( fin, import_name ) . good ( ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			if ( import_name . size ( ) > 14 || import_name . size ( ) == 0 )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			if ( ! getline ( fin, import_place ) . good ( ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			if ( import_place . size ( ) > 14 || import_place . size ( ) == 0 )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			if ( ! getline ( fin, line ) . good ( ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			else
			{
				for ( size_t i = 0; i < line . size ( ); i ++)
				{
					if ( line [ i ] < '0' || line [ i ] > '9' )
					{
						cout << "Loading Failed\n" << endl;
						number_of_events = 0;
						events . erase ( events . begin ( ), events . end ( ) );
						fin . clear ( ios::failbit );
						fin . close ( );
						return false;
					}
				}
				stringstream number ( line ); 
				number >> import_year;
				if ( import_year == 0 || import_year > 9999 )
				{
					cout << "Loading Failed\n" << endl;
					number_of_events = 0;
					events . erase ( events . begin ( ), events . end ( ) );
					fin . clear ( ios::failbit );
					fin . close ( );
					return false;
				}
			}
			if ( ! getline ( fin, line ) . good ( ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			else
			{
				for ( size_t i = 0; i < line . size ( ); i ++)
				{
					if ( line [ i ] < '0' || line [ i ] > '9' )
					{
						cout << "Loading Failed\n" << endl;
						number_of_events = 0;
						events . erase ( events . begin ( ), events . end ( ) );
						fin . clear ( ios::failbit );
						fin . close ( );
						return false;
					}
				}
				stringstream number ( line ); 
				number >> import_month;
				if ( import_month == 0 || import_month > 12 )
				{
					cout << "Loading Failed\n" << endl;
					number_of_events = 0;
					events . erase ( events . begin ( ), events . end ( ) );
					fin . clear ( ios::failbit );
					fin . close ( );
					return false;
				}
			}
			if ( ! getline ( fin, line ) . good ( ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			else
			{
				for ( size_t i = 0; i < line . size ( ); i ++)
				{
					if ( line [ i ] < '0' || line [ i ] > '9' )
					{
						cout << "Loading Failed\n" << endl;
						number_of_events = 0;
						events . erase ( events . begin ( ), events . end ( ) );
						fin . clear ( ios::failbit );
						fin . close ( );
						return false;
					}
				}
				stringstream number ( line ); 
				number >> import_day;
				if ( import_day == 0 || import_day > 31 )
				{
					cout << "Loading Failed\n" << endl;
					number_of_events = 0;
					events . erase ( events . begin ( ), events . end ( ) );
					fin . clear ( ios::failbit );
					fin . close ( );
					return false;
				}
			}
			if ( ! getline ( fin, line ) . good ( ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			else
			{
				for ( size_t i = 0; i < line . size ( ); i ++)
				{
					if ( line [ i ] < '0' || line [ i ] > '9' )
					{
						cout << "Loading Failed\n" << endl;
						number_of_events = 0;
						events . erase ( events . begin ( ), events . end ( ) );
						fin . clear ( ios::failbit );
						fin . close ( );
						return false;
					}
				}
				stringstream number ( line ); 
				number >> import_hour;
				if ( import_hour > 23 )
				{
					cout << "Loading Failed\n" << endl;
					number_of_events = 0;
					events . erase ( events . begin ( ), events . end ( ) );
					fin . clear ( ios::failbit );
					fin . close ( );
					return false;
				}
			}
			if ( ! getline ( fin, line ) . good ( ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			else
			{
				for ( size_t i = 0; i < line . size ( ); i ++)
				{
					if ( line [ i ] < '0' || line [ i ] > '9' )
					{
						cout << "Loading Failed\n" << endl;
						number_of_events = 0;
						events . erase ( events . begin ( ), events . end ( ) );
						fin . clear ( ios::failbit );
						fin . close ( );
						return false;
					}
				}
				stringstream number ( line ); 
				number >> import_minute;
				if ( import_minute > 59 )
				{
					cout << "Loading Failed\n" << endl;
					number_of_events = 0;
					events . erase ( events . begin ( ), events . end ( ) );
					fin . clear ( ios::failbit );
					fin . close ( );
					return false;
				}
			}
			if ( ! getline ( fin, line ) . good ( ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			else
			{
				for ( size_t i = 0; i < line . size ( ); i ++)
				{
					if ( line [ i ] < '0' || line [ i ] > '9' )
					{
						cout << "Loading Failed\n" << endl;
						number_of_events = 0;
						events . erase ( events . begin ( ), events . end ( ) );
						fin . clear ( ios::failbit );
						fin . close ( );
						return false;
					}
				}
				stringstream number ( line ); 
				number >> import_hour_end;
				if ( import_hour_end > 23 || import_hour_end < import_hour )
				{
					cout << "Loading Failed\n" << endl;
					number_of_events = 0;
					events . erase ( events . begin ( ), events . end ( ) );
					fin . clear ( ios::failbit );
					fin . close ( );
					return false;
				}
			}
			if ( ! getline ( fin, line ) . good ( ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			else
			{
				for ( size_t i = 0; i < line . size ( ); i ++)
				{
					if ( line [ i ] < '0' || line [ i ] > '9' )
					{
						cout << "Loading Failed\n" << endl;
						number_of_events = 0;
						events . erase ( events . begin ( ), events . end ( ) );
						fin . clear ( ios::failbit );
						fin . close ( );
						return false;
					}
				}
				stringstream number ( line ); 
				number >> import_minute_end;
				if ( import_minute_end > 59 || ( import_minute_end < import_minute && import_hour_end == import_hour ) )
				{
					cout << "Loading Failed\n" << endl;
					number_of_events = 0;
					events . erase ( events . begin ( ), events . end ( ) );
					fin . clear ( ios::failbit );
					fin . close ( );
					return false;
				}
			}
			if ( ! getline ( fin, line ) . good ( ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			else
			{
				for ( size_t i = 0; i < line . size ( ); i ++)
				{
					if ( line [ i ] < '0' || line [ i ] > '9' )
					{
						cout << "Loading Failed\n" << endl;
						number_of_events = 0;
						events . erase ( events . begin ( ), events . end ( ) );
						fin . clear ( ios::failbit );
						fin . close ( );
						return false;
					}
				}
				stringstream number ( line ); 
				number >> import_shift;
				if ( import_shift > 9999 )
				{
					cout << "Loading Failed\n" << endl;
					number_of_events = 0;
					events . erase ( events . begin ( ), events . end ( ) );
					fin . clear ( ios::failbit );
					fin . close ( );
					return false;
				}
			}
			if ( ! getline ( fin, line ) . good ( ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			else
			{
				for ( size_t i = 0; i < line . size ( ); i ++)
				{
					if ( line [ i ] < '0' || line [ i ] > '9' )
					{
						cout << "Loading Failed\n" << endl;
						number_of_events = 0;
						events . erase ( events . begin ( ), events . end ( ) );
						fin . clear ( ios::failbit );
						fin . close ( );
						return false;
					}
				}
				stringstream number ( line ); 
				number >> import_repeat;
				if ( import_repeat > 9999 || ( import_shift == 0 && import_repeat > 0 ) )
				{
					cout << "Loading Failed\n" << endl;
					number_of_events = 0;
					events . erase ( events . begin ( ), events . end ( ) );
					fin . clear ( ios::failbit );
					fin . close ( );
					return false;
				}
			}
			if ( ! getline ( fin, line ) . good ( ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			else
			{
				for ( size_t i = 0; i < line . size ( ); i ++)
				{
					if ( line [ i ] < '0' || line [ i ] > '9' )
					{
						cout << "Loading Failed\n" << endl;
						number_of_events = 0;
						events . erase ( events . begin ( ), events . end ( ) );
						fin . clear ( ios::failbit );
						fin . close ( );
						return false;
					}
				}
				stringstream number ( line ); 
				number >> import_people;
			}
			
			if ( ! add (  import_year,  import_month,  import_day,  import_hour,  import_minute,  import_hour_end,  import_minute_end,  import_name,  import_place,  import_shift,  import_repeat ) )
			{
				cout << "Loading Failed\n" << endl;
				number_of_events = 0;
				events . erase ( events . begin ( ), events . end ( ) );
				fin . clear ( ios::failbit );
				fin . close ( );
				return false;
			}
			for ( size_t j = 0; j <  import_people; j ++ )
			{
				if ( ! getline ( fin, import_person ) . good ( ) )
				{
					cout << "Loading Failed\n" << endl;
					number_of_events = 0;
					events . erase ( events . begin ( ), events . end ( ) );
					fin . clear ( ios::failbit );
					fin . close ( );
					return false;
				}
				if ( import_person . size ( ) > 14 || import_person . size ( ) == 0 )
				{
					cout << "Loading Failed\n" << endl;
					number_of_events = 0;
					events . erase ( events . begin ( ), events . end ( ) );
					fin . clear ( ios::failbit );
					fin . close ( );
					return false;
				}
				add_person_id ( import_person, e );
			}
		}
		if ( fin . good ( ) )
		{
			cout<<"Loading Was Succesful\n"<<endl;
			fin . close ( );
			return true;
		}
		else 
		{
			cout << "Loading Failed\n" << endl;
			number_of_events = 0;
			events . erase ( events . begin ( ), events . end ( ) );
			fin . clear ( ios::failbit );
			fin . close ( );
			return false;
		}
	}
	cout << "Loading Failed\n" << endl;
	number_of_events = 0;
	events . erase ( events . begin ( ), events . end ( ) );
	fin . clear ( ios::failbit );
	fin . close ( );
	return false;
}