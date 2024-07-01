#include <iostream>
#include <vector>

class Shape {
public:
  virtual void draw() = 0;
  virtual ~Shape() {} // Virtual destructor for polymorphism
};

class Circle : public Shape {
public:
  void draw() override {
    std::cout << "Drawing a Circle" << std::endl;
  }
};

class Square : public Shape {
public:
  void draw() override {
    std::cout << "Drawing a Square" << std::endl;
  }
};

class ShapeFactory {
public:
  virtual Shape* createShape(std::string data) {
    if (data == "Square") return new Square();
    if (data == "Circle") return new Circle();
    std::cerr << "wrong shape input\n";
    return nullptr;
  };
  virtual ~ShapeFactory() {} // Virtual destructor for polymorphism
};


int main() {


  [](std::vector<std::string> shapes = { "Square", "Square", "Circle" }){

    ShapeFactory* _ShapeFactory = new ShapeFactory();

    std::vector<Shape*> _shapes;

    for (std::string shape : shapes) {
      _shapes.push_back(_ShapeFactory->createShape(shape));
    }

    for (Shape* shape : _shapes) {
      shape->draw();
    }

  }();


  return 0;
}