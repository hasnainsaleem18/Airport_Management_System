#include "employees.h"
#include <iostream>
#include <vector>
#include <iomanip>
#include <cstring>

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