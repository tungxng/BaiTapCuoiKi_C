#include "employee.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include<conio.h>
Employee::Employee()
{
    id = "";
    name = "";
    dateofbirth = "";
    adress = "";
    department = "";
    date="";
    status="";
}

Employee::Employee(string id, string name, string dateofbirth, string adress, string department,string date,string status)
{
    this->id = id;
    this->name = name;
    this->dateofbirth = dateofbirth;
    this->adress = adress;
    this->department = department;
    this->date=date;
    this->status=status;
}

void Employee::setId(string id)
{
    this->id = id;
}
void Employee::setName(string name)
{
    this->name = name;
}
void Employee::setdateofbirth(string dateofbirth)
{
    this->dateofbirth = dateofbirth;
}
void Employee::setAdress(string adress)
{
    this->adress = adress;
}
void Employee::setdepartment(string department)
{
    this->department = department;
}
void Employee::setDate(string date)
{
    this->date = date;
}
void Employee::setStatus(string status)
{
    this->status = status;
}

string Employee::getId()
{
    return this->id;
}
string Employee::getdateofbirth()
{
    return this->dateofbirth;
}
string Employee::getAdress()
{
    return this->adress;
}
string Employee::getdepartment()
{
    return this->department;
}
string Employee::getName()
{
    return this->name;
}
string Employee::getDate()
{
    return this->date;
}
string Employee::getStatus()
{
    return this->status;
}


Employee searchEmployee(string file, string id)
{
    Employee e;
    string line;
    ifstream fileInput(file, ios::in);
    if (fileInput.is_open())
    {
        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                e.setId(id);
                getline(stm, token, ',');
                e.setName(token);
                getline(stm, token, ',');
                e.setdateofbirth(token);
                getline(stm, token, ',');
                e.setAdress(token);
                getline(stm, token, ',');
                e.setdepartment(token);
                getline(stm, token, ',');
                e.setDate(token);
                getline(stm, token, ',');
                e.setStatus(token);

            }

        }
        fileInput.close();
    }
    return e;
}
int validateDate(string dateofbirth)
{
    stringstream ss(dateofbirth);
    int day, month, year;

    ss >> day >> month >> year;

    if (year >= 1000 && year <= 3000)
    {
        if ((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 0 && day <= 31)
            return 1;
        else
            if (month == 4 || month == 6 || month == 9 || month == 11 && day > 0 && day <= 30)
                return 1;
            else
                if (month == 2)
                {
                    if ((year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) && day > 0 && day <= 29)
                    {
                        if (day > 0 && day <= 28)
                            return 1;
                        else
                            return 0;
                    }

                }
                else
                    return 0;
    }
    else
        return 0;
    return 0;
}

int checkId(string file, string id)
{
    string line;
    ifstream fileInput(file, ios::in);
    if (fileInput.is_open())
    {
        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                return 0;
            }

        }
        fileInput.close();
    }
    return 1;
}
int checkDate(string file,string id,string date){
    string line;
    ifstream fileInput(file, ios::in);
    Employee e;
    if (fileInput.is_open())
    {
        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                getline(stm, token, ',');
                if(token.compare(date)==0){
                    return 0;
                }
            }

        }
        fileInput.close();
    }
    return 1;
}
int checkDating(string date){
    stringstream ss(date);
    int day, month, year;
    int thisday, thismonth, thisyear;
    ss >> day >> month >> year;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    thisyear = 1900 + ltm->tm_year;
    thismonth =1 + ltm->tm_mon;
    thisday =ltm->tm_mday;
    if(year == thisyear && month==thismonth){
        if(day<=thisday){
            return 1;
        }
    }
    return 0;
}
int checkMonth(string date,int months){
    stringstream ss(date);
    int day, month, year;
    ss >> day >> month >> year;
    if(months == month){
        return  1;
    }
    return 0;
}
void writeFileTxt(string file)
{
    ofstream myfile(file, ios::app);
    if (myfile.is_open())
    {
        string id;
        string name, dateofbirth, adress, department;

        cout << "Nhap ma nhan vien (VD: 01): ";
        cin >> id;
        while (checkId(file, id) == 0) {
            cout << "Ma nhan vien bi trung, moi ban nhap lai:  \n";
            cout << "Nhap ma nhan vien: ";
            cin >> id;
        }

        cout << "Nhap ten: ";
        cin.ignore();
        getline(cin, name);

        cout << "Nhap ngay thang nam sinh: ";
        getline(cin, dateofbirth);
        while (validateDate(dateofbirth) == 0)
        {
            cout << "Ban chua nhap dung dinh dang ngay thang, VD: 14 5 1999 \n";
            cout << "Nhap ngay thang nam sinh: ";
            getline(cin, dateofbirth);
        }

        cout << "Nhap dia chi: ";
        getline(cin, adress);
        while (adress.empty())
        {
            cout << "Khong duoc bo trong dia chi \n";
            cout << "Moi ban nhap lai dia chi \n";
            getline(cin, adress);
        }

        cout << "Nhap bo phan cong tac: ";
        getline(cin, department);
        while (department.empty())
        {
            cout << "Khong duoc bo trong bo phan cong tac \n";
            cout << "Moi ban nhap lai bo phan cong tac \n";
            cin >> department;
        }
        cout << "-------------------------------------------------" << endl;
        myfile << id << "," << name << "," << dateofbirth << "," << adress << "," << department << endl;

        myfile.close();
    }
    else cout << "Khong the mo duoc file" << endl;

}



void print(Employee e)
{
    cout << "Ma NV: " << e.getId() << endl;
    cout << "Ten NV: " << e.getName() << endl;
    cout << "Ngay thang nam sinh: " << e.getdateofbirth() << endl;
    cout << "Dia chi: " << e.getAdress() << endl;
    cout << "Bo phan cong tac: " << e.getdepartment() << endl;
    cout << "Ngay di lam: " << e.getDate() << endl;
    cout << "Trang thai: " << e.getStatus() << endl;


}
int checkStatus(string status){
    if(status.compare("DL")==0||status.compare("DLNN")==0||status.compare("N")==0||status.compare("NP")==0){
        return 1;
    }
    return 0;
}
void inputAttendance(string file)
{
    ofstream myfile(file, ios::app);
    if (myfile.is_open())
    {
        string id;string date;string status;

        cout << "Nhap ma nhan vien (VD:ANLAB_1): ";
        cin >> id;
        while(checkId("ImportData.csv", id) == 1) {
            cout << "Ma nhan vien không ton tai, moi ban nhap lai:  \n";
            cout << "Nhap ma nhan vien: ";
            cin >> id;
        }
        cout << "Nhap ngay thang nam di lam: \n";
        while (validateDate(date) == 0)
        {
            getline(cin, date);
            while (checkDate("chamcong.txt",id,date)==0)
            {
                cout<<"Ngay nhap da ton tai,moi ban nhap lai \n";
                getline(cin, date);
                if(checkDating(date)==0){
                    cout<<"Ngay nhap khong hop le,moi ban nhap lai\n";
                    getline(cin, date);

                }
            }
        }

        cout << "Nhap trang thai : \n";
        getline(cin, status);
        while(checkStatus(status) == 0){
            cout << "Nhap lai trang thai : \n";
            getline(cin, status);
        }
        cout << "-------------------------------------------------" << endl;
        myfile << id << "," << date << "," << status << endl;

        myfile.close();


    }

}
Employee searchThang(string file,int month){
    Employee e[10000];
    Employee employee;
    ifstream inFile(file, ios::in);
    string line;
    int linenum = 0;
    while (getline (inFile, line))
    {
        istringstream linestream(line);
        string item;
        getline(linestream, item, ',');
        employee.setId(item);
        e[linenum].setId(item);
        getline(linestream, item, ',');
        employee.setDate(item);
        e[linenum].setDate(item);
        getline(linestream, item, ',');
        employee.setStatus(item);
        e[linenum].setStatus(item);
        if(checkMonth(e[linenum].getDate(),month)==1){
            cout<<e[linenum].getId()<<e[linenum].getDate()<<e[linenum].getStatus()<<"\n";
        }
        linenum++;

    }


}
Employee searchStatus(string file,string status){
    Employee e[10000];
    Employee employee;
    ifstream inFile(file, ios::in);
    string line;
    int linenum = 0;
    while (getline (inFile, line))
    {
        istringstream linestream(line);
        string item;
        getline(linestream, item, ',');
        employee.setId(item);
        e[linenum].setId(item);
        getline(linestream, item, ',');
        employee.setDate(item);
        e[linenum].setDate(item);
        getline(linestream, item, ',');
        employee.setStatus(item);
        e[linenum].setStatus(item);
        if(e[linenum].getStatus()==status){
            cout<<e[linenum].getId()<<e[linenum].getDate()<<e[linenum].getStatus()<<"\n";
        }
        linenum++;

    }


}
Employee searchAttendance(string file, string id)
{
    Employee e;
    Employee arr[10000];
    int couts=0;
    int dl=0;
    int dlnn=0;
    int n=0;
    int np =0;
    string line;
    ifstream fileInput2("ImportData.csv", ios::in);
    ifstream fileInput(file, ios::in);
    if (fileInput.is_open())
    {
        while (!fileInput.eof())
        {
            getline(fileInput, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                e.setId(id);
                getline(stm, token, ',');
                e.setDate(token);
                getline(stm, token, ',');
                e.setStatus(token);
                if(e.getStatus().compare("DL")==0){
                    dl++;
                }else if (e.getStatus().compare("DLNN")==0) {
                    dlnn++;
                }else if (e.getStatus().compare("N")==0) {
                    n++;
                }else if (e.getStatus().compare("NP")==0) {
                    np++;
                }
                couts++;
            }

        }
        fileInput.close();
    }
    if (fileInput2.is_open())
    {
        while (!fileInput2.eof())
        {
            getline(fileInput2, line);
            string epl = line;
            istringstream stm(epl);
            string token;
            getline(stm, token, ',');
            if (token == id)
            {
                getline(stm, token, ',');
                e.setName(token);
             }

        }
        fileInput.close();
    }


    cout<<"Ma nhan vien :"<<id<<" |"<<"Name :"<<e.getName()<<" |"<<"DL :"<<dl<<" |"<<"DLNN :"<<dlnn<<" |"<<"N :"<<n<<" |"<<"NP :"<<np<<"\n";
}
void searchName(string file,string name){
    Employee e[10000];
    Employee employee;
    ifstream inFile(file, ios::in);
    string line;
    int linenum = 0;
    while (getline (inFile, line))
    {
        istringstream linestream(line);
        string item;
        //use this to get up to the first comma
        getline(linestream, item, ',');
        employee.setId(item);
        getline(linestream, item, ',');
        employee.setName(item);
        getline(linestream, item, ',');
        employee.setdateofbirth(item);
        getline(linestream, item, ',');
       employee.setAdress(item);
        getline(linestream, item, ',');
        employee.setdepartment(item);
        e[linenum] = employee;
        linenum++;
    }
    for (int i=0;i<linenum;i++) {
        if(e[i].getName()==name){
            cout<<"\n"<<e[i].getId()<<setw(30)<<e[i].getName()<<setw(25)<<e[i].getdateofbirth()<<setw(35)<<e[i].getAdress()<<setw(20)<<e[i].getdepartment()<<"\n";
        }else{
            cout<<"\n Khong tim thay nhan vien ";
            break;
        }
    }
}

void importCSV(){
       Employee employee;
       Employee e[10000];
     ifstream inFile("Import1.text", ios::in);
      string line;
      int linenum = 0;
      while (getline (inFile, line))
      {
          istringstream linestream(line);
          string item;
          //use this to get up to the first comma
          getline(linestream, item, ',');
          employee.setId(item);
          getline(linestream, item, ',');
          employee.setName(item);
          getline(linestream, item, ',');
          employee.setdateofbirth(item);
          getline(linestream, item, ',');
          employee.setAdress(item);
          getline(linestream, item, ',');
          employee.setdepartment(item);
          e[linenum] = employee;
          linenum++;
      }
      for (int i=0;i<linenum;i++) {
          cout<<"\n"<<e[i].getId()<<setw(30)<<e[i].getName()<<setw(25)<<e[i].getdateofbirth()<<setw(35)<<e[i].getAdress()<<setw(20)<<e[i].getdepartment()<<"\n";
      }

}
void readCSV(string file){
    Employee e[10000];
    Employee employee;
    ifstream inFile(file, ios::in);
    ofstream myfile("Import1.text", ios::app);
    string line;
    int linenum = 0;
    while (getline (inFile, line))
    {
        istringstream linestream(line);
        string item;
        //use this to get up to the first comma
        getline(linestream, item, ',');
        employee.setId(item);
        getline(linestream, item, ',');
        employee.setName(item);
        getline(linestream, item, ',');
        employee.setdateofbirth(item);
        getline(linestream, item, ',');
        employee.setAdress(item);
        getline(linestream, item, ',');
        employee.setdepartment(item);
        e[linenum] = employee;
        linenum++;
    }
    for (int i=0;i<linenum;i++) {
        myfile<<e[i].getId()<<","<<e[i].getName()<<","<<e[i].getdateofbirth()<<","<<e[i].getAdress()<<","<<e[i].getdepartment()<<"\n";
    }
}

void pressAnyKey() {
    cout << "\n\nPress any key to continue...";
    getch();
    system("cls");
}
