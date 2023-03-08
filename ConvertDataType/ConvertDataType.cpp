#include "ConvertDataType.h"

#include "../../StringTool/StringTool/StringTool.h"

#if _MSC_VER > 1200
#include <locale>
#else
#include <locale.h>
#endif

#include <sstream>
#include <strsafe.h>

const std::string MOONG::ConvertDataType::to_string(const WORD word)
{
#if _MSC_VER > 1200
	return MOONG::ConvertDataType::to_string<const WORD>(word);
#else
	std::ostringstream stream;
	stream << word;
	return stream.str();
#endif
}

const std::string MOONG::ConvertDataType::to_string(const DWORD dword)
{
#if _MSC_VER > 1200
	return MOONG::ConvertDataType::to_string<const DWORD>(dword);
#else
	std::ostringstream stream;
	stream << dword;
	return stream.str();
#endif
}

const std::string MOONG::ConvertDataType::to_string(const int integer)
{
#if _MSC_VER > 1200
	return MOONG::ConvertDataType::to_string<const int>(integer);
#else
	std::ostringstream stream;
	stream << integer;
	return stream.str();
#endif
}

const std::string MOONG::ConvertDataType::to_string(const unsigned int unsigned_int)
{
#if _MSC_VER > 1200
	return MOONG::ConvertDataType::to_string<const unsigned int>(unsigned_int);
#else
	std::ostringstream stream;
	stream << unsigned_int;
	return stream.str();
#endif
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
	setlocale(LC_ALL, "korean");    // �� �ڵ尡 �־�� �ѱ��� ����� ��µ�.

	std::wstring wstr = L"";

	if (true == str.empty())
	{
		return wstr;
	}

#if _MSC_VER > 1200
	int required_cch = MultiByteToWideChar(
		CP_ACP,
		0,
		str.c_str(),
		static_cast<int>(str.size()),
		nullptr,
		0
	);
#else
	int required_cch = MultiByteToWideChar(
		CP_ACP,
		0,
		str.c_str(),
		static_cast<int>(str.size()),
		NULL,
		0
	);
#endif

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

const bool MOONG::ConvertDataType::string_to_bool(const std::string str)
{
	if (MOONG::StringTool::tolower_keep_origin(MOONG::StringTool::trim_keep_origin(str)).compare("true") == 0)
	{
		return true;
	}

	return false;
}

const std::wstring MOONG::ConvertDataType::utf8_to_wstring(const std::string str)
{
	setlocale(LC_ALL, "korean");    // �� �ڵ尡 �־�� �ѱ��� ����� ��µ�.

	std::wstring wstr = L"";

	if (true == str.empty())
	{
		return wstr;
	}

#if _MSC_VER > 1200
	int required_cch = MultiByteToWideChar(
		CP_UTF8,
		MB_ERR_INVALID_CHARS,
		str.c_str(),
		static_cast<int>(str.size()),
		nullptr,
		0
	);
#else
	int required_cch = MultiByteToWideChar(
		CP_UTF8,
		MB_ERR_INVALID_CHARS,
		str.c_str(),
		static_cast<int>(str.size()),
		NULL,
		0
	);
#endif

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
	setlocale(LC_ALL, "korean");    // �� �ڵ尡 �־�� �ѱ��� ����� ��µ�.

	std::string str = "";

	if (true == wstr.empty())
	{
		return str;
	}

#if _MSC_VER > 1200
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
#else
	int required_cch = WideCharToMultiByte(
		CP_ACP,
		0,
		wstr.c_str(),
		static_cast<int>(wstr.size()),
		NULL,
		0,
		NULL,
		NULL
	);
#endif

	if (0 == required_cch)
	{
		return str;
	}

	str.resize(required_cch);

#if _MSC_VER > 1200
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
#else
	WideCharToMultiByte(
		CP_ACP,
		0,
		wstr.c_str(),
		static_cast<int>(wstr.size()),
		const_cast<char*>(str.c_str()),
		static_cast<int>(str.size()),
		NULL,
		NULL
	);
#endif

	return str;
}

const std::string MOONG::ConvertDataType::wstring_to_utf8(const std::wstring wstr)
{
	setlocale(LC_ALL, "korean");    // �� �ڵ尡 �־�� �ѱ��� ����� ��µ�.

	std::string utf8 = "";

	if (true == wstr.empty())
	{
		return utf8;
	}

#if _MSC_VER > 1200
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
#else
	int required_cch = WideCharToMultiByte(
		CP_UTF8,
		0,
		wstr.c_str(),
		static_cast<int>(wstr.size()),
		NULL,
		0,
		NULL,
		NULL
	);
#endif

	if (0 == required_cch)
	{
		return utf8;
	}

	utf8.resize(required_cch);

#if _MSC_VER > 1200
	WideCharToMultiByte(
		CP_UTF8,
		WC_ERR_INVALID_CHARS,
		wstr.c_str(), static_cast<int>(wstr.size()),
		const_cast<char*>(utf8.c_str()),
		static_cast<int>(utf8.size()),
		nullptr,
		nullptr
	);
#else
	WideCharToMultiByte(
		CP_UTF8,
		0,
		wstr.c_str(), static_cast<int>(wstr.size()),
		const_cast<char*>(utf8.c_str()),
		static_cast<int>(utf8.size()),
		NULL,
		NULL
	);
#endif

	return utf8;
}

const SYSTEMTIME MOONG::ConvertDataType::milliseconds_to_systemtime(unsigned __int64 param_milliseconds)
{
	const unsigned __int64 milliseconds_equal_to_second = 1000;
	const unsigned __int64 milliseconds_equal_to_minute = milliseconds_equal_to_second * 60;
	const unsigned __int64 milliseconds_equal_to_hour = milliseconds_equal_to_minute * 60;
	const unsigned __int64 milliseconds_equal_to_day = milliseconds_equal_to_hour * 24;

	WORD day = static_cast<WORD>(param_milliseconds / milliseconds_equal_to_day);
	param_milliseconds %= milliseconds_equal_to_day;

	WORD hour = static_cast<WORD>(param_milliseconds / milliseconds_equal_to_hour);
	param_milliseconds %= milliseconds_equal_to_hour;

	WORD minute = static_cast<WORD>(param_milliseconds / milliseconds_equal_to_minute);
	param_milliseconds %= milliseconds_equal_to_minute;

	WORD second = static_cast<WORD>(param_milliseconds / milliseconds_equal_to_second);
	param_milliseconds %= milliseconds_equal_to_second;

	WORD milliseconds = static_cast<WORD>(param_milliseconds);

	SYSTEMTIME calculated_time = { 0 };
	calculated_time.wDay = day;
	calculated_time.wHour = hour;
	calculated_time.wMinute = minute;
	calculated_time.wSecond = second;
	calculated_time.wMilliseconds = milliseconds;

	return calculated_time;
}

const double MOONG::ConvertDataType::unsigned_int64_to_double(unsigned __int64 unsigned_int64_value)
{
	__int64 i64 = (unsigned_int64_value & 0x7FFFFFFFFFFFFFF);
	double dbl = static_cast<double>(i64);

	if (unsigned_int64_value & 0x8000000000000000)
	{
		dbl += static_cast<double>(0x8000000000000000);
	}

	return dbl;
}