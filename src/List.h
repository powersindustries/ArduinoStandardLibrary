#ifndef List_h
#define List_h


#include <cstdint>
template <typename T>
class LNode
{
public:


	// ---------------------------------------------
	// ---------------------------------------------
	LNode()
		: m_NextNode(nullptr), m_PreviousNode(nullptr)
	{
	}


	// ---------------------------------------------
	// ---------------------------------------------
	LNode(T inData)
		: m_NextNode(nullptr), m_PreviousNode(nullptr)
	{
		m_Data = inData;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	~LNode()
	{
	}


public:

	LNode* m_NextNode;
	LNode* m_PreviousNode;

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
	void push_back(const T inData)
	{
        LNode<T>* newNode = new LNode<T>(inData);

        if (m_iSize == 0)
        {
            m_HeadNode = newNode;
            m_iSize++;
            return;
        }

        LNode<T>* tempNode = m_HeadNode;
        while (tempNode != nullptr)
        {
            if (tempNode->m_NextNode == nullptr)
            {
                tempNode->m_NextNode = newNode;
                newNode->m_PreviousNode = tempNode; 
                newNode->m_NextNode = nullptr;

                m_iSize++;
                return;
            }

            tempNode = tempNode->m_NextNode;
        }
    }


	// ---------------------------------------------
	// ---------------------------------------------
	void push_front(const T inData)
	{
        LNode<T>* newNode = new LNode<T>(inData);

        if (m_HeadNode == nullptr)
        {
            m_HeadNode = newNode;
        }
        else
        {
            newNode->m_NextNode = m_HeadNode;
            newNode->m_PreviousNode = nullptr;

            m_HeadNode->m_PreviousNode = newNode;
            m_HeadNode = newNode;
        }

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

		LNode<T>* oldHeadNode = m_HeadNode;
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

		LNode<T>* tempListNode = m_HeadNode;
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
        if (index > m_iSize)
        {
            return;
        }

        if (index == 0)
        {
            push_front(inData);
        }
        else if (index == m_iSize)
        {
            push_back(inData);
        }
        else
        {
            LNode<T>* newNode = new LNode<T>(inData);

            LNode<T>* tempNode = m_HeadNode;
            unsigned int tempIndex = 0;
            while (tempNode != nullptr)
            {
                if (tempIndex == index)
                {
                    newNode->m_NextNode = tempNode;
                    newNode->m_PreviousNode = tempNode->m_PreviousNode;

                    tempNode->m_PreviousNode->m_NextNode = newNode;
                    tempNode->m_PreviousNode = newNode;

                    m_iSize++;
                    return;
                }

                tempNode = tempNode->m_NextNode;
                tempIndex++;
            }
        }
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
		return !m_HeadNode ? nullptr : m_HeadNode->m_Data;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	T* front()
	{
		return !m_HeadNode ? nullptr : &m_HeadNode->m_Data;
	}


	// ---------------------------------------------
	// ---------------------------------------------
	T* end()
	{
		if (!m_HeadNode)
		{
			return nullptr;
		}

		LNode<T>* tempListNode = m_HeadNode;
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
	T* back()
	{
		if (!m_HeadNode)
		{
			return nullptr;
		}

		LNode<T>* tempListNode = m_HeadNode;
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

	LNode<T>* m_HeadNode;

	uint8_t m_iSize;

};


#endif
