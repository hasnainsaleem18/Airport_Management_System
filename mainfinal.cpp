//header files
#include "employees.h"
#include "flight_Schedule_type.h"
#include "airline_employees.h"
#include "airport_employees.h"
#include "ticket_booking.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

static const string admin_code = "admin321";  //global constant initialized for administrator 

//structure
struct Airport_Details
{
    string name;
    string location;
    string history;
    string map;
};
//functions for Airport Details struct 
//functions declared
void details(Airport_Details d);
void display_map();
void feedback();
//functions definition
void details(Airport_Details d) //data hard coded
{
    d.name = " Solara International Airport ";
    d.history = " Solara International Airport, named after the fictional city of Solara, was inaugurated on September 15, 1990. The airport was conceptualized as a modern transportation hub to cater to the growing demands of air travel in the region. ";
    d.location = " Solara International Airport is located on the picturesque island of Veridian, nestled in the midst of the Elysian Ocean. ";

    cout << "Airport Name: " << d.name << endl;
    cout << "Airport Location: " << d.location << endl;
    cout << "Airport History: " << d.history << endl;
    cout << "Airport Map " <<  endl << endl;
    display_map();
}

//printing map of the   Airport
void display_map()
{
    cout << "           +----------------------------------------------------++-------------------------------------------------------+\n";
    cout << "           |                                                    ||                                                       |\n";
    cout << "     +-----+--------------+------------------+-----------------+ +----+------------------------+------------------------+----+\n";
    cout << "     |     |              |                  |                 | |                              |                               |\n";
    cout << "     |     |              |                  |                 | |          Terminal 1          |           Terminal 2          |\n";
    cout << "     |     |     Lobby    |     Concourse    |   Facilities    | |                              |                               |\n";
    cout << "     |     |              |                  |                 | |                              |                               |\n";
    cout << "     |     |              |                  |                 | |   +-------------------+      |      +-------------------+   |\n";
    cout << "     +-----+--------------+------------------+-----------------+ |   |                   |      |      |                   |   |\n";
    cout << "     |     |              |                  |                 | +---|      Gate A1      |------+------|      Gate B1      |---+\n";
    cout << "     |     |              |                  |                 | |   |                   |      |      |                   |   |\n";
    cout << "     |     |   Lobby      |     Concourse    |   Facilities    | |   +-------------------+      |      +-------------------+   |\n";
    cout << "     |     |              |                  |                 | |                            |                                |\n";
    cout << "     |     |              |                  |                 | |                            |                                |\n";
    cout << "     +-----+--------------+------------------+-----------------+ |   +-------------------+    |    +-------------------+      |\n";
    cout << "           |              |                  |                 | |   |                   |    |    |                   |      |\n";
    cout << "           |              |                  |                 | +---|      Gate A2      |----+----|      Gate B2      |------+\n";
    cout << "           |   Lobby      |     Concourse    |   Facilities    | |   |                   |    |    |                   |      |\n";
    cout << "           |              |                  |                 | |   +-------------------+    |    +-------------------+      |\n";
    cout << "           |              |                  |                 | |                            |                                |\n";
    cout << "           |              |                  |                 | |                            |                                |\n";
    cout << "           +--------------+------------------+-----------------+ |   +-------------------+    |    +-------------------+      |\n";
    cout << "                           |                  |                 | |   |                   |    |    |                   |      |\n";
    cout << "                           |                  |                 | +---|      Gate A3      |----+----|      Gate B3      |------+\n";
    cout << "                           |     Concourse    |   Facilities    | |   |                   |    |    |                   |      |\n";
    cout << "                           |                  |                 | |   |                   |    |    |                   |      |\n";
    cout << "            +--------------+------------------+-----------------+ |   +-------------------+    |    +-------------------+      |\n";

}

void feedback()
{
    string line;
    fstream fout;
    ifstream fin;

    fout.open("feedback.txt", ios::app); //out file created
    cout << "Enter your Feedback: ";
    getline(cin >> ws, line);  //taking the input into the file
    fout << line << endl;
    cout << endl << "Thank You for your Feedback!" << endl << endl;
    fout.close();
}

int main()
{   
    vector<int> used_passenger_ids; //vector array of passenger id 
    vector<int> used_airline_ids;   //vector array of airline employee id
    vector<int> used_airport_ids;   // vector array of airport employee

    Passenger passenger;     

    Flight_Schedule arrival1("2023-05-15", "09:00", "New York", "AB123");   //constructor of flight schedule called for arrival 
    Flight_Schedule departure1("2023-05-15", "12:00", "London", "CD456");    //constructor of flight schedule called for departure
    Flight_Type flight(arrival1, departure1);  //passing arrival and departure to flight_type class

    string departure;
    string arrival;
    string seat_type;
    string passenger_name;
    string password;

    int passport_id;

    //menu drive options
    int choice;
    int option; 
    
    while (1)
    {
        //main menu
        cout << endl << "****** Airport Management System ******" << endl << endl;
        cout << "1. Airport Details" << endl;
        cout << "2. Administrator" << endl;
        cout << "3. Passenger" << endl;
        cout << "4. Feedback" << endl;
        cout << "5. Exit" << endl << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Airport_Details d;
            details(d);
        }
        else if(choice == 2)
        {
            cout << endl << "Give PASSWORD to login: ";  //checking credability for administrative tasks
            getline(cin>>ws, password);

            if (password == admin_code)
            {
                while (choice != 5)
                {
                    cout << "Login Successful" << endl << endl;
                    cout << "*** Menu ***\n\n 1. Airline Employee\n 2. Airport Employees\n 3. Ticket Booking\n 4. Flight Details\n 5. Exit" << endl << endl;
                    cout << "Please enter your choice: ";
                    cin >> choice;
                    
                    if(choice == 1)
                    {
                        Airline airline_data;
                        
                        while (option != 6)
                        {
                            cout << "\n1) Airline Employee Data "<< endl << endl;
                            cout << "*** Menu ***"<< endl << endl
                                << "1) Add  new Employee data "<< endl
                                << "2) Remove Employee data"<< endl
                                << "3) Update Employee data"<< endl
                                << "4) Delete file"<< endl
                                << "5) View data"<< endl
                                << "6) Exit"<< endl << endl;
                            cout << "Please enter your choice: ";
                            cin  >> option;  

                            switch(option)
                            {
                                case 1:
                                {
                                    Airline_Employee emp;
                                    int id;
                                    string name;
                                    double salary;
                                    string designation;
                                    string company;
                                    int shift_hours; 
                                    
                                    cout << endl << "Enter employee ID: ";
                                    cin >> id;
                                    emp.set_id(id);

                                    bool isAirlineIdUsed = false;
                                    for (int i = 0; i < used_airline_ids.size(); i++) //loop for checking whether the  airline employee id exist already or not
                                    {
                                        if (used_airline_ids[i] == id)
                                        {
                                            isAirlineIdUsed = true;
                                            break;
                                        }
                                    }

                                    if (isAirlineIdUsed)
                                    {
                                        cout << "Airline ID already exists. Please enter a unique ID." << endl;
                                        continue;
                                    }

                                    used_airline_ids.push_back(id);  //giving data to  the vector 

                                    cout << "Enter employee name: ";
                                    getline(cin >> ws , name);
                                    emp.set_name(name);

                                    cout << "Enter employee salary: ";
                                    cin >> salary;
                                    emp.set_salary(salary);

                                    cout << "Enter employee designation: ";
                                    getline( cin >> ws , designation);
                                    emp.set_designation( designation);

                                    cout << "Enter employee company: ";
                                    getline( cin >> ws , company);
                                    emp.set_company(company);

                                    cout << "Enter employee shift hours: ";
                                    cin >> shift_hours;
                                    emp.set_shift_hours(shift_hours);

                                    airline_data.add_emp(emp);  //adding the employee data 
                                    break; 

                                }
                                case 2:
                                {
                                    int index;
                                    cout << endl << "Enter the index of the employee you want to remove: ";
                                    cin  >> index;
                                    airline_data.remove_emp(index);  //removing the specified data
                                    break;
                                }
                                case 3:
                                {

                                    int index;
                                    cout << endl << "Enter the index at which you want the employee data to be updated: ";
                                    cin  >> index;

                                    //updating the index with new emp's info
                                    Airline_Employee emp;
                                    int id;
                                    string name;
                                    double salary;
                                    string designation;
                                    string company;
                                    int shift_hours; 

                                    cout<< "Enter the updated data: "<<endl;
                                    cout << "Enter employee ID: ";
                                    cin >> id;
                                    emp.set_id(id);

                                    cout << "Enter employee name: ";
                                    getline( cin >> ws , name );
                                    emp.set_name(name);

                                    cout << "Enter employee salary: ";
                                    cin >> salary;
                                    emp.set_salary(salary);

                                    cout << "Enter employee designation: ";
                                    cin >> designation;
                                    emp.set_designation(designation);

                                    cout << "Enter employee company: ";
                                    cin >> company;
                                    emp.set_company(company);

                                    cout << "Enter employee shift hours: ";
                                    cin >> shift_hours;
                                    emp.set_shift_hours(shift_hours);

                                    airline_data.update_emp(emp, index);

                                    break;

                                }    
                                case 4:
                                {
                                    airline_data.delete_data();
                                    break;
                                }
                                case 5:
                                {
                                    airline_data.print_data();
                                    break;
                                }  
                            } 
                        }  
                    }
                    else if(choice == 2)
                    {
                        Airport airport_data;
                        
                        while ( option!=6 )
                        {

                            cout << "\nAirport Employee Data: "<<endl;
                            cout << "Menu:"<<endl
                                << "1) Add  new Employee data "<<endl
                                << "2) Remove Employee data"<<endl
                                << "3) Update Employee data"<<endl
                                << "4) Delete file"<<endl
                                << "5) View data"<<endl
                                << "6) Exit"<<endl << endl;
                            cout << "Please enter your choice: ";
                            cin  >> option;  

                            switch(option)
                            {
                                case 1:
                                {
                                    Airport_Employee emp;
                                    int id;
                                    string name;
                                    double salary;
                                    string designation;
                                    string department;
                                    
                                    cout << "Enter employee ID: ";
                                    cin >> id;
                                    emp.set_id(id);

                                    bool isAirportIdUsed = false;
                                    for (int i = 0; i < used_airport_ids.size(); i++) 
                                    {
                                        if (used_airport_ids[i] == id)
                                        {
                                            isAirportIdUsed = true;
                                            break;
                                        }
                                    }

                                    if (isAirportIdUsed)
                                    {
                                        cout << endl << "Airline ID already exists. Please enter a unique ID." << endl << endl;
                                        continue;
                                    }

                                    used_airport_ids.push_back(id);

                                    cout << "Enter employee name: ";
                                    getline(cin >> ws , name);
                                    emp.set_name(name);

                                    cout << "Enter employee salary: ";
                                    cin >> salary;
                                    emp.set_salary(salary);

                                    cout << "Enter employee designation: ";
                                    getline(cin >> ws , designation);
                                    emp.set_designation(designation);

                                    cout << "Enter employee company: ";
                                    getline(cin >> ws , department);
                                    emp.set_department(department);

                                    airport_data.add_emp(emp);
                                    break;

                                }
                                case 2:
                                {
                                    int index;
                                    cout << "Enter the index of the employee you want to remove: ";
                                    cin  >> index;
                                    airport_data.remove_emp(index);
                                    break;
                                }
                                case 3:
                                {

                                    int index;
                                    cout << "Enter the index at which you want the employee data to be updated: ";
                                    cin  >> index;

                                    //updating the index with new emp's info
                                    Airport_Employee emp;
                                    int id;
                                    string name;
                                    double salary;
                                    string designation;
                                    string department;
                            
                                    cout<< "Enter the updated data: "<<endl;
                                    cout << "Enter employee ID: ";
                                    cin >> id;
                                    emp.set_id(id);

                                    cout << "Enter employee name: ";
                                    getline(cin >> ws , name);
                                    emp.set_name(name);

                                    cout << "Enter employee salary: ";
                                    cin >> salary;
                                    emp.set_salary(salary);

                                    cout << "Enter employee designation: ";
                                    cin >> designation;
                                    emp.set_designation(designation);

                                    cout << "Enter employee company: ";
                                    cin >> department;
                                    emp.set_department(department);

                                    airport_data.update_emp(emp , index);

                                    break;

                                }    
                                case 4:
                                {
                                    airport_data.delete_data();
                                    break;
                                }
                                case 5:
                                {
                                    airport_data.print_data();

                                    break;
                                }        
                            }
                        }  
                    }
                    else if(choice == 3)
                    {
                        for (int i;;)
                        {
                            cout << endl << "FLIGHT BOOKING" << endl << endl;
                            cout << "1.  Book Ticket" << endl;
                            cout << "2.  Delete Ticket" << endl;
                            cout << "3.  Update Ticket" << endl;
                            cout << "4.  Search Ticket" << endl;
                            cout << "5.  Backup Tickets" << endl;
                            cout << "6.  Show all Tickets" << endl;
                            cout << "7.  Exit" << endl << endl;
                            cout << "Enter your choice: ";
                            cin >> choice;

                            if (choice == 1)
                            {
                                cout << endl << "Enter your Passport ID: ";
                                cin >> passport_id;

                                bool isPassengerIdUsed = false;
                                for (int i = 0; i < used_passenger_ids.size(); i++)
                                {
                                    if (used_passenger_ids[i] == passport_id)
                                    {
                                        isPassengerIdUsed = true;
                                        break;
                                    }
                                }

                                if (isPassengerIdUsed)
                                {
                                    cout << endl << "Passenger ID already exists. Please enter a unique ID." << endl << endl;
                                    continue;
                                }

                                used_passenger_ids.push_back(passport_id);

                                cout << "Enter your Passenger Name: ";
                                getline(cin>>ws, passenger_name);

                                cout << "Enter Arrival city: ";
                                getline(cin>>ws, arrival);

                                cout << "Enter departure city: ";
                                getline(cin>>ws, departure);

                                cout << "Enter Seat Type with full class name: " << endl;
                                cout << "1. First Class" << endl;
                                cout << "2. Business Class" << endl;
                                cout << "3. Economy Class" << endl << endl;
                                cout << "Please enter your choice: ";
                                getline(cin>>ws, seat_type);
                                cout << endl;

                                Ticket_Booking Flight(passport_id ,passenger_name, arrival, departure, seat_type); //constructor called
                                passenger.book_ticket(&Flight);
                                
                            }
                            else if (choice == 2)
                            {
                                cout << "Enter Passenger ID: " << endl;
                                cin >> passport_id;
                                passenger.delete_ticket(passport_id);
                            }
                            else if (choice == 3)
                            {
                                cout << "Enter Passenger ID: " << endl;
                                cin >> passport_id;
                                passenger.update_ticket(passport_id);
                            }
                            else if (choice == 4)
                            {
                                cout << "Enter Passenger ID: " << endl;
                                cin >> passport_id;
                                passenger.search_ticket(passport_id);
                            }
                            else if (choice == 5)
                            {
                                passenger.backup_tickets(passenger);
                            }
                            else if (choice == 6)
                            {
                                passenger.print();
                            }
                            else 
                            break;
                        }
                    }
                    else if(choice == 4)
                    {
                        while(choice != 5)
                        {
                            cout << "Menu: "<<endl;
                            cout << "1.Add Flight Details " <<endl
                                << "2.Upgrade Flight Details " <<endl
                                << "3.Delete Flight Details " << endl
                                << "4.View Flight Details " <<endl
                                << "5.Exit " <<endl << endl;
                            cout << "Please enter your choice: ";
                            cin >> choice;

                            switch(choice)
                            {
                                case 1:
                                {
                                    int option;

                                    cout << "Do you want to add in:\n 1.International Flights\n 2.Domestic Flight? "<< endl << endl;
                                    cout << "Please enter your choice: ";
                                    cin >> option;
                                    
                                    string flight_info;
                                    cout << "Enter details you want to add using the syntax:" << endl
                                        << "Departure: date , time  ,city , flight code----------Arrival: date , time , city , flight code" << endl
                                        << "                                           (10 dashes)                                        " << endl;
                                    getline( cin >> ws, flight_info);
                                    flight.add_info(flight_info, option);   

                                    break;  
                            
                                }
                                case 2:
                                {
                                    int option;

                                    cout << "Do you want to delete from:\n 1.International Flights\n 2.Domestic Flight? " << endl << endl;
                                    cout << "Please enter your choice: ";
                                    cin >> option;

                                    //Read old_flight_info from file using index
                                    int index;
                                    cout << "Enter the index of the flight you want to update: ";
                                    cin >> index;

                                    string old_flight_info;
                                    string new_flight_info;

                                    cout << "Enter the new flight details using the syntax:" << endl
                                        << "Departure: date, time, city, flight code----------Arrival: date, time, city, flight code" << endl
                                        << "(10 dashes)" << endl;
                                    getline(cin >> ws, new_flight_info);
                                    flight.update_info(index, new_flight_info , option);

                                    break;

                                }
                                case 3:
                                {
                                    int option;

                                    cout << "Do you want to delete from:\n 1.International Flights\n 2.Domestic Flight? " << endl << endl;
                                    cout << "Please enter your choice: ";
                                    cin >> option;

                                    int index;
                                    cout << "Enter the index of the flight you want to delete: ";
                                    cin >> index;

                                    flight.delete_info(index, option);

                                    break; 
                                }
                                case 4:
                                {
                                    flight.print_info();
                                    break;
                                }    
                            } 
                        }  
                    }
                    else 
                    break; 
                }    
            }
            else 
            {
                cout << endl << "Password is wrong! enter correct one." << endl << endl;
            }
        }
        else if(choice == 3)
        {
            for(int i;;)
            {
                cout << endl << "*** Menu ***" << endl << endl;
                cout << "1. Ticket Booking\n2. View Flight Details\n3. Exit" << endl << endl;
                cout << "Please enter your choice: ";
                cin >> choice;

                if(choice == 1)
                {
                    cout << endl << "Go to Ticket Booth or Administrator" << endl << endl;
                }
                else if(choice == 2)
                {
                    flight.print_info();
                }
                else
                break;
            }
        }
        else if(choice == 4)
        {
            feedback();
        }
        else
        break;
    }    
    return 0;
}