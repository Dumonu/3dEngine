#ifndef LIST_H_
#define LIST_H_

template <class T>
class Node
{
public:
    T val;
    Node<T>* next;

    Node(T val, Node<T>* next)
    {
        this->val = val;
        this->next = next;
    }
};

template <class T>
class List
{
public:
    Node<T>* head;
    Node<T>* tail;

    int size;

    List()
    {
        head = nullptr;
        tail = nullptr;
        size = 0;
    }

    ~List()
    {
        tail = nullptr;
        while(head != nullptr)
        {
            Node<T>* p = head; //save reference to head
            head = head->next; //move head to next
            delete p;          //delete first node
        }
    }
    
    T operator[](int i)
    {
        Node<T>* n = head;
        for(int j = 0; j < i && n != nullptr; ++j)
        {
            n = n->next; //keep going until we get to the right node
        }
        return n->val; //now return its value
    }

    void add(T val)
    {
        Node<T>* in = new Node<T>(val, nullptr);
        if(tail != nullptr)
            tail->next = in; //insert after tail node

        tail = in;  //and update tail pointer
        if(head == nullptr)
            head = in; //if the list is empty, update head to match

        ++size;
    }
    
    void remove(T val)
    {
        Node<T>** n = &head;
        while(*n != nullptr)
        {
            if((**n).val == val)
            {
                Node<T>* temp = (**n).next; // prev next pointer equals this next pointer
                delete *n;       // now we can get rid of the Node
                *n = temp;
                --size;
                return;     //and we're done
            }
            n = &((**n).next); // move pointer n along
        }
    }
};

#endif
