#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

//int main() {
//	char a[9], b[9];
//	char c = '\0';
//
//	cin >> setw(5) >> a >> setw(5) >> b;
//	cout << a <<endl;
//	cout << setw(5) << a << setw(5) << b << endl;
//	cout << setw(4) << a << setw(4) << b << endl;
//	cout << c << a << c << endl;
//}

//int main()
//{
//	char ch;
//	
//	while (true)
//	{
//		ch = cin.get();
//		cout << ch;
//		if (cin.get() == '0') break;
//	}
//
//	return 0;
//
//}

void readDataFromFileWordbyWord()
{
	ifstream fin("data.txt");
	char s;
	while (fin >> s) {
		cout << "Read from file: " << s << endl;
	}
	
}

void readDataFromFileintoCharArray()
{
	ifstream fin("data.txt");
	const int LINE_LENGTH = 100;
	char str[LINE_LENGTH];
	while (fin.getline(str, LINE_LENGTH))
	{
		cout << "Read from file: " << str << endl;

	}
}

void readDataFromFileLinebyLineintoString()
{
	ifstream fin("data.txt");
	string s;
	while (getline(fin, s)) {
		cout << "Read from file: " << s << endl;
	}
}

void readDataWithErrChecking()
{
	string filename = "dataFunny.txt";
	ifstream fin(filename.c_str());
	if (!fin) {
		cout << "Error opening " << filename << " for input" << endl;
		exit(-1);
	}
}
//
//int main()
//{
//	readDataFromFileintoCharArray();
//	cout << "_________________" << endl;
//	readDataFromFileLinebyLineintoString();
//	cout << "_________________" << endl;
//	readDataFromFileWordbyWord();
//	cout << "_________________" << endl;
//	readDataWithErrChecking();
//	cout << "_________________" << endl;
//
//}