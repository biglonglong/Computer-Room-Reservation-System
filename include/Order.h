#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "globalFile.h"
using namespace std;

class Order
{
public:
    Order();
    ~Order() = default;

    // load order file
    void initOrderMap();

    // update order map
    void updateOrderFile();

public:
    int orderSize;
    map<int, map<string, string> > orderMap;
};