#pragma once

#include <math.h>
#include <vector>
#include <iostream>
#include <stdio.h>
#include <stdarg.h>
/*
the amount of itemTypes will determine the order of the tensor
*/

///#define LOG(...) std::cout << __VA_ARGS__ << std::endl; 
//#define LOG(X) std::cout << X << std::endl;
/*
Tensor<isDiscrete=false, order=2, Dimensions=3> T1;
Tensor<itemType=float, order=2, Dimensions=3> T2;
Tensor<itemType=float, order=1, Dimensions_1=3, Dimensions_2=3, Dimensions_3=3> T3;

Tensor<space=L^p, itemType=float, order=2, Dimensions=3>
*/

static enum class Spaces : unsigned char
{
	_UNSPECIFIED = 0,
	SEuclidian,
	SLP,
	SBANANCH
};



template <class A, class B>
unsigned int _fold(A&&, B&& b)
{
	std::forward<B>(b);
}

template <typename T>
T sum(T t)
{
	return t;
}

template <typename... Args>
auto fold(Args... args)
{
	return args + sum(args...);
}



#define CONCAT_BRACES(_IN__Order) []##[]...

#define NUM_OPERATIONS(_IN_Order) \
if(_IN_Order == 0) \
{ \
	## \
} \
else \
{ \
	for(auto i = 0; i < _IN_Order; i++) \
	{ \
		CONCAT_BRACES([],[]) \
	} \
} \

#define NUM_INDICES(n) \
for (auto i = 0; i < n; i++) \
{ \
	_CONCAT([], ) \
} \

#define TENSOR(__ItemType, __Space, __Order, __Dim) \
template <class ItemType, Spaces space, unsigned int Order, unsigned int Dim> \
class _TENSOR \
{ \
protected: \
	unsigned int _num_elements = static_cast<unsigned int>(std::powf(static_cast<float>(Dim), static_cast<float>(Order))); \
public: \
} \

#define INF_PTR(__NUM_PTRS) \
	for (auto& i : _NUM_PTRS) \
	{ \
		
	} \

#define PTR_2 _CONCAT(*,*)


template <class ItemType, Spaces Space, unsigned int Order, unsigned int Dim>
class Tensor
{
protected:
	///constexpr unsigned int _num_elements = static_cast<std::powf(3, static_cast<sizeof...(Order)>(float))>(int);
	unsigned int _num_elements = static_cast<unsigned int>(std::powf(static_cast<float>(Dim), static_cast<float>(Order)));

	static int _iteration = Order;

	ItemType _elements[_num_elements];
	// = static_cast<unsigned int>(std::powf(3, static_cast<float>(sizeof...(order))));
	//std::vector<itemType...>* _elements = new std::vector<itemType>(3*sizeof...(itemType), 0);
public:
	//Tensor(const itemType&& _itemTypes) : itemType(_itemTypes)
	Tensor()
	{
		//_num_elements = static_cast<unsigned int>(std::powf(static_cast<float>(Dim), static_cast<float>(Order)));
		//LOG(Order);
		//LOG(_num_elements);
		std::cout << _num_elements << std::endl;
		std::cout << Order << std::endl;

		for (auto& i : _elements)
			_elements[i] = 0;
	}

	Tensor& operator[] (constexpr unsigned int index)
	{
		if (index > _num_elements)
			return 0;

		_iteration--;
		if (_iteration > 0)
		{
			for()
		}

	}

	~Tensor()
	{
		
	}
};

