#ifndef CEventDisplay_h
#define CEventDisplay_h
#include "CCalendar.h"
#include "CDisplay.h"
#include "CEventDisplay.h"

class CEventDisplay : public CDisplay
{
	public:
	virtual void print (vector < CEvent >& all_events,  int year, unsigned month, unsigned day ) ;
};
#endif/*CEventDisplay_h*/