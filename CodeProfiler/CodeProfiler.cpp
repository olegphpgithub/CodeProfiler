#include "CodeProfiler.h"

#include <stdarg.h>

std::basic_string<TCHAR> CodeProfiler::m_log;
unsigned int CodeProfiler::m_startTickCount = 0;
unsigned int CodeProfiler::m_finishTickCount = 0;

void CodeProfiler::PinpointTime()
{
    CodeProfiler::m_startTickCount = GetTickCount();
}

void CodeProfiler::PrintLog(LPCTSTR szFmt, const TCHAR szFunc[], const TCHAR szFile[], const DWORD dwLine, ...)
{
    TCHAR szLog[MAX_LOG_BUF_SIZE] = { 0 };
    TCHAR szTime[32] = { 0 };
    TCHAR szLocation[1024] = { 0 };
    SYSTEMTIME st;
    va_list va_Args;

    va_start(va_Args, dwLine);
    _vsntprintf_s(szLog, MAX_LOG_BUF_SIZE, _TRUNCATE, szFmt, va_Args);
    va_end(va_Args);

    CodeProfiler::m_finishTickCount = GetTickCount();

    GetSystemTime(&st);
    _sntprintf_s(szTime, ARRAYSIZE(szTime), _TRUNCATE, _T("[%04u-%02u-%02u %02u:%02u:%02u:%03u] "), st.wYear, st.wMonth, st.wDay,
        st.wHour, st.wMinute, st.wSecond, st.wMilliseconds);

    _sntprintf_s(
        szLocation,
        ARRAYSIZE(szLocation),
        _TRUNCATE,
        _T("(%s @ %s:%u) Time spent %lu ms. "),
        szFunc,
        szFile,
        dwLine,
        m_finishTickCount - m_startTickCount
    );

    m_log.append(szTime);
    m_log.append(szLocation);
    m_log.append(szLog);
    m_log.append(TEXT("\r\n"));

}
