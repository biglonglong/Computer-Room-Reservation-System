#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include "globalFile.h"
#include "Order.h"
#include "ComputerRoom.h"
using namespace std;

class Identity {
public:
    Identity() = default;
    ~Identity() = default;

    virtual void openMenu() = 0;

public:
    string i_Name;
    string i_Pwd;
};