#include "flight_Schedule_type.h"
#include <iostream>
#include <string>
#include <fstream>

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
            cout << endl <<  "Flight information added successfully." << endl << endl;
        }
        else
        {
            cout << endl << "Error opening file!" << endl << endl;
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
            cout << endl << "Flight information added successfully." << endl << endl;
        }
        else
        {
            cout << endl << "Error opening file!" << endl << endl;
        }
        ofile.close();   
    }
    else
    {
        cout << endl << "Invalid input!" << endl << endl;
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
            cout << endl << "Error opening file!" << endl << endl;
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
            cout << endl << "Flight information deleted successfully." << endl << endl;
        }
        else
        {
            cout << endl << "Flight information not found." << endl << endl;
        }
    }
    else if (type == 2)
    {
        ifstream ifile("Domestic.txt");
        if (!ifile)
        {
            cout << endl << "Error opening file!" << endl << endl;
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
            cout << endl << "Flight information deleted successfully." << endl << endl;
        }
        else
        {
            cout << endl << "Flight information not found." << endl << endl;
        }
    }
    else
    {
        cout << endl << "Invalid input!" << endl << endl;
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
            cout << endl << "Error opening file!." << endl << endl;
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
            cout << endl << "Flight information updated successfully." << endl << endl;
        }
        else
        {
            cout << endl << "Flight information not found." << endl << endl;
        }
    }
    else if (type == 2)
    {
            ifstream ifile("Domestic.txt");
            if (!ifile)
            {
                cout << endl << "Error opening file!" << endl << endl;
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
                cout << endl << "Flight information updated successfully." << endl << endl;
            }
            else
            {
                cout << endl  << "Flight information not found." << endl << endl;
            }
    }
    else
    {
        cout << endl << "Invalid input!" << endl << endl;
    }
        

}
//method to view the flight info
void Flight_Type::print_info() const
{
    int option;

    cout << endl << "Which you want to view:\n 1. International Flights\n 2. Domestic Flight " << endl << endl;
    cout << "Please enter your choice: ";
    cin >> option;

    if (option == 1)
    {
        ifstream ifile("International.txt");
        if (!ifile)
        {
            cout << endl << "Error opening file!" << endl << endl;
            return;
        }

        string line;
        int index = 1;
        cout << endl << "International Flights:" << endl << endl;

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
            cout << endl << "Error opening file!" << endl << endl;
            return;
        }

        string line;
        int index = 1;
        cout << endl << "Domestic Flights:" << endl << endl;

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
