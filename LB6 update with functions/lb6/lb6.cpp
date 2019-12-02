#include <iostream>
#include <math.h>
#include <stdlib.h>
#include <iomanip>
using namespace std;


void exOne() {
	float x, y, y1, e;
	int n;
	//  cout << "x = ";
	//  cin >> x;
	//  cout << "n = ";
	//  cin >> n;
	//  cout << "e = ";
	//  cin >> e;
	x = 11.6;
	n = 6;
	e = 0.1;
	y = x;
	y1 = (1. / n) * (x / pow(y, n - 1) + (n - 1) * y);
	while (fabs(y1 - y) > e) {
		y = y1;
		y1 = (1. / n) * (x / pow(y, n - 1) + (n - 1) * y);
	}
	cout << "y1 = " << y1 << endl;
}


void exTwo() {
	float x, y, x1, x0, e;
	int i;
	//  cout << "x0 = ";
	//  cin >> x0;
	//  cout << "e = ";
	//  cin >> e;
	x0 = 2;
	e = 0.0001;
	x = x0;
	x1 = x - (pow(x, 3) + x - 3) / (3 * pow(x, 2) + 1);
	for (i = 0; fabs(x1 - x) > e; i++) {
		x = x1;
		x1 = x - (pow(x, 3) + x - 3) / (3 * pow(x0, 2) + 1);
	}
	cout << "x1 = " << x1 << endl;
	cout << "i = " << i << endl;
}


void exThree() {
	float x, x1 = 1, e, sum, n;
	int  i;
	//  cout << "x = ";
	//  cin >> x;
	//  cout << "e = ";
	//  cin >> e;
	x = 0.3;
	e = 0.01;
	n = 2;
	sum = 1 + x / 2;
	for (i = 0; fabs(x1) > e; i++) {
		n *= 2 * n;
		x1 = ((2 * n - 1) / (2 * n)) * pow(x, n);
		sum += x1;
		cout << "n= " << n << endl;
	}
	cout << "f(x) = " << sum << endl;
	cout << "x1 = " << x1 << endl;
	cout << "n = " << n << endl;
}


void exFour() {
	float e, x, y, y1, a;
	int n = 100, i, m = 1000;

	//  cout << "x = ";
	//  cin >> x;

	e = pow(10, -4);
	a = 1;
	x = 5;
	y1 = 0;
	y = (exp(x) / pow(x, 2));

	for (i = 1; (fabs(y1 - y) > e); i++) {
		if ((i < n) && (fabs(y1 - y) < m)) {
			x -= .1;
			if (x > a) {
				y1 = (exp(x) / pow(x, 2));
			}
			else break;
		}
		else {
			y1 = -1;
			break;
		}
	}
	if (y1 != -1) {
		cout << "i = " << i << endl;
		cout << "y1 = " << y1 << endl;
	}
	else {
		cout << "the limit does not exist";
	}
}

int main(int argc, char** argv) {
	cout << "Hello World!\n";
	double lb;
	cout << "which lab you want to run(1,2,3,4)\n";
	cin >> lb;
	while (true) {
		if (lb == 1) {
			exOne();
			system("pause");
			cout << "which lab you want to run(1,2,3,4)\n";
			cin >> lb;
		}
		else if (lb == 2) {
			exTwo();
			system("pause");
			cout << "which lab you want to run(1,2,3,4)\n";
			cin >> lb;
		}
		else if (lb == 3) {
			exThree();
			system("pause");
			cout << "which lab you want to run(1,2,3,4)\n";
			cin >> lb;
		}
		else if (lb == 4) {
			exFour();
			system("pause");
			cout << "which lab you want to run(1,2,3,4)\n";
			cin >> lb;
		}
		else if(lb>4 || lb<=0){
			cout << "which lab you want to run(1,2,3,4)\n";
			cin >> lb;
		}
	}
}