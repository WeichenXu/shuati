#include <iostream>

template<typename T>
struct NumericalFunctions{
    void scale(const double multiplicator)
    {
        T& underlying = static_cast<T&>(*this);
        underlying.setValue(multiplicator*underlying.getValue());
    }
    void square(){
    
    }

    void setToOpposite()
    {}
};

// CRTP to instantiate a sensitivity class
class Sensitivity : public NumericalFunctions<Sensitivity>
{
public:
    double getValue() const{return m_value;};
    void setValue(const double value){m_value = value;};
private:
    double m_value{0.0};
};


int main(){
    Sensitivity s;
    s.setValue(1.0);
    s.scale(100);
    std::cout << s.getValue() << std::endl;
    return 0;
}

