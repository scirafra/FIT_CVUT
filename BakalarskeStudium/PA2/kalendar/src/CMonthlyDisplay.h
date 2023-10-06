#ifndef CMonth_h
#define CMonth_h
#include "CDisplay.h"
#include "CMonthlyDisplay.h"

class CMonthlyDisplay : public CDisplay
{
	public:
	virtual void print (vector < CEvent >& all_events,  int year, unsigned month, unsigned day );
};
#endif/*CMonthlyDisplay_h*/