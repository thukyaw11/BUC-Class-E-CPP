#include<iostream>
using namespace std;

class Shape {
    protected:
        int width, height;
    public:
        Shape(int a = 0, int b = 0) {
            width = a;
            height = b;
        } 
        virtual int area() {
            cout << "Parent Class Area";
            return 0;
        }
};

class Rectangle:public Shape {
    public: 
        Rectangle(int a=0, int b=0) : Shape(a,b) {
            width = a;
            height = b;
        }
        int area() {
            cout << "Rectangle Class Area: " << width*height << endl;
            return (width*height);
        }
};

class Triangle:public Shape {
    public: 
        Triangle(int a=0, int b=0) : Shape(a,b) {

        }
        int area() {
            cout << "Triangle Class Area";
            return (0.5*width*height);
        }
};

int main() {
    Shape *shape;
    Rectangle rect(8,9);
    Triangle tri;
    shape = &rect;
    shape->area();

    shape = &tri;
    shape->area();
    return 0;
}

