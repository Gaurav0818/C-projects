#include "Stock.h"

Stock g_stock;

Stock::Stock()
{
	fetchStock();
}

Stock::~Stock()
{
	std::cout << "\nEdit stocks called\n";
	saveChanges();
}

void Stock::editStock()
{
	while (true)
	{
		system("cls");

		int choice;
		std::cout << "1.Add Item.\n";
		std::cout << "2.Remove Item.\n";
		std::cout << "3.Print Stock.\n";
		std::cout << "4.Close.\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

		WAIT_FOR_2_SEC;

		switch (choice)
		{
		case(1):
		{
			addItem();
			break;
		}
		case(2):
		{
			removeItem();
			break;
		}
		case(3):
		{
			printStock();
			break;
		}
		case(4):
			return;
		default:
			std::cout << "\nInvalid Input";;
		}
	}
}

void Stock::fetchStock()
{
	std::ifstream inFile(STOCK_LOCATION);

	if (!inFile)
	{
		std::cout << "\nError: Unable to open Stock File! \n";

		return;
	}

	std::string line;

	while (std::getline(inFile, line))
	{
		std::stringstream ss;
		ss << line;

		char delimiter;

		Item item;

		ss >> m_itemName >> delimiter >> item.rate >> delimiter >> item.quantity;

		m_itemMap.emplace(m_itemName, item);
	}

	inFile.close();
}

void Stock::addItem()
{

	m_itemName = "";
	m_rate = 0;
	m_quantity = 0;

	std::cout << "\nEnter Item Name: ";
	std::cin >> m_itemName;
	std::cout << "\nAmount to be added : ";
	std::cin >> m_quantity;

	if (!m_itemMap.contains(m_itemName))
	{
		std::cout << "\nRate of item :";
		std::cin >> m_rate;

		Item item;
		item.rate = m_rate;
		item.quantity = m_quantity;

		m_itemMap.emplace(m_itemName, item);
	}
	else
	{
		m_itemMap[m_itemName].quantity += m_quantity;
	}

	std::cout << DOTTED_LINE << "Item Added Successfully" << DOTTED_LINE;

	WAIT_FOR_2_SEC;
}

void Stock::removeItem()
{
	m_itemName = "";
	m_rate = 0;
	m_quantity = 0;

	std::cout << "\nEnter Item Name: ";
	std::cin >> m_itemName;


	if (m_itemMap.contains(m_itemName))
	{
		std::cout << "\nAmount to be removed : ";
		std::cin >> m_quantity;
		m_itemMap[m_itemName].quantity -= m_quantity;
	}

	std::cout << DOTTED_LINE << m_quantity <<" Item Removed Successfully" << DOTTED_LINE;

	WAIT_FOR_2_SEC;
}

void Stock::removeItem(const std::string& name, int quantity)
{
	if (m_itemMap.contains(name))
	{
		m_itemMap[name].quantity -= quantity;
	}
}

void Stock::printStock()
{
	system("cls");

	std::cout << DOTTED_LINE;
	std::cout << "\n" << std::right << std::setw(22) << "STOCK" << "\n";
	std::cout << DOTTED_LINE;

	std::cout << std::left << std::setw(5) << "No."
		<< std::setw(20) << "Item"
		<< std::setw(10) << "Rate"
		<< std::setw(10) << "Quantity";
	std::cout << DOTTED_LINE;

	int i = 0;
	for (auto e : m_itemMap)
	{
		i++;
		std::cout << "\n" << std::left << std::setw(5) << i
			<< std::setw(20) << e.first
			<< std::setw(10) << e.second.rate
			<< std::setw(10) << e.second.quantity;
	}

	std::cout << "\n\npress any key to return \n";
	std::cin.get(); // To consume any leftover newline character
	std::cin.get(); // To actually wait for the user's key press
}

void Stock::saveChanges()
{
	std::ofstream outFile(STOCK_LOCATION);

	if (!outFile)
	{
		std::cout << "\nError: Unable to open Stock File! \n";

		return;
	}

	for (auto e : m_itemMap)
	{
		outFile << e.first << " : " << e.second.rate << " : " << e.second.quantity << "\n";
	}

	outFile.close();

}

bool Stock::fetchItemQuantity(const std::string& name, Item& item)
{
	if(!m_itemMap.contains(name))
    {
        return false;
    }
	item = m_itemMap[name];

	return true;
}
