#include <iostream>
#include <SDL.h>
#include <task2.0.h>
#include <vector>



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

void testRendering(vector<Shape*>shapes, SDL_Renderer* r) {
    shapes[0]->render(r);
    shapes[1]->render(r);
    shapes[2]->render(r);    
}

int main(int arg, char *args[])
{
    SDL_Init(SDL_INIT_EVERYTHING);
    SDL_Window* window = SDL_CreateWindow("title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 600, 400, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);

    int arr[4] = { 255, 0, 50, 255 };
    int arr2[4] = { 150, 255, 50, 255 };
    int arr3[4] = { 0, 100, 255, 255 };
    Point2D p(200, 250);
    Shape s(p, arr);
    cout << s.getColors() << endl;

    vector<Shape*>shapes;
    Triangle t(p, arr, 100, 150);
    Circle c(p, arr2, 50);
    Rectangle r(p, arr3, 100, 120);

    shapes.push_back(&t);
    shapes.push_back(&c);
    shapes.push_back(&r);
    testRendering(shapes, renderer);

    return 0;
}

