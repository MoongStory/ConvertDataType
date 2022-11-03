#include "ConvertDataType.h"

#include <iostream>

int main()
{
	try
	{
		const wchar_t* wchar_dummy = L"wstring to string, 한글 테스트";
		std::string string_dummy(MOONG::ConvertDataType::wstring_to_string(wchar_dummy));
		std::cout << string_dummy.c_str() << std::endl;
	}
	catch (const std::bad_alloc& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		const char* char_dummy = "string to wstring, 한글 테스트";
		std::wstring wstring_dummy(MOONG::ConvertDataType::string_to_wstring(char_dummy));
		std::wcout << wstring_dummy.c_str() << std::endl;
	}
	catch (const std::bad_alloc& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << std::endl;

	DWORD dword = 123;
	std::cout << "DWORD to std::string[" << MOONG::ConvertDataType::dword_to_string(dword).c_str() << "]" << std::endl;

	std::cout << std::endl;

	int integer = 123;
	std::cout << "int to std::string[" << MOONG::ConvertDataType::int_to_string(integer).c_str() << "]" << std::endl;

	return 0;
}