#include "CTime.h"

CTime::CTime ( int year, int month, int day, int hour, int minute)
	{
		m_Year = year;
		m_Month = month;
		m_Day = day;
		m_Hour = hour;
		m_Minute = minute;
	}
	unsigned CTime::year ( void ) const
	{
		return m_Year;
	}
	unsigned CTime::day ( void ) const
	{
		return m_Day;
	}
	string CTime::hour ( void ) const
	{
		return to_string ( m_Hour );
	}
	string CTime::minute ( void ) const
	{
		return to_string ( m_Minute );
	}
	unsigned CTime::month ( void) const
	{
		return unsigned ( m_Month );
	}
	//counts if that year is a leap year
	bool CTime::leap_year ( int year ) const
	{
		if ( year % 4 == 0 && ( year % 100 !=0 || year % 400 == 0 ) ) 
		{
			return true;
		}
		return false;
	}
	//counts which day of week it is ( Monday ... )
	string CTime::weekday ( void ) const
	{
		int day;
		day = m_Year % 100;
		day += ( day / 4 );
		day = day % 7;
		switch ( m_Month )
		{
			case 1 : break;
			case 2 : day += 3; break;
			case 3 : day += 3; break;
			case 4 : day += 6; break;
			case 5 : day += 1; break;
			case 6 : day += 4; break;
			case 7 : day += 6; break;
			case 8 : day += 2; break;
			case 9 : day += 5; break;
			case 10 : break;
			case 11 : day += 3; break;
			case 12 : day += 5; break;
		}
		day += ( 6 - ( ( ( m_Year / 100 ) % 4 ) * 2 ) );
		day += m_Day;
		if ( leap_year ( m_Year ) && ( m_Month == 1 || m_Month == 2 ) )
		{
			day -= 1;
		}
		switch ( day % 7 )
		{
			case 0 : return "Sun";
			case 1 : return "Mon";
			case 2 : return "Tue";
			case 3 : return "Wed";
			case 4 : return "Thu";
			case 5 : return "Fri";
			case 6 : return "Sat";
		}
		return "";
		
	}
	void CTime::edit_time ( unsigned hour, unsigned minute )
	{
		m_Hour = hour;
		m_Minute = minute;
	}
	//shifts date and puts it into valid date
	void CTime::shift ( const int days ) 
	{
		m_Day += days;
		while ( 1 )
		{
			if ( m_Day > 28 )
			{
				if ( m_Day > 31 )
				{
					if ( m_Month == 12 )
					{
						m_Day -= 31;
						m_Month = 1;
						m_Year ++;
					}
					else if ( m_Month == 1 || m_Month == 3 || m_Month == 5 || m_Month == 7 || m_Month == 8 || m_Month == 10 )
					{
						m_Day -= 31;
						m_Month ++;
					}
					else if ( m_Month == 4 || m_Month == 6 || m_Month == 9 || m_Month == 11 )
					{
						m_Day -= 30;
						m_Month ++;
					}
					else if ( m_Month == 2 )
					{
						if ( leap_year ( m_Year ) ) 
						{ 
							m_Day -= 29;
							m_Month ++;
						} 
						else
						{ 
							m_Day -= 28;
							m_Month ++;
						}
					}
					else
					{
						return;// false;
					}
				}
				if ( m_Day == 31 )
				{
					if ( m_Month == 1 || m_Month == 3 || m_Month == 5 || m_Month == 7 || m_Month == 8 || m_Month == 10 || m_Month == 12 )
					{
						return;// true;
					}
					else if ( m_Month == 4 || m_Month == 6 || m_Month == 9 || m_Month == 11 )
					{
						m_Day -= 30;
						m_Month ++;
					}
					else if ( m_Month == 2 )
					{
						if ( leap_year ( m_Year ) )
						{ 
							m_Day -= 29;
							m_Month ++;
						} 
						else
						{ 
							m_Day -= 28;
							m_Month ++;
						}
					}
					else
					{
						return;// false;
					}
				}
				if ( m_Day == 30 )
				{
					if ( m_Month > 0 && m_Month < 13 && m_Month != 2 )
					{
						return;// true;
					}
					else if ( m_Month == 2 )
					{
						if ( leap_year ( m_Year ) )
						{ 
							m_Day -= 29;
							m_Month ++;
						} 
						else
						{ 
							m_Day -= 28;
							m_Month ++;
						}
					}
					else
					{
						return;
					}
				}
				if ( m_Day == 29 )
				{
					if ( m_Month > 0 && m_Month < 13 && m_Month != 2 )
					{
						return;
					}
					else if ( m_Month == 2 )
					{
						if ( leap_year ( m_Year ) )
						{ 
							return;
						} 
						else
						{ 
							m_Day -= 28;
							m_Month ++;
						}
					}
					else
					{
						return;
					}
				}
			}
			else if ( m_Day < 1 )
			{
				if ( m_Month == 1 )
					{
						m_Day += 31;
						m_Month = 12;
						m_Year --;
					}
					else if ( m_Month == 2 || m_Month == 4 || m_Month == 6 || m_Month == 8 || m_Month == 9 || m_Month == 11 )
					{
						m_Day += 31;
						m_Month --;
					}
					else if ( m_Month == 5 || m_Month == 7 || m_Month == 10 || m_Month == 12 )
					{
						m_Day += 30;
						m_Month --;
					}
					else if ( m_Month == 3 )
					{
						if ( leap_year ( m_Year ) )
						{ 
							m_Day += 29;
							m_Month --;
						} 
						else
						{ 
							m_Day += 28;
							m_Month --;
						}
					}
					else
					{
						return;
					}
			}
			else
			{
				return;
			}
		}
	}
	//compare time with another time class
	int CTime::CompareTime ( const CTime & x ) const
	{
		if ( m_Hour != x.m_Hour )
		{
			if ( m_Hour < x.m_Hour )
			{ 
				return -1;
			}
			else
			{
				return 1;
			}
		}
		else if ( m_Minute != x.m_Minute )
		{
			if ( m_Minute < x.m_Minute )
				{ 
					return -1;
				}
			else
				{
					return 1;
				}
		}
		else
		{
			return 0;
		}
	}
	//compare date with another time class
	int CTime::CompareDate ( const CTime & x ) const
	{
		if ( m_Year != x.m_Year )
		{
			if ( m_Year < x.m_Year )
			{ 
				return -1;
			}
			else
			{
				return 1;
			}
		}
		else if ( m_Month != x.m_Month )
		{
			if ( m_Month < x.m_Month )
				{
					return -1;
				}
			else
				{
					return 1;
				}
		}
		else if ( m_Day != x.m_Day )
		{
			if ( m_Day < x.m_Day )
				{
					return -1;
				}
			else
				{
					return 1;
				}
		}
		else
		{
			return 0;
		}
	}
	//compare date and time with another time class
	int CTime::Compare ( const CTime & x ) const
	{
		if ( m_Year != x.m_Year )
		{
			if ( m_Year < x.m_Year )
			{ 
				return -1;
			}
			else
			{
				return 1;
			}
		}
		else if ( m_Month != x.m_Month )
		{
			if ( m_Month < x.m_Month )
				{
					return -1;
				}
			else
				{
					return 1;
				}
		}
		else if ( m_Day != x.m_Day )
		{
			if ( m_Day < x.m_Day )
				{
					return -1;
				}
			else
				{
					return 1;
				}
		}
		else if ( m_Hour != x.m_Hour )
		{
			if ( m_Hour < x.m_Hour )
			{ 
				return -1;
			}
			else
			{
				return 1;
			}
		}
		else if ( m_Minute != x.m_Minute )
		{
			if ( m_Minute < x.m_Minute )
				{ 
					return -1;
				}
			else
				{
					return 1;
				}
		}
		else
		{
			return 0;
		}
	}
	//return date in string form
	string CTime::date ( void ) const
	{
		string str = "";
		str += to_string ( m_Day );
		str += '.';
		str += to_string ( m_Month );
		str += '.';
		str += to_string ( m_Year );
		return str;
	}
	//return time in string form
	string CTime::time ( void ) const
	{
		string str = "";
		if ( m_Hour < 10 )
		{
			str += '0';
		}
		str += to_string ( m_Hour );
		str += ':';
		if ( m_Minute < 10 )
		{
			str += '0';
		}
		str += to_string ( m_Minute );
		return str;
	}
