#ifndef CDailyDisplay_h
#define CDailyDisplay_h
#include "CDisplay.h"
//#include "CDailyDisplay.h"

class CDailyDisplay : public CDisplay
{
	public:
	virtual void print (vector < CEvent >& all_events,  int year, unsigned month, unsigned day );
};
#endif/*CDailyDisplay_h*/