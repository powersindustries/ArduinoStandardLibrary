#ifndef Queue_h
#define Queue_h

#define MAX_CAPACITY 128

template<typename T>
class Queue
{
public:


    // ---------------------------------------------
    // ---------------------------------------------
    Queue()
    {
        m_Array = new T[MAX_CAPACITY];
        m_iHead = -1;
        m_iTail = -1;
    }


    // ---------------------------------------------
    // ---------------------------------------------
    ~Queue()
    {
        delete[] m_Array;
    }


    // ---------------------------------------------
    // ---------------------------------------------
    bool empty()
    {
        return m_iHead == -1;
    }


    // ---------------------------------------------
    // ---------------------------------------------
    void enqueu(T inData)
    {
        if (full())
        {
            return;
        }

        m_Array[m_iTail] = inData;
        if (m_iTail == MAX_CAPACITY - 1)
        {
            m_iTail = 0;
        } else
        {
            m_iTail++;
        }
    }


    // ---------------------------------------------
    // ---------------------------------------------
    void dequeue()
    {
        if (full())
        {
           return;
        }

        if (m_iHead == MAX_CAPACITY - 1)
        {
            m_iHead = 0;
        } else
        {
            m_iHead++;
        }
    }


    // ---------------------------------------------
    // ---------------------------------------------
    T front()
    {
        return m_Array[m_iHead];
    }


    // ---------------------------------------------
    // ---------------------------------------------
    T back()
    {
        return m_Array[m_iTail - 1];
    }


private:


    // ---------------------------------------------
    // ---------------------------------------------
    bool full()
    {
        return (m_iHead == m_iTail + 1) || (m_iHead == 1 && m_iTail == MAX_CAPACITY);
    }


private:

    T *m_Array;

    int m_iHead;
    int m_iTail;

};

#endif
