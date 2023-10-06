#ifndef CCalendar_h
#define CCalendar_h
#include <fstream>
#include "CEvent.h"

class CCalendar
{
	protected:
	size_t number_of_events = 0;
	vector < CEvent > events;
	public:
	bool add ( unsigned year, unsigned month, unsigned day, unsigned hour_start, unsigned minute_start, unsigned hour_end, unsigned minute_end, string name, string place, unsigned shift, unsigned repeat );
	unsigned check ( CTime start, CTime end, unsigned shift, unsigned repeat );
	unsigned check ( unsigned id, unsigned days );
	unsigned check ( unsigned id, unsigned shift, unsigned repeat );
	unsigned check ( unsigned id, unsigned hour, unsigned minute, unsigned & event );
	unsigned people_number ( unsigned id );
	void delete_event ( unsigned id );
	void find_by_name ( string name );
	void find_by_place ( string place );
	void edit_name ( string name, unsigned id );
	void edit_place ( string place, unsigned id );
	void edit_time ( unsigned hour, unsigned minute, unsigned id, unsigned event );
	void shift_date ( unsigned days, unsigned id );
	void edit_repeat ( unsigned repeat, unsigned id );
	void add_person_id ( string person, unsigned id );
	void delete_person_id ( unsigned id_person, unsigned id );
	bool export_calendar ( string file );
	bool import_calendar ( string file );
	CTime time_start ( unsigned id );
	CTime time_end ( unsigned id );
	size_t size ( void );
	vector < CEvent >& get ( ) { return events; }
};
#endif/*CCalendar_h*/