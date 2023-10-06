#ifndef my_CTime_h
#define my_CTime_h
#include<iostream>
#include <iomanip>
using namespace std;

class CTime
{
	public:
	int  m_Year;
	int m_Month;
	int m_Day;
	int m_Hour;
	int m_Minute;
	CTime ( int year, int month, int day, int hour, int minute);
	unsigned year ( void ) const;
	unsigned day ( void ) const;
	string hour ( void ) const;
	string minute ( void ) const;
	unsigned month ( void) const;
	bool leap_year ( int year ) const;
	string weekday ( void ) const;
	void edit_time ( unsigned hour, unsigned minute );
	void shift ( const int days );
	int CompareTime ( const CTime & x ) const;
	int CompareDate ( const CTime & x ) const;
	int Compare ( const CTime & x ) const;
	string date ( void ) const;
	string time ( void ) const;
};
#endif/*my_CTime_h*/