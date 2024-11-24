#include <iostream>
using namespace std;

class Complex {
private:
	int real;  
	int imag;

public:
	Complex() : real(0), imag(0) {}
	Complex(int r, int i) : real(r), imag(i) {}
	void Show()const
	{
		cout << "real = " << real << " imag = " << imag << endl;
	}
	Complex operator+(const Complex& other)const
	{
		Complex temp;
		temp.real + other.real;
		temp.imag + other.imag;
		return temp;
	}
	Complex operator-(const Complex& other)const
	{
		Complex temp;
		temp.real - other.real;
		temp.imag - other.imag;
		return temp;
	}
	Complex operator*(const Complex& other)const
	{
		Complex temp;
		temp.real* other.real - imag * other.imag;
		temp.real* other.imag + imag * other.real;
		return temp;
	}
	Complex operator/(const Complex& other)const
	{
		Complex temp;
		if (other.real == 0 || other.imag == 0) {
			cout << ("Ділення на нуль неможливе!") << endl;
		}
		temp.real/ other.real - imag / other.imag;
		temp.real/ other.imag + imag / other.real;
		return temp;
	}
	void display() const {
		cout << real;
		if (imag >= 0) {
			cout << " + " << imag << "i";
		}
		else {
			cout << " - " << -imag << "i";
		}
		cout << endl;
	}
};

class Point
{
	int x;
	int y;
public:
	Point() : x(0), y(0) {}
	Point(int value) : x(value), y(value) {}
	Point(int x, int y) : x(x), y(y) {}
	Point(const Point& other) : x(other.x), y(other.y) {}
	void Show()const
	{
		cout << "x = " << x << " y = " << y << endl;
	}
	Point operator+(const Point& other)const
	{
		Point temp;
		temp.x = this->x + other.x;
		temp.y = this->y + other.y;
		return temp;
	}
	Point operator-(const Point& other)const
	{
		Point temp;
		temp.x = this->x - other.x;
		temp.y = this->y - other.y;
		return temp;
	}
	Point operator/(const Point& other) const {
		Point temp;
		if (other.x == 0 || other.y == 0) {
			cout << ("Ділення на нуль неможливе!") << endl;
		}
		temp.x = this->x / other.x;
		temp.y = this->y / other.y;
		return temp;
	}
	Point operator*(const Point& other)const
	{
		Point temp;
		temp.x = this->x * other.x;
		temp.y = this->y * other.y;
		return temp;
	}
};

int main()
{
	Complex c1(4, 5);   
    Complex c2(2, -3);  

    cout << "Complex num 1: ";
    c1.Show();
    cout << "Complex num 2: ";
    c2.Show();
	Complex c3 = c1 + c2;
	cout << "Sum c1, c2: ";
	c3.Show();
	Complex c4 = c1 - c2;
	cout << "Diff c1, c2: ";
	c4.Show();
	Complex c5 = c1 * c2;
	cout << "Multiply c1, c2: ";
	c5.Show();
	try {
		Complex c6 = c1 / c2;
		cout << "Remainder: ";
		c6.Show();
	}
	catch (const runtime_error& e) {
		cerr << e.what() << endl;
	}




	Point p1(2, 4);
	p1.Show();
	Point p2 = p1 + 2;
	p2.Show();
	Point p3 = p1 - 2;
	p3.Show();
	Point p4 = p1 / 2;
	p4.Show();
	Point p5 = p1 * 2;
	p5.Show();
}