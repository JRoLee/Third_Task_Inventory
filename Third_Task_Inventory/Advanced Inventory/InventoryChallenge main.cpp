#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Item
{
public:
	Item() : itemName(""), price(0) {}
	Item(const string& name, int price) : itemName(name), price(price) {}

	const string& GetName() const { return itemName; }
	const int GetPrice()	const { return price; }
	void Clear()
	{
		itemName = "";
		price = 0;
	}

private:
	string itemName;
	int price;
};



template<typename T>
class Inventory
{
public:
	Inventory(int cap = 10) : capacity(cap), size(0)
	{
		pItems = new T[capacity];
	}

	Inventory(const Inventory<T>& other)
	{
		capacity = other.capacity;
		size = other.size;
		pItems = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			pItems[i] = other.pItems[i];
		}
		cout << "Inventory copy complete!" << endl;
	}

	~Inventory()
	{
		delete[] pItems;
	}

	void AddItem(const T& item)
	{
		if (size < capacity)
		{
			pItems[size++] = item;
		}
		else
		{
			Resize(2 * capacity);
			cout << "Inventory is full! Double the capacity! Capacity: " << capacity << endl;
			pItems[size++] = item;
		}
	}

	void Assign(const Inventory<T>& other)
	{
		capacity = other.capacity;
		size = other.size;
		pItems = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			pItems[i] = other.pItems[i];
		}
	}

	void Resize(int newCapacity)
	{
		Inventory<Item>* tempInv = new Inventory<Item>(*this);
		capacity = newCapacity;
		size = tempInv->size;
		pItems = new T[capacity];
		for (int i = 0; i < size; i++)
		{
			pItems[i] = tempInv->pItems[i];
		}
		delete tempInv;
	}

	static bool compareItemsByPrice(const Item& a, const Item& b)
	{
		return a.GetPrice() > b.GetPrice();
	}

	void SortItems()
	{
		sort(pItems, pItems + size, compareItemsByPrice);
	}

	void RemoveLastItem()
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

	void printAllItems() const
	{
		if (size > 0)
		{
			cout << "======= Items in inventory =======" << endl;
			for (int i = 0; i < size; i++)
			{
				cout << i + 1 << ") Name: " << pItems[i].GetName();
				cout << " Price: " << pItems[i].GetPrice();
				cout << endl;
			}
		}
		else
		{
			cout << "No items in inventory!" << endl;
		}
	}

	//getter
	int GetSize() const { return size; }
	int GetCapacity() const { return capacity; }

private:
	T* pItems;
	int capacity;
	int size;
};



int main()
{

	Inventory<Item>* itemInventory = new Inventory<Item>();
	
	for (int i = 0; i < 11; ++i)
	{
		itemInventory->AddItem(Item("Item" + to_string(i), i * 100));
	}

	itemInventory->printAllItems();

	itemInventory->SortItems();
	cout << endl;

	delete itemInventory;
}
