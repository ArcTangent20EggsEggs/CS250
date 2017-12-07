#include "project1_LinkedList.hpp"

Node::Node()
{
	m_ptrNext = nullptr;
	m_ptrPrev = nullptr;
}

LinkedList::LinkedList()
{
	m_ptrFirst = nullptr;
	m_ptrLast = nullptr;
	m_itemCount = 0;
}

LinkedList::~LinkedList()
{
	Clear();
}

void LinkedList::Clear()
{
	while (m_itemCount > 0)
	{
		PopFront();
	}
}

void LinkedList::PushFront( CustomerData newData )
{
	Node* newNode = new Node;
	newNode->m_data = newData;
	m_itemCount++;
	if (m_ptrLast != nullptr && m_ptrFirst != nullptr)
	{
		m_ptrFirst->m_ptrPrev = newNode;
		newNode->m_ptrNext = newNode;
		m_ptrFirst = newNode;
	}
	else
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}
	
}

void LinkedList::PushBack( CustomerData newData )
{
	Node* newNode = new Node;
	newNode->m_data = newData;
	m_itemCount++;
	if (m_ptrLast != nullptr && m_ptrFirst != nullptr)
	{
		m_ptrLast->m_ptrNext = newNode;
		newNode->m_ptrPrev = newNode;
		m_ptrLast = newNode;
	}
	else
	{
		m_ptrFirst = newNode;
		m_ptrLast = newNode;
	}
	
}

void LinkedList::Insert(int index, CustomerData newData)
{
	int count = 0;
	Node* ptrCurrent = m_ptrFirst;
	Node* newNode = new Node;
	newNode->m_data = newData;
	while (count != index || ptrCurrent->m_ptrNext != nullptr)
	{
		if (ptrCurrent == nullptr)
		{
			throw("Greater then or equal to Linked List size!");
		}
		else
		{
			ptrCurrent = ptrCurrent->m_ptrNext;
			count++;
		}
	}
	if (count == index)
	{
		newNode->m_ptrPrev = ptrCurrent->m_ptrPrev;
		ptrCurrent->m_ptrPrev = newNode;
		newNode->m_ptrNext = ptrCurrent;
		m_itemCount++;
	}
	else
	{
		throw("Greater then or equal to Linked List size!");
	}
}


void LinkedList::PopFront() noexcept
{
	if (m_ptrFirst == m_ptrLast)
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	if (m_ptrLast != nullptr && m_ptrFirst != nullptr)
	{
		Node* newFirst = m_ptrFirst->m_ptrNext;
		newFirst->m_ptrPrev = nullptr;
		delete m_ptrFirst;
		m_ptrFirst = newFirst;
		m_itemCount--;
	}
	
}

void LinkedList::PopBack() noexcept
{
	if (m_ptrFirst == m_ptrLast)
	{
		delete m_ptrFirst;
		m_ptrFirst = nullptr;
		m_ptrLast = nullptr;
		m_itemCount--;
	}
	if (m_ptrLast != nullptr && m_ptrFirst != nullptr)
	{
		Node* newLast = m_ptrLast->m_ptrPrev;
		newLast->m_ptrNext = nullptr;
		delete m_ptrLast;
		m_ptrLast = newLast;
		m_itemCount--;
	}	
}

void LinkedList::Remove(int index)
{
	int count = 0;
	Node* ptrCurrent = m_ptrFirst;
	while (count != index || ptrCurrent->m_ptrNext != nullptr)
	{
		if (ptrCurrent == nullptr)
		{
			throw("Greater then or equal to Linked List size!");
		}
		else
		{
			ptrCurrent = ptrCurrent->m_ptrNext;
			count++;
		}
	}
	if (count == index)
	{
		Node* ptrPrev = ptrCurrent->m_ptrPrev;
		Node* ptrNext = ptrCurrent->m_ptrNext;
		ptrPrev->m_ptrNext = ptrNext;
		ptrNext->m_ptrPrev = ptrPrev;
		delete ptrCurrent;
		m_itemCount--;
	}
	else
	{
		throw("Greater then or equal to Linked List size!");
	}
}

CustomerData LinkedList::GetFront()
{
	if (m_ptrFirst != nullptr)
	{
		return m_ptrFirst->m_data;
	}
}

CustomerData LinkedList::GetBack()
{
	if (m_ptrLast != nullptr)
	{
		return m_ptrLast->m_data;
	}
}

CustomerData& LinkedList::operator[]( const int index )
{
	int count = 0;
	Node* ptrCurrent = m_ptrFirst;
	while (count != index || ptrCurrent->m_ptrNext != nullptr)
	{
		if (ptrCurrent == nullptr)
		{
			throw("Greater then or equal to Linked List size!");
		}
		else
		{
			ptrCurrent = ptrCurrent->m_ptrNext;
			count++;
		}
	}
	if (count == index)
	{
		return ptrCurrent->m_data;
	}
	else
	{
		throw("Greater then or equal to Linked List size!");
	}
}

bool LinkedList::IsEmpty()
{
	if (m_itemCount == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

int LinkedList::Size()
{
	return m_itemCount;
}

