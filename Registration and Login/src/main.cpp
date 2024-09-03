#include <iostream>
#include <chrono>
#include <thread>
#include <sstream>
#include <fstream>

#include "Login.h"

void Registration()
{
	std::string id, password;
	
	while (true)
	{
		system("cls");
		std::cout<<"Enter your ID: ";
		std::cin>>id;
		g_login.setID(id);

		if(!g_login.isIdUnique())
		{
			std::cout<<"ID already exists\n";
			std::this_thread::sleep_for(std::chrono::seconds(2));
		}
		else
		{
			break;
		}
	};


	while(true)
	{
		std::cout<<"Enter your password: ";
		std::cin>>password;
		g_login.setPassword(password);

		if (g_login.isPasswordValid())
			break;
	}

	if (g_login.saveCredentials())
	{
		std::cout << "Registration successful!\n";
	}
	else
	{
		std::cout << "Failed to save credentials\n";
	}
	
	std::this_thread::sleep_for(std::chrono::seconds(1));
}

void login()
{
	system("cls");
	std::string id, password;
	std::cout<<"Enter your ID: ";
	std::cin>>id;
	g_login.setID(id);
	std::cout<<"Enter your password: ";
	std::cin>>password;
	g_login.setPassword(password);

	if(g_login.checkCredentials())
	{
		std::cout<<"redirecting to the main page\n";
	}
	else
	{
		std::cout<<"Invalid ID or password\n";
		std::cout<<"redirecting\n";
	}
	
	std::this_thread::sleep_for(std::chrono::seconds(2));
}

int main()
{
	while(true)
	{
		std::system("cls"); // Clear the console screen

		int val;
		std::cout<<"\n*******************************************\n";
		std::cout<<"\tWelcome to the Login System";
		std::cout<<"\n*******************************************\n";
		std::cout<<"1. Register\n";
		std::cout<<"2. Login\n";
		std::cout<<"3. Exit\n";
		std::cout<<"Enter your choice: ";
		std::cin>>val;

		if(val == 1)
		{
			Registration();
		}
		else if(val == 2)
		{
			login();
		}
		else if( val == 3)
		{
			return 0;
		}
		else
		{
			std::cout<<"Invalid choice\n";
		}
		
		std::this_thread::sleep_for(std::chrono::seconds(1));
	}
}