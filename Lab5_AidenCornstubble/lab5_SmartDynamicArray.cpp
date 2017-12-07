#include "lab5_SmartDynamicArray.hpp"

#include "cuTEST/Menu.hpp"

SmartDynamicArray::SmartDynamicArray()
{
}

SmartDynamicArray::~SmartDynamicArray()
{
}

void SmartDynamicArray::AllocateMemory()
{
}

void SmartDynamicArray::AllocateMemory( int newSize )
{
}

void SmartDynamicArray::DeallocateMemory()
{
}


bool SmartDynamicArray::IsInvalidIndex( int index ) const
{
    return false; // placeholder
}


bool SmartDynamicArray::IsNonContiguousIndex( int index ) const
{
    return false; // placeholder
}


void SmartDynamicArray::Push( const string& newItem )
{
}


void SmartDynamicArray::Pop()
{
}


bool SmartDynamicArray::IsEmpty() const
{
    return false; // placeholder
}


void SmartDynamicArray::ShiftRight( int index )
{
}


void SmartDynamicArray::ShiftLeft( int index )
{
}


void SmartDynamicArray::Resize()
{
}


void SmartDynamicArray::Resize( int newSize )
{
}


bool SmartDynamicArray::IsFull() const
{
    return false; // placeholder
}


int SmartDynamicArray::Size() const
{
    return -1; // placeholder
}


void SmartDynamicArray::Remove( int index )
{
}


string SmartDynamicArray::Get( int index ) const
{
    return "placeholder"; // placeholder
}


void SmartDynamicArray::Insert( int index, const string& newItem )
{
}


void SmartDynamicArray::Extend( const SmartDynamicArray& other )
{
}


string SmartDynamicArray::operator[]( int index )
{
    return Get( index );
}


SmartDynamicArray& SmartDynamicArray::operator=( const SmartDynamicArray& other )
{
    for ( int i = 0; i < other.m_itemCount; i++ )
    {
        m_data[i] = other.m_data[i];
        m_itemCount++;
    }

    return *this;
}

bool SmartDynamicArray::operator==( const SmartDynamicArray& other )
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


bool SmartDynamicArray::operator!=( const SmartDynamicArray& other )
{
    return !( *this == other );
}
