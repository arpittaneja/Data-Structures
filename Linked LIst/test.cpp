#include <iostream>
using namespace std;
class A
{
public:
    int a, b;
};
int main()
{

    {
        A obj;
        obj.a = 4;
        obj.b = 5;
        cout << obj.a << obj.b;
    }
    cout << obj.a << obj.b;
}