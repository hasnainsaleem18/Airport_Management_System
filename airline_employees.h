//#include "employees.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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
