#pragma once
#include <vector>

namespace Ane
{
template<typename _Ty, typename _Ax = std::allocator<_Ty>>
class vector
	: public std::vector<_Ty, _Ax>
{

};
}//namespace Ane