#include <iostream>
#include <stack>
#include <list>
using namespace std;

void printNum(int);
//
//int main()
//{
//	int num;
//	cin >> num;
//	printNum(num);
//	return 0;
//}

void printNum(int num)
{
	stack <int,list<int>> s;
	int tmp;
	int t;
	//while (t = num%10)
	//{
	//	s.push(t);
	//	num = num / 10;
	//}
	s.push(num);

	while (!s.empty()) {
		tmp = s.top();
		s.pop();
		if (tmp > 9) {
			s.push(tmp % 10);
			s.push(tmp / 10);
		}
		else
			cout.put(tmp + '0');
	}
}