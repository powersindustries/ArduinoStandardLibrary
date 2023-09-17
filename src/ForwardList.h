#ifndef ForwardList_h
#define ForwardList_h

#include <cstdint>
template <typename T>
struct FLNode
{
    FLNode() 
        : m_NextNode(nullptr)
    {}

    FLNode* m_NextNode;
    T m_Data;

};

template <typename T>
class ForwardList
{
public:


	// ---------------------------------------------
	// ---------------------------------------------
	ForwardList()
        : m_HeadNode(nullptr)
	{
        m_Count = 0;
	}


	// ---------------------------------------------
	// ---------------------------------------------
    T* front()
    {
        if(!m_HeadNode)
        {
            return nullptr;
        }

        return m_HeadNode->m_Data;
    }


	// ---------------------------------------------
	// ---------------------------------------------
    void push_back(T inData)
    {
        FLNode<T>* newNode = new FLNode<T>();
        newNode->m_Data = inData;

        if (m_HeadNode == nullptr)
        {
            m_HeadNode = newNode;
            m_Count++;
            return;
        }

        FLNode<T>* tempNode = m_HeadNode;
        while (tempNode != nullptr)
        {
            if (tempNode->m_NextNode == nullptr)
            {
                tempNode->m_NextNode = newNode;
                break;
            }

            tempNode = tempNode->m_NextNode;
        }

        m_Count++;
    }


	// ---------------------------------------------
	// ---------------------------------------------
    void push_front(T inData)
    {
        FLNode<T>* newNode = new FLNode<T>();
        newNode->m_Data = inData;

        if (m_HeadNode == nullptr)
        {
            m_HeadNode = newNode;
            m_Count++;
            return;
        }

        newNode->m_NextNode = m_HeadNode;
        m_HeadNode = newNode;
        m_Count++;
    }


	// ---------------------------------------------
	// ---------------------------------------------
    void insert(const uint8_t index, int inData)
    {
        if (index == 0)
        {
            push_front(inData);
        }
        else if (index >= m_Count)
        {
            push_back(inData);
        }
        else
        {
            FLNode<T>* newNode = new FLNode<T>();
            newNode->m_Data = inData;

            FLNode<T>* previousNode = m_HeadNode;

            for (unsigned int x = 0; x < index - 1; ++x)
            {
                previousNode = previousNode->m_NextNode;
            }

            newNode->m_NextNode = previousNode->m_NextNode;
            previousNode->m_NextNode = newNode;
            m_Count++;
        }
    }


	// ---------------------------------------------
	// ---------------------------------------------
    void remove(const uint8_t index)
    {
        if (index > m_Count)
        {
            return;
        }

        FLNode<T>* tempNode = m_HeadNode;
        if (index == 0)
        {
            m_HeadNode = m_HeadNode->m_NextNode;

            delete tempNode;

            m_Count--;
            return;
        }

        for (unsigned int x = 1; tempNode != nullptr && x < index - 1; ++x)
        {
            tempNode = tempNode->m_NextNode;
        }

        if (tempNode == nullptr || tempNode->m_NextNode == nullptr)
        {
            return;
        }

        FLNode<T>* nextNode = tempNode->m_NextNode->m_NextNode;
        delete tempNode->m_NextNode;
        tempNode->m_NextNode = nextNode;

        m_Count--;
        return;
    }


private:

    FLNode<T>* m_HeadNode;

    uint8_t m_Count;

};


#endif
