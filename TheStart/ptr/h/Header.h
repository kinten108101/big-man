#pragma once

#include <stdio.h>
#include <iostream>
#include <string>
#include <iterator>
#include <array>
#include <algorithm>
#include <chrono>
#include <thread>
#include <vector>
#include <Windows.h>

//#define LOG(message) std::cout << message << std::endl;
template<class T>
void LOG(T message)
{
	std::cout << message << "\n";
}
//void LOG(const char message);
//void NUMLOG(const int number);
//void PTRLOG(const int* ptrlog);

