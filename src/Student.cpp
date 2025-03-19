#include "Student.h"

Student::Student(int id, string name, string pwd) {
    this->i_Id = id;
    this->i_Name = name;
    this->i_Pwd = pwd;
}

void Student::openMenu() {
    cout << "welcome student: " << this->i_Name << " login." << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t| please input your choice:       |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1. apply order         |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2. show my order       |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3. show all order      |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4. cancel order        |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0. logout              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t input:";
}

void Student::applyOrder() {
    cout << "please check you whether reapplied before." << endl << endl;
    
    int date = 0;
    cout << "order applied day:(1. Mon, 2. Tue, 3. Wed, 4. Thu, 5. Fri): ";
    cin >> date;
    if(date < 1 || date > 5) {
        cout << "input error." << endl;
        return;
    }

    int interval = 0;
    cout << "order applied interval:(1. morning, 2. afternoon): ";
    cin >> interval;
    if(interval < 1 || interval > 2) {
        cout << "input error." << endl;
        return;
    }
    
    int room = 0;
    cout << "order applied computer room:(1. room1, 2. room2, 3. room3): ";
    cin >> room;
    if(room < 1 || room > 3) {
        cout << "input error." << endl;
        return;
    }

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::out | ios::app);
    if(!ofs.is_open()) {
        cout << "file does not exist." << endl;
        ofs.close();
        return;
    }
    ofs << "date:" << date << " interval:" << interval << " room:" << room << " id:" << this->i_Id << " status:1" << endl;
    ofs.close();
    cout << "order applied successfully." << endl;
    return;
}

void Student::showMyOrder() {
    Order of;
    if(of.orderSize == 0) {
        cout << "no order record." << endl;
        return;
    }

    for(int i = 1; i <= of.orderSize; i++) {
        if(to_string(this->i_Id) == of.orderMap[i]["id"]) {
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
    return;
}

void Student::showAllOrder() {
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

void Student::cancelOrder() {
    Order of;
    if(of.orderSize == 0) {
        cout << "no order record." << endl;
        return;
    }

    cout << "only order under review or approved can be canceled" << endl << endl;
    vector<int> vOrder;
    int index = 1;
    for(int i = 1; i <= of.orderSize; i++) {
        if(to_string(this->i_Id) == of.orderMap[i]["id"]) {
            if(of.orderMap[i]["status"] == "1" || of.orderMap[i]["status"] == "2") {
                vOrder.push_back(i);
                cout << index++ << "<<\t";
                cout << "date:" << of.orderMap[i]["date"] << "\t";
                cout << "interval:" << (of.orderMap[i]["interval"] == "1" ? "morning" : "afternoon") << "\t";
                cout << "room:" << of.orderMap[i]["room"] << "\t";
                cout << "status:" << (of.orderMap[i]["status"] == "1" ? "under review" : "approved") << endl;
                cout << "---------------------------------" << endl;
            }
        }
    }

    int select = 0;
    cout << "please input the order you want to cancel, else to return: ";
    cin >> select;
    if(select <= 0 || select > vOrder.size()) {
        cout << "back." << endl;
        return;
    }
    else {
        Order of;
        of.orderMap[vOrder[select - 1]]["status"] = "0";
        of.updateOrderFile();
        cout << "order canceled successfully." << endl;
    }
    return;
}



