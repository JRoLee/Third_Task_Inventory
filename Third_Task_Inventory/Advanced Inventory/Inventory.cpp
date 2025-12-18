#include <iostream>
#include "Inventory.h"

template <class T>
Inventory<T>::Inventory(int cap) : capacity(cap), size(0)
{
	pItems = pItems[cap];
}

template <class T>
Inventory<T>::~Inventory()
{
	delete[] pItems;
}

template <class T>
void Inventory<T>::AddItem(const T& item)
{
	if (size < capacity)
	{
		pItems[size] = item;
		size++;
	}
	else
	{
		cout << "Inventory is full! Can't add more items" << endl;
	}
}

template <class T>
void Inventory<T>::RemoveLastItem()
{
	if (size > 0)
	{
		size--;
	}
	else
	{
		cout << "No items in inventory!" << endl;
	}
}

template <class T>

template <class T>
int Inventory<T>::GetSize() const { return size; }

template <class T>
int Inventory<T>::GetCapacity() const { return capacity; }