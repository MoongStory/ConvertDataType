#include "ConvertDataType.h"

#if _MSC_VER > 1200
    #include <locale>
#else
    #include <locale.h>
#endif

#include <sstream>
#include <strsafe.h>

const std::string MOONG::ConvertDataType::toString(const DWORD dword)
{
	return MOONG::ConvertDataType::toString<const DWORD>(dword);
}

const std::string MOONG::ConvertDataType::toString(const int integer)
{
	return MOONG::ConvertDataType::toString<const int>(integer);
}

const std::string MOONG::ConvertDataType::toString(const unsigned int unsigned_int)
{
	return MOONG::ConvertDataType::toString<const unsigned int>(unsigned_int);
}

const std::string MOONG::ConvertDataType::seconds_to_data(const unsigned long seconds)
{
	if(seconds < 0)
	{
		return "";
	}
	
	const unsigned long secOfDay	= 60 * 60 * 24;
	const unsigned long secOfHour	= 60 * 60 ;
	const unsigned long secOfMin	= 60;
	
	unsigned long day = seconds/secOfDay;
	unsigned long hour = (seconds - day*secOfDay)/secOfHour;
	unsigned long min = (seconds - day*secOfDay - hour*secOfHour)/secOfMin;
	unsigned long sec = seconds - day*secOfDay - hour*secOfHour - min*secOfMin;
	
	std::string strDay;
	std::string strHour;
	std::string strMin;
	std::string strSec;
	
	std::string result;
	
	const int bufsize = 1024;
	char buf[bufsize] = {0,};
	if(day > 0)
	{
		StringCbPrintfA(buf, bufsize, "%d일", day);
		strDay = buf;
	}
	if(hour > 0)
	{
		StringCbPrintfA(buf, bufsize, "%d시간", hour);
		strHour = buf;
	}
	if(min > 0)
	{
		StringCbPrintfA(buf, bufsize, "%d분", min);
		strMin = buf;
	}
	if(sec > 0)
	{
		StringCbPrintfA(buf, bufsize, "%d초", sec);
		strSec = buf;
	}
	else if(sec == 0 && (day > 0 || hour > 0 || min > 0))
	{
		strSec = "";
	}
	else
	{
		StringCbPrintfA(buf, bufsize, "%d초", sec);
		strSec = buf;
	}
	
	result = strDay + strHour + strMin + strSec;
	
	return result;
}

const int MOONG::ConvertDataType::string_to_integer(const std::string str)
{
#if _MSC_VER > 1200
    return std::stoi(str);
#else
	int num = 0;
	std::stringstream ss(str);
	ss >> num;

	return num;
#endif
}

const std::wstring MOONG::ConvertDataType::string_to_wstring(const std::string str)
{
    setlocale(LC_ALL, "korean");    // 이 코드가 있어야 한글이 제대로 출력됨.

    size_t new_size = (str.length() + 1) * 2;

    wchar_t* nstring = NULL;
    try
    {
        nstring = new wchar_t[new_size];
    }
    catch (const std::exception& exception)
    {
        throw exception;
    }

#if _MSC_VER > 1200
    size_t convertedChars = 0;
    mbstowcs_s(&convertedChars, nstring, new_size, str.c_str(), _TRUNCATE);
#else
    mbstowcs(nstring, str.c_str(), new_size);
#endif

    std::wstring return_string(nstring);

    delete[] nstring;

    return return_string;
}

const std::string MOONG::ConvertDataType::wstring_to_string(const std::wstring wstr)
{
    setlocale(LC_ALL, "korean");    // 이 코드가 있어야 한글이 제대로 출력됨.

    size_t new_size = (wstr.length() + 1) * 2;

    char* nstring = NULL;
    try
    {
        nstring = new char[new_size];
    }
    catch (const std::exception& exception)
    {
        throw exception;
    }

#if _MSC_VER > 1200
    size_t convertedChars = 0;
    wcstombs_s(&convertedChars, nstring, new_size, wstr.c_str(), _TRUNCATE);
#else
    wcstombs(nstring, wstr.c_str(), new_size);
#endif

    std::string return_string(nstring);
    
    delete[] nstring;

    return return_string;
}

double MOONG::ConvertDataType::unsigned_int64_to_double(unsigned __int64 unsigned_int64_value)
{
    __int64 i64 = (unsigned_int64_value & 0x7FFFFFFFFFFFFFF);
    double dbl = (double) i64;

    if (unsigned_int64_value & 0x8000000000000000)
	{
        dbl += (double) 0x8000000000000000;
	}

    return dbl; 
}