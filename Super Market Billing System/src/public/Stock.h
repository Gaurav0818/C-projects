#pragma once

#include"Core.h"
#include<unordered_map>

struct Item
{
	int quantity;
	int rate;
};

class Stock
{
public:
	Stock();
	~Stock();

	void editStock();
	void saveChanges();

	bool fetchItemQuantity(const std::string& name, Item& item);
	void removeItem();
	void removeItem(const std::string& name, int quantity);

private:

	void fetchStock();
	void addItem();

	void printStock();

private:
	std::unordered_map<std::string, Item> m_itemMap;
	std::string m_itemName;
	int m_rate, m_quantity;
};

extern Stock g_stock;