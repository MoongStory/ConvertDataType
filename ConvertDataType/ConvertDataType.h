// https://github.com/MoongStory/ConvertDataType

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _CONVERT_DATA_TYPE_H_
#define _CONVERT_DATA_TYPE_H_

#include <iostream>
//#include <Windows.h>
#include <wtypes.h>

namespace MOONG
{
	class ConvertDataType
	{
	public:
	protected:
	private:

	public:
		// 문자열
		static const std::string toString(const WORD word);
		static const std::string toString(const DWORD dword);
		static const std::string toString(const int integer);
		static const std::string toString(const unsigned int unsigned_int);

		static const int string_to_integer(const std::string str);
		static const std::wstring string_to_wstring(const std::string str);
		static const std::string string_to_utf8(const std::string str);
		static const bool string_to_bool(const std::string str);

		static const std::wstring utf8_to_wstring(const std::string str);
		static const std::string utf8_to_string(const std::string str);

		static const std::string wstring_to_string(const std::wstring wstr);
		static const std::string wstring_to_utf8(const std::wstring wstr);

		// 숫자
		static const SYSTEMTIME milliseconds_to_systemtime(unsigned long long param_milliseconds);

		static const double unsigned_int64_to_double(unsigned __int64 unsigned_int64_value);
	protected:
	private:
#if _MSC_VER > 1200
		template <typename T>
		inline static const std::string toString(const T parameter)
		{
			std::ostringstream stream;
			stream << parameter;
			return stream.str();
		}
#endif
	};
}
#endif	// _CONVERT_DATA_TYPE_H_