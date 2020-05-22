#include "CodeProfiler.h"

#include <stdarg.h>

std::basic_string<TCHAR> CodeProfiler::m_log;
unsigned int CodeProfiler::m_startTickCount;
unsigned int CodeProfiler::m_finishTickCount;

void CodeProfiler::PrintLog(LPCTSTR szFmt, const TCHAR szFunc[], const TCHAR szFile[], const DWORD dwLine, ...)
{
    TCHAR szLog[MAX_LOG_BUF_SIZE] = { 0 };
    TCHAR szModuleName[MAX_PATH] = { 0 };
    TCHAR szFilename[MAX_PATH * 2] = { 0 };
    TCHAR szTime[32] = { 0 };
    TCHAR szFFL[1024] = { 0 };
    DWORD dwTid = GetCurrentThreadId();
    SYSTEMTIME st;
    HANDLE hFile = NULL;
    va_list va_Args;

    va_start(va_Args, dwLine);
    _vsntprintf_s(szLog, MAX_LOG_BUF_SIZE, _TRUNCATE, szFmt, va_Args);
    va_end(va_Args);

    GetModuleFileName(NULL, szModuleName, MAX_PATH);
    szModuleName[MAX_PATH - 1] = _T('\0');
    _sntprintf_s(szFilename, ARRAYSIZE(szFilename), _TRUNCATE, _T("%s_log%03u.txt"), szModuleName, dwTid);

    GetSystemTime(&st);
    _sntprintf_s(szTime, ARRAYSIZE(szTime), _TRUNCATE, _T("[%04u-%02u-%02u %02u:%02u:%02u:%03u] "), st.wYear, st.wMonth, st.wDay,
        st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

    _sntprintf_s(szFFL, ARRAYSIZE(szFFL), _TRUNCATE, _T("(%s @ %s:%u) "), szFunc, szFile, dwLine);

    m_log.append(szTime);
    m_log.append(szFFL);
    m_log.append(szLog);
    m_log.append(TEXT("\r\n"));

}
