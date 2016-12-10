#include <iostream>
using namespace std;
#include "ReservationDatabase.h" // ReservationDatabase class definition
#include "FlightSchedule.h" // FlightSchedule class definition
#include "MakingReservation.h" // MakingReservation class definition
#include "ViewingCanceling.h" // ViewingCanceling class definition
#include "Reservation.h"
#include "Flight.h"

char airport[6][12] = { "", "Songshan", "Kaohsiung", "Hualien", "Kinmen", "Makung" };

int flightPrices[6][6] = { { 0,    0,    0,    0,    0,    0 },
                           { 0,    0,    0, 1455, 2088, 1790 },
                           { 0,    0,    0,    0, 1945, 1455 },
                           { 0, 1455,    0,    0,    0,    0 },
                           { 0, 1989, 1852,    0,    0,    0 },
                           { 0, 1705, 1386,    0,    0,    0 } };

int enterChoice();

int main()
{
   cout << "Welcome to the TransAsia Airways Flight Reservation System\n";

   ReservationDatabase reservationDatabase;
   FlightSchedule flightSchedule;
   MakingReservation makingReservation( reservationDatabase, flightSchedule );
   ViewingCanceling viewingCanceling( reservationDatabase, flightSchedule );

   int choice;
   while ( ( choice = enterChoice() ) != 4 )
   {
      switch ( choice )
      {
      case 1:
         makingReservation.execute();
         break;
      case 2:
         viewingCanceling.viewingReservation();
         break;
      case 3:
         viewingCanceling.cancelingReservation();
         break;
      default:
         cerr << "Incorrect choice" << endl;
         break;
      }
   }

   cout << endl;
   system("pause");
}

int enterChoice()
{
   cout << "\nInput your choice¡G\n"
      << "1. Booking Flights\n"
      << "2. Reservation Enquiry\n"
      << "3. Cancel Reservation\n"
      << "4. End\n? ";

   int menuChoice;
   cin >> menuChoice;
   return menuChoice;
}