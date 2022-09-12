using namespace std;
#include <cmath>
#include <iostream>

int main()
{

    for (int i = 1; i < 101; i++) {
        bool fizz = false;
        bool bas = false;
        if (i % 3 == 0) {
            fizz = true;
        }
        if (i % 5 == 0) {
            bas = true;
        }
        if (bas == true) {
            cout << "bass" << " ";
        }
        if (fizz == true) {
            cout << "fizz" << " ";
        }
        if (bas != true && fizz != true) {
            cout << i << " ";
        }
    }

}
