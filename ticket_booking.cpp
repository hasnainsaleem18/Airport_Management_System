#include "ticket_booking.h"
#include <fstream>
#include <iostream>
#include <string>
#include <time.h>

Ticket_Booking::Ticket_Booking()
{
    ticket_id = 0;
    departure = "";
    arrival = "";
    seat_type = "";
    passport_id = 0;
    passenger_name = "";
}
Ticket_Booking::Ticket_Booking(int passport_id, string passenger_name, string arrival, string departure, string seat_type)
{
    this->passport_id = passport_id;
    this->passenger_name = passenger_name;
    this->arrival = arrival;
    this->departure = departure;
    this->seat_type = seat_type;
    srand(time(NULL)); //seed set on time.
    this->ticket_id = (rand() % 1001) + 100; //rand function used to generate unique ticket id each time 
}
int Ticket_Booking::get_ticket_id()
{
    return ticket_id;
}
string Ticket_Booking::get_departure() const
{
    return departure;
}
string Ticket_Booking::get_arrival() const
{
    return arrival;
}
string Ticket_Booking::get_seat_type() const
{
    return seat_type;
}
int Ticket_Booking::get_passport_id() const
{
    return passport_id;
}
string Ticket_Booking::get_passenger_name() const
{
    return passenger_name;
}
void Ticket_Booking::set_seat_type(string seat_type)
{
    this->seat_type = seat_type;
}

Passenger::Passenger()
{
    tickets = nullptr;
    size = 0;
}
Passenger::Passenger(const Passenger &flight) //copy constructor
{
    size = flight.size;

    if (size > 0)
    {
        tickets = new Ticket_Booking[size]; //dynamic array involved (new array created in heap)
        for(int i = 0; i < size; i++)   //loop for coyping the values of old array into the new created array
        {
            tickets[i] = flight.tickets[i];   //assigning values to the index of new array
        } 
    }
    else 
    {
        tickets = nullptr;  //pointer assinged null to avoid dangling pointer issue
    }

    // File handling
    ofstream ofile("passenger_copy.txt", ios::app);
    if (ofile.is_open()) 
    {
         for (int i = 0; i < size ; i++) 
        {   // writing ticket data to file
            ofile << "Passport ID : " << tickets[i].get_passport_id() <<endl;
            ofile << "Full Name : " << tickets[i].get_passenger_name() <<endl;
            ofile << "Ticket ID : " << tickets[i].get_ticket_id() << endl;
            ofile << "Arrival : " << tickets[i].get_arrival() <<endl;
            ofile << "Departure : " << tickets[i].get_departure() <<endl;
            
        }
        ofile.close();
    }
    else
    {
        cout << endl << "Error opening file!" << endl << endl;
    }
}
void Passenger::book_ticket(Ticket_Booking *flight)
{
    Ticket_Booking* new_arr = new Ticket_Booking[size + 1];  //new array created in heap wiht size  + 1

    for(int i = 0; i < size; i++)
    { 
        new_arr[i] = tickets[i];   //copying values into the index of new created array
    }
    
    new_arr[size] = *flight;   //assigning value at the last index of array as passed by user ( data for booking the flight for passenger)

    delete[] tickets;   //pointing pointiing path deleted
    tickets = new_arr;  //new pointing assigned
    size++;     //size increased by 1

    cout << endl << "TICKET BOOKED SUCCESSFULLY!" << endl << endl;
}
void Passenger::delete_ticket(int id)   //deleting the booked flight data
{
    int index = -1;

    for (int i = 0; i <size; i++) 
    {
        if (tickets[i].get_passport_id() == id)   //if condition to check whether the user entered passport id macthes id(if any) in the array containing data regarded ticket booking
        {
            index = i;
            break;
        }
    }
    if (index != -1) 
    {
        Ticket_Booking *array2 = new Ticket_Booking[size - 1];  //new array wiht size -1 (than orginal) created in heap

        for (int i = 0, j=0; i < size; i++)
        {
            if (i != index) 
            {
                array2[j]=tickets[i]; //once the  index is found copy all the data except data at that index copied to the new created array
                j++;   
            }
        }
        delete[] tickets;   //old pointing path deleted
        tickets = array2;   //new pointing path assigned
        size--;    //size reduced ny 1
 
        cout << endl << "TICKET DELETED SUCCESSFULLY!"<<endl;
        cout << endl;
    }
    else
    cout << endl << "INVALID ID" << endl << endl;
}
void Passenger::update_ticket(int id)   //updating the booked tikcet details for passenger
{
    string new_seat_type;
    int count = 0;

    for(int i=0; i < size; i++)
    {
        if (tickets[i].get_passport_id() == id) //if condition to check whether the provided passport id is present in the  array containing booked ticket details
        {
            cout << endl << "Enter new seat type: " << endl;
            getline(cin>>ws, new_seat_type);    //getting the updated details from the user
            tickets[i].set_seat_type(new_seat_type);  //assigning the updated data
            cout << endl << "SEAT TYPE UPDATED SUCCESSFULLY!" << endl << endl;
            count++;
        }    
    }
    if(count == 0)
    {
        cout << endl << "TICKET NOT FOUND!" << endl << endl;
    }
}
void Passenger::search_ticket(int id)  //searching the ticket in the array
{
    int count = 0;
    
    for (int i = 0; i < sizeof(tickets); i++)
    {
        if(tickets[i].get_passport_id() == id)  //if found,print the details
        {
            cout << endl << "Passport ID : " << tickets[i].get_passport_id() <<endl;
            cout << "Full Name : " << tickets[i].get_passenger_name() <<endl;
            cout << "Ticket ID : " << tickets[i].get_ticket_id() << endl;
            cout << "Arrival : " << tickets[i].get_arrival() <<endl;
            cout << "Departure : " << tickets[i].get_departure() <<endl;
            cout << "Seat Type : " << tickets[i].get_seat_type() << endl << endl;
            count++;
        }
    }
    if (count == 0)
    cout << "TICKET NOT FOUND!" << endl;
}
void Passenger::print()const  //printing the data
{
    for(int i=0; i<size; i++) 
    {
        cout << endl << "Passport ID : " << tickets[i].get_passport_id() <<endl;
        cout << "Full Name : " << tickets[i].get_passenger_name() <<endl;
        cout << "Ticket ID : " << tickets[i].get_ticket_id() << endl;
        cout << "Arrival : " << tickets[i].get_arrival() <<endl;
        cout << "Departure : " << tickets[i].get_departure() <<endl;
        cout << "Seat Type : " << tickets[i].get_seat_type() << endl << endl;
    } 
}
void Passenger::backup_tickets(const Passenger &passenger)  //creating backup for ticket booking data
{
    Passenger backup(passenger);
}