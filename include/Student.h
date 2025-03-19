#pragma once
#include "Identity.h"

class Student: public Identity
{
public:
    Student() = default;
    Student(int id, string name, string pwd);
    Student(const Student&) = default;   // no pointer member
    ~Student() = default;

    // student menu
    void openMenu() override;

    // apply for reservation
    void applyOrder();

    // view my reservation
    void showMyOrder();

    // view all reservation
    void showAllOrder();

    // cancel reservation
    void cancelOrder();

public:
    int i_Id;
};