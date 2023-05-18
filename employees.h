//#ifndef EMPLOYEES_H
//#define EMPLOYEES_H
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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

//#endif