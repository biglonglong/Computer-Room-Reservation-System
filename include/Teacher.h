#pragma once
#include "Identity.h"

class Teacher: public Identity
{
public:
    Teacher() = default;
    Teacher(int id, string name, string pwd);
    Teacher(const Teacher&) = default;   // no pointer member
    ~Teacher() = default;

    // teacher menu
    void openMenu() override;

    // view all reservation
    void showAllOrder();

    // verify reservation
    void verifyOrder();

public:
    int i_Id;
};