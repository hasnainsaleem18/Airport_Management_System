#ifndef AIRLINE_EMPLOYEES_H
#define AIRLINE_EMPLOYEES_H
#include "employees.h"
#include "airline_employees.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>

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


void Airline::add_emp(Airline_Employee emp)  //adding  new employee to the vector of airline employee 
{
    airline_emp.push_back(emp);
    cout << endl << "Employee data added successfully!" << endl << endl;
}
void Airline::remove_emp(int index)  //removing an employee to the vector of airline employee 
{
    bool check = airline_emp.empty();
    if (check == true)
    {
        cout << endl << "File is empty." << endl << endl;
    }
    else
    {
        airline_emp.erase(airline_emp.begin() + (index-1));

        cout << endl << "Employee data deleted successfully!" << endl << endl;
    }
}

void Airline::update_emp(Airline_Employee emp,int index) //updating the details of an  exisitng employee
{
    bool check = airline_emp.empty();
    if (check == true)
    {
        cout << endl << "File is empty.No data to exchange."<< endl << endl;
    }
    else
    {
        airline_emp.at(index-1) = emp;
        cout << endl << "Employee data updated successfully!" << endl << endl;
    }
}

void Airline::delete_data() //deleting the whole vector containing emoloyee details
{
    
    airline_emp.clear();
    cout << endl << "File data cleared successfully!" << endl << endl;
    
}
void Airline::print_data() const //method printing the employee data
{
    bool check = airline_emp.empty();
    if (check == true)
    {
        cout << endl << "File is empty." << endl << endl;
    }
    else
    {
        for(int i = 0; i != airline_emp.size(); i++)
        {
            cout << endl;
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

#endif