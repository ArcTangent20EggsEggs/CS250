#ifndef _SMART_DYNAMIC_ARRAY_HPP
#define _SMART_DYNAMIC_ARRAY_HPP

#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

class SmartDynamicArray
{
    public:
	SmartDynamicArray()
	{
		m_itemCount = 0;
		m_arraySize = 0;
		m_data = nullptr;
	}
	~SmartDynamicArray()
	{
		DeallocateMemory();
	}

	void Push(const string& newItem)
	{
		if (m_data == nullptr)
		{
			AllocateMemory();
		}
		if (IsFull())
		{
			Resize();
		}
		m_data[m_itemCount] = newItem;
		m_itemCount++;
	}
	void Insert(int index, const string& newItem)
	{		
		if (m_data[index - 1] == "")
		{
			throw out_of_range("Cannot insert at index - must be contiguous");
		}
		else if (index < 0)
		{
			throw out_of_range("Cannot get at index - out of range");
		}
		else
		{
			if (IsFull())
			{
				Resize();
			}
			ShiftRight(index);
			m_data[index] = newItem;
			m_itemCount++;
		}			
	}
	void Extend(const SmartDynamicArray& other)
	{
		if (m_itemCount + other.m_itemCount >= m_arraySize)
		{
			Resize(m_itemCount + other.m_itemCount);
		}
		for (int i = 0; i < other.m_itemCount; i++)
		{
			Push(other.Get(i));
		}
	}
	void Pop() noexcept
	{
		if (m_itemCount > 0)
		{
			m_itemCount--;
		}
	}
	void Remove(int index)
	{
		if (index < 0 || index >= m_itemCount)
		{
			throw out_of_range("Cannot insert at index - out of range");
		}
		else
		{
			ShiftLeft(index);
			m_itemCount--;
		}
	}
	string Get(int index) const
	{
		if (index < 0 || index >= m_itemCount)
		{
			throw out_of_range("Cannot get at index - out of range");
		}
		else
		{
			return m_data[index];
		}
	}
	void Resize()
	{
		Resize(m_arraySize + 10);
	}
	void Resize(int newSize)
	{
		if (m_data == nullptr)
		{
			AllocateMemory(newSize);
			return;
		}
		string* tempStr = new string[newSize];
		for (int i = 0; i < m_arraySize; i++)
		{
			tempStr[i] = m_data[i];
		}
		delete(m_data);
		m_data = tempStr;
		m_arraySize = newSize;
	}

	int Size() const noexcept
	{
		return m_itemCount;
	}
	bool IsFull() const noexcept
	{
		if (m_itemCount == m_arraySize)
			return true;
		else
			return false;
	}
	bool IsEmpty() const noexcept
	{
		if (m_itemCount == 0)
			return true;
		else
			return false;
	}

    string operator[]( int index );
    SmartDynamicArray& operator=( const SmartDynamicArray& other );
    bool operator==( const SmartDynamicArray& other );
    bool operator!=( const SmartDynamicArray& other );

    private:
	void ShiftRight(int index) noexcept
	{
		for (int i = m_itemCount; i > index; i--)
		{
			m_data[i] = m_data[i - 1];
		}
	}
	void ShiftLeft(int index)
	{
		for (int i = index; i < m_itemCount - 1; i++)
		{
			m_data[i] = m_data[i + 1];
		}
	}
	bool IsInvalidIndex(int index) const noexcept
	{
		if (index < 0)
			return true;
		else
			return false;
	}
	bool IsNonContiguousIndex(int index) const
	{
		if (index > m_itemCount)
			return true;
		else
			return false;
	}
	void AllocateMemory()
	{
		AllocateMemory(10);
	}
	void AllocateMemory(int newSize)
	{
		if (m_data == nullptr)
		{
			m_arraySize = newSize;
			m_itemCount = 0;
			m_data = new string[m_arraySize];
		}
		else
		{
			throw logic_error("Memory cannot be allocated because m_data is already pointing to something");
		}
	}
	void DeallocateMemory()
	{
		if (m_data != nullptr)
		{
			delete(m_data);
			m_data = nullptr;
		}
	}

    string* m_data;
    int m_itemCount;
    int m_arraySize;

    friend class Tester;
};

#endif
