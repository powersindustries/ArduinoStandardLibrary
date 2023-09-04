#ifndef Vector_h
#define Vector_h


template <typename T>
class Vector
{
public:


    // ---------------------------------------------
    // ---------------------------------------------
	Vector()
	{
		m_Array = new T[4];

		m_iCapacity = 4;
		m_iSize = 0;
	}


    // ---------------------------------------------
    // ---------------------------------------------
	~Vector()
	{
		delete[] m_Array;
	}


    // ---------------------------------------------
    // ---------------------------------------------
	void push_back(T inData)
	{
		if (m_iSize == m_iCapacity)
		{
			IncreaseCapacity();
		}

		m_Array[m_iSize] = inData;
		m_iSize++;
	}


    // ---------------------------------------------
    // ---------------------------------------------
	void insert(int index, T inData)
	{
		if (index == m_iCapacity)
		{
			push_back(inData);
		}
		else
		{
			m_Array[index] = inData;
		}
	}


    // ---------------------------------------------
    // ---------------------------------------------
	void pop()
	{
		m_iSize--;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void clear()
	{
		m_iSize = 0;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void reserve(const int inCapacity)
	{
		m_iCapacity = inCapacity;
		m_iSize = 0;

		delete[] m_Array;
		m_Array = new T[m_iCapacity];
	}


    // ---------------------------------------------
    // ---------------------------------------------
	int size()
	{
		return m_iSize;
	}


    // ---------------------------------------------
    // ---------------------------------------------
	int capacity()
	{
		return m_iCapacity;
	}


    // ---------------------------------------------
    // ---------------------------------------------
	T& operator[](int index)
	{
		if (index >= m_iSize)
		{
			exit(0);
		}

		return m_Array[index];
	}


private:


    // ---------------------------------------------
    // ---------------------------------------------
	void IncreaseCapacity()
	{
		// Double capacity.
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
