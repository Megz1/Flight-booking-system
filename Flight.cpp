#include <iostream>
#include <iomanip>
#include "Flight.h" // Flight class definition

extern char airport[6][12];
extern int flightPrices[6][6];

Flight::Flight( string flightNumberValue, int departureAirportValue,
                int arrivalAirportValue, string departureTimeValue, string arrivalTimeValue )
{
   setFlightNumber( flightNumberValue );
   setDepartureAirport( departureAirportValue );
   setArrivalAirport( arrivalAirportValue );
   setDepartureTime( departureTimeValue );
   setArrivalTime( arrivalTimeValue );
}

void Flight::setFlightNumber( string flightNumberValue )
{
   int length = flightNumberValue.size();
   length = ( length < 8 ? length : 7 );
   flightNumberValue.copy( flightNumber, length );
   flightNumber[ length ] = '\0';
}

string Flight::getFlightNumber()
{
   return flightNumber;
}

void Flight::setDepartureAirport( int departureAirportValue )
{
   departureAirport = departureAirportValue;
}

int Flight::getDepartureAirport()
{
   return departureAirport;
}

void Flight::setArrivalAirport( int arrivalAirportValue )
{
   arrivalAirport = arrivalAirportValue;
}

int Flight::getArrivalAirport()
{
   return arrivalAirport;
}

void Flight::setDepartureTime( string departureTimeValue )
{
   int length = departureTimeValue.size();
   length = ( length < 8 ? length : 7 );
   departureTimeValue.copy( departureTime, length );
   departureTime[ length ] = '\0';
}

string Flight::getDepartureTime()
{
   string buffer( departureTime );
   return buffer;
}

void Flight::setArrivalTime( string arrivalTimeValue )
{
   int length = arrivalTimeValue.size();
   length = ( length < 8 ? length : 7 );
   arrivalTimeValue.copy( arrivalTime, length );
   arrivalTime[ length ] = '\0';
}

string Flight::getArrivalTime()
{
   string buffer( arrivalTime );
   return buffer;
}

void Flight::display( string date )
{
   cout << setw(6) << flightNumber
        << setw(19) << airport[ departureAirport ]
        << setw(17) << airport[ arrivalAirport ]
        << setw(12) << date
        << setw(16) << departureTime
        << setw(14) << arrivalTime
        << setw(6) << flightPrices[ departureAirport ][ arrivalAirport ]
        << endl;
}
