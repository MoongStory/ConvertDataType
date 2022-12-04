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
	// GitHub 历厘家 促矫 积己.
	class ConvertDataType
	{
	public:
	protected:
	private:

	public:
		static const std::string toString(const DWORD dword);
		static const std::string toString(const int integer);
		static const std::string toString(const unsigned int unsigned_int);

		static const int string_to_integer(const std::string str);
		static const std::wstring string_to_wstring(const std::string str) noexcept(false);
		static const std::string wstring_to_string(const std::wstring wstr) noexcept(false);

	protected:
	private:
	};
}
#endif	// _CONVERT_DATA_TYPE_H_