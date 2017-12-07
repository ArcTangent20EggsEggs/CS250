#include "lab3_SmartStaticArray.hpp"
#include "cuTEST/Menu.hpp"

SmartStaticArray::SmartStaticArray()
{
}

int SmartStaticArray::Size() const
{
        return -1; // placeholder
}

bool SmartStaticArray::IsFull() const
{
        return false; // placeholder
}

bool SmartStaticArray::IsEmpty() const
{
        return false; // placeholder
}

string SmartStaticArray::Get( int index ) const
{
    return ""; // placeholder
}

void SmartStaticArray::Pop()
{
}

void SmartStaticArray::ShiftRight( int index )
{
}

void SmartStaticArray::ShiftLeft( int index )
{
}

void SmartStaticArray::Push( const string& newItem )
{
}

void SmartStaticArray::Insert( int index, const string& newItem )
{
}

void SmartStaticArray::Extend( const SmartStaticArray& other )
{
}

void SmartStaticArray::Remove( int index )
{
}

SmartStaticArray& SmartStaticArray::operator=( const SmartStaticArray& other )
{
        for ( int i = 0; i < other.m_itemCount; i++ )
        {
        m_data[i] = other.m_data[i];
        m_itemCount++;
        }

        return *this;
}

bool SmartStaticArray::operator==( const SmartStaticArray& other )
{
        if ( m_itemCount != other.m_itemCount )
        {
        return false;
        }

        for ( int i = 0; i < m_itemCount; i++ )
        {
        if ( m_data[i] != other.m_data[i] )
        {
            return false;
        }
        }

        return true;
}

bool SmartStaticArray::operator!=( const SmartStaticArray& other )
{
        return !( *this == other );
}

string SmartStaticArray::operator[]( int index )
{
    return Get( index );
}
