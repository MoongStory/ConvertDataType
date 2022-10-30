#include "ConvertDataType.h"

#if _MSC_VER > 1200
    #include <locale>
#else
    #include <locale.h>
#endif

#include <sstream>

const std::string MOONG::ConvertDataType::wstring_to_string(const std::wstring wstr) noexcept(false)
{
    setlocale(LC_ALL, "korean");    // 이 코드가 있어야 한글이 제대로 출력됨.

    size_t new_size = (wstr.length() + 1) * 2;

    char* nstring = NULL;
    try
    {
        nstring = new char[new_size];
    }
    catch (const std::bad_alloc& exception)
    {
        throw MOONG::Exception(MOONG::EXCEPTION::CODE::BAD_ALLOC, exception.what());
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

const std::wstring MOONG::ConvertDataType::string_to_wstring(const std::string str) noexcept(false)
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
        throw MOONG::Exception(MOONG::EXCEPTION::CODE::BAD_ALLOC, exception.what());
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

const std::string MOONG::ConvertDataType::dword_to_string(const DWORD dword)
{
    std::ostringstream stream;
    stream << dword;
    return stream.str();
}
