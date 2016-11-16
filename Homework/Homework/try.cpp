#include <iostream>
//#include "List.h"
using namespace std;

class OutOfBound
{};
template <class T>
class list
{
public:
	virtual void clear() = 0;
	virtual int length() const = 0;
	virtual void insert(int i, const T &x) = 0;
	virtual void remove(int i) = 0;
	virtual int search(const T &x)const = 0;
	virtual T visit(int i)const = 0;
	virtual void traverse()const = 0;
	virtual ~list() {};
};


template <class T>
struct node {
	T data;
	node *prev, *next;
	node(const T& x, node *p = NULL, node *n = NULL) {
		data = x; prev = p; next = n;
	}
	node() :prev(NULL), next(NULL) {}
	~node() {}
};

template <class T>
class linkList : public list <T>
{
	template <class U>
	friend linkList<U> operator + (const linkList<U> & list1, const linkList<U> & list2);
private:
	node<T> *head, *tail;
	int currentLength;
	node<T> * move(int i) const;

public:
	linkList();
	~linkList() { clear(); delete head; delete tail; }
	void clear();
	int length() const { return currentLength; }
	void insert(int i, const T & x);
	void insertBefore(const T & x);
	void append(const T &x);
	void remove(int i);
	// void reverse(linkList<T> &list);
	int search(const T & x) const;
	T visit(int i) const;
	void traverse()const;
	T endOfList() const { return visit(currentLength - 1); }
	node<T> * operator [](int i) const { return move(i); }
	// node <T> & previous(node<T> & listnode) const { return listnode->prev; }
};

template <class T>
node<T> * linkList<T>::move(int i) const
{
	node<T> * p = head->next;
	if (i > currentLength || i < 0) throw OutOfBound();
	while (i--) p = p->next;
	return p;
}

template <class T>
linkList<T>::linkList()
{
	head = new node<T>;
	tail = new node<T>;
	head->next = tail;
	tail->prev = head;
	currentLength = 0;
}

template<class T>
void linkList<T>::clear()
{
	node<T> *p = head->next, *q;
	head->next = tail;
	tail->prev = head;
	while (p != tail) {
		q = p->next;
		delete p;
		p = q;
	}
}

template<class T>
void linkList<T>::insert(int i, const T& x)
{
	node<T> * pos, *tmp;
	pos = move(i);
	tmp = new node<T>(x, pos->prev, pos);
	pos->prev->next = tmp;
	pos->prev = tmp;

	++currentLength;
}

template<class T>
void linkList<T>::insertBefore(const T & x)
{
	node<T> * pos = head, *tmp;
	tmp = new node<T>(x, pos, pos->next);
	pos->next->prev = tmp;
	pos->next = tmp;
	++currentLength;
}

template<class T>
void linkList<T>::append(const T & x)
{
	insert(currentLength, x);
}


template<class T>
void linkList<T>::remove(int i)
{
	node<T> *pos;
	pos = move(i);
	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;

	delete pos;
	--currentLength;
}

//template<class T>
//void linkList<T>::reverse(linkList<T>& list)
//{
//	node<T> *p = head->next, *q = tail->prev, *tmp;
//	tmp = p;
//	p = q;
//	q = tmp;
//	while (q->next != p) {
//		q->next
//	}
//}

template<class T>
int linkList<T>::search(const T& x) const
{
	node<T> *p = head->next;
	int i = 0;
	while (true) {
		if (p->next == NULL) return -1;
		else if (p->data == x) {
			return i;
		}
		++i;
	}
}

template<class T>
T linkList<T>::visit(int i)const
{
	node<T> * pos;
	pos = move(i);
	return(pos->data);
}

template<class T>
void linkList<T>::traverse() const
{
	node<T> *pos = head->next;
	while (pos != tail) {
		cout << pos->data;
		pos = pos->next;
	}
	cout << endl;
}


int main()
{
	linkList<int> num1, num2;
	char n;
	cin.get(n);

	while (n != '\n') {
		num1.append(n - '0');
		cin.get(n);
	}

	cin.get(n);
	while (n != '\n') {
		num2.append(n - '0');
		cin.get(n);
	}
	linkList<int> list = num1 + num2;
	list.traverse();
	//unsigned short tmp = 0;
	//node<int> * smallNumber = new node<int>;
	//node<int> * bigNumber = new node<int>;
	//
	//smallNumber = num1[num1.length()]->prev;
	//bigNumber = num2[num2.length()]->prev;
	//while (smallNumber->prev && bigNumber->prev)
	//{
	//	bigNumber->data += smallNumber->data;
	//	tmp = bigNumber->data / 10;
	//	smallNumber->data = bigNumber->data %= 10;
	//	smallNumber = smallNumber->prev;
	//	bigNumber = bigNumber->prev;
	//	if (tmp > 0 && bigNumber->prev)
	//	{
	//		while (true) {
	//			bigNumber->data += tmp;
	//			tmp = bigNumber->data / 10;
	//			bigNumber->data %= 10;
	//			num2.traverse();
	//			if (tmp > 0) {
	//				bigNumber = bigNumber->prev;
	//			}
	//			else {
	//				break;
	//			}
	//			if (bigNumber->prev == NULL) { num2.insert(0, tmp); bigNumber = bigNumber->next; tmp = 0; break; }

	//		}
	//	}

	//	else if (tmp > 0 && smallNumber->prev)
	//	{
	//		while (true) {
	//			smallNumber->data += tmp;
	//			tmp = smallNumber->data / 10;
	//			smallNumber->data %= 10;
	//			if (tmp > 0) {
	//				smallNumber = smallNumber->prev;
	//			}
	//			else {
	//				break;
	//			}
	//			if (smallNumber->prev == NULL) { num1.insert(0, tmp); smallNumber = smallNumber->next; tmp = 0; break; }
	//		}
	//	}


	//}
	//if (bigNumber->prev) num2.traverse();
	//else num1.traverse();
	getchar();
	return 0;
}

template <class T, class U>
linkList<U> operator+(const linkList<U> &list1, const linkList<U> &list2)
{
	unsigned short tmp = 0;
	unsigned short sum = 0;
	linkList <U> newList;
	node<T> * number1 = new node<T>;
	node<T> * number2 = new node<T>;

	number1 = list1[list1.length()]->prev;
	number2 = list2[list2.length()]->prev;

	sum = number1->data + number2->data;
	tmp = sum / 10;
	newList.append(sum % 10);
	while (number1->prev && number2->prev) {
		number1 = number1->prev;
		number2 = number2->prev;
		sum = number1->data + number2->data + tmp;
		tmp = sum / 10;
		newList.insertBefore(sum % 10);
	}
	while (number1->prev) {
		number1 = number1->prev;
		sum = number1->data + tmp;
		tmp = sum / 10;
		linkList.insertBefore(sum % 10);
	}
	while (number2->prev) {
		number2 = number2->prev;
		sum = number2->data + tmp;
		tmp = sum / 10;
		newList.insertBefore(sum % 10);
	}
	return(newList);

}
