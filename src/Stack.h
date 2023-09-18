#ifndef Stack_h
#define Stack_h


template <typename T>
class Stack 
{
public:


	// ---------------------------------------------
	// ---------------------------------------------
	Stack()
	{
		m_Array = new T[4];

		m_iCapacity = 4;
		m_iSize = 0;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	~Stack()
	{
		delete[] m_Array;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void push(T inData)
	{
		if (m_iSize == m_iCapacity)
		{
			DoubleCapacity();
		}

		m_Array[m_iSize] = inData;
		m_iSize++;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	T* top()
	{
	    return &m_Array[m_iSize - 1];
    }


	// ---------------------------------------------
	// ---------------------------------------------
	void pop()
	{
		m_iSize--;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void empty()
	{
		m_iSize = 0;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	int size()
	{
		return m_iSize;
	}


private:


	// ---------------------------------------------
	// ---------------------------------------------
	void DoubleCapacity()
	{
		T* tempArray = new T[2 * m_iCapacity];

		for (int x = 0; x < m_iCapacity; ++x)
		{
			tempArray[x] = m_Array[x];
		}

		delete[] m_Array;
		m_Array = tempArray;

		m_iCapacity *= 2;
	}


private:

	T* m_Array;

	int m_iCapacity;
	int m_iSize;

};

#endif
