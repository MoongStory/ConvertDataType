// https://github.com/MoongStory/ConvertDataType

#if _MSC_VER > 1000
#pragma once
#endif

#ifndef _CONVERT_DATA_TYPE_H_
#define _CONVERT_DATA_TYPE_H_

#include <iostream>
#include <Windows.h>

namespace MOONG
{
	class ConvertDataType
	{
	public:
	protected:
	private:

	public:
		static const std::string toString(const DWORD dword);
		static const std::string toString(const int integer);
		static const std::string toString(const unsigned int unsigned_int);

		static const std::string seconds_to_data(const unsigned long seconds);

		static const int string_to_integer(const std::string str);
		static const std::wstring string_to_wstring(const std::string str);
		static const std::string wstring_to_string(const std::wstring wstr);

		static double unsigned_int64_to_double(unsigned __int64 unsigned_int64_value);
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