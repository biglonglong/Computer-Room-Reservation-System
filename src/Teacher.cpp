#include "Teacher.h"

Teacher::Teacher(int id, string name, string pwd) {
    this->i_Id = id;
    this->i_Name = name;
    this->i_Pwd = pwd;
}

void Teacher::openMenu() {
    cout << "welcome teacher: " << this->i_Name << " login." << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t| please input your choice:       |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1. show all order      |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2. vertify order       |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0. logout              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t input:";
}

void Teacher::showAllOrder() {
    Order of;
    if(of.orderSize == 0) {
        cout << "no order record." << endl;
        return;
    }

    for(int i = 1; i <= of.orderSize; i++) {
        cout << i << "." << endl;
        cout << "id:" << of.orderMap[i]["id"] << endl;
        cout << "date:" << of.orderMap[i]["date"] << endl;
        cout << "interval:" << (of.orderMap[i]["interval"] == "1" ? "morning" : "afternoon") << endl;
        cout << "room:" << of.orderMap[i]["room"] << endl;
        string status = "status:";
        if(of.orderMap[i]["status"] == "1") {
            status += "under review";
        } else if(of.orderMap[i]["status"] == "2") {
            status += "approved";
        } else if(of.orderMap[i]["status"] == "-1") {
            status += "rejected";
        } else {
            status += "canceled";
        }
        cout << status << endl;
        cout << "---------------------------------" << endl;
    }
}

void Teacher::verifyOrder() {
    Order of;
    if(of.orderSize == 0) {
        cout << "no order record." << endl;
        return;
    }

    cout << "order to verify: " << endl << endl;
    vector<int> v;
    int index = 1;
    for(int i = 1; i <= of.orderSize; i++) {
        if(of.orderMap[i]["status"] == "1") {
            v.push_back(i);
            cout << index << "." << endl;
            cout << "date:" << of.orderMap[i]["date"] << endl;
            cout << "interval:" << (of.orderMap[i]["interval"] == "1" ? "morning" : "afternoon") << endl;
            cout << "room:" << of.orderMap[i]["room"] << endl;
            cout << "id:" << of.orderMap[i]["id"] << endl;
            cout << "---------------------------------" << endl;
            index++;
        }
    }

    int select = 0;
    cout << "please input the order id to verify, else to return: ";
    cin >> select;
    while(true) {
        if(select <=0 || select > v.size()) {
            cout << "back." << endl;
            return;
        }
        else {
            int verify = 0;
            cout << "please input the verify result(1.approve 2.reject): ";
            cin >> verify;
            if(verify == 1) {
                of.orderMap[v[select-1]]["status"] = "2";
            } else if(verify == 2) {
                of.orderMap[v[select-1]]["status"] = "-1";
            } else {
                cout << "input error, please input again" << endl;
            }
            of.updateOrderFile();
            cout << "verify success" << endl;
            return;
        }
    }
}