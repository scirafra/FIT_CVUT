
#include "CDisplay.h"
#include "CEventDisplay.h"
#include "CDailyDisplay.h"
#include "CWeeklyDisplay.h"
#include "CMonthlyDisplay.h"

class CCommand 
{
	public:
	string read_string ( string text, unsigned max );
	string read_file_name ( string text, unsigned max );
	unsigned read_day ( unsigned year, unsigned month );
	unsigned read_number ( string text, unsigned min, unsigned max, bool menu );
	int run ( void );
};