// ReservationDatabase.cpp
// Member-function definitions for class ReservationDatabase.
#include <iostream>
#include <fstream>
#include "ReservationDatabase.h" // ReservationDatabase class definition

// ReservationDatabase default constructor loads flight reservations from the file Reservations.dat
ReservationDatabase::ReservationDatabase()
{
   loadReservations();
}

// ReservationDatabase destructor stores flight reservations into the file Reservations.dat
ReservationDatabase::~ReservationDatabase()
{
   storeReservations();
}

int ReservationDatabase::getNumberOfReservations()
{
   return reservations.size();
}

void ReservationDatabase::addReservation( Reservation reservation )
{
   reservations.push_back( reservation );
}

int ReservationDatabase::id_howmany( string id )
{
	int howmany = 0;

	for ( int i=0 ; i < reservations.size() ; i++ )
	{
		if ( reservations[ i ].getId().compare( id ) == 0 )
		{
			howmany++;
		}
	}
	return howmany;
}

// get pointer to the first Reservation object in reservations[ begin ], reservations[ begin + 1 ], ...
// 從ReservationDatabase中找出 reservations[ begin ] *******
Reservation * ReservationDatabase::getNextReservation( string id, int &begin )         // 加入& , 讓begin傳參照 以便記錄更動的值 , add by s1003352 陳恒劭
{
	//return &reservations[ begin ];
	for ( int i=begin ; i < reservations.size() ; i++ )
	{
		//cout << "i" << i << endl << reservations[ i ].getf
		if ( reservations[ i ].getId().compare( id ) == 0 )
		{	
			if( (i+1) < reservations.size() ) // 防止找到最後一筆又加一筆
				begin = i+1;                  // add by s1003352 陳恒劭
			return &reservations[ i ];
		}
	}
	return NULL;
}

// cancels the first reservation object containing specified flightNumber and id
// 刪除reservationDatabase中 和傳入的id , flightNumber 相符的
void ReservationDatabase::cancelReservation( string id, string flightNumber )
{
	for ( int i=0 ; i < reservations.size() ; i++ )
	{
		if ( reservations[ i ].getId().compare( id ) == 0 && reservations[ i ].getFlightNumber().compare( flightNumber ) == 0 )
		{
			reservations[ i ].setId( "\0" );
			reservations[ i ].setFlightNumber( "\0" );
		}
	}

}

// get pointer to Reservation object containing specified flightNumber, id and date
// 將ReservationsDatabase中 找出某筆 flightNumber , id , date 相同的 回傳該位址
Reservation * ReservationDatabase::getReservation( string flightNumber, string id, string date )
{
	for ( int i=0 ; i < reservations.size() ; i++ )
	{
		if ( reservations[ i ].getFlightNumber().compare( flightNumber ) == 0 && reservations[ i ].getId().compare( id ) == 0 && reservations[ i ].getDate().compare( date ) == 0 )
		{
			return &reservations[ i ];
		}
	}
}

// loads flight reservations from the file Reservations.dat
void ReservationDatabase::loadReservations()
{
	Reservation oneReservation ;
	ifstream loadReservations( "Reservations.dat" , ios::binary | ios::in );
	if ( !loadReservations )
	{
		cerr << "無法開啟Reservations.dat" << endl ;
		system( "PAUSE" );
		exit ( 1 );
	}

	while ( !loadReservations.eof() )
	{
		loadReservations.read( reinterpret_cast < char * > ( &oneReservation ) , sizeof ( oneReservation ) );
		reservations.push_back( oneReservation );
	}
	// 是否加入pop_back()
	reservations.pop_back();

	loadReservations.close();
}

// stores flight reservations into the file Reservations.dat
void ReservationDatabase::storeReservations()
{
	ofstream writeReservations( "Reservations.dat" , ios::binary | ios::out );
	if ( !writeReservations )
	{
		cerr << "無法開啟Reservations.dat" << endl ;
		system( "PAUSE" );
		exit ( 1 );
	}

	for ( int i=0 ; i < reservations.size() ; i++ )
		writeReservations.write( reinterpret_cast < char * > ( &reservations[ i ] ) , sizeof ( reservations[ i ] ) );

	writeReservations.close();
}