#include <bits/stdc++.h>

// Modern Computer (Client)
class ModernComputer {
public:
    void sendCommand(const std::string& command) {
        std::cout << "Sending command: " << command << std::endl;
    }
};
// Legacy Printer (Adaptee)
class LegacyPrinter {
public:
    void printInUppercase(const char* text) {
        char* msg;
        strcpy(msg, text);
        for (int i = 0; msg[i]!=NULL; i++) msg[i] = toupper(msg[i]); 
        std::cout << "Printing: " << msg << std::endl;
    }
};

// Adapter class to make the LegacyPrinter compatible with ModernComputer
class PrinterAdapter {
private:
    LegacyPrinter legacyPrinter;

public:
    void sendCommand(const std::string& command) {
        legacyPrinter.printInUppercase(command.c_str());
    }
};


int main() {
    ModernComputer computer;
    PrinterAdapter adapter;

    computer.sendCommand("Print this in lowercase");
    adapter.sendCommand("Print this in lowercase (adapted)");

    return 0;
}