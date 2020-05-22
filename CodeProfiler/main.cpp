// CodeProfiler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "CodeProfiler.h"

int main()
{
    START_LOG();
    Sleep(100);
    PRINT_LOG(_T("%s %d"), _T("iii"), 789);
    std::wcout << CodeProfiler::m_log << std::endl;
}
