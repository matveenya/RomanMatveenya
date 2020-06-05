//9)arctgx+sinx
#include <iostream>
#include <math.h> 
#include <stdlib.h>
using namespace std;
double Exp(double, double);
int main() {
	double a, b, h, eps;
	a = -1;
	b = 1;
	h = 0.2;
	eps = 0.0001;
	cout << "\nТаблица значений функции\\n\n";
	for (double x = a; x <= b + h / 2; x = x + h) {
		cout << " x = ";
		cout.width(6);
		cout << x;
		cout.width(10);
		cout << Exp(x, eps);
	}
	system("pause");
	return 0;
}
double Exp(double x, double eps) {
	double Sum = 1, Term = 1;
	for (int i = 1; fabs(Term) > eps; i++) {
		Term = Term * (atan(x) + sin(x)) / i;
		Sum = Sum + Term;
	}
	return Sum;
}