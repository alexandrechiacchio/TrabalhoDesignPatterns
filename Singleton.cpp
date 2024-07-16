#include <string>
#include <iostream>

class Singleton {

protected:
  Singleton(const std::string value) : value_(value) {
  }

  static Singleton* singleton_;

  std::string value_;

public:

  Singleton(Singleton& other) = delete;

  void operator=(const Singleton&) = delete;

  static Singleton* GetInstance(const std::string& value) {
    if (singleton_ == nullptr) {
      std::cout << "Singleton not created, creating instance\n";
      return singleton_ = new Singleton(value);
    } else {
      std:: cout << "Singleton already created, returning instance\n";
      return singleton_;
    }
  }

  void log() {
    std::cout << value_ << std::endl;
  }

  std::string value() const {
    return value_;
  }
};

Singleton* Singleton::singleton_= nullptr;


class MLModel : public Singleton{
public:
  void train();
  void predict();

  static MLModel* GetInstance(const std::string& value){return (MLModel*)Singleton::GetInstance(value);}

};

void MLModel::train(){
  // training logic
  std::cout << "training model\n";
}

void MLModel::predict(){
  // prediction logic
  std::cout << "prediction\n";
}



int main() {

  Singleton* example = Singleton::GetInstance("YOLOv8");

  Singleton* example2 = Singleton::GetInstance("YOLOv8");

  std::cout << (example == example2) <<  std::endl;

  return 0;
}