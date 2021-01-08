#pragma once
#include <iostream>
#include <string>
using namespace std;

class Point2D {
public:
	float x, y;

	Point2D operator+(const Point2D& p);
	Point2D& operator=(const Point2D& p);
	bool operator==(const Point2D& p);

	Point2D() {
		x = 0.0;
		y = 0.0;
	}
	Point2D(const float& nx, const float& ny) {
		x = nx;
		y = ny;
	}
	float Distance(float p1, float p2);

	//string Location();
};

class Shape {
private:
	int colors[4];
	Point2D pos;
public:
	Shape(Point2D p, int* arr) {
		pos = p;
		for (int k = 0; k < 4; k++) {
			colors[k] = arr[k];
		}
	}

	string getColors() {
		string s = to_string(colors[0]) + ", " + to_string(colors[1]) + ", " + to_string(colors[2]) + ", " + to_string(colors[3]);
		return s;
	}
	int getX() {
		return pos.x;
	}
	int getY() {
		return pos.y;
	}
	virtual void render() {
		cout << "Drawing a shape";
	}
	void setRed(int setRed) {
		if (colors[0] < 0 || colors[0] > 255) {
			colors[0] = colors[0];
		}
		else {
			colors[0] = setRed;
		}
	}
	void setGreen(int setGreen) {
		if (colors[1] < 0 || colors[1] > 255) {
			colors[1] = colors[1];
		}
		else {
			colors[1] = setGreen;
		}
	}
	void setBlue(int setBlue) {
		if (colors[2] < 0 || colors[2] > 255) {
			colors[2] = colors[2];
		}
		else {
			colors[2] = setBlue;
		}
	}
	void setAlpha(int setAlpha) {
		if (colors[3] < 0 || colors[3] > 255) {
			colors[3] = colors[3];
		}
		else {
			colors[3] = setAlpha;
		}
	}
};
class Rectangle : public Shape {
private:
	int width;
	int height;
public:
	Rectangle(Point2D p, int* arr, int nw, int nh) :
		Shape(p, arr), width(nw), height(nh) {
	}
	int getWidth() {
		return width;
	}
	int getHeight() {
		return height;
	}
	void setWidth(int nw) {
		width = nw;
	}
	void setHeight(int nh) {
		height = nh;
	}
	void render() {
		cout << "Drawing a rectangle with the height of: " << width << "and height of: " << height << " at: " << getX() << ", " << getY() << endl;
	}
};
class Triangle : public Shape {
private:
	int base;
	int height;
public:
	Triangle(Point2D p, int* arr, int nb, int nh) :
		Shape(p, arr), base(nb), height(nh) {
	}
	int getBase() {
		return base;
	}
	int getHeight() {
		return height;
	}
	void setBase(int nb) {
		base = nb;
	}
	void setHeight(int nh) {
		height = nh;
	}
	void render() {
		cout << "Drawing a triangle with the base of: " << base << "and height of: " << height << " at: " << getX() << ", " << getY() << endl;
	}
};
class Circle : public Shape {
private:
	int radius;
public:
	Circle(Point2D p, int* arr, int nr) :
		Shape(p, arr), radius(nr) {
	}
	int getRadius() {
		return radius;
	}
	void setRadius(int nr) {
		radius = nr;
	}
	void render() {
		cout << "Drawing a circle with a radius of: " << radius << " at: " << getX() << ", " << getY() << endl;
	}
};