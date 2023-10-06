#ifndef CEvent_h
#define CEvent_h
#include<vector>
#include "CTime.h"

class CEvent
{
	private:
		CTime m_Start;
		CTime m_End;
		string m_Name;
		string m_Place;
		unsigned m_Shift;
		unsigned m_Repeat;
		vector < string > people;
		unsigned number_of_people = 0;
	public:
		CEvent ( const CTime & start, const CTime & end, const string & name, const string & place, const unsigned & shift, const unsigned & repeat );
		bool collision ( CTime start, CTime end, unsigned shift, unsigned repeat  );
		string print ( void ) const;
		void edit_name ( string name );
		void edit_place ( string place );
		void edit_date ( const int days ) ;
		void edit_time ( unsigned hour, unsigned minute, unsigned event );
		void edit_repeat ( unsigned repeat );
		void add_person ( string human );
		void delete_person ( unsigned person );
		unsigned repeat ( void ) const;
		unsigned shift ( void ) const;
		string name ( void );
		string place ( void );
		string export_event ( void );
		vector < string > people_export ( void ) const;
		unsigned date ( void ) const;
		unsigned people_number ( void );
		string start_time ( void ) const;
		string end_time ( void ) const;
		int Compare ( CTime time ) const;
		int CompareTime ( CTime time ) const;
		CTime time_start ( void ) const;
		CTime time_end ( void ) const;
		string weekday ( void ) const;
	
};
#endif/*CEvent_h*/