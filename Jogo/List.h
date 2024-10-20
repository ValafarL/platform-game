#pragma once
#include "Element.h"
#include "stdfx.h"
template <class TYPE>
class List
{
private:
	int nElements;
	Element<TYPE>* pFirst;
	Element<TYPE>* pCurrent;
public:
	List();
	~List();
	void include(Element<TYPE>* pElem);
	void includeElement(TYPE* pElem);
	void list();
	void plusElements();
	void minusElements();
	int getNumberOfElements();
	void clearList(Element<TYPE>* pDeleting);
	Element<TYPE>* getFirst();
	void remove(Element<TYPE>* pElement);

};

template<class TYPE>
List<TYPE>::List()
{
	nElements = 0;
	pFirst = NULL;
	pCurrent = NULL;
}

template<class TYPE>
List<TYPE>::~List()
{
	if (pFirst != NULL)
	{
		clearList(pFirst);
	}
	pFirst = NULL;
	pCurrent = NULL;
}

template<class TYPE>
void List<TYPE>::include(Element<TYPE>* pElem)
{
	if (pFirst == NULL)
	{
		pFirst = pElem;
		pCurrent = pElem;
		pFirst->setPrev(NULL);
		pFirst->setNext(NULL);
	}
	else
	{
		pCurrent->setNext(pElem);
		pElem->setPrev(pCurrent);
		pElem->setNext(NULL);
		pCurrent = pElem;
	}
}
template<class TYPE>
inline void List<TYPE>::includeElement(TYPE* pElem)
{
	if (pElem != NULL)
	{
		if (pFirst == NULL)
		{
			Element<TYPE>* pAux;
			pAux = new Element<TYPE>();
			pFirst = pAux;
			pCurrent = pAux;
			pFirst->setPrev(NULL);
			pFirst->setNext(NULL);
			pFirst->setElement(pElem);
		}
		else
		{
			Element<TYPE>* pAux;
			pAux = new Element<TYPE>();
			pCurrent->setNext(pAux);
			pAux->setPrev(pCurrent);
			pAux->setNext(NULL);
			pCurrent = pAux;
			pCurrent->setElement(pElem);
		}
	}
	else
	{
		cout << "ELEMENTO NULO" << endl;
	}
}
template<class TYPE>
inline void List<TYPE>::list()
{
	Element<TYPE>* pAux;
	pAux = pFirst;
	if (pAux == NULL)
	{
		cout << "PRIMEIRO PONTEIRO EH NULO" << endl;
	}
	else
	{

	}
}
template<class TYPE>
void List<TYPE>::plusElements()
{
	nElements++;
}
template<class TYPE>
void List<TYPE>::minusElements()
{
	nElements--;
}
template<class TYPE>
int List<TYPE>::getNumberOfElements()
{
	return nElements;
}

template<class TYPE>
inline void List<TYPE>::clearList(Element<TYPE>* pDeleting)
{
	if (pDeleting->getNext() != NULL)
	{
		clearList(pDeleting->getNext());
	}
	delete(pDeleting);
}

template<class TYPE>
inline Element<TYPE>* List<TYPE>::getFirst()
{
	return pFirst;
}

template<class TYPE>
inline void List<TYPE>::remove(Element<TYPE>* pElement)
{
	if (pElement)
	{
		if (pElement->getPrev() == NULL)
		{
			pFirst = pElement->getNext();
			if (pFirst)
			{
				pFirst->setPrev(NULL);
			}
			delete pElement;
		}
		else
		{
			Element<TYPE>* pPrev = pElement->getPrev();
			Element<TYPE>* pNext = pElement->getNext();
			if (pNext)
			{
				pNext->setPrev(pPrev);
			}
			pPrev->setNext(pNext);
			delete pElement;
		}
	}
}
