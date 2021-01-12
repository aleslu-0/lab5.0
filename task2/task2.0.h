#pragma once
#include <iostream>
#include <string>
#include <SDL.h>
#include <math.h>
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

	string Location();
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
	int getRed() {
		return colors[0];
	}
	int getGreen() {
		return colors[1];
	}
	int getBlue() {
		return colors[2];
	}
	int getAlpha() {
		return colors[3];
	}
	int getX() {
		return pos.x;
	}
	int getY() {
		return pos.y;
	}
	virtual void render(SDL_Renderer* r) {
		cout << "Drawing a shape";
		
		SDL_SetRenderDrawColor(r, getRed(), getGreen(), getBlue(), getAlpha());
		SDL_RenderDrawLine(r, 0, 0, 200, 200);
		
		SDL_RenderClear(r);
		SDL_RenderPresent(r);

		SDL_Delay(3000);
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
	virtual void render(SDL_Renderer* r) {
		int x = getX();
		int y = getY();
		cout << "Drawing a rectangle with the height of: " << width << " and height of: " << height << " at: " << getX() << ", " << getY() << endl;
		SDL_SetRenderDrawColor(r, 0, 0, 0, 0);
		SDL_RenderClear(r);
		SDL_SetRenderDrawColor(r, getRed(), getGreen(), getBlue(), getAlpha());
		SDL_RenderDrawLine(r, x, y, x+width, y);	
		SDL_RenderDrawLine(r, x+width, y, x+width, y-height);
		SDL_RenderDrawLine(r, x+width, y-height, x, y-height);
		SDL_RenderDrawLine(r, x, y-height, x, y);
		
		SDL_RenderPresent(r);

		SDL_Delay(3000);
		
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
	virtual void render(SDL_Renderer* r) {
		int x = getX();
		int y = getY();
		cout << "Drawing a triangle with the base of: " << base << " and height of: " << height << " at: " << getX() << ", " << getY() << endl;
		SDL_SetRenderDrawColor(r, 0, 0, 0, 0);
		SDL_RenderClear(r);
		SDL_SetRenderDrawColor(r, getRed(), getGreen(), getBlue(), getAlpha());
		SDL_RenderDrawLine(r, x, y, x+base/2, y-height);
		SDL_RenderDrawLine(r, x+base/2, y-height, x+base, y);
		SDL_RenderDrawLine(r, x+base, y, x, y);

		SDL_RenderPresent(r);

		SDL_Delay(3000);
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
	virtual void render(SDL_Renderer* r) {
		cout << "Drawing a circle with a radius of: " << radius << " at: " << getX() << ", " << getY() << endl;
		SDL_SetRenderDrawColor(r, 0, 0, 0, 0);
		SDL_RenderClear(r);
		SDL_SetRenderDrawColor(r, getRed(), getGreen(), getBlue(), getAlpha());
		int pos_x = getX();
		int pos_y = getY();
		int theta = 0;
		int h = 12;
		int k = 10;
		int step = 15;
		while (theta <= 1080) {
			int x = h + radius * cos(theta);
			int y = k + radius * sin(theta);
			SDL_RenderDrawLine(r, pos_x+x, pos_y+y, pos_x+x, pos_y+y);
			theta += step;
		}

		SDL_RenderPresent(r);

		SDL_Delay(3000);
	}
};
