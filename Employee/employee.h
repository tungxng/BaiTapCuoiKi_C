#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#pragma once
#include <string>

using namespace std;
class Employee
{
    private:
        string id;
        string name;
        string dateofbirth;
        string adress;
        string department;
        string date;
        string status;
    public:
        Employee();
        Employee(string id, string name, string dateofbirth, string adress, string department,string date,string status);

        void setId(string id);
        void setName(string name);
        void setdateofbirth(string dateofbirth);
        void setAdress(string adress);
        void setdepartment(string department);
        void setDate(string date);
        void setStatus(string status);

        string getId();
        string getName();
        string getdateofbirth();
        string getAdress();
        string getdepartment();
        string getDate();
        string getStatus();
};


Employee searchEmployee(string file, string id);
int validateDate(string dateofbirth);
int checkId(string file, string id);
void writeFileTxt(string file);
int checkDate(string file,string id,string date);
int checkDating(string date);
void print(Employee e);
void inputAttendance(string file);
void pressAnyKey();
void importCSV();
void searchName(string file,string name);
void readCSV(string file);
Employee searchAttendance(string file, string id);
#endif // EMPLOYEE_H
