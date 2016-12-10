// MakingReservation.h
// MakingReservation class definition. Represents a balance inquiry.
#ifndef MAKING_RESERVATION_H
#define MAKING_RESERVATION_H

#include "ReservationDatabase.h" // ReservationDatabase class definition
#include "FlightSchedule.h" // FlightSchedule class definition

class MakingReservation
{
public:
   MakingReservation( ReservationDatabase &, FlightSchedule & ); // constructor initializes data members
   void execute(); // performs making reservation
private:
   ReservationDatabase &reservationDatabase; // reference to the reservationDatabase
   FlightSchedule &flightSchedule; // reference to the flightSchedule
}; // end class MakingReservation

#endif // MAKING_RESERVATION_H