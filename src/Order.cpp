#include "Order.h"

void Order::initOrderMap() {
    ifstream ifs;
    ifs.open(ORDER_FILE, ios::in);
    if(!ifs.is_open()) {
        cout << "file does not exist." << endl;
        ifs.close();
        return;
    }

    string orderDate;
    string orderInterval;
    string orderRoom;
    string orderStuId;
    string orderStatus;
    while(ifs >> orderDate && ifs >> orderInterval && ifs >> 
        orderRoom && ifs >> orderStuId && ifs >> orderStatus) {
            string key, value;
            map<string, string> m;
            int pos;

            pos=orderDate.find(":");
            if(pos!=-1) {
                key=orderDate.substr(0, pos);
                value=orderDate.substr(pos+1, orderDate.size()-pos-1);
                m.insert({key,value});
            }

            pos=orderInterval.find(":");
            if(pos!=-1) {
                key=orderInterval.substr(0, pos);
                value=orderInterval.substr(pos+1, orderInterval.size()-pos-1);
                m.insert({key,value});
            }

            pos=orderRoom.find(":");
            if(pos!=-1) {
                key=orderRoom.substr(0, pos);
                value=orderRoom.substr(pos+1, orderRoom.size()-pos-1);
                m.insert({key,value});
            }

            pos=orderStuId.find(":");
            if(pos!=-1) {
                key=orderStuId.substr(0, pos);
                value=orderStuId.substr(pos+1, orderStuId.size()-pos-1);
                m.insert({key,value});
            }

            pos=orderStatus.find(":");
            if(pos!=-1) {
                key=orderStatus.substr(0, pos);
                value=orderStatus.substr(pos+1, orderStatus.size()-pos-1);
                m.insert({key,value});
            }

            this->orderMap.insert({++this->orderSize,m});
    }
    ifs.close();
}

void Order::updateOrderFile() {
    if(this->orderSize == 0) {
        return;
    }

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::trunc);
    for(int i=1; i<=this->orderSize; i++) {
        ofs << "date:" << this->orderMap[i]["date"] << " ";
        ofs << "interval:" << this->orderMap[i]["interval"] << " ";
        ofs << "room:" << this->orderMap[i]["room"] << " ";
        ofs << "id:" << this->orderMap[i]["id"] << " ";
        ofs << "status:" << this->orderMap[i]["status"] << endl;
    }
    ofs.close();
}

Order::Order() {
    this->orderSize = 0;
    this->initOrderMap();
}
