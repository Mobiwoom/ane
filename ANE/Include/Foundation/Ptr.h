#pragma once

namespace Ane
{
template<class Type>
class Ptr
{
public:
	Ptr();
	Ptr(Type* p);
	Ptr(const Ptr<Type>& p);
	~Ptr();

	void										operator=(const Ptr<Type>& p);
	void										operator=(Type* p);
	bool										operator==(const Ptr<Type>& p)				const;
	bool										operator!=(const Ptr<Type>& p)				const;
	bool										operator==(const Type* p)					const;
	bool										operator!=(const Type* p)					const;
	Type*										operator->()								const;
	Type&										operator*()									const;
	operator									Type*()										const;

private:
	Type*									m_Ptr;
};

template<class Type>
Ptr<Type>::Ptr()
: m_Ptr(0)
{

}

template<class Type>
Ptr<Type>::Ptr(Type* p)
:m_Ptr(p)
{
	if(0 != this->m_Ptr)
	{
		this->m_Ptr->InitRef();
		this->m_Ptr->AddRef();
	}
}

template<class Type>
Ptr<Type>::Ptr(const Ptr<Type> &p)
:m_Ptr(p.m_Ptr)
{
	if(0 != this->m_Ptr)
	{
		this->m_Ptr->AddRef();
	}
}

template<class Type>
Ptr<Type>::~Ptr()
{
	if(0 != this->m_Ptr)
	{
		this->m_Ptr->Release();
		this->m_Ptr = 0;
	}
}

template<class Type>
void Ptr<Type>::operator=(const Ptr<Type>& p)
{
	if(this->m_Ptr)
	{
		this->m_Ptr->Release();
	}
	this->m_Ptr = p.m_Ptr;
	if(this->m_Ptr)
	{
		this->m_Ptr->AddRef();
	}
}

template<class Type>
void Ptr<Type>::operator=(Type* p)
{
	if(this->m_Ptr)
	{
		this->m_Ptr->Release();
	}
	this->m_Ptr = p;
	if(this->m_Ptr)
	{
		this->m_Ptr->AddRef();
	}
}

template<class Type>
bool Ptr<Type>::operator==(const Ptr<Type>& p) const
{
	return (this->m_Ptr == p.m_Ptr);
}

template<class Type>
bool Ptr<Type>::operator!=(const Ptr<Type>&p) const
{
	return(this->m_Ptr != p.m_Ptr);
}

template<class Type>
bool Ptr<Type>::operator ==(const Type* p) const
{
	return (this->m_Ptr == p);
}

template<class Type>
bool Ptr<Type>::operator!=(const Type* p)const
{
	return (this->m_Ptr != p);
}

template<class Type>
Type* Ptr<Type>::operator->() const
{
	return this->m_Ptr;
}

template<class Type>
Type& Ptr<Type>::operator*() const
{
	this->m_Ptr->AddRef();
	return this->m_Ptr;
}


template<class Type>
Ptr<Type>::operator Type*() const
{
	this->m_Ptr->AddRef();
	return this->m_Ptr;
}
}