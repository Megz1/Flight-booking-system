#include <iostream>
#include "ViewingCanceling.h" // ViewingCanceling class definition

extern char airport[6][12];

extern int flightPrices[6][6];

// ViewingCanceling constructor initializes data members
ViewingCanceling::ViewingCanceling( ReservationDatabase &theReservationDatabase,
   FlightSchedule &theFlightSchedule )
   : reservationDatabase( theReservationDatabase ),
     flightSchedule( theFlightSchedule ) 
{
   id.copy( "", 0 );
} // end ViewingCanceling constructor


// performs reservation enquiry
// �qreservationDatabase�����M�ϥΪ̿�J��ID�۲Ū�,�⨺����ƥΤ@��reservation���Ы��V����
// �M��N���������ܥX��
// ����ܥ����Ψ�Flight����T,�ҥH�N��쨺����reservation����,���X�L��flightNumber�ǤJ,�N�i���n������Flight
bool ViewingCanceling::viewingReservation() 
{
	int howmany = 0;   // �O���YID�@���X�����
	int dataKey = 0;
	string bufID;
	
	cout << endl << "Enter ID Number:" ;
	cin  >> bufID;

	Reservation *reservationPtr = reservationDatabase.getNextReservation( bufID , dataKey );
	
	// �P�_���reservationDatabase���S���MID�۲Ū����
	if ( reservationPtr == NULL )
	{
		cout << endl << "No reservation information!" << endl;
		return 0;
	}

	howmany = reservationDatabase.id_howmany( bufID );

	cout << endl << endl << "    Name  Fare  Flight              Segment        Date  Departure time  Arrival time" << endl;

	for( int i=0 ; i < howmany ; i++ )
	{																							    // modify by s1003352 �����o
		Flight *flightPtr = flightSchedule.getNextFlight( reservationPtr->getFlightNumber() , 0 );	// modify �]���A�]�@���|�ק��
		cout << i << "." ;
		reservationPtr->display( flightPtr );
		// dataKey++																				// delete by s1003352 �����o
		reservationPtr = reservationDatabase.getNextReservation( bufID , dataKey ) ;
	}

}

// performs canceling reservation
void ViewingCanceling::cancelingReservation()
{
	int choice =0 ;
	int howmany = 0;   // �O���YID�@���X�����
	int dataKey = 0;
	string bufID;
	
	cout << endl << "Enter ID Number:" ;
	cin  >> bufID;

	Reservation *reservationPtr = reservationDatabase.getNextReservation( bufID , dataKey );
	
	// �P�_���reservationDatabase���S���MID�۲Ū����
	if ( reservationPtr == NULL )
	{
		cout << endl << "No reservation information!" << endl;
		return ;
	}

	howmany = reservationDatabase.id_howmany( bufID );

	cout << endl << endl << "    Name  Fare  Flight              Segment        Date  Departure time  Arrival time" << endl;

	for( int i=0 ; i < howmany ; i++ )
	{																								 // modify by s1003352 �����o
		Flight *flightPtr = flightSchedule.getNextFlight( reservationPtr->getFlightNumber() , 0 );	 // modify �]���A�]�@���|�ק��
		cout << i << "." ;
		reservationPtr->display( flightPtr );
		// dataKey++																				// delete by s1003352 �����o
		reservationPtr = reservationDatabase.getNextReservation( bufID , dataKey ) ;  
	}

	if ( howmany <= 1 )
	{
		cout << endl << "�o��ID Number�����쪺�q���q�ȳѤ@��"
			 << endl << "�L�k�A�i��R��" << endl;
		return ;
	}

	cout << endl << "Enter your choice�G";
	cin  >> choice ;

	dataKey = 0 ;

	for( int i=0 ; i < howmany ; i++ )
	{
		if ( choice == i )  // �n�R�������M�j�饿�]�쪺�����ۦP , �N��{�b�����ЬO���V "�n�R������" , �h�i�H��ӵ��@�R�����ʧ@
		{
			reservationDatabase.cancelReservation( bufID , reservationDatabase.getNextReservation( bufID , choice )->getFlightNumber() );
			break;
		}
	}
	cout << endl << "Reservation Cancelled!" << endl;
}