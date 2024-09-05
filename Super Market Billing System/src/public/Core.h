
#include <string>
#include <iostream>
#include <chrono>
#include <thread>
#include <ostream>
#include <fstream>
#include <sstream>

#define WAIT_FOR_2_SEC std::this_thread::sleep_for(std::chrono::seconds(2))
#define DOTTED_LINE "\n********************************************\n" 

#define STOCK_LOCATION "data\\Stock.txt"