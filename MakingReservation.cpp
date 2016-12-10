// MakingReservation.cpp
// Member-function definitions for class MakingReservation.
#include <iostream>
#include "ReservationDatabase.h" // ReservationDatabase class definition
#include "FlightSchedule.h" // FlightSchedule class definition
#include "MakingReservation.h" // MakingReservation class definition

extern char airport[6][12];
extern int flightPrices[6][6];

// MakingReservation constructor initializes data members
MakingReservation::MakingReservation( ReservationDatabase &theReservationDatabase,
   FlightSchedule &theFlightSchedule )
   : reservationDatabase( theReservationDatabase ),
     flightSchedule( theFlightSchedule )
{
} // end MakingReservation constructor


// performs making reservation
void MakingReservation::execute()
{
	Reservation newReservation;
	int departureAirport ;
	int arriveAirport ;

	string keyString;
	cout << endl << "Input Booking Data" << endl;
	cout << endl << "Departure Date (yyyy/mm/dd)：" ;
	cin  >> keyString;
	newReservation.setDate( keyString );

	cout << endl << endl << "Departure Airport："  << endl;
	for ( int i=1 ; i <= 5 ; i++ )  //顯示出發機場
	{
		cout << i << ". " << airport[ i ] << endl;
	}
	cout << "? " ;
	cin  >> departureAirport;
	
	cout << endl << endl << "Arrive Airport：" << endl ;
	if ( departureAirport == 1 )  // Songshan 會到的
	{
		for( int i=0 ; i <= 5 ; i++ )
		{
			if( flightPrices[ departureAirport ][ i ] != 0 )
			{
				cout << i << ". " << airport[ i ] << endl ;
			}
		}
	}
	else if ( departureAirport == 2 ) // Kaohsiung 會到的
	{
		for( int i=0 ; i <= 5 ; i++ )
		{
			if( flightPrices[ departureAirport ][ i ] != 0 )
			{
				cout << i << ". " << airport[ i ] << endl ;
			}
		}
	}
	else if ( departureAirport == 3 ) // Hualien 會到的
	{
		for( int i=0 ; i <= 5 ; i++ )
		{
			if( flightPrices[ departureAirport ][ i ] != 0 )
			{
				cout << i << ". " << airport[ i ] << endl ;
			}
		}
	}
	else if ( departureAirport == 4 ) // Kinmen 會到的
	{
		for( int i=0 ; i <= 5 ; i++ )
		{
			if( flightPrices[ departureAirport ][ i ] != 0 )
			{
				cout << i << ". " << airport[ i ] << endl ;
			}
		}
	}
	else if ( departureAirport == 5 ) // Makung 會到的
	{
		for( int i=0 ; i <= 5 ; i++ )
		{
			if( flightPrices[ departureAirport ][ i ] != 0 )
			{
				cout << i << ". " << airport[ i ] << endl ;
			}
		}
	}
	cout << "? " ;
	cin  >> arriveAirport ;

	flightSchedule.display( departureAirport , arriveAirport , newReservation.getDate() );

	cout << endl << "Flight Number: ";
	cin  >> keyString;
	newReservation.setFlightNumber( keyString );
	
	Flight *bufflightPtr = flightSchedule.getFlight( newReservation.getFlightNumber() , departureAirport , arriveAirport );
	// 儲存使用者當前選擇的那筆Flight Number的飛機 ,用這指標指向那筆飛機


	cout << endl << endl << "Input ID Number:";
	cin  >> keyString;
	newReservation.setId( keyString );

	cout << endl << endl << "Name:" ;
	cin  >> keyString;
	newReservation.setName( keyString );

	cout << endl << endl << "Mobile Phone:" ;
	cin  >> keyString;
	newReservation.setMobile( keyString );

	cout << endl << endl << "    Name  Fare  Flight              Segment        Date  Departure time  Arrival time" << endl;

	newReservation.display( bufflightPtr );
	
	reservationDatabase.addReservation( newReservation );

	cout << endl << "Reservation Completed!" << endl << endl;

}