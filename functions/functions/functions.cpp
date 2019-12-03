#include <iostream>
using namespace std;

int helloWorld()
{
	cout << "Hello World!\n";
	int lol;
	cin >> lol;
	return lol;
}

void lol(int arbidol) {
	cout << arbidol << "- that's kek";
}

void main()
{
	int kek;
	kek = helloWorld();
	cout << "kek" << kek << endl;
	lol(kek);
}