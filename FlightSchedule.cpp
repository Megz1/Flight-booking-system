// FlightSchedule.cpp
// Member-function definitions for class FlightSchedule.
#include <iostream>
#include <iomanip>
#include <fstream>
#include "FlightSchedule.h" // FlightSchedule class definition

// FlightSchedule default constructor loads flight schedule from the file FlightSchedule.dat
FlightSchedule::FlightSchedule()
{
   loadFlightSchedule();
}

int FlightSchedule::getNumberOfFlights()
{
   return flights.size();
}

// loads flight schedule from the file FlightSchedule.dat
void FlightSchedule::loadFlightSchedule()
{
	Flight oneFlight ;

	ifstream loadFlight( "FlightSchedule.dat" , ios::binary | ios::in );
	if ( !loadFlight )
	{
		cerr << "無法開啟FlightSchedule.dat" << endl ;
		system( "PAUSE" );
		exit ( 1 );
	}

	while ( !loadFlight.eof() )
	{
		loadFlight.read( reinterpret_cast < char * > ( &oneFlight ) , sizeof ( oneFlight ) );
		flights.push_back( oneFlight );
	}
	// 是否加入pop_back()
	loadFlight.close();
}

// get pointer to the first Flight object in flights[ begin ], flights[ begin + 1 ], flights[ begin + 2 ], ...
// ***********
Flight * FlightSchedule::getNextFlight( string flightNumber, int begin )
{
	//return &flights[ begin ];
	for ( int i=begin ; i < flights.size() ; i++ )
	{
		if ( flights[ i ].getFlightNumber().compare( flightNumber ) == 0 )
		{
			return &flights[ i ];
		}
	}
	return NULL;
}

// calls the function display in the class Flight to display the information regarding the
// Flight object containing specified departureAirport and arrivalAirport
void FlightSchedule::display( int departureAirport, int arrivalAirport, string date )
{
	cout << endl << endl << "Flight  Departure airport  Arrival airport        Date  Departure time  Arrival time  Fare" << endl;
	for ( int i=0 ; i < flights.size() ; i++ )
	{
		if ( flights[ i ].getDepartureAirport() == departureAirport && flights[ i ].getArrivalAirport() == arrivalAirport )
		{
			cout << setw(6) << flights[ i ].getFlightNumber() << setw(19) << airport[ flights[ i ].getDepartureAirport() ]
				 << setw(17) << airport[ flights[ i ].getArrivalAirport() ] << setw(12) << date << setw(16) << flights[ i ].getDepartureTime() 
				 << setw(14) << flights[ i ].getArrivalTime() << setw(6) << flightPrices[ flights[ i ].getDepartureAirport() ][ flights[ i ].getArrivalAirport() ] << endl;
		}

	}
}

// retrieve Flight object containing specified flight number, departureAirport and arrivalAirport
Flight * FlightSchedule::getFlight( string flightNumber, int departureAirport, int arrivalAirport )
{
	for ( int i=0 ; i < flights.size() ; i++ )
	{
		if ( flights[ i ].getFlightNumber().compare( flightNumber ) == 0 && flights[ i ].getDepartureAirport() == departureAirport && flights[ i ].getArrivalAirport() == arrivalAirport )
		{
			return &flights[ i ];
		}
	}
}