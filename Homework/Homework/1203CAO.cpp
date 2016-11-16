#include <iostream>
using namespace std;

template <class T>
struct LinkNode
{
    T data;
    LinkNode<T> *next;
    LinkNode(LinkNode<T> *ptr = NULL) { next = ptr; }
    LinkNode(const T &item, LinkNode<T> *ptr = NULL)
    {
        next = ptr;
        data = item;
    }
};
template <class T>
class LinkList
{
    template <class U>
    friend LinkList<U> operator+(const LinkList<U> &l1, const LinkList<U> &l2);
    // template <class U>
    // friend istream & operator >> (istream &is, LinkList<U> &link);
    // template <class U>
    // friend ostream & operator<<(ostream &os, const LinkList<U> &link);

  public:
    LinkList() { head = new LinkNode<T>; }
    LinkList(const T &item) { head = new LinkNode<T>(item); }
    ~LinkList() { Clear(); }
    LinkList<T> &operator=(LinkList<T> &List);

    friend istream &operator>>(istream &is, T &link)
    {
        link.Insert(is);
    }

    friend ostream &operator<<(ostream &os, const LinkList<T> &link)
    {
        LinkNode<T> *p;

        p = link.head->next;
        while (p->next != NULL)
        {
            os << (p->data);
            p = p->next;
        }
        return os;
    }

    void Clear();
    void Insert(T &d);
    void Print() const;
    void Reverse();

  private:
    LinkNode<T> *head;
};

template <class T>
void LinkList<T>::Insert(T &d)
{
    LinkNode<T> *p = new LinkNode<T>(d);
    p->next = head->next;
    head->next = p;
}

template <class T>
void LinkList<T>::Clear()
{
    LinkNode<T> *p = NULL;

    while (NULL != head->next)
    {
        p = head->next;
        head->next = p->next;
        delete p;
    }
}

template <class T>
void LinkList<T>::Print() const
{
    int count = 0;
    LinkNode<T> *p = head;
    while (NULL != p->next)
    {
        p = p->next;
        std::cout << p->data << " ";
        if (++count % 10 == 0)
            cout << std::endl;
    }
}

template <class T>
void LinkList<T>::Reverse()
{
    LinkNode<T> *pre = head->next;
    LinkNode<T> *curr = pre->next;
    LinkNode<T> *next = NULL;

    head->next->next = NULL;
    while (curr)
    {
        next = curr->next;
        curr->next = pre;
        pre = curr;
        curr = next;
    }

    head->next = pre;
}

template <class T>
LinkList<T> operator+(const LinkList<T> &l1, const LinkList<T> &l2)
{
    LinkNode<T> *temp = l2->next;
    while (temp->next)
        temp = temp->next;
    temp->next = l1->next;
}

int main()
{
    char type[7];
    int length = 0;
    int sizeA, sizeB = 0;
    cin >> type;
    cin >> sizeA >> sizeB;
    for (int i = 0; type[i] != '\0'; i++)
        length += 1;
    switch (length)
    {
    case 3:
    {
        LinkList<int> linkA, linkB;
        for (int i = 0; i < sizeA; ++i)
        {
            cin >> linkA;
        }
        for (int i = 0; i < sizeB; ++i)
        {
            cin >> linkB;
        }
        cout << linkA + linkB;
        break;
    }
    case 4:
    {
        LinkList<char> linkA, linkB;
        for (int i = 0; i < sizeA; ++i)
        {
            cin >> linkA;
        }
        for (int i = 0; i < sizeB; ++i)
        {
            cin >> linkB;
        }
        linkA + linkB;
        break;
    }
    case 5:
    {
        LinkList<float> linkA, linkB;
        for (int i = 0; i < sizeA; ++i)
        {
            cin >> linkA;
        }
        for (int i = 0; i < sizeB; ++i)
        {
            cin >> linkB;
        }
        cout << linkA + linkB;
        break;
    }
    default:
        break;
    }
}