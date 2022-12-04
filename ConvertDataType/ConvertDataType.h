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
	// GitHub 저장소 다시 생성.
	class ConvertDataType
	{
	public:
	protected:
	private:

	public:
		static const std::string wstring_to_string(const std::wstring wstr) noexcept(false);
		static const std::wstring string_to_wstring(const std::string str) noexcept(false);
		static const std::string toString(const DWORD dword);
		static const std::string toString(const int integer);
		static const std::string toString(const unsigned int unsigned_int);
	protected:
	private:
	};
}
#endif	// _CONVERT_DATA_TYPE_H_