#include "Manager.h"

void Manager::initAccountVec() {
    this->vStu.clear();
    this->vTea.clear();

    ifstream ifs;
    ifs.open(STUDENT_FILE, ios::in);
    if(!ifs.is_open()) {
        cout << "file does not exist." << endl;
        ifs.close();
        return;
    }
    Student stu;
    while(ifs >> stu.i_Id && ifs >> stu.i_Name && ifs >> stu.i_Pwd) {
        this->vStu.push_back(stu);
    }
    ifs.close();

    ifs.open(TEACHER_FILE, ios::in);
    if(!ifs.is_open()) {
        cout << "file does not exist." << endl;
        ifs.close();
        return;
    }
    Teacher tea;
    while(ifs >> tea.i_Id && ifs >> tea.i_Name && ifs >> tea.i_Pwd) {
        this->vTea.push_back(tea);
    }
    ifs.close();
}

void Manager::appendAccountVec(int id, string name, string pwd, int type) {
    if(type == 1) {
        this->vStu.push_back(Student(id, name, pwd));
    }
    else {
        this->vTea.push_back(Teacher(id, name, pwd));
    }
}

bool Manager::checkAccountRepeat(int id, int type) {
    if(type == 1) {
        return find_if(this->vStu.begin(), this->vStu.end(), [id](Student& stu) {
            return stu.i_Id == id;
        }) != this->vStu.end();
    }
    else {
        return find_if(this->vTea.begin(), this->vTea.end(), [id](Teacher& tea) {
            return tea.i_Id == id;
        }) != this->vTea.end();
    }
}

void Manager::initComputerRoomVec() {
    this->vCom.clear();

    ifstream ifs;
    ifs.open(COMPUTER_FILE, ios::in);
    if(!ifs.is_open()) {
        cout << "file does not exist." << endl;
        ifs.close();
        return;
    }
    ComputerRoom com;
    while(ifs >> com.i_RoomId && ifs >> com.i_MaxNum) {
        this->vCom.push_back(com);
    }
    ifs.close();
}

Manager::Manager(string name, string pwd) {
    this->i_Name = name;
    this->i_Pwd = pwd;
    this->initAccountVec();
    this->initComputerRoomVec();
}

void Manager::openMenu() {
    cout << "welcome manager: " << this->i_Name << " login." << endl;
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t| please input your choice:       |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          1. add account         |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          2. view account        |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          3. view machine        |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          4. clear reservation   |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t|          0. logout              |\n";
    cout << "\t\t|                                 |\n";
    cout << "\t\t ---------------------------------\n";
    cout << "\t\t input:";
}

void Manager::addAccount() {
    string filename;
    int select = 0;
    cout << "account added kind:(1. student, 2. teacher): ";
    cin >> select;
    if(select == 1) {
        filename = STUDENT_FILE;
    }
    else {
        filename = TEACHER_FILE;
    }

    ofstream ofs;
    ofs.open(filename, ios::out | ios::app);
    if(!ofs.is_open()) {
        cout << "file does not exist." << endl;
        ofs.close();
        return;
    }

    int id;
    string name;
    string pwd;
    cout << "id: ";
    cin >> id;
    cout << "name: ";
    cin >> name;
    cout << "password: ";
    cin >> pwd;
    if(this->checkAccountRepeat(id, select)) {
        cout << "account exists." << endl;
    }
    else {
        this->appendAccountVec(id, name, pwd, select);
        ofs << id << " " << name << " " << pwd << endl;
        cout << "account added success." << endl;
    }
    ofs.close();
    return;
}

void Manager::showAccount() {
    int select = 0;
    cout << "account showed kind:(1. student, 2. teacher): ";
    cin >> select;
    if(select == 1) {
        cout << "student(total of " << this->vStu.size() << "):" << endl;
        for_each(this->vStu.begin(), this->vStu.end(), [](Student& stu) {
            cout << "id: " << stu.i_Id << "\t name: " << stu.i_Name << "\t password: " << stu.i_Pwd << endl;
        });
    }
    else{
        cout << "teacher(total of " << this->vTea.size() << "):" << endl;
        for_each(this->vTea.begin(), this->vTea.end(), [](Teacher& tea) {
            cout << "id: " << tea.i_Id << "\t name: " << tea.i_Name << "\t password: " << tea.i_Pwd << endl;
        });
    }
    return;
}

void Manager::showMachine() {
    cout << "machine(total of " << this->vCom.size() << "):" << endl;
    for_each(this->vCom.begin(), this->vCom.end(), [](ComputerRoom& com) {
        cout << "id: " << com.i_RoomId << "\t max number: " << com.i_MaxNum << endl;
    });
    return;
}

void Manager::clearOrder() {
    ifstream ifs(ORDER_FILE, ios::in);
    ofstream ofs_bak(ORDER_FILE_BAK, ios::out | ios::app);
    if(!ifs.is_open() || !ofs_bak.is_open()) {
        cout << "file does not exist." << endl;
        ifs.close();
        ofs_bak.close();
        return;
    }

    string line;
    while(getline(ifs, line)) {
        ofs_bak << line << endl;
    }
    ifs.close();
    ofs_bak.close();

    ofstream ofs;
    ofs.open(ORDER_FILE, ios::trunc);
    ofs.close();
    cout << "reservation cleared and baked." << endl;
    return;
}