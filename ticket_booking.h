#include <iostream>
#include <string>

using namespace std;

class Ticket_Booking
{
    private: //private data members
        int ticket_id;
        string departure;
        string arrival;
        string seat_type;
        int passport_id;
        string passenger_name;
    public:
        Ticket_Booking(); //default constructor 
        Ticket_Booking(int passport_id, string passenger_name, string arrival, string departure, string seat_type); //parameterized constructor 
        //getetrs
        int get_ticket_id();
        string get_departure() const;
        string get_arrival() const;
        string get_seat_type() const;
        int get_passport_id() const;
        string get_passenger_name() const;
        void set_seat_type(string seat_type); //setters
};

class Passenger
{
    private:
        Ticket_Booking *tickets; //pointer for an array of ticket booking created ---dynamic array involved
        int size;        //size data member to assign size to the array
    public:
        Passenger();
        Passenger(const Passenger &flight);  //constant parameter sent by reference to avoid value replacement
        void book_ticket(Ticket_Booking *flight); //pointer of the ticket booking array as parameter
        void delete_ticket(int id);
        void update_ticket(int id);
        void search_ticket(int id);
        void print()const;
        void backup_tickets(const Passenger &passenger);
};