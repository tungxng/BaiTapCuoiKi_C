#include "employee.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdlib.h>
#include <iomanip>
#include<conio.h>
using std::setw;

int main()
{
    string filePath = "employee.txt";
    string fileCSV = "chamcong.txt";
    string fileDataCSV = "ImportData.csv";
    string y;
    int key;
    do
    {
        cout << "Employee Manager\n";
        cout << "-------------------------MENU-----------------------------\n";
        cout << "==  1. Them nhan vien.                                  ==\n";
        cout << "==  2. Tim nhan vien bang ma nhan vien.                 ==\n";
        cout << "==  3. In ra danh sach nhan vien (file importData.csv). ==\n";
        cout << "==  4. Cham cong nhan vien theo ma nhan vien.           ==\n";
        cout << "==  5. In ra bang cham cong theo ma nhan vien.          ==\n";
        cout << "==  0. Exit progame.                                    ==\n";
        cout << "----------------------------------------------------------\n";
        cout << "Enter a selection: ";
        cin >> key;
        switch(key)
        {
        case 1:
        {
            cout << "Moi nhap thong tin nhan vien: \n";
            writeFileTxt(filePath);
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
            print(searchEmployee(filePath, id));
        }

            pressAnyKey();
            break;
        case 3:
        {
            cout << "Danh sach nhan vien  : \n";
            importCSV();
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
            cout << "In ra bang cham cong theo ma nhan vien. \n";
            string id;
            cout << "Moi nhap ma nhan vien can kiem tra: ";
            cin >> id;
            while (checkId(fileCSV, id) != 0) {
                cout << "Ma nv ban kiem tra khong ton tai \n" ;
                cout << "Moi ban nhap lai ma nhan vien can kiem tra: ";
                cin >> id;
            }

            searchAttendance(fileCSV,id);
        }
        case 6:
        {
            string name;
            string firtName;
            string lastName;
            cout << "Tim theo ten nhan vien   : \n";
            cout << "Moi ban nhap ho nhan vien   : \n";
            cin>>firtName;
            cout << "Moi ban nhap ten nhan vien   : \n";
            cin>>lastName;
            name =firtName+" "+lastName;
            cout << "Thong tin nhan vien   : \n";
            searchName(fileDataCSV,name);
        }
            pressAnyKey();
            break;

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
    }while (key == 1 || key == 2||key == 3 || key == 4);

    return 0;
}


