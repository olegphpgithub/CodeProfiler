// CodeProfiler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "CodeProfiler.h"

int main()
{
    START_LOG();
    Sleep(100);
    PRINT_LOG(_T("%s %d"), _T("iii"), 789);
    PRINT_LOG(_T("Count %s %d %s"), _T("xxx"), 789, _T("aaa"));
    std::wcout << CodeProfiler::m_log << std::endl;
    std::cout << "Hello World!\n";
}
