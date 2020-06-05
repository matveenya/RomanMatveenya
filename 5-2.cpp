#include <iostream>
#include <math.h>
using namespace std;



class Colour {

private:

	int r, g, b;

public:

	Colour() {



	}

	Colour(int red, int green, int blue)

		:r(red), g(green), b(blue)

	{

	}

	void setRed(int r) {

		this->r = r;

	}

	void setGreen(int g) {

		this->g = g;

	}

	void setBlue(int b) {

		this->b = b;

	}

	int getRGB() {

		return r + g + b;

	}

	void show() {
		cout << "\n";

		cout << "Red - " << r << " Green - " << g << " Blue - " << b;

	}
};

int operator + (Colour c1, Colour c2) {

	return (c1.getRGB() + c2.getRGB());
}

int operator - (Colour c1, Colour c2) {

	return (c1.getRGB() - c2.getRGB());

}

int operator * (Colour c1, Colour c2) {

	return (c1.getRGB() * c2.getRGB());
}

bool operator > (Colour c1, Colour c2) {

	return (c1.getRGB() > c2.getRGB());

}

bool operator < (Colour c1, Colour c2) {

	return (c1.getRGB() < c2.getRGB());
}



int main() {

	int r, g, b = 0;
	cout << "Enter Red";
	cin >> r;
	cout << "Enter Green";
	cin >> g;
	cout << "Enter Blue";
	cin >> b;
	Colour colour1(r, g, b);



	Colour colour2;
	colour2.setBlue(20);
	colour2.setGreen(100);
	colour2.setRed(34);

	colour1.show();
	colour2.show();


	int unitRGB = colour1 + colour2;

	cout << "\n";

	cout << "\n" << "unit = " << unitRGB;
	int diffRGB = colour1 - colour2;

	cout << "\n" << "diff = " << diffRGB;

	int compRGB = colour1 * colour2;

	cout << "\n" << "comp = " << compRGB;
	bool C1moreC2 = colour1 > colour2;

	cout << "\n" << "C1>C2 = " << C1moreC2;
	bool C1lessC2 = colour1 < colour2;
	cout << "\n" << "C1<C2 = " << C1lessC2;
}

