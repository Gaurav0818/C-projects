#include <iostream>
#include <thread>
#include <chrono>

#include "Core.h"
#include "Bill.h"
#include "Stock.h"


int main()
{
	bool exit = false;
	while (!exit)
	{
		system("cls");

		int val;
		std::cout << DOTTED_LINE;
		std::cout << "\n\tSuper Market Billing System\n";
		std::cout << DOTTED_LINE;
		std::cout << "1.Stock\n";
		std::cout << "2.Bill\n";
		std::cout << "3.Exit.\n";
		std::cout << "Enter Your Choice: ";
		std::cin >> val;

		WAIT_FOR_2_SEC;

		switch (val)
		{
			case(1):
			{
				g_stock.editStock();
				break;
			}
			case(2):
			{
				g_bill.editBill();
				break;
			}
			case(3): 
			{
				exit = true;
				break;
			}
			default:
				std::cout << "\nInvalid Input";
		}
	}
	return 0;
}