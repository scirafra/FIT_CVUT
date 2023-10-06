#include "CEvent.h"

CEvent::CEvent ( const CTime & start, const CTime & end, const string & name, const string & place, const unsigned & shift, const unsigned & repeat ):m_Start ( start ), m_End ( end ), m_Name ( name ), m_Place ( place ), m_Shift ( shift ), m_Repeat ( repeat )
{
}
//checks if input date is in collision with this event
bool CEvent::collision ( CTime start, CTime end, unsigned shift, unsigned repeat )
{
	unsigned repeat_orig = 0, repeat_new = 0;
	while ( repeat_orig <= m_Repeat && repeat_new <= repeat  )
	{
		if ( start . Compare ( m_End ) >= 0 )
		{
			m_Start . shift ( m_Shift );
			m_End . shift ( m_Shift );
			repeat_orig ++;
		}
		else if ( m_Start . Compare ( end ) >= 0 )
		{
			start . shift ( shift );
			end . shift ( shift );
			repeat_new ++;
		}
		else 
		{
			m_Start . shift ( m_Shift * repeat_orig * -1 );
			m_End . shift ( m_Shift * repeat_orig * -1 );
			return true;
		}
	}
	m_Start . shift ( m_Shift * repeat_orig * -1 );
	m_End . shift ( m_Shift * repeat_orig * -1 );
	return false;
}
//puts data from event into string which is ready to export
string CEvent::export_event ( void )
{
	string str = "";
	str += m_Name;
	str += '\n';
	str += m_Place;
	str += '\n';
	str +=  to_string ( m_Start . year ( ) );
	str += '\n';
	str += to_string ( m_Start . month ( ) );
	str += '\n';
	str +=  to_string ( m_Start . day ( ) );
	str += '\n';
	str += m_Start . hour ( );
	str += '\n';
	str += m_Start . minute ( );
	str += '\n';
	str += m_End . hour ( );
	str += '\n';
	str += m_End . minute ( );
	str += '\n';
	str += to_string ( m_Shift );
	str += '\n';
	str += to_string ( m_Repeat );
	str += '\n';
	str += to_string ( number_of_people );
	str += '\n';
	for ( unsigned i = 0; i < number_of_people; i++ )
	{
		str += people [ i ];
		str += '\n';
	}
	return str;
}
//prints what day in week is it ( Mon, Tue... )
string CEvent::weekday ( void ) const
{
	return m_Start . weekday ( );
}
CTime CEvent::time_start ( void ) const
{
	return m_Start;
}
CTime CEvent::time_end ( void ) const
{
	return m_End;
}
//compares date and time from input with date and time when event starts
int CEvent::Compare ( CTime time ) const
{
	return m_Start . Compare ( time );
}
//compares time from input with time when event starts
int CEvent::CompareTime ( CTime time ) const
{
	return m_Start . CompareTime ( time );
}
//returns string with data from event in nice form ready to print to screen
string CEvent::print ( void ) const
{
	string str = "\nTime: ";
	str += m_Start . time ( );
	str += '-';
	str += m_End . time ( );
	str += ' ';
	str += m_Start . weekday ( );
	str += ' ';
	str += m_Start . date ( );
	str += "\nPlace: ";
	str += m_Place;
	str += "\nName: ";
	str += m_Name;
	str += "\nRepeat ";
	str += to_string ( m_Repeat );
	str += " times every ";
	str += to_string ( m_Shift );
	str += " days";
	if ( number_of_people > 0 )
	str += "\nPeople:\n";
	for ( unsigned i = 0; i < number_of_people; i++)
	{
		str += to_string ( i );
		str += ' ';
		str += people [ i ];
		str += '\n';
	}
	if ( number_of_people == 0 )
	{
		str += "\n";
	}
	return str;
}

void CEvent::edit_name ( string name )
{
	m_Name = name;
}

void CEvent::edit_place ( string place )
{
	m_Place = place;
}

void CEvent::edit_date ( const int days ) 
{
	m_Start . shift ( days );
	m_End . shift ( days );
}

void CEvent::edit_time ( unsigned hour, unsigned minute, unsigned event )
{
	if ( event == 0 )
	{
		m_Start . edit_time ( hour, minute );
	}
	else
	{
		m_End . edit_time ( hour, minute );
	}
}

void CEvent::edit_repeat ( unsigned repeat ) 
{
	m_Repeat = repeat;
}

void CEvent::add_person ( string person )
{
	people . push_back ( person );
	number_of_people ++;
}

void CEvent::delete_person ( unsigned id_person )
{
	if ( id_person >= 0 && id_person < number_of_people )
	{
		people . erase ( people . begin ( ) + id_person );
		number_of_people --;
		cout<<"Succesfully deleted\n"<<endl;
	}
	else
	{
		cout<<"Delete wasn't succesful\n"<<endl;
	}
}

unsigned CEvent::repeat ( void ) const
{
	return m_Repeat;
}

unsigned CEvent::shift ( void ) const
{
	return m_Shift;
}

string CEvent::name ( void )
{
	return m_Name;
}

string CEvent::place ( void )
{
	return m_Place;
}

vector < string > CEvent::people_export ( void ) const
{
	return people;
}

string CEvent::start_time ( void ) const
{
	return m_Start . time ( );
}

string CEvent::end_time ( void ) const
{
	return m_End . time ( );
}

unsigned CEvent::people_number ( void )
{
	return number_of_people;
}