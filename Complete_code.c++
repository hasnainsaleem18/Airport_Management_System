
//header files 
#include <iostream>
#include <vector>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cstring>
#include <fstream>

using namespace std;

static const string static_password = "admin321";  //global constant initialized for administrator 

//structure
struct Airport_Details
{
    string name;
    string location;
    string history;
    string map;
};
//fucntions for Airport Details struct 
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

//Employee class used in Ploymorphism
class Employee
{   
    protected:
        int id;
        string name;
        double salary;
        string designation;
    public:
        Employee(); //default constructor
        Employee(int id, string name, double salary, string designation); //parameterized constructor 
        virtual ~Employee(); //destructor declared virtual
        //setters
        void set_id(int id);
        void set_name(string name);
        void set_salary(double salary);
        void set_designation(string designation);
        //getters
        int get_id() const;
        string get_name() const;
        double get_salary() const;
        string get_designation() const;
        //methods
        virtual void add_emp();
        virtual void remove_emp();
        virtual void update_emp();
        virtual void delete_data();
        virtual void print_data()const;     
};
//methods dfeined outside the class for good programming practice
Employee::Employee()
{
    id = 0;
    name = "";
    salary = 0.0;
    designation = "";
}
Employee::Employee(int id, string name, double salary, string designation)
{
    set_id(id);
    set_name(name);
    set_salary(salary);
    set_designation(designation);
}
Employee::~Employee()
{
    cout << "Employee destroyed!" << endl;
}
void Employee::set_id(int id)
{
    this->id = id;
}
void Employee::set_name(string name)
{
    this->name = name;
}
void Employee::set_salary(double salary)
{
    this->salary = salary;
}
void Employee::set_designation(string designation)
{
    this->designation = designation;
}
int Employee::get_id() const
{
    return id;
}
string Employee::get_name()const
{
    return name;
}
double Employee::get_salary()const
{
    return salary;
}
string Employee::get_designation()const
{
    return designation;
}
void Employee::add_emp() //methods to be overrided in inherited classes
{

}
void Employee::remove_emp()
{

}
void Employee::update_emp()
{

}
void Employee::delete_data() 
{

}
void Employee::print_data() const
{
            
}  

//Airline Employee is publically inherited from Employee 
class Airline_Employee: public Employee
{
    private: //private data members declared
       string company;
       int shift_hours; 
    public:
        Airline_Employee(); //default contructor 
        Airline_Employee(int id, string name, double salary, string designation, string company, int shift_hours); //parameterized constructor
        ~Airline_Employee(); //destructor
        //setters
        void set_company(string company);
        void set_shift_hours(int shift_hours);
        //getters
        string get_company()const;
        int get_shift_hours()const;
};
Airline_Employee::Airline_Employee()
{

}
Airline_Employee::Airline_Employee(int id, string name, double salary, string designation, string company, int shift_hours): Employee(id, name, salary, designation)
{
    this->company = company;
    this->shift_hours = shift_hours;
}
Airline_Employee::~Airline_Employee()
{
    cout << "Airline_Employee destroyed!" << endl;
}
void Airline_Employee::set_company(string company)
{
    this->company = company;
}
void Airline_Employee::set_shift_hours(int shift_hours)
{
    this->shift_hours = shift_hours;
}
string Airline_Employee::get_company()const
{
    return company;
}
int Airline_Employee::get_shift_hours()const
{
    return shift_hours;
}

//class for operations over Airline Employee
class Airline
{
    private:
        //vector of Airline Employee created
        vector<Airline_Employee> airline_emp;
    public:
        //overrided methods
        void add_emp(Airline_Employee emp);
        void remove_emp(int index);
        void update_emp(Airline_Employee emp,int index);
        void delete_data();
        void print_data() const;
};

void Airline::add_emp(Airline_Employee emp)  //adding  new employee to the vector of airline employee 
{
    airline_emp.push_back(emp);
    cout << "Employee data added successfully!" << endl;
}
void Airline::remove_emp(int index)  //removing an employee to the vector of airline employee 
{
    bool check = airline_emp.empty();
    if (check == true)
    {
        cout << "File is empty." << endl;
    }
    else
    {
        airline_emp.erase(airline_emp.begin() + (index-1));

        cout << "Employee data deleted successfully!" << endl;
    }
}

void Airline::update_emp(Airline_Employee emp,int index) //updating the details of an  exisitng employee
{
    bool check = airline_emp.empty();
    if (check == true)
    {
        cout<<"File is empty.No data to exchange."<<endl;
    }
    else
    {
        airline_emp.at(index-1) = emp;
        cout << "Employee data updated successfully!" << endl;
    }
}

void Airline::delete_data() //deleting the whole vector containing emoloyee details
{
    
    airline_emp.clear();
    cout << "File data cleared successfully!" << endl;
    
}
void Airline::print_data() const //method printing the employee data
{
    bool check = airline_emp.empty();
    if (check == true)
    {
        cout << "File is empty." << endl;
    }
    else
    {
        for(int i = 0; i != airline_emp.size(); i++)
        {
            cout << setfill('-') << setw(50) << "-" << endl;
            cout << setfill(' ') << setw(25) << "INDEX " << i + 1 << endl;
            cout << setfill('-') << setw(50) << '-'  << endl;
            cout << "ID: " << airline_emp[i].get_id() << endl;
            cout << "Name: " << airline_emp[i].get_name() << endl;
            cout << "Salary: " << airline_emp[i].get_salary() << endl;
            cout << "Designation: " << airline_emp[i].get_designation() << endl;
            cout << "Company: " << airline_emp[i].get_company() << endl;
            cout << "Shift Hours: " << airline_emp[i].get_shift_hours() << endl << endl;
        }
    }
}

//Airport employee publically inherited by employee
class Airport_Employee: public Employee
{                              
    protected: //protected data members 
       string department;
    public:
        Airport_Employee();
        Airport_Employee(int id, string name, double salary, string designation, string department);
        ~Airport_Employee();
        void set_department(string department);
        string get_department() const;
};
Airport_Employee::Airport_Employee()
{

}
Airport_Employee::Airport_Employee(int id, string name, double salary, string designation, string department): Employee(id, name, salary, designation)
{
    this->department=department;
}
Airport_Employee::~Airport_Employee()
{
    cout << "Airport_Employee destroyed!" << endl;
}
void Airport_Employee::set_department(string department)
{
    this->department = department;
}
string Airport_Employee::get_department() const
{
    return department;
}

//classes performing operations on Airport Employees
class Airport
{
    private:
        vector<Airport_Employee> airport_emp;
    public:
    //overrided methods
        void add_emp(Airport_Employee emp);
        void remove_emp(int index);
        void update_emp(Airport_Employee emp,int index);
        void delete_data();
        void print_data()const;
};
void Airport::add_emp(Airport_Employee emp) //adding  new employee data into the employee's vectors
{
    airport_emp.push_back(emp);
    cout << "Employee data added successfully!" << endl;
}
void Airport::remove_emp(int index) //removing employee data from vector
{ 
    bool check = airport_emp.empty();
    if (check == true)
    {
        cout << "File is empty." << endl;
    }
    else
    {
        airport_emp.erase(airport_emp.begin() + (index-1));

        cout << "Employee data deleted successfully!" << endl;
    }
}
void Airport::update_emp(Airport_Employee emp,int index) //updating the existing employee's data in the vector
{
    bool check = airport_emp.empty();
    if (check == true)
    {
        cout << "File is empty.No data to exchange." << endl;
    }
    else
    {
        airport_emp.at( index-1 ) = emp;
        cout << "Employee data updated successfully!" << endl;
    }
}
void Airport::delete_data() //deleting the whole vector containing employees data
{   
    airport_emp.clear();
    cout << "File data cleared successfully!" << endl;    
}
void Airport::print_data()const  //printing the vector 
{
    bool check = airport_emp.empty();
    if (check == true)
    {
        cout << "File is empty." << endl;
    }
    else
    {
        cout << "Airport Employee File opened: "<< endl << endl;    
        cout << left << setw(5) << "Index" 
                << right << setw(15) << "Id" 
                << setw(15) << right << "Name"
                << setw(15) << right << "salary" 
                << setw(20) << right << "Designation" 
                << setw(15) << right << "Department" << endl;
cout << "-------------------------------------------------------------------------------------------------------"<<endl;     

        for(int i=0;i!=airport_emp.size();i++)
        {                   
            cout << right << setw(5) << i + 1 << "." 
                    << right << setw(15) << airport_emp[i].get_id()
                    << setw(22) << airport_emp[i].get_name()
                    << setw(5) << "RS-" << left << fixed << setprecision(2) << airport_emp[i].get_salary()
                    << left <<setw(20) << airport_emp[i].get_designation()
                    << setw(10) << right << airport_emp[i].get_department() << endl;          
        }
    }
}
//ticket booking class to book the ticket for the passenger 
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

//passenger class used by adminsitrator  for booking related operations
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
        cout << "Error opening file!" << endl;
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

    cout << "TICKET BOOKED SUCCESSFULLY!" << endl;
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
    cout << "INVALID ID" << endl;
}
void Passenger::update_ticket(int id)   //updating the booked tikcet details for passenger
{
    string new_seat_type;
    int count = 0;

    for(int i=0; i < size; i++)
    {
        if (tickets[i].get_passport_id() == id) //if condition to check whether the provided passport id is present in the  array containing booked ticket details
        {
            cout << "Enter new seat type: " << endl;
            getline(cin>>ws, new_seat_type);    //getting the updated details from the user
            tickets[i].set_seat_type(new_seat_type);  //assigning the updated data
            cout << "SEAT TYPE UPDATED SUCCESSFULLY!" << endl;
            count++;
        }    
    }
    if(count == 0)
    {
        cout << "TICKET NOT FOUND!" << endl;
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
Flight_Schedule::Flight_Schedule(string date, string time, string city, string flight_code)
{
    set_date(date);
    set_time(time);
    set_city(city);
    set_flight_code(flight_code);
}    
void Flight_Schedule::set_date(string date)
{
    this->date=date;
}
void Flight_Schedule::set_time(string time)
{
    this->time=time;
}
void Flight_Schedule::set_city(string city)
{
    this->city=city;    
}
void Flight_Schedule::set_flight_code(string flight_code)
{
    this->flight_code=flight_code;
}
string Flight_Schedule::get_date() const
{
    return date;
}
string Flight_Schedule::get_time() const
{
    return time;
}
string Flight_Schedule::get_flight_code() const
{
    return flight_code;
} 

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
Flight_Type::Flight_Type(Flight_Schedule arrival, Flight_Schedule departure): arrival(arrival), departure(departure)
{
    
}
void Flight_Type::set_arrival(Flight_Schedule arrival)
{
    this->arrival = arrival;
}
void Flight_Type::set_departure(Flight_Schedule departure)
{
    this->departure = departure;
}
Flight_Schedule Flight_Type::get_arrival() const
{
    return arrival;
}
Flight_Schedule Flight_Type::get_departure() const
{
    return departure;
}
//adding flight info to a file via file handling
void Flight_Type::add_info(string flight_info, int type)  
{
    if(type == 1)
    {
        ofstream ofile;    
        ofile.open("International.txt", ios::app);   //file opened in append mode for writing into the file
        if (ofile.is_open())
        {
            ofile << flight_info << endl;
            cout << "Flight information added successfully." << endl;
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
        ofile.close();       
    }
    else if( type == 2 )
    {
        ofstream ofile;
        ofile.open("Domestic.txt", ios::app);  //file opened in appened mode for writing into the file
        if (ofile.is_open())
        {
            ofile << flight_info << endl;
            cout << "Flight information added successfully." << endl;
        }
        else
        {
            cout << "Error opening file!" << endl;
        }
        ofile.close();   
    }
    else
    {
        cout << "Invalid input!" <<endl;
    }
} 
//deleting data from the file   
void Flight_Type::delete_info(int index , int type)
{   
    if (type == 1)
    {
        ifstream ifile("International.txt");    //opening input file in append mode in order to update the file
        if (!ifile)
        {
            cout << "Error opening file!" << endl;
            return;
        }

        ofstream temp("temp.txt");   //creating  new  output temp file for copying the updated code (wihtout the deleted data) 
        string line;
        int current_index = 1;
        bool found = false;

        while (getline(ifile, line))
        {
            if (current_index != index)  //if data to be deleted not found in the current place , print it into the temp file created
            {
                temp << line << endl;
            }
            else
            {
                found = true;   //data to be deleted found , update variable "found"
            }
            current_index++;
        }

        ifile.close();  //Input file closed
        temp.close();    //output file closed

        remove("International.txt");   //delete the file
        rename("temp.txt", "International.txt");  //renaming the temp file

        if (found)
        {
            cout << "Flight information deleted successfully." << endl;
        }
        else
        {
            cout << "Flight information not found." << endl;
        }
    }
    else if ( type == 2)
    {
        ifstream ifile("Domestic.txt");
        if (!ifile)
        {
            cout << "Error opening file!" << endl;
            return;
        }

        ofstream temp("temp.txt");
        string line;
        int current_index = 1;
        bool found = false;

        while (getline(ifile, line))
        {
            if (current_index != index)
            {
                temp << line << endl;
            }
            else
            {
                found = true;
            }
            current_index++;
        }

        ifile.close();
        temp.close();

        remove("Domestic.txt");
        rename("temp.txt", "Domestic.txt");

        if (found)
        {
            cout << "Flight information deleted successfully." << endl;
        }
        else
        {
            cout << "Flight information not found." << endl;
        }
    }
    else
    {
        cout << "Invalid input!" << endl;
    }
}
// Update data in a file
void Flight_Type::update_info(int index,string new_flight_info , int type)
{
    if (type == 1)
    {
        ifstream ifile("International.txt");
        if (!ifile)
        {
            cout << "Error opening file!." << endl;
            return;
        }

        ofstream temp("temp.txt");
        string line;
        int current_index = 1;
        bool found = false;

        while (getline(ifile, line))
        {
            if (current_index != index)  //if index doesnt match , copy same data
            {
                temp << line << endl;
            }
            else
            {
                temp << new_flight_info << endl;  //if index found , update the data at that index
                found = true;
            }
            current_index++;

                    // Break the loop if the end of the file is reached
            if (ifile.eof())  //comes out of loop if end of file reached
            {
                break;
            }
        }

        ifile.close();
        temp.close();

        remove("International.txt"); //delete file
        rename("temp.txt", "International.txt"); //renaming the temp file

        if (found)
        {
            cout << "Flight information updated successfully." << endl;
        }
        else
        {
            cout << "Flight information not found." << endl;
        }
    }
    else if (type == 2)
    {
            ifstream ifile("Domestic.txt");
            if (!ifile)
            {
                cout << "Error opening file!" << endl;
                return;
            }
            ofstream temp("temp.txt");
            string line;
            int current_index = 1;
            bool found = false;

            while (getline(ifile, line))
            {
                if (current_index != index)
                {
                    temp << line << endl;
                }
                else
                {
                    temp << new_flight_info << endl;
                    found = true;
                }
                current_index++;

                // Break the loop if the end of the file is reached
                if (ifile.eof())
                {
                    break;
                }
            }

            ifile.close();
            temp.close();

            remove("Domestic.txt");
            rename("temp.txt", "Domestic.txt");

            if (found)
            {
                cout << "Flight information updated successfully." << endl;
            }
            else
            {
                cout << "Flight information not found." << endl;
            }
    }
    else
    {
        cout << "Invalid input!" << endl;
    }
        

}
//method to view the flight info
void Flight_Type::print_info() const
{
    int option;

    cout << "Do you want to view:\n 1.International Flights\n 2.Domestic Flight? " << endl;
    cin >> option;

    if (option == 1)
    {
        ifstream ifile("International.txt");
        if (!ifile)
        {
            cout << "Error opening file!" << endl;
            return;
        }

        string line;
        int index = 1;
        cout << "International Flights:" << endl;

        while (getline(ifile, line))
        {
            cout << index << ". " << line << endl;  //printing the data from the file
            index++;

            // Break the loop if the end of the file is reached
            if (ifile.eof())
            {
                break;
            }
        }

        ifile.close();
    }
    else if (option == 2)
    {
        ifstream ifile("Domestic.txt");
        if (!ifile)
        {
            cout << "Error opening file!" << endl;
            return;
        }

        string line;
        int index = 1;
        cout << "Domestic Flights:" << endl;

        while (getline(ifile, line))
        {
            cout << index << ". " << line << endl;  //printing the data from the file 
            index++;
            
            // Break the loop if the end of the file is reached
            if (ifile.eof())
            {
                break;
            }
            
        }

        ifile.close(); //closing input file
    }
}

// standout function  for recording the feedback of user
void feedback()
{
    string line;
    fstream fout;
    ifstream fin;

    fout.open("feedback.txt", ios::app); //out file created
    cout << "Enter your Feedback: ";
    getline(cin >> ws, line);  //taking the input into the file
    fout << line << endl;
    cout << "Thank You for your Feedback!" << endl;
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
        cout << endl << "Airport Management System" << endl << endl;
        cout << "1. Airport Details" << endl;
        cout << "2. Administrator" << endl;
        cout << "3. Passenger" << endl;
        cout << "4. Feedback" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1)
        {
            Airport_Details d;
            details(d);
        }
        else if(choice == 2)
        {
            cout << "Give PASSWORD to login: ";  //checking credability for administrative tasks
            getline(cin>>ws, password);

            if (password == static_password)
            {
                cout << "choose\n 1. Airline Employee File\n 2. Airport Employees File\n 3. Ticket Booking\n 4. Flight Details\n 5. Exit" << endl;
                cin >> choice;
                
                if(choice == 1)
                {
                    Airline airline_data;
                    
                    while (option != 6)
                    {
                        cout << "\nAirline Employee Data: "<<endl;
                        cout << "Menu:"<<endl
                            << "1) Add  new Employee data "<<endl
                            << "2) Remove Employee data"<<endl
                            << "3) Update Employee data"<<endl
                            << "4) Delete file"<<endl
                            << "5) View data"<<endl
                            << "6) Exit"<<endl;
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
                                
                                cout << "Enter employee ID: ";
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
                                cout << "Enter the index of the employee you want to remove: ";
                                cin  >> index;
                                airline_data.remove_emp(index);  //removing the specified data
                                break;
                            }
                            case 3:
                            {

                                int index;
                                cout << "Enter the index at which you want the employee data to be updated: ";
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
                                 << "6) Exit"<<endl;
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
                                        cout << "Airline ID already exists. Please enter a unique ID." << endl;
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
                        cout << "7.  Exit" << endl;
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
                                cout << "Passenger ID already exists. Please enter a unique ID." << endl;
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
                            cout << "3. Economy Class" << endl;
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
                            << "5.Exit " <<endl;

                        cin >> choice;

                        switch(choice)
                        {
                            case 1:
                            {
                                int option;

                                cout << "Do you want to add in:\n 1.International Flights\n 2.Domestic Flight? "<< endl;
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

                                cout << "Do you want to delete from:\n 1.International Flights\n 2.Domestic Flight? " << endl;
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

                                cout << "Do you want to delete from:\n 1.International Flights\n 2.Domestic Flight? " << endl;
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
            }
            else 
            {
                cout << "Password is wrong! enter correct one." << endl;
            }
        }
        else if(choice == 3)
        {
            cout << "choose\n 1. Ticket Booking\n 2.  View Flight Details 3. Exit" << endl;
            cin >> choice; 

            if(choice == 1)
            {
                cout << "go to ticket booth or administrator" << endl;
            }
            else if(choice == 2)
            {
                flight.print_info();
            }
            else
            break;
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