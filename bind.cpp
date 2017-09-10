#include <iostream>
#include <functional> //for bind()

using namespace std;

void func(int a, int b, int c)
{
    cout << a - b - c << endl;
}

int main(){
    using namespace std::placeholders;

    auto b1 = bind(func, _1, 2, 3);
    auto b2 = bind(func, 1, _1, 3);

    // switch the order of val
    auto b3 = bind(func, _1, _2, 10);
    auto b4 = bind(func, _2, _1, 10);

    b1(0);
    b2(0);
    b3(10,0);
    b4(10,0);

    return 0;
}
