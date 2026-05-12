#include <iostream>
#include "appModule.h"
#include "appHeader.h"

class mainSub : public appModule {
  public:
    void Init() override  {
        std::cout << "Howdy App!!" << "\n";
    }  
    void Terminate() override {
        std::cout << "See ya!!" << "\n";
    }
};


class mainClass : public appModule {

public:
    void Init() override  {
        std::cout << "hello App!!" << "\n";
        AppHead::startModule<mainSub>();
    }
    void Terminate() override {
        std::cout << "Ending Execution" << "\n";
    }
};

int main() {

    AppHead::startModule<mainClass>();
    AppHead::KillApp();
    return 0;
}