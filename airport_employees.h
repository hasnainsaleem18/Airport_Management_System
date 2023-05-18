//#include "employees.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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