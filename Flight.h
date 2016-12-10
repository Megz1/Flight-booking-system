#ifndef FLIGHT_H
#define FLIGHT_H

#include <string>
using namespace std;

class Flight
{
public:
   // constructor initializes data members
   Flight( string = "", int = 0, int = 0, string = "", string = "" );

   void setFlightNumber( string );
   string getFlightNumber();
   void setDepartureAirport( int );
   int getDepartureAirport();
   void setArrivalAirport( int );
   int getArrivalAirport();
   void setDepartureTime( string );
   string getDepartureTime();
   void setArrivalTime( string );
   string getArrivalTime();

   // displays flightNumber, airport[ departureAirport ], airport[ arrivalAirport ], date,
   // departureTime, arrivalTime and flightPrices[ departureAirport ][ arrivalAirport ]
   void display( string );
private:
   char flightNumber[8];  // flight number
   int departureAirport;  // departure airport code
   int arrivalAirport;    // arrival airport code
   char departureTime[8]; // departure time
   char arrivalTime[8];   // arrival time
};

#endif