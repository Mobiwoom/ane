#pragma once
#include <map>

namespace Ane
{
template<typename _K, typename _Ty>
class map
	: public std::map<_K, _Ty>
{

};
}//namespace Ane