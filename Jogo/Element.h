#pragma once
#include "stdfx.h"
template <class TYPE>
class Element
{
private:
	Element<TYPE>* pNext;
	Element<TYPE>* pPrev;
	TYPE* element;

public:
	Element();
	~Element();
	void setNext(Element<TYPE>* pElem);
	Element<TYPE>* getNext();
	void setPrev(Element<TYPE>* pElem);
	Element<TYPE>* getPrev();
	void setElement(TYPE* pElement );
	TYPE* getElement();
};

	template<class TYPE>
	inline Element<TYPE>::Element()
	{
		pNext = NULL;
		pPrev = NULL;
		element = NULL;
	}

	template<class TYPE>
	inline Element<TYPE>::~Element()
	{
		pNext = NULL;
		pPrev = NULL;
		element = NULL;
	}

	template <class TYPE>
	void Element<TYPE>::setNext(Element<TYPE>*pElem)
	{
		pNext = pElem;
	}

	template<class TYPE>
	inline Element<TYPE>* Element<TYPE>::getNext()
	{
		return pNext;
	}

	template <class TYPE>
	void Element<TYPE>::setPrev(Element<TYPE>* pElem)
	{
		pPrev = pElem;
	}

	template<class TYPE>
	inline Element<TYPE>* Element<TYPE>::getPrev()
	{
		return pPrev;
	}

	template<class TYPE>
	inline void Element<TYPE>::setElement(TYPE* pElement)
	{
		element = pElement;
	}

	template<class TYPE>
	inline TYPE* Element<TYPE>::getElement()
	{
		return element;
	}
