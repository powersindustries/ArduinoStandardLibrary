#ifndef Deque_h
#define Deque_h

#define DEQUEU_MAX 128

template <typename T>
class Deque
{
public:


	// ---------------------------------------------
	// ---------------------------------------------
	Deque(int inSize)
		: m_Array(nullptr)
	{
		m_iSize = inSize;

		m_Array = new T[128];

		m_iBackIndex = 0;
		m_iFrontIndex = -1;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	bool empty()
	{
		return m_iFrontIndex == -1;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	bool full()
	{
		return (m_iFrontIndex == 0 && m_iBackIndex == (m_iSize - 1)) || (m_iFrontIndex == (m_iBackIndex + 1));
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void push_front(const T inData)
	{
		if (full())
		{
			return;
		}

		if (m_iFrontIndex == -1)
		{
			m_iFrontIndex = 0;
			m_iBackIndex = 0;
		}
		else if (m_iFrontIndex == 0)
		{
			m_iFrontIndex = m_iSize - 1;
		}
		else
		{
			m_iFrontIndex = m_iFrontIndex - 1;
		}

		m_Array[m_iFrontIndex] = inData;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void push_back(const T inData)
	{
		if (full())
		{
			return;
		}

		if (m_iFrontIndex == -1)
		{
			m_iFrontIndex = 0;
			m_iBackIndex = 0;
		}
		else if (m_iBackIndex == m_iSize - 1)
		{
			m_iBackIndex = 0;
		}
		else
		{
			m_iBackIndex = m_iBackIndex + 1;
		}

		m_Array[m_iBackIndex] = inData;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void pop_front()
	{
		if (empty())
		{
			return;
		}

		if (m_iBackIndex == m_iFrontIndex)
		{
			m_iBackIndex = -1;
			m_iFrontIndex = -1;
		}
		else if (m_iFrontIndex == m_iSize - 1)
		{
			m_iFrontIndex = 0;
		}
		else
		{
			m_iFrontIndex = m_iFrontIndex + 1;
		}
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void pop_back()
	{
		if (empty())
		{
			return;
		}

		if (m_iFrontIndex == m_iBackIndex)
		{
			m_iFrontIndex = -1;
			m_iBackIndex = -1;
		}
		else if (m_iBackIndex == 0)
		{
			m_iBackIndex = m_iSize - 1;
		}
		else
		{
			m_iBackIndex = m_iBackIndex - 1;
		}
	}


	// ---------------------------------------------
	// ---------------------------------------------
	T* front()
	{
		if (empty())
		{
			return nullptr;
		}

		return m_Array[m_iFrontIndex];
	}


	// ---------------------------------------------
	// ---------------------------------------------
	T* back()
	{
		if (empty() || m_iBackIndex < 0)
		{
			return nullptr;
		}

		return m_Array[m_iBackIndex];
	}


private:

	T* m_Array;

	int m_iSize;
	int m_iBackIndex;
	int m_iFrontIndex;

};


#endif
