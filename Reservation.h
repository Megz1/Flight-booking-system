// Reservation.h
// Reservation class definition. Represents a reservation.
#ifndef RESERVATION_H
#define RESERVATION_H

#include "Flight.h"

class Reservation
{
public:
   // constructor initializes data members
   Reservation( string = "", string = "", string = "", string = "", string = "" );

   void setFlightNumber( string );
   string getFlightNumber();
   void setId( string );
   string getId();
   void setName( string );
   string getName();
   void setMobile( string );
   string getMobile();
   void setDate( string );
   string getDate();

   // displays name, flightPrices[ flightPtr->getDepartureAirport() ][ flightPtr->getArrivalAirport() ],
   // airport[ flightPtr->getDepartureAirport() ], airport[ flightPtr->getArrivalAirport() ],
   // date, flightPtr->getDepartureTime() and flightPtr->getArrivalTime()
   void display( Flight *flightPtr );
private:
   char flightNumber[8]; // flight number
   char id[12];          // id number
   char name[8];         // name
   char mobile[12];      // mobile phone number
   char date[12];          // departure date
};

#endif