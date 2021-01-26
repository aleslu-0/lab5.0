#include <iostream>
#include <task1.h>
#include <string>
#include <vector>
using namespace std;

Point2D Point2D::operator+(const Point2D& p) {
    Point2D P;
    P.x = this->x + p.x;
    P.y = this->y + p.y;
    return P;
}
Point2D& Point2D::operator=(const Point2D& p) {
    x = p.x;
    y = p.y;
    return *this;
}
bool Point2D::operator==(const Point2D& p) {
    return (x == p.x && y == p.y);
}

float Point2D::Distance(float px, float py) {
    float a = px - x;
    float b = py - y;
    float dist = sqrt(pow(a, 2) + pow(b, 2));
    return dist;
}

string Point2D::Location() {
    string sx = to_string(x);
    string sy = to_string(y);
    string p = "[" + sx + "," + sy + "]";
    return p;
}

void testRendering(vector<Shape*>shapes) {
    shapes[0]->render();
    shapes[1]->render();
    shapes[2]->render();
}
int main()
{
    int arr[4] = { 3, 2, 3, 4 };
    Point2D p(1, 5);

    vector<Shape*>shapes;
    Triangle t(p, arr, 1, 2);
    Circle c(p, arr, 1);
    Rectangle r(p, arr, 1, 9);

    shapes.push_back(&t);
    shapes.push_back(&c);
    shapes.push_back(&r);
    testRendering(shapes);
}

