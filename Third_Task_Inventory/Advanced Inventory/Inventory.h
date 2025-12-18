#pragma once
#include <iostream>
using namespace std;


template <typename T>
class Inventory
{
public:
	Inventory(int capacity = 10);
	~Inventory();
	void AddItem(const T& item);
	void RemoveLastItem();
	void printAllItems() const;

	//getter
	int GetSize() const;
	int GetCapacity() const;

	private:
	T* pItems;
	int capacity;
	int size;
};

void 
