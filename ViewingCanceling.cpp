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
// 從reservationDatabase中找到和使用者輸入的ID相符的,把那筆資料用一個reservation指標指向那筆
// 然後將那筆資料顯示出來
// 但顯示必須用到Flight的資訊,所以將找到那筆的reservation指標,取出他的flightNumber傳入,就可找到要的那筆Flight
bool ViewingCanceling::viewingReservation() 
{
	int howmany = 0;   // 記錄某ID共有幾筆資料
	int dataKey = 0;
	string bufID;
	
	cout << endl << "Enter ID Number:" ;
	cin  >> bufID;

	Reservation *reservationPtr = reservationDatabase.getNextReservation( bufID , dataKey );
	
	// 判斷整個reservationDatabase有沒有和ID相符的資料
	if ( reservationPtr == NULL )
	{
		cout << endl << "No reservation information!" << endl;
		return 0;
	}

	howmany = reservationDatabase.id_howmany( bufID );

	cout << endl << endl << "    Name  Fare  Flight              Segment        Date  Departure time  Arrival time" << endl;

	for( int i=0 ; i < howmany ; i++ )
	{																							    // modify by s1003352 陳恒劭
		Flight *flightPtr = flightSchedule.getNextFlight( reservationPtr->getFlightNumber() , 0 );	// modify 因為再跑一次會修改到
		cout << i << "." ;
		reservationPtr->display( flightPtr );
		// dataKey++																				// delete by s1003352 陳恒劭
		reservationPtr = reservationDatabase.getNextReservation( bufID , dataKey ) ;
	}

}

// performs canceling reservation
void ViewingCanceling::cancelingReservation()
{
	int choice =0 ;
	int howmany = 0;   // 記錄某ID共有幾筆資料
	int dataKey = 0;
	string bufID;
	
	cout << endl << "Enter ID Number:" ;
	cin  >> bufID;

	Reservation *reservationPtr = reservationDatabase.getNextReservation( bufID , dataKey );
	
	// 判斷整個reservationDatabase有沒有和ID相符的資料
	if ( reservationPtr == NULL )
	{
		cout << endl << "No reservation information!" << endl;
		return ;
	}

	howmany = reservationDatabase.id_howmany( bufID );

	cout << endl << endl << "    Name  Fare  Flight              Segment        Date  Departure time  Arrival time" << endl;

	for( int i=0 ; i < howmany ; i++ )
	{																								 // modify by s1003352 陳恒劭
		Flight *flightPtr = flightSchedule.getNextFlight( reservationPtr->getFlightNumber() , 0 );	 // modify 因為再跑一次會修改到
		cout << i << "." ;
		reservationPtr->display( flightPtr );
		// dataKey++																				// delete by s1003352 陳恒劭
		reservationPtr = reservationDatabase.getNextReservation( bufID , dataKey ) ;  
	}

	if ( howmany <= 1 )
	{
		cout << endl << "這個ID Number對應到的訂票量僅剩一筆"
			 << endl << "無法再進行刪除" << endl;
		return ;
	}

	cout << endl << "Enter your choice：";
	cin  >> choice ;

	dataKey = 0 ;

	for( int i=0 ; i < howmany ; i++ )
	{
		if ( choice == i )  // 要刪的那筆和迴圈正跑到的那筆相同 , 代表現在的指標是指向 "要刪的那筆" , 則可以對該筆作刪除的動作
		{
			reservationDatabase.cancelReservation( bufID , reservationDatabase.getNextReservation( bufID , choice )->getFlightNumber() );
			break;
		}
	}
	cout << endl << "Reservation Cancelled!" << endl;
}