#pragma once

#include <string>
#include <iostream>
#include <fstream>
#include <sstream>

#include "Core.h"
#include "Stock.h"

class Bill
{
public:
	Bill() = default;
	~Bill() = default;

	void editBill();

private:

	void printBill();
	void clearBill();
	void addItem();
	void removeItem();
	void saveItemInBill();

private:
	std::unordered_map<std::string, Item> m_itemMap;
	std::string m_itemName;
	Item m_item;

};

extern Bill g_bill;