#include <iostream>
#include <cstring>
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
	line(const char * l);
	// void addWords(const char & word);
	void printWords();
	void printWords(int start, int end);
	void ins(int col, const char *l);
	void del(int col, int num);
	~line();
};

class article
{
private:
	int lineNum;
	line* head, *tail;
	line* move(int i) const;

public:
	article();
	void addLine(const char * l);
	void list(int start, int end);
	void printLine(int l);
	void ins(int row, int col, const char * l);
	void del(int row, int col, int num);
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
	// cout << "$line constructor!" << endl;

	wordNum = 0;
	head = new node;
	tail = new node;

	head->prev = NULL;
	tail->next = NULL;
	head->next = tail;
	tail->prev = head;
}

line::line(const char * l)
{
	// cout << "$line constructor!" << endl;

	wordNum = 0;
	head = new node;
	tail = new node;

	head->prev = NULL;
	tail->next = NULL;
	head->next = tail;
	tail->prev = head;

	for (int i = 0; i < strlen(l); ++i) {
		node * p = tail->prev;
		node * q;
		q = new node(l[i], p, p->next);
		p->next->prev = q;
		p->next = q;
		++wordNum;
	}

}

void line::printWords()
{
	node* p = head->next;
	for (int i = 0; i < wordNum; ++i) {
		cout << p->word;
		p = p->next;
	}
	cout << endl;
	//cout << endl;
}

void line::printWords(int start, int end)
{
	if (start <= 0 || start > wordNum || start > end) { cout << "Error!\n"; }
	else {
		node* p = move(start);
		for (int i = 0; i < end - start + 1; ++i) {
			cout << p->word;
			p = p->next;
		}
		//cout << endl;
	}
	cout << endl;
}

void line::ins(int col, const char *l)
{
	if (col < 0 || col > wordNum) { cout << "Error!\n"; return; }

	node* p = move(col);
	node* word;
	for (int i = 0; i < strlen(l); ++i) {
		word = new node(l[i], p->prev, p);
		p->prev->next = word;
		p->prev = word;
		++wordNum;
	}
}

void line::del(int col, int num)
{
	if (col < 0 || col + num > wordNum || num < 0) { cout << "Error!\n"; return; }
	node *p = move(col), *q, *r;
	r = p->prev;
	for (int i = 0; i < num; ++i) {
		q = p->next;
		delete p;
		r->next = q;
		q->prev = r;
		p = q;
		--wordNum;
	}
}

line::~line()
{
	// cout << "$line destructor!" << endl;

	node*p = head->next, *q;
	while (p != tail) {
		q = p->next;
		delete p;
		p = q;
	}
	delete head;
	delete tail;
}

article::article()
{
	// cout << "$article constructor!" << endl;

	lineNum = 0;
	head = new line;
	tail = new line;

	head->prev = NULL;
	tail->next = NULL;
	head->next = tail;
	tail->prev = head;

}

void article::addLine(const char * l)
{
	line* tmp;
	tmp = new line(l);
	tmp->next = tail;
	tmp->prev = tail->prev;
	tail->prev->next = tmp;
	tail->prev = tmp;
	++lineNum;
}

line* article::move(int i) const
{
	line *p = head;
	while (i--) p = p->next;
	return p;
}

void article::list(int start, int end)
{
	if (start <= 0 || end > lineNum || start > end) { cout << "Error!\n"; return; }
	else {
		line* p = move(start);
		int lines = end - start + 1;
		while (lines--) {
			p->printWords();
			p = p->next;
		}
	}
}

void article::printLine(int l)
{
	line *p = move(l);
	p->printWords();
	// cout << endl;
}

void article::ins(int row, int col, const char * l)
{
	if (row <= 0 || row > lineNum ) { cout << "Error!\n"; return; }
	line *p = move(row);
	p->ins(col-1, l);
}

void article::del(int row, int col, int num)
{
	if (row <= 0 || row > lineNum) { cout << "Error!\n"; return; }
	line *p = move(row);
	p->del(col-1, num);
}

void article::quit()
{
	for (int i = 1; i <= lineNum; ++i) {
		printLine(i);
	}
}

article::~article()
{
	// cout << "$article destructor!" << endl;

	line*p = head->next, *q;
	while (p != tail) {
		q = p->next;
		delete p;
		p = q;
	}
	delete head;
	delete tail;
}

int main()
{
	char content[2001]; article art; int start, end, row, col, num;
	char ls[100];
	cin.getline(content, 2001);
	while (strcmp(content, "******") != 0) {
		art.addLine(content);
		cin.getline(content, 2001);
	}
	cin >> content;
	while (strcmp(content, "quit") != 0) {
		if (strcmp(content, "list") == 0) {
			cin >> start >> end;
			art.list(start, end);
		}
		else if (strcmp(content, "ins") == 0) {
			cin >> row >> col;
			cin.get();
			cin.getline(content, 2001);
			art.ins(row, col, content);
		}
		else if (strcmp(content, "del") == 0) {
			cin >> row >> col >> num;
			art.del(row, col, num);
		}
		cin >> content;
	}
	art.quit();
	return 0;
}