#ifndef List_h
#define List_h


template <typename T>
class ListNode
{
public:


	// ---------------------------------------------
	// ---------------------------------------------
	ListNode()
		: m_NextNode(nullptr)
	{
	}


	// ---------------------------------------------
	// ---------------------------------------------
	ListNode(T inData)
		: m_NextNode(nullptr)
	{
		m_Data = inData;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	ListNode(T inData, ListNode* inNextNode)
		: m_NextNode(inNextNode)
	{
		m_Data = inData;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	~ListNode()
	{
	}


public:

	ListNode* m_NextNode;

	T m_Data;

};


template <typename T>
class List
{
public:


	// ---------------------------------------------
	// ---------------------------------------------
	List()
		: m_HeadNode(nullptr)
	{
		m_iSize = 0;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	~List()
	{
		delete m_HeadNode;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	T* front()
	{
		return !m_HeadNode ? nullptr : &m_HeadNode->m_Data;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	T* back()
	{
		if (!m_HeadNode)
		{
			return nullptr;
		}

		ListNode<T>* tempListNode = m_HeadNode;
		while (tempListNode)
		{
			if (!tempListNode->m_NextNode)
			{
				break;
			}

			tempListNode = tempListNode->m_NextNode;
		}

		return &tempListNode->m_Data;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void push_back(const T inData)
	{
		if (!m_HeadNode)
		{
			m_HeadNode = new ListNode<T>(inData);
			m_iSize++;
			return;
		}

		ListNode<T>* tempListNode = m_HeadNode;
		while (tempListNode)
		{
			if (!tempListNode->m_NextNode)
			{
				break;
			}

			tempListNode = tempListNode->m_NextNode;
		}

		ListNode<T>* newListNode = new ListNode<T>(inData);
		tempListNode->m_NextNode = newListNode;

		m_iSize++;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void push_front(const T inData)
	{
		if (!m_HeadNode)
		{
			m_HeadNode = new ListNode<T>(inData);
			m_iSize++;
			return;
		}

		ListNode<T>* newListNode = new ListNode<T>(inData);
		ListNode<T>* oldHeadNode = m_HeadNode;
		newListNode->m_NextNode = oldHeadNode;

		m_HeadNode = newListNode;

		m_iSize++;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void pop_front()
	{
		if (!m_HeadNode)
		{
			return;
		}
		else if (!m_HeadNode->m_NextNode)
		{
			delete m_HeadNode;
			return;
		}

		ListNode<T>* oldHeadNode = m_HeadNode;
		m_HeadNode = m_HeadNode->m_NextNode;
		delete oldHeadNode;

		m_iSize--;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void pop_back()
	{
		if (!m_HeadNode)
		{
			return;
		}
		else if (!m_HeadNode->m_NextNode)
		{
			delete m_HeadNode;
			return;
		}

		ListNode<T>* tempListNode = m_HeadNode;
		while (tempListNode)
		{
			if (!tempListNode->m_NextNode->m_NextNode)
			{
				break;
			}

			tempListNode = tempListNode->m_NextNode;
		}

		delete tempListNode->m_NextNode->m_NextNode;

		tempListNode->m_NextNode = nullptr;

		m_iSize--;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	void insert(const int index, T inData)
	{
		if (!m_HeadNode || index >= m_iSize)
		{
			return;
		}

		ListNode<T>* tempListNode = m_HeadNode;
		for (int x = 0; x < index - 1; ++x)
		{
			tempListNode = tempListNode->m_NextNode;
		}

		ListNode<T>* newNode = new ListNode<T>(inData);
		ListNode<T>* newNextNode = tempListNode->m_NextNode;

		tempListNode->m_NextNode = newNode;
		newNode->m_NextNode = newNextNode;

		m_iSize++;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	const int size()
	{
		return m_iSize;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	T* begin()
	{
		return !m_HeadNode : nullptr ? m_HeadNode->m_Data;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	T* end()
	{
		if (!m_HeadNode)
		{
			return nullptr;
		}

		ListNode<T>* tempListNode = m_HeadNode;
		while (tempListNode)
		{
			if (!tempListNode->m_NextNode)
			{
				break;
			}

			tempListNode = tempListNode->m_NextNode;
		}

		return &tempListNode->m_Data;
	}


private:

	ListNode<T>* m_HeadNode;

	int m_iSize;

};


#endif
