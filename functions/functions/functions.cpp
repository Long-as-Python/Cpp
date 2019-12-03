#include <iostream>
using namespace std;

int helloWorld()
{
	cout << "Hello World!\n";
	int lol;
	cin >> lol;
	return lol;
}

void main()
{
	int kek;
	kek = helloWorld();
	cout << "kek" << kek << endl;
}