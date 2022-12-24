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
#if _MSC_VER > 1200
	return MOONG::ConvertDataType::toString<const DWORD>(dword);
#else
	std::ostringstream stream;
	stream << dword;
	return stream.str();
#endif
}

const std::string MOONG::ConvertDataType::toString(const int integer)
{
#if _MSC_VER > 1200
	return MOONG::ConvertDataType::toString<const int>(integer);
#else
	std::ostringstream stream;
	stream << integer;
	return stream.str();
#endif
}

const std::string MOONG::ConvertDataType::toString(const unsigned int unsigned_int)
{
#if _MSC_VER > 1200
	return MOONG::ConvertDataType::toString<const unsigned int>(unsigned_int);
#else
	std::ostringstream stream;
	stream << unsigned_int;
	return stream.str();
#endif
}

const std::string MOONG::ConvertDataType::seconds_to_data(const unsigned long seconds)
{
	if (seconds < 0)
	{
		return "";
	}

	const unsigned long secOfDay = 60 * 60 * 24;
	const unsigned long secOfHour = 60 * 60;
	const unsigned long secOfMin = 60;

	unsigned long day = seconds / secOfDay;
	unsigned long hour = (seconds - day * secOfDay) / secOfHour;
	unsigned long min = (seconds - day * secOfDay - hour * secOfHour) / secOfMin;
	unsigned long sec = seconds - day * secOfDay - hour * secOfHour - min * secOfMin;

	std::string strDay;
	std::string strHour;
	std::string strMin;
	std::string strSec;

	std::string result;

	const int bufsize = 1024;
	char buf[bufsize] = { 0 };
	if (day > 0)
	{
		StringCbPrintfA(buf, bufsize, "%d일", day);
		strDay = buf;
	}
	if (hour > 0)
	{
		StringCbPrintfA(buf, bufsize, "%d시간", hour);
		strHour = buf;
	}
	if (min > 0)
	{
		StringCbPrintfA(buf, bufsize, "%d분", min);
		strMin = buf;
	}
	if (sec > 0)
	{
		StringCbPrintfA(buf, bufsize, "%d초", sec);
		strSec = buf;
	}
	else if (sec == 0 && (day > 0 || hour > 0 || min > 0))
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

	std::wstring wstr = L"";

	if (true == str.empty())
	{
		return wstr;
	}

	int required_cch = MultiByteToWideChar(
		CP_ACP,
		0,
		str.c_str(),
		static_cast<int>(str.size()),
		nullptr,
		0
	);

	if (0 == required_cch)
	{
		return wstr;
	}

	wstr.resize(required_cch);

	MultiByteToWideChar(
		CP_ACP,
		0,
		str.c_str(),
		static_cast<int>(str.size()),
		const_cast<wchar_t*>(wstr.c_str()),
		static_cast<int>(wstr.size())
	);

	return wstr;
}

const std::string MOONG::ConvertDataType::string_to_utf8(const std::string str)
{
	return MOONG::ConvertDataType::wstring_to_utf8(MOONG::ConvertDataType::string_to_wstring(str));
}

const std::wstring MOONG::ConvertDataType::utf8_to_wstring(const std::string str)
{
	setlocale(LC_ALL, "korean");    // 이 코드가 있어야 한글이 제대로 출력됨.

	std::wstring wstr = L"";

	if (true == str.empty())
	{
		return wstr;
	}

	int required_cch = MultiByteToWideChar(
		CP_UTF8,
		MB_ERR_INVALID_CHARS,
		str.c_str(),
		static_cast<int>(str.size()),
		nullptr,
		0
	);

	if (0 == required_cch)
	{
		return wstr;
	}

	wstr.resize(required_cch);

	MultiByteToWideChar(
		CP_UTF8,
		MB_ERR_INVALID_CHARS,
		str.c_str(),
		static_cast<int>(str.length()),
		const_cast<wchar_t*>(wstr.c_str()),
		static_cast<int>(wstr.size())
	);

	return wstr;
}

const std::string MOONG::ConvertDataType::utf8_to_string(const std::string str)
{
	return MOONG::ConvertDataType::wstring_to_string(MOONG::ConvertDataType::utf8_to_wstring(str));
}

const std::string MOONG::ConvertDataType::wstring_to_string(const std::wstring wstr)
{
	setlocale(LC_ALL, "korean");    // 이 코드가 있어야 한글이 제대로 출력됨.

	std::string str = "";

	if (true == wstr.empty())
	{
		return str;
	}

	int required_cch = WideCharToMultiByte(
		CP_ACP,
		0,
		wstr.c_str(),
		static_cast<int>(wstr.size()),
		nullptr,
		0,
		nullptr,
		nullptr
	);

	if (0 == required_cch)
	{
		return str;
	}

	str.resize(required_cch);

	WideCharToMultiByte(
		CP_ACP,
		0,
		wstr.c_str(),
		static_cast<int>(wstr.size()),
		const_cast<char*>(str.c_str()),
		static_cast<int>(str.size()),
		nullptr,
		nullptr
	);

	return str;
}

const std::string MOONG::ConvertDataType::wstring_to_utf8(const std::wstring wstr)
{
	setlocale(LC_ALL, "korean");    // 이 코드가 있어야 한글이 제대로 출력됨.

	std::string utf8 = "";

	if (true == wstr.empty())
	{
		return utf8;
	}

	int required_cch = WideCharToMultiByte(
		CP_UTF8,
		WC_ERR_INVALID_CHARS,
		wstr.c_str(),
		static_cast<int>(wstr.size()),
		nullptr,
		0,
		nullptr,
		nullptr
	);

	if (0 == required_cch)
	{
		return utf8;
	}

	utf8.resize(required_cch);

	WideCharToMultiByte(
		CP_UTF8,
		WC_ERR_INVALID_CHARS,
		wstr.c_str(), static_cast<int>(wstr.size()),
		const_cast<char*>(utf8.c_str()),
		static_cast<int>(utf8.size()),
		nullptr,
		nullptr
	);

	return utf8;
}

double MOONG::ConvertDataType::unsigned_int64_to_double(unsigned __int64 unsigned_int64_value)
{
	__int64 i64 = (unsigned_int64_value & 0x7FFFFFFFFFFFFFF);
	double dbl = static_cast<double>(i64);

	if (unsigned_int64_value & 0x8000000000000000)
	{
		dbl += static_cast<double>(0x8000000000000000);
	}

	return dbl;
}