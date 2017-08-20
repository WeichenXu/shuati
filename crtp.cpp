#include <iostream>

// Base class could access derived class implementation
// Downcast at compile time
template<typename T>
class Base{
public:
    int hello(){
        return static_cast<T*>(this)->hello_impl();
    }
    
private:
    // prevent Derived class unmatch <T>
    Base(){};
    friend T;
    
};

class Derived:public Base<Derived>
{
public:
    int hello_impl(){
        std::cout << "Hello\n" << std::endl;
        return 0;
    }
};

int main (){
    using namespace std;
    Derived tObj;
    tObj.hello();
    return 0;
}
