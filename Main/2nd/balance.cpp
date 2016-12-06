#include <iostream>
#include <fstream>
#include "seqStack.cpp"
using namespace std;


class balance
{
private:
	ifstream fin;
	int currentLine;
	int Error;

	struct Symbol
	{
		char Token;
		int TheLine;
	};

	enum CommentType {
		SlashSlash, SlashStar
	};

	bool CheckMatch(char Symb1, char Symb2, int Line1, int Line2);
	char GetNextSymbol();
	void PutBackChar(char ch);
	void SkipComment(enum CommentType type);
	void SkipQuote(char type);
	char NextChar();

public:
	balance(const char*s);
	int CheckBalance();
};

class noFile {};

balance::balance(const char*s) 
{
	fin.open(s);
	if (!fin)throw noFile();

	currentLine = 1;
	Error = 0;
}

int balance::CheckBalance()
{
	struct Symbol node;
	seqStack <Symbol> st;
	char LastChar, Match;

	while (LastChar = GetNextSymbol()) {
		switch (LastChar)
		{
		case'(':case'[':case'{':
			node.Token = LastChar;
			node.TheLine = currentLine;
			st.push(node);
			break;

		case')':case']':case'}':
			if (st.isEmpty()) {
				Error++;
				cout << "In Line " << currentLine << " left redundant " << LastChar << endl;
			}
			else {
				node = st.pop(); Match = node.Token;
				if (!CheckMatch(Match, LastChar, node.TheLine, currentLine)) 
					Error++;
			}
			break;

		default:
			break;
		}
	}
	while (!st.isEmpty()) {
		Error++;
		node = st.pop();
		cout << "In Line " << node.TheLine << " Symbol " << node.Token << " not match" << endl;
	}

	return Error;
}

bool balance::CheckMatch(char Symb1, char Symb2, int Line1, int Line2)
{
	if (Symb1 == '('&&Symb2 != ')' || Symb1 == '['&&Symb2 != ']' || Symb1 == '{'&&Symb2 != '}') {
		cout << "In Line " << Line2 << " symbol " << Symb2 << " not match line " << Line1 << " symbol " << Symb1 << endl;
		return false;
	}
	else return true;
}

char balance::GetNextSymbol()
{
	char ch;
	while (ch = NextChar()) {
		if (ch == '/') {
			ch = NextChar();
			if (ch == '*') SkipComment(SlashStar);
			else if (ch == '/') SkipComment(SlashSlash);
			else PutBackChar(ch);
		}
		else if (ch == '\'' || ch == '"')SkipQuote(ch);
		else if (ch == '{' || ch == '[' || ch == '{' || ch == '}' || ch == ']' || ch == '}') return ch;
	}

	return NULL;
}

char balance::NextChar()
{
	char ch;
	if ((ch = fin.get()) == EOF) return NULL;
	if ((ch == '\n')) currentLine++;

	return ch;
}

void balance::PutBackChar(char ch)
{
	fin.putback(ch);
	if (ch == '\n') currentLine--;
}

void balance::SkipQuote(char type)
{
	char ch;
	while ((ch = NextChar())) {
		if (ch == type) return;
		else if (ch == '\n') {
			Error++;
			cout << "missing closing quote at line " << currentLine << endl;
			return;
		}
		else if (ch == '\\') ch = NextChar();
	}
}

void balance::SkipComment(enum CommentType type)
{
	char ch, flag;

	if (type == SlashSlash) {
		while ((ch = NextChar()) && (ch != '\n'));
		return;
	}

	flag = ' ';
	while ((ch = NextChar()) != NULL) {
		if (flag == '*'&&ch == '/') return;
		flag = ch;
	}
	Error++;
	cout << "Comment is unterminated!" << endl;
}

//int main(int argc, const char ** argv)
//{
//	char filename[80];
//	balance * p;
//	int result;
//
//	try {
//		if (argc == 1) {
//			cout << "Please enter file name: "; cin >> filename;
//			p = new balance(filename);
//			result = p->CheckBalance();
//			delete p;
//			cout << "Total errors: " << result << endl;
//			return 0;
//		}
//		while (--argc)
//		{
//			cout << "checking file... " << *++argv << endl;
//			p = new balance(*argv);
//			result = p->CheckBalance();
//			delete p;
//			cout << "Total errors: " << result << endl;
//		}
//	}
//	catch (noFile) { cout << "no such file" << endl; }
//	return 0;
//
//}