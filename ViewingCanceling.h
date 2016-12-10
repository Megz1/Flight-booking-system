// ViewingCanceling.h
// ViewingCanceling class definition.
#ifndef VIEWING_CANCELING_H
#define VIEWING_CANCELING_H

#include "ReservationDatabase.h" // ReservationDatabase class definition
#include "FlightSchedule.h" // FlightSchedule class definition

class ViewingCanceling
{
public:
   ViewingCanceling( ReservationDatabase &, FlightSchedule & ); // constructor initializes data members
   void cancelingReservation(); // performs canceling reservation
   bool viewingReservation(); // performs reservation enquiry
private:
   string id; // current user's id number
   ReservationDatabase &reservationDatabase; // reference to the reservationDatabase
   FlightSchedule &flightSchedule; // reference to the flightSchedule
}; // end class ViewingCanceling

#endif // VIEWING_CANCELING_H