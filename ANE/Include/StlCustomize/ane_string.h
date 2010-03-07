#pragma once
#include <xstring>

namespace Ane
{
typedef std::basic_string<char, std::char_traits<char>, std::allocator<char>> string; 

typedef std::basic_string<wchar_t, std::char_traits<wchar_t>, std::allocator<wchar_t>> wstring;

#ifdef _DEBUG
typedef Ane::string _tstring;
#else
typedef Ane::wstring _tstring;
#endif

}//namespace Ane