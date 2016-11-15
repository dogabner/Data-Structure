#include <iostream>
#include "List.h"
using namespace std;

struct node
{
	char word;
	node* prev, *next;
	node(const char &w, node* p = NULL, node* q = NULL)
	{
		word = w; prev = p; next = q;
	}
	node() :prev(NULL), next(NULL) {  };
	~node() {};
};

class line
{
private:
	int wordNum;
	node* head, *tail;
	node* move(int i) const;
public:
	line* prev, *next;
	line();
	line(const line&);
	void addWords(const char & word);
	void printWords();
	void printWords(int start, int end);

	~line();
};

class article
{
private:
	int lineNum;
	line* head, *tail;

public:
	article();
	void addLine(void (line::*addWords)());
	void list(int start, int end);
	void printLine(int l);
	void ins(int line, int col, const char * w);
	void del();
	void quit();
	~article();
};

node * line::move(int i) const
{
	node *p = head->next;
	while (i--) p = p->next;
	return p;
}

line::line()
{
	wordNum = 0;
	head = new node;
	tail = new node;

	head->prev = NULL;
	tail->next = NULL;
	head->next = tail;
	tail->prev = head;
}

line::line(const line& line2)
{

}

void line::addWords(const char & word)
{
	node *w = new node;
	w->next = tail;
	w->prev = tail->prev;
	w->word = word;
}

void line::printWords()
{
	node* p = head->next;
	for (int i = 0; i < wordNum; ++i) cout << p->word;
	cout << endl;
}

void line::printWords(int start, int end)
{
	if (start<=0 || start > wordNum || start>end) { cout << "Error!\n"; }
	else {
		node* p = move(start);
		for (int i = 0; i < end - start + 1; ++i) cout << p->word;
		cout << endl;
	}
}

article::article()
{
	lineNum = 0;
	head = new line;
	tail = new line;

	head->prev = NULL;
	tail->next = NULL;
	head->next = tail;
	tail->prev = head;

}

void article::list(int start, int end)
{
	if (start <= 0 || end > lineNum || start > end) { cout << "Error!\n"; return; }
	else {
		line* p = head->next;
		for (int i = 0; i < end - start + 1; ++i) p->printWords();
	}

}

void article::printLine(int l)
{
	
}
