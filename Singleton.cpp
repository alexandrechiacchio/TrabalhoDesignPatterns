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


int main() {

  Singleton* example = Singleton::GetInstance("Hi!, I'm a singleton");

  example->log();

  Singleton* example2 = Singleton::GetInstance("Hi!, I'm a second singleton");

  example2->log();

  return 0;
}