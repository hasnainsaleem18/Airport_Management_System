#ifndef AIRPORT_EMPLOYEES_H
#define AIRPORT_EMPLOYEES_H
#include "employees.h"
#include "airport_employees.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>

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


void Airport::add_emp(Airport_Employee emp) //adding  new employee data into the employee's vectors
{
    airport_emp.push_back(emp);
    cout << endl << "Employee data added successfully!" << endl << endl;
}
void Airport::remove_emp(int index) //removing employee data from vector
{ 
    bool check = airport_emp.empty();
    if (check == true)
    {
        cout << endl << "File is empty." << endl << endl;
    }
    else
    {
        airport_emp.erase(airport_emp.begin() + (index-1));

        cout << endl << "Employee data deleted successfully!" << endl << endl;
    }
}
void Airport::update_emp(Airport_Employee emp,int index) //updating the existing employee's data in the vector
{
    bool check = airport_emp.empty();
    if (check == true)
    {
        cout << endl << "File is empty.No data to exchange." << endl << endl;
    }
    else
    {
        airport_emp.at( index-1 ) = emp;
        cout << endl << "Employee data updated successfully!" << endl << endl;
    }
}
void Airport::delete_data() //deleting the whole vector containing employees data
{   
    airport_emp.clear();
    cout << endl << "File data cleared successfully!" << endl << endl;    
}
void Airport::print_data()const  //printing the vector 
{
    bool check = airport_emp.empty();
    if (check == true)
    {
        cout << endl << "File is empty." << endl << endl;
    }
    else
    {
        for(int i = 0; i != airport_emp.size(); i++)
        {
            cout << endl;
            cout << setfill('-') << setw(50) << "-" << endl;
            cout << setfill(' ') << setw(25) << "INDEX " << i + 1 << endl;
            cout << setfill('-') << setw(50) << '-'  << endl;
            cout << "ID: " << airport_emp[i].get_id() << endl;
            cout << "Name: " << airport_emp[i].get_name() << endl;
            cout << "Salary: " << airport_emp[i].get_salary() << endl;
            cout << "Designation: " << airport_emp[i].get_designation() << endl;
            cout << "Department: " << airport_emp[i].get_department() << endl << endl;
        }
    }
}

#endif