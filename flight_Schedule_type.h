#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class Flight_Schedule  //flight schedule class for flight related data
{
    private:
        string date;
        string time;
        string city;
        string flight_code;

    public:
        Flight_Schedule(string date="", string time="" , string city="",string flight_code="");   //default+ parameterized constructor  
        //setters
        void set_date(string date);
        void set_time(string time);
        void set_city(string city);
        void set_flight_code(string flight_code);
        //getters
        string get_date() const;
        string get_time() const;
        string get_flight_code() const;     
};

class Flight_Type
{
        Flight_Schedule arrival; //composition of flight schedule done in this class---arrival and departure as data members
        Flight_Schedule departure; 

    public:
        Flight_Type(Flight_Schedule arrival, Flight_Schedule departure);
        void set_arrival(Flight_Schedule arrival);
        void set_departure(Flight_Schedule departure);
        Flight_Schedule get_arrival() const;
        Flight_Schedule get_departure() const;
        //adding flight info to a file
        void add_info(string flight_info, int type); 
        //deleting data from the file   
        void delete_info(int index , int type);
        // Update data in a file
        void update_info(int index,string new_flight_info , int type);
        //method to view the flight info
        void print_info() const;
};
