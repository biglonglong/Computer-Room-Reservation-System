#include <iostream>
#include <fstream>
#include <string>
#include "globalFile.h"
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"
#include "Manager.h"
using namespace std;

void mainopenMenu() {
    cout << "=============================================" << endl;
    cout << "Welcome to [Computer Room Reservation System]" << endl;
    cout << "=============================================" << endl;
    cout << endl;
    cout << "\t\t please input the number of your identity or the function: " << endl;
    cout << "\t\t --------------------------" << endl;
    cout << "\t\t - \t 1. student \t -" << endl;
    cout << "\t\t - \t 2. teacher \t -" << endl;
    cout << "\t\t - \t 3. manager \t -" << endl;
    cout << "\t\t - \t 0. exit    \t -" << endl;
    cout << "\t\t --------------------------" << endl;
    cout <<"\t\t input: ";
}

void managerMenu(Identity* manager) {
    while(true) {
        manager->openMenu();
        Manager *mgr = (Manager*)manager;

        int select = 0;
        cin >> select;
        if(select == 1) {
            mgr->addAccount();
        }
        else if(select == 2) {
            mgr->showAccount();
        }
        else if(select == 3) {
            mgr->showMachine();
        }
        else if(select == 4) {
            mgr->clearOrder();
        }
        else {
            // logout
            delete manager;
            cout << "logout success." << endl;
            system("pause");
            system("cls");
            return;
        }
        system("pause");
        system("cls");
    }
}

void studentMenu(Identity* student) {
    while(true) {
        student->openMenu();
        Student *stu = (Student*)student;

        int select = 0;
        cin >> select;
        if(select == 1) {
            stu->applyOrder();
        }
        else if(select == 2) {
            stu->showMyOrder();
        }
        else if(select == 3) {
            stu->showAllOrder();
        }
        else if(select == 4) {
            stu->cancelOrder();
        }
        else {
            // logout
            delete student;
            cout << "logout success." << endl;
            system("pause");
            system("cls");
            return;
        }
        system("pause");
        system("cls");
    }
}

void teacherMenu(Identity* teacher) {
    while(true) {
        teacher->openMenu();
        Teacher *tea = (Teacher*)teacher;

        int select = 0;
        cin >> select;
        if(select == 1) {
            tea->showAllOrder();
        }
        else if(select == 2) {
            tea->verifyOrder();
        }
        else {
            // logout
            delete teacher;
            cout << "logout success." << endl;
            system("pause");
            system("cls");
            return;
        }
        system("pause");
        system("cls");
    }
}

void loginIn(string fileName, int type) {
    while(true) {
        ifstream ifs;
        ifs.open(fileName, ios::in);
        if(!ifs.is_open()) {
            cout << "file does not exist." << endl;
            ifs.close();
            return;
        }

        int id = 0;
        string name;
        string pwd;
        if(type == 1) {
            cout << "please input your student id: ";
            cin >> id;
        }
        else if(type == 2) {
            cout << "please input your teacher id: ";
            cin >> id;
        }
        cout << "please input your name: ";
        cin >> name;
        cout << "please input your password: ";
        cin >> pwd;

        Identity* person = NULL;
        if(type == 1) {
            // student vertify
            int s_Id;
            string s_Name;
            string s_Pwd;
            while(ifs >> s_Id && ifs >> s_Name && ifs >> s_Pwd) {
                if(s_Id == id && s_Name == name && s_Pwd == pwd) {
                    system("cls");
                    cout << "student vertify success." << endl;
                    person = new Student(id, name, pwd);
                    // student menu
                    studentMenu(person);
                    return;
                }
            }
        }
        else if(type == 2) {
            // teacher vertify
            int t_Id;
            string t_Name;
            string t_Pwd;
            while(ifs >> t_Id && ifs >> t_Name && ifs >> t_Pwd) {
                if(t_Id == id && t_Name == name && t_Pwd == pwd) {
                    system("cls");
                    cout << "teacher vertify success." << endl;
                    person = new Teacher(id, name, pwd);
                    // teacher menu
                    teacherMenu(person);
                    return;
                }
            }
        }
        else if(type == 3) {
            // manager vertify
            string m_Name;
            string m_Pwd;
            while(ifs >> m_Name && ifs >> m_Pwd) {
                if(m_Name == name && m_Pwd == pwd) {
                    system("cls");
                    cout << "manager vertify success." << endl;
                    person = new Manager(name, pwd);
                    // manager menu
                    managerMenu(person);
                    return;
                }
            }
        }
    
        cout << "login failed, retry(y/Y) or back(else): ";
        char select = 'n';
        cin >> select;
        if(select == 'y' || select == 'Y') continue;

        ifs.close();
        system("pause");
        system("cls");
        return;
    }
}

int main()
{
    system("cls");
    int select = 0;
    while(true) {
        mainopenMenu();
        cin>>select;
        switch (select) {
        case 1:
            // student login
            loginIn(STUDENT_FILE, 1);
            break;
        case 2:
            // teacher login
            loginIn(TEACHER_FILE, 2);
            break;
        case 3:
            // manager login
            loginIn(MANAGER_FILE, 3);
            break;
        case 0:
            // exit system
            cout << "exiting, see you next use!" << endl;
            system("pause");
            system("cls");
            return 0;
        default:
            // input error
            cout << "input error, please input again." << endl;
            system("pause");
            system("cls");
            break;
        }
    }
    return 0;
}