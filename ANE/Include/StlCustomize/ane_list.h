#pragma once
#include <list>

namespace Ane
{
template<typename _Ty, typename _Ax = std::allocator<_Ty>>
class list
	: public std::list<_Ty, _Ax>
{

};
}//namespace Ane