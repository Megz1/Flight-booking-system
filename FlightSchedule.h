// FlightSchedule.h
// FlightSchedule class definition. Represents the flight schedule.
#ifndef FLIGHT_SCHEDULE_H
#define FLIGHT_SCHEDULE_H

#include <vector> // class uses vector to store Flight objects
#include "Flight.h" // FlightSchedule class definition
/*
char Fairport[6][12] = { "", "Songshan", "Kaohsiung", "Hualien", "Kinmen", "Makung" };

int FflightPrices[6][6] = { { 0,    0,    0,    0,    0,    0 },
                           { 0,    0,    0, 1455, 2088, 1790 },
                           { 0,    0,    0,    0, 1945, 1455 },
                           { 0, 1455,    0,    0,    0,    0 },
                           { 0, 1989, 1852,    0,    0,    0 },
                           { 0, 1705, 1386,    0,    0,    0 } };
*/


extern char airport[6][12];
extern int flightPrices[6][6];

class FlightSchedule
{
public:
   // constructor calls loadFlightSchedule to load flight schedule from the file FlightSchedule.dat
   FlightSchedule();

   int getNumberOfFlights(); // returns flights.size()

   // get pointer to the first Flight object in flights[ begin ], flights[ begin + 1 ], flights[ begin + 2 ], ...
   Flight * getNextFlight( string flightNumber, int begin );

   // calls the function display in the class Flight to display the information regarding the
   // Flight object containing specified departureAirport and arrivalAirport
   void display( int departureAirport, int arrivalAirport, string date );

    // retrieve Flight object containing specified flight number, departureAirport and arrivalAirport
   Flight * getFlight( string flightNumber, int departureAirport, int arrivalAirport );
private:
   std::vector< Flight > flights; // vector of the flights

   void loadFlightSchedule(); // loads flight schedule from the file FlightSchedule.dat
}; // end class FlightSchedule

#endif // FLIGHT_SCHEDULE_H
