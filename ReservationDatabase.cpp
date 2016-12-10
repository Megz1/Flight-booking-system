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
// �qReservationDatabase����X reservations[ begin ] *******
Reservation * ReservationDatabase::getNextReservation( string id, int &begin )         // �[�J& , ��begin�ǰѷ� �H�K�O����ʪ��� , add by s1003352 �����o
{
	//return &reservations[ begin ];
	for ( int i=begin ; i < reservations.size() ; i++ )
	{
		//cout << "i" << i << endl << reservations[ i ].getf
		if ( reservations[ i ].getId().compare( id ) == 0 )
		{	
			if( (i+1) < reservations.size() ) // ������̫�@���S�[�@��
				begin = i+1;                  // add by s1003352 �����o
			return &reservations[ i ];
		}
	}
	return NULL;
}

// cancels the first reservation object containing specified flightNumber and id
// �R��reservationDatabase�� �M�ǤJ��id , flightNumber �۲Ū�
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
// �NReservationsDatabase�� ��X�Y�� flightNumber , id , date �ۦP�� �^�ǸӦ�}
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
		cerr << "�L�k�}��Reservations.dat" << endl ;
		system( "PAUSE" );
		exit ( 1 );
	}

	while ( !loadReservations.eof() )
	{
		loadReservations.read( reinterpret_cast < char * > ( &oneReservation ) , sizeof ( oneReservation ) );
		reservations.push_back( oneReservation );
	}
	// �O�_�[�Jpop_back()
	reservations.pop_back();

	loadReservations.close();
}

// stores flight reservations into the file Reservations.dat
void ReservationDatabase::storeReservations()
{
	ofstream writeReservations( "Reservations.dat" , ios::binary | ios::out );
	if ( !writeReservations )
	{
		cerr << "�L�k�}��Reservations.dat" << endl ;
		system( "PAUSE" );
		exit ( 1 );
	}

	for ( int i=0 ; i < reservations.size() ; i++ )
		writeReservations.write( reinterpret_cast < char * > ( &reservations[ i ] ) , sizeof ( reservations[ i ] ) );

	writeReservations.close();
}