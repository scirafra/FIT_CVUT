#ifndef CDisplay_h
#define CDisplay_h
#include "CCalendar.h"
#include "CDisplay.h"

class CDisplay
{
	public:
	virtual void print (vector < CEvent >& all_events,  int year, unsigned month, unsigned day ) = 0 ;
};
#endif/*CDisplay_h*/