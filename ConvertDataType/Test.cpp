#include "ConvertDataType.h"

#include <iostream>

int main()
{
	DWORD dword = 123;
	std::cout << "toString DWORD[" << MOONG::ConvertDataType::to_string(dword).c_str() << "]" << std::endl;

	std::cout << std::endl;

	int integer = 123;
	std::cout << "toString int[" << MOONG::ConvertDataType::to_string(integer).c_str() << "]" << std::endl;

	std::cout << std::endl;

	unsigned int unsigned_integer = 123;
	std::cout << "toString unsigned int[" << MOONG::ConvertDataType::to_string(unsigned_integer).c_str() << "]" << std::endl;

	std::cout << std::endl;

	const wchar_t* wchar_dummy = L"wstring_to_string, 한글 테스트";
	std::string string_dummy(MOONG::ConvertDataType::wstring_to_string(wchar_dummy));
	std::cout << string_dummy.c_str() << std::endl;

	std::cout << std::endl;

	std::string utf8 = MOONG::ConvertDataType::wstring_to_utf8(L"wstring_to_utf8, 한글 테스트");
#if _MSC_VER > 1200
	std::cout << "wstring_to_utf8[" << utf8.c_str() << "]" << std::endl;
#else
	printf("wstring_to_utf8[%s]\n", utf8.c_str());
#endif
	std::wstring wstr = MOONG::ConvertDataType::utf8_to_wstring(utf8);
#if _MSC_VER > 1200
	std::wcout << L"utf8_to_wstring[" << wstr << L"]" << std::endl;
#else
 	printf("utf8_to_wstring[%ws]\n", wstr.c_str());
#endif

	std::cout << std::endl;

	utf8 = MOONG::ConvertDataType::string_to_utf8("string_to_utf8, 한글 테스트");
#if _MSC_VER > 1200
	std::cout << "string_to_utf8[" << utf8.c_str() << "]" << std::endl;
#else
	printf("string_to_utf8[%s]\n", utf8.c_str());
#endif
	std::string str = MOONG::ConvertDataType::utf8_to_string(utf8);
#if _MSC_VER > 1200
	std::cout << "utf8_to_string[" << str.c_str() << "]" << std::endl;
#else
	printf("utf8_to_string[%s]\n", str.c_str());
#endif

	std::cout << std::endl;

	std::cout << "string_to_bool true[" << MOONG::ConvertDataType::string_to_bool("true") << "]" << std::endl;
	std::cout << "string_to_bool false[" << MOONG::ConvertDataType::string_to_bool("false") << "]" << std::endl;

	std::cout << std::endl;

	const char* char_dummy = "string_to_wstring, 한글 테스트";
	std::wstring wstring_dummy(MOONG::ConvertDataType::string_to_wstring(char_dummy));
#if _MSC_VER > 1200
	std::wcout << wstring_dummy.c_str() << std::endl;
#else
	printf("%ws\n", wstring_dummy.c_str());
#endif

	std::cout << std::endl;

	std::string string_number = "123";
	std::cout << "string_to_integer[" << MOONG::ConvertDataType::string_to_integer(string_number) + 1 << "]" << std::endl;

	std::cout << std::endl;

	unsigned __int64 int64_value = 3;
	std::cout << "unsigned_int64_to_double[" << MOONG::ConvertDataType::unsigned_int64_to_double(int64_value) + 1.1 << "]" << std::endl;

	std::cout << std::endl;

	unsigned long long milliseconds = 1001;
	SYSTEMTIME time = MOONG::ConvertDataType::milliseconds_to_systemtime(milliseconds);

	std::cout << std::endl;

	return 0;
}