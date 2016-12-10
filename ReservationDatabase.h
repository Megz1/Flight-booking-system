// ReservationDatabase.h
// ReservationDatabase class definition. Represents the reservation database.
#ifndef RESERVATION_DATABASE_H
#define RESERVATION_DATABASE_H

#include <vector> // class uses vector to store Reservation objects
#include "Reservation.h" // Reservation class definition

class ReservationDatabase
{
public:
   // constructor calls loadReservations to load flight reservations from the file Reservations.dat
   ReservationDatabase();

   // destructor calls storeReservations to store flight reservations into the file Reservations.dat
   ~ReservationDatabase();

   int getNumberOfReservations(); // reservations.size()

   // get pointer to the first Reservation object in reservations[ begin ], reservations[ begin + 1 ], ...
   Reservation * getNextReservation( string id, int &begin );         // 加入& , 讓begin傳參照 以便記錄更動的值 , add by s1003352 陳恒劭

   int id_howmany( string id );

   // cancels the first reservation object containing specified flightNumber and id
   //void cancelReservation( string id, int flightNumber );
   void cancelReservation( string id, string flightNumber );

   void addReservation( Reservation reservation ); // add reservation at the end of reservations
private:
   std::vector< Reservation > reservations; // vector of the flight reservations

   // get pointer to Reservation object containing specified flightNumber, id and date
   Reservation * getReservation( string flightNumber, string id, string date );

   void loadReservations(); // loads flight reservations from the file Reservations.dat
   void storeReservations(); // stores flight reservations into the file Reservations.dat
}; // end class ReservationDatabase

#endif // RESERVATION_DATABASE_H