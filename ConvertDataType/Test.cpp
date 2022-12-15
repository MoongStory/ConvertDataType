#include "ConvertDataType.h"

#include <iostream>

int main()
{
	DWORD dword = 123;
	std::cout << "toString DWORD[" << MOONG::ConvertDataType::toString(dword).c_str() << "]" << std::endl;

	std::cout << std::endl;

	int integer = 123;
	std::cout << "toString int[" << MOONG::ConvertDataType::toString(integer).c_str() << "]" << std::endl;

	std::cout << std::endl;

	unsigned int unsigned_integer = 123;
	std::cout << "toString unsigned int[" << MOONG::ConvertDataType::toString(unsigned_integer).c_str() << "]" << std::endl;

	std::cout << std::endl;

	unsigned long seconds = (55 * 24 * 60 * 60 * 1) + (2 * 60 * 60 * 1) + (61 * 60 * 1) + (60 * 1);
	std::cout << "toString unsigned int[" << MOONG::ConvertDataType::seconds_to_data(seconds).c_str() << "]" << std::endl;

	std::cout << std::endl;

	try
	{
		const wchar_t* wchar_dummy = L"wstring_to_string, 한글 테스트";
		std::string string_dummy(MOONG::ConvertDataType::wstring_to_string(wchar_dummy));
		std::cout << string_dummy.c_str() << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << std::endl;

	try
	{
		const char* char_dummy = "string_to_wstring, 한글 테스트";
		std::wstring wstring_dummy(MOONG::ConvertDataType::string_to_wstring(char_dummy));
		std::wcout << wstring_dummy.c_str() << std::endl;
	}
	catch (const std::exception& exception)
	{
		std::cout << exception.what() << std::endl;
	}

	std::cout << std::endl;

	std::string string_number = "123";
	std::cout << "string_to_integer[" << MOONG::ConvertDataType::string_to_integer(string_number) + 1 << "]" << std::endl;

	std::cout << std::endl;

	unsigned __int64 int64_value = 3;
	std::cout << "unsigned_int64_to_double[" << MOONG::ConvertDataType::unsigned_int64_to_double(int64_value) + 1.1 << "]" << std::endl;

	std::cout << std::endl;

	return 0;
}