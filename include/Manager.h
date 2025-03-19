#pragma once
#include "Identity.h"
#include "Student.h"
#include "Teacher.h"

class Manager: public Identity
{
public:
    Manager() = default;
    Manager(string name, string pwd);
    Manager(const Manager&) = default;  // no pointer member
    ~Manager() = default;

    // manager menu
    void openMenu() override;

    // add account
    void addAccount();

    // view account
    void showAccount();

    // view machine
    void showMachine();

    // clear reservation
    void clearOrder();

    // init stu && tea vector
    void initAccountVec();

    // append stu && tea vector
    void appendAccountVec(int id, string name, string pwd, int type);

    // check if the account exists
    bool checkAccountRepeat(int id, int type);

    // init computer room vector
    void initComputerRoomVec();

private:
    vector<Student> vStu;
    vector<Teacher> vTea;
    vector<ComputerRoom> vCom;
};