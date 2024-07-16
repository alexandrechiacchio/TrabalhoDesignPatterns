#include <iostream> 
#include <set>

// Observer interface
class Observer {
public:
    virtual void update(float temperature, float humidity, float pressure) = 0;
};

// Subject interface
class Subject {
public:
    virtual void registerObserver(Observer* observer) = 0;
    virtual void removeObserver(Observer* observer) = 0;
    virtual void notifyObservers() = 0;
};

class WeatherStation : public Subject {
private:
    float temperature;
    float humidity;
    float pressure;
    std::set<Observer*> observers;

public:
    void registerObserver(Observer* observer) {
        observers.insert(observer);
    }

    void removeObserver(Observer* observer) {
        observers.erase(observer);
    }

    void notifyObservers() {
        for (Observer* observer : observers) {
            observer->update(temperature, humidity, pressure);
        }
    }

    void setMeasurements(float temp, float hum, float press) {
        temperature = temp;
        humidity = hum;
        pressure = press;
        notifyObservers();
    }
};

class Display : public Observer {
public:
    void update(float temperature, float humidity, float pressure) {
        std::cout << "Display: Temperature = " << temperature
                  << "°C, Humidity = " << humidity
                  << "%, Pressure = " << pressure << " hPa"
                  << std::endl;
    }
};

int main() {
    WeatherStation weatherStation;

    // Create displays
    Display display1;
    Display display2;

    // Register displays as observers
    weatherStation.registerObserver(&display1);
    weatherStation.registerObserver(&display2);

    // Simulate weather data updates
    weatherStation.setMeasurements(25.5, 60, 1013.2);

    weatherStation.removeObserver(&display1);

    weatherStation.setMeasurements(24.8, 58, 1014.5);



    return 0;
}