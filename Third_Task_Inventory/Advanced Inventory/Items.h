#pragma once
#include <iostream>
#include <string>
using namespace std;

class Items
{
public:
	Items(string itemName, int price);

protected:
	string itemName;
	int price;
};

