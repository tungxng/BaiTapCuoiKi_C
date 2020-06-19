#include "employee.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include<conio.h>
using std::setw;
Employee searchEmployee(string file, string id);
int main()
{
    string fileCSV = "chamcong.txt";

    string filePath = "employee.txt";

    string fileDataCSV = "ImportData.csv";
    string filemonth = "month.txt";
    string y;
    int key,k;
    do
    {
        cout << "Employee Manager\n";
        cout << "-------------------------MENU-----------------------------\n";
        cout << "==  1. Them nhan vien.                                  ==\n";
        cout << "==  2. Tim nhan vien bang ma nhan vien.                 ==\n";
        cout << "==  3. In ra danh sach nhan vien (file importData.csv). ==\n";
        cout << "==  4. Cham cong nhan vien theo ma nhan vien.           ==\n";
        cout << "==  5. Hien thi diem danh theo ma nhan vien.            ==\n";
        cout << "==  6. Tim theo ten nhan vien.                          ==\n";
        cout << "==  7. Hien thi danh sach diem danh theo thang.         ==\n";
        cout << "==  8. Hien thi diem danh theo phong ban.               ==\n";
        cout << "==  9. Xem diem danh cua nhan vien theo thang.          ==\n";
        cout << "==  0. Exit progame.                                    ==\n";
        cout << "----------------------------------------------------------\n";
        cout << "Enter a selection: ";
        cin >> key;
        switch(key)
        {
        case 1:
        {
            int x;
            cout<<"Nhap so nhan vien muon them :";
            cin>>x;
            for(int i=0;i<x;i++){
                cout << "Nhap nhan vien thu:"<<i+1<<"\n";
                writeFileTxt(filePath);
            }

        }

            pressAnyKey();
            break;
        case 2:
        {
            string id;
            cout << "Moi nhap ma nhan vien can tim kiem: ";
            cin >> id;
            while (checkId(filePath, id) != 0) {
                cout << "Ma nv ban tim kiem khong ton tai \n" ;
                cout << "Moi ban nhap lai ma nhan vien can tim kiem: ";
                cin >> id;
            }
            cout << "Thong tin cua nhan vien co ma " << id << endl;
            prints(searchEmployee(filePath, id));
        }

            pressAnyKey();
            break;
        case 3:
        {
            string x;
            cout<<"Nhap file can import";
            cin>>x;
            importCSV(x);
        }

            pressAnyKey();
            break;

        case 4:
        {
            cout << "Cham cong nhan vien theo ma nhan vien: \n";
            int n;
            cout<<"Nhap so nhan vien muon cham cong :";
            cin>>n;
            for(int i=0;i<n;i++){
                cout<<"Nhan vien thu :"<<i+1<<"\n";
                inputAttendance(fileCSV);
            }
        }
            pressAnyKey();
            break;
        case 5:
        {
            string id;
            cout << "Moi nhap ma nhan vien can kiem tra: ";
            cin >> id;
            while (checkId(fileCSV, id) != 0) {
                cout << "Ma nv ban kiem tra khong ton tai \n" ;
                cout << "Moi ban nhap lai ma nhan vien can kiem tra: ";
                cin >> id;
            }
            searchAttendance(fileCSV,id);
            pressAnyKey();
            break;
        }
        case 6:
        {
            cin.ignore();

            string name;
            cout<<"Nhap ten can tim\n";
            getline(cin,name);
            searchName(fileDataCSV,name);
        }
            pressAnyKey();
            break;
        case 7:
        {
            int month;
            cout << "Moi nhap thang can kiem tra: ";
            cin >> month;
            searchThang(fileCSV,month);
            pressAnyKey();
            break;
        }
            pressAnyKey();
            break;
        case 8:
        {
            string pb;
            cout << "Moi nhap phong ban can kiem tra: ";
            cin >> pb;
            searchDepartment(fileCSV,pb);
            pressAnyKey();
            break;
        }
            pressAnyKey();
            break;
        case 9:
        {

            do
            {
                cout << "Employee Manager\n";
                cout << "-------------------------MENU----------------------------- \n";
                cout << "==  1. Chon thang can kiem tra                           ==\n";
                cout << "==  2. Hien thi danh sach diem danh theo ma nhan vien    ==\n";
                cout << "----------------------------------------------------------\n";
                cout << "Enter a selection: ";
                cin >> k;
                switch(k)
                {
                case 2:
                {
                    string id;
                    cout << "Moi nhap ma nhan vien can kiem tra: ";
                    cin >> id;
                    while (checkId(fileCSV, id) != 0) {
                        cout << "Ma nv ban kiem tra khong ton tai \n" ;
                        cout << "Moi ban nhap lai ma nhan vien can kiem tra: ";
                        cin >> id;
                    }
                    searchAttendance(fileCSV,id);
                    pressAnyKey();
                    DeleteFile("month.txt");
                    break;
                }


                case 1:
                {
                    int month;
                    cout << "Moi nhap thang can kiem tra: ";
                    cin >> month;
                    searchThang(fileCSV,month);
                    pressAnyKey();
                    break;
                }
            }

            }while (key == 1 || key == 2||key == 3);
            pressAnyKey();
            break;
        }
        case 0:
            cout << "\nBan da thoat chuong trinh!";
            getch();
            return 0;
        default:
            cout << "\nLua chon khong ton tai!";
            cout << "\nChon phim bat ki de quay lai menu.";
            pressAnyKey();
            break;
    }
    }while (key == 1 || key == 2||key == 3 || key == 4 ||key==5 ||key==6 ||key==7||key==8);

    return 0;
}


