#include "Bill.h"

Bill g_bill;

void Bill::editBill()
{
	clearBill();

	while (true)
	{
		system("cls");
	
		int choice;
		std::cout << "1.Add Item.\n";
		std::cout << "2.Remove Item.\n";
		std::cout << "3.Print Bill.\n";
		std::cout << "4.close.\n";
		std::cout << "Enter your choice: ";
		std::cin >> choice;

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
				printBill();
				break;
			}
		case(4):
			return;

		default:
			std::cout << "\nInvalid Input";;
		}

	}

}

void Bill::printBill()
{

	system("cls");

	std::cout << DOTTED_LINE;
	std::cout << "\n" << std::right << std::setw(22) <<"Bill" <<  "\n";
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

		g_stock.removeItem(e.first , e.second.quantity);
	}

	std::cout << "\n\npress any key to return \n";
	std::cin.get(); // To consume any leftover newline character
	std::cin.get(); // To actually wait for the user's key press
}

void Bill::clearBill()
{
	m_itemMap.clear();
}

void Bill::addItem()
{
	std::cout << "\nEnter Item Name: ";
	std::cin >> m_itemName;

	Item item;
	if (!g_stock.fetchItemQuantity(m_itemName, item))
	{
		std::cout << "\nItem Not found in Stock ";

		WAIT_FOR_2_SEC;
		return;
	}

	std::cout << "\nEnter Item Quanity: ";
	std::cin >> m_item.quantity;

	m_item.rate = item.rate;

	saveItemInBill();

	WAIT_FOR_2_SEC;
}

void Bill::removeItem()
{
	std::cout << "\nEnter Item Name: ";
	std::cin >> m_itemName;

	if(m_itemMap.contains(m_itemName))
	{
		m_itemMap.erase(m_itemName);
		std::cout << "\nItem Removed Successfully";
	}
	else
	{
		std::cout << "\nItem Not found in Bill ";
	}

	WAIT_FOR_2_SEC;
}

void Bill::saveItemInBill()
{
	if (m_itemMap.contains(m_itemName))
	{
		m_itemMap[m_itemName].quantity += m_item.quantity;
	}
	else
	{
		m_itemMap.emplace(m_itemName, m_item);
	}

	std::cout << "\nItem Added Successfully";
}
