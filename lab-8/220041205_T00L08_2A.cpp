#include <iostream>
#include <cmath>
using namespace std;

#define PI 3.1416

class Shape {
public:
  virtual void whoAmI() = 0;
};

class TwoDimensionalShape : public Shape {
public:
  void whoAmI() {
    cout << "I am a two dimensional shape\n";
  }

  virtual float area() = 0;
  virtual float perimeter() = 0;
};

class ThreeDimensionalShape : public Shape {
public:
  void whoAmI() {
    cout << "I am a three dimensional shape\n";
  }

  virtual float surfaceArea() = 0;
  virtual float volume() = 0;
};

class Square : private TwoDimensionalShape {
private:
  float side;

public:
  Square(float a) : side(a) {}

  void whoAmI() {
    cout << "I am a square\n";
    TwoDimensionalShape::whoAmI();
  }

  float area() {
    return side * side;
  }

  float perimeter() {
    return 4 * side;
  }
};

class Circle : public TwoDimensionalShape {
private:
  float radius;

public:
  Circle(float r) : radius(r) {}

  void whoAmI() {
    cout << "I am a circle\n";
    TwoDimensionalShape::whoAmI();
  }

  float area() {
    return PI * radius * radius;
  }

  float perimeter() {
    return 2 * PI * radius;
  }
};

class Triangle : public TwoDimensionalShape {
private:
  float a, b, c;

public:
  Triangle(float p, float q, float m) : a(p), b(q), c(m) {}

  void whoAmI() {
    cout << "I am a Triangle\n";
    TwoDimensionalShape::whoAmI();
  }

  float area() {
    float s = (a + b + c) / 2;
    return sqrtf(s * (s - a) * (s - b) * (s - c));
  }

  float perimeter() {
    return a + b + c;
  }
};

class Cube : public ThreeDimensionalShape {
private:
  float side;

public:
  Cube(float a) : side(a) {}

  void whoAmI() {
    cout << "I am a cube\n";
    ThreeDimensionalShape::whoAmI();
  }

  float surfaceArea() {
    return 6 * side * side;
  }

  float volume() {
    return side * side * side;
  }
};

class Sphere : public ThreeDimensionalShape {
private:
  float radius;

public:
  Sphere(float r) : radius(r) {}

  void whoAmI() {
    cout << "I am a Sphere\n";
    ThreeDimensionalShape::whoAmI();
  }

  float surfaceArea() {
    return 4 * PI * radius * radius;
  }

  float volume() {
    return (4.0f / 3) * PI * powf(radius, 3);
  }
};

class Cylinder : public ThreeDimensionalShape {
private:
  float radius;
  float height;

public:
  Cylinder(float r, float h) : radius(r), height(h) {}

  void whoAmI() {
    cout << "I am a Cylinder\n";
    ThreeDimensionalShape::whoAmI();
  }

  float surfaceArea() {
    return (2 * PI * radius * height) + (2 * PI * powf(radius, 2));
  }

  float volume() {
    return PI * powf(radius, 2) * height;
  }
};

int main() {
  TwoDimensionalShape* circle = new Circle(6.0f);
  ThreeDimensionalShape* cylinder = new Cylinder(5.0f, 8.0f);

  circle->whoAmI();
  cout << "Circle area: " << circle->area() << "\n";
  cout << "Circle perimeter: " << circle->perimeter() << "\n";

  cylinder->whoAmI();
  cout << "Cylinder surface area: " << cylinder->surfaceArea() << "\n";
  cout << "Cylinder volume: " << cylinder->volume() << "\n";

  delete circle;
  delete cylinder;
}