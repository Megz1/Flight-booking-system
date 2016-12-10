#include <iostream>
#include <iomanip>
#include "Reservation.h" // Reservation class definition

extern char airport[6][12];
extern int flightPrices[6][6];

Reservation::Reservation( string flightNumberValue, string idValue,
                          string nameValue, string mobileValue, string dateValue )
{
   setFlightNumber( flightNumberValue );
   setId( idValue );
   setName( nameValue );
   setMobile( mobileValue );
   setDate( dateValue );
}

void Reservation::setFlightNumber( string flightNumberValue )
{
   int length = flightNumberValue.size();
   length = ( length < 8 ? length : 7 );
   flightNumberValue.copy( flightNumber, length );
   flightNumber[ length ] = '\0';
}

string Reservation::getFlightNumber()
{
   string buffer( flightNumber );
   return buffer;
}

void Reservation::setId( string idValue )
{
   int length = idValue.size();
   length = ( length < 12 ? length : 11 );
   idValue.copy( id, length );
   id[ length ] = '\0';
}

string Reservation::getId()
{
   string buffer( id );
   return buffer;
}

void Reservation::setName( string nameValue )
{
   int length = nameValue.size();
   length = ( length < 8 ? length : 7 );
   nameValue.copy( name, length );
   name[ length ] = '\0';
}

string Reservation::getName()
{
   string buffer( name );
   return buffer;
}

void Reservation::setMobile( string mobileValue )
{
   int length = mobileValue.size();
   length = ( length < 12 ? length : 11 );
   mobileValue.copy( mobile, length );
   mobile[ length ] = '\0';
}

string Reservation::getMobile()
{
   string buffer( mobile );
   return buffer;
}

void Reservation::setDate( string dateValue )
{
   int length = dateValue.size();
   length = ( length < 12 ? length : 11 );
   dateValue.copy( date, length );
   date[ length ] = '\0';
}

string Reservation::getDate()
{
   string buffer( date );
   return buffer;
}

// displays name, flightPrices[ flightPtr->getDepartureAirport() ][ flightPtr->getArrivalAirport() ],
// airport[ flightPtr->getDepartureAirport() ], airport[ flightPtr->getArrivalAirport() ],
// date, flightPtr->getDepartureTime() and flightPtr->getArrivalTime()
void Reservation::display( Flight *flightPtr )
{
	//cout << endl << endl << "    Name  Fare  Flight              Segment        Date  Departure time  Arrival time" << endl;
	cout << setw(8) << name << setw(6) << flightPrices[ flightPtr->getDepartureAirport() ][ flightPtr->getArrivalAirport() ]
	<< setw(8) << "GE" << flightPtr->getFlightNumber() << setw(14) << airport[ flightPtr->getDepartureAirport() ] << " - " << setw(7) << airport[ flightPtr->getArrivalAirport() ]
	<< setw(12) << date << setw(16) << flightPtr->getDepartureTime() << setw(14) << flightPtr->getArrivalTime() << endl;
}