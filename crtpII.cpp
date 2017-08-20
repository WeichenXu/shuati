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

template <typename T>
class Amount{
public:
    double getValue() const{
        return static_cast<T const&>(*this).getValue();
    }
};

class ConstAmount : public Amount<ConstAmount>{
public:
    double getValue() const{
        return 42.0;
    }
};

class Variable : public Amount<Variable>{
public:
    double getValue() const{
        return m_value;
    }
    explicit Variable(double v) : m_value(v){}
private:
    double m_value;
};

// print interface for amount
template<typename T>
void print(Amount<T> const& amount){
    std::cout << amount.getValue() << std::endl;
}

int main(){
    // extend functions
    Sensitivity s;
    s.setValue(1.0);
    s.scale(100);
    std::cout << s.getValue() << std::endl;

    // static interface
    ConstAmount c;
    print(c);
    Variable v(43.00);
    print(v);

    return 0;
}

