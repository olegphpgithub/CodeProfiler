#pragma once

#include <tchar.h>
#include <Windows.h>
#include <string>

#define MAX_LOG_BUF_SIZE 2048
#define USE_CODE_PROFILER

#if defined(USE_CODE_PROFILER)

#   define START_LOG() CodeProfiler::PinpointTime()
#   define PRINT_LOG(szFmt, ...) CodeProfiler::PrintLog(szFmt, _T(__FUNCTION__), _T(__FILE__), __LINE__, ##__VA_ARGS__)

#else

#   define START_LOG()
#   define PRINT_LOG(szFmt, ...)

#endif

class CodeProfiler
{
public:
    static std::basic_string<TCHAR> m_log;
    static unsigned int m_startTickCount;
    static unsigned int m_finishTickCount;
    static void PinpointTime();
    static void PrintLog(LPCTSTR szFmt, const TCHAR szFunc[], const TCHAR szFile[], const DWORD dwLine, ...);
};

