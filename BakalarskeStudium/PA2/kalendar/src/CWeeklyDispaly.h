#ifndef CWeeklyDisplay_h
#define CWeeklyDisplay_h
#include "CDisplay.h"
#include "CWeeklyDisplay.h"

class CWeeklyDisplay : public CDisplay
{
	public:
	virtual void print (vector < CEvent >& all_events,  int year, unsigned month, unsigned day );
};
#endif/*CWeeklyDisplay_h*/