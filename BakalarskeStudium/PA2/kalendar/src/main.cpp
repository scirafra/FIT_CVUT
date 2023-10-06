#include "CCommand.h"
int main (){
	/*! \mainpage Planning Calendar
	*
	* \section intro_sec What is possible
	*
	* Planning Calendar is program in which can user create, delete and edit events to which is possible adding and deleting people, show month, week or day, search by name or place, and export or import calendar to/from file.
	*
	* \section install_sec Control
	*
	* User can move from menu to function by choosing number between 0 and 15 ( each opens different function ). Number 16 quits the program.
	* Each functions requires input either number or string ( depends on function ).
	* User can return to menu by typing wrong input.
	*/
	CCommand app;
	app.run();
	return 0;
}