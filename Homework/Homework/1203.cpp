#include <iostream>
using namespace std;


//template <class T>
//void getInput(&LinkRec linkA, &LinkRec linkA, sizeA, sizeB);
//
template<class T>
struct Node
{
	T data;
	Node<T> *next;
	Node(Node<T> *ptr = NULL) { next = ptr; }
	Node(const T &d) : data(d), next(NULL) {};
};

template <class T>
class LinkRec
{
	template <class U>
	friend LinkRec<U> operator+(const LinkRec<U> &l1, const LinkRec<U> &l2);
	template <class U>	
	friend ostream & operator<<(ostream &os, const LinkRec<U> &link);
	template <class U>
	friend istream & operator >> (istream &is, const LinkRec<U> &link);
public:
	LinkRec<T>() { this->head = new Node(0); }
	//LinkRec(LinkRec<T> &Rec);
	~LinkRec() { this->clear(); }
	void createLinkRec();
	void insert(const T &d);
	void reverse();

private:
};

// template <class T>
// LinkRec<T>::createLinkRec() {
// 	head = new Node(0);
// }

template <class T>
void LinkRec<T>::clear()
{
	Node<T> *p = NULL;
	while (p) {
		p->next = head->next;
		head->next = p->next;
		delete p;
	}
	p = NULL;
}


template <class T>
LinkRec<T>::insert(const T &d)
{
	Node *p = new Node(d);
	p->next = head->next;
	head->next = p;
	
}

template <class T>
LinkRec<T>::reverse()
{
	Node<T> *pre = head->next;
	Node<T> *curr = pre->next;
	Node<T> *next = NULL;

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
LinkRec<T> operator+(const LinkRec<T> &l1, const LinkRec<T> &l2)
{
    LinkRec<T> tmp(l1.length + l2.length);
    Node<T> *temp = l1->next;
    //LinkRec::Node *temp2 = l2.head->next;
    while (temp->next)
	temp = head->next;
    temp->next = l1->next;

    return tmp;
}

template <class T>
ostream & operator << (ostream & os, const LinkRec<T> & link) {
	LinkRec::Node *p = link.head->next;
	while (p->next != NULL) {
		os << (p->data);
		p = p->next;
	}
	return os;
}

template <class T>
istream & operator >> (istream &is, const LinkRec<T> &link) {
	link.insert(is);
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
	LinkRec<int> linkA, linkB;
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
		LinkRec<char> linkA, linkB;
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
    case 5:
	{
		LinkRec<float> linkA, linkB;
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
