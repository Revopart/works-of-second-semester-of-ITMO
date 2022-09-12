using namespace std;
#include <iostream>
#include <string>

class Solution {
private:
    int temp;
    int dt, result = 0;
public:
    int romanToInt(string s) {
        for (int i = 0; i < s.length(); i++) {
            switch (s[i]) {
            case 'I':
                dt = 1;
                break;
            case 'V':
                dt = 5;
                break;
            case 'X':
                dt = 10;
                break;
            case 'L':
                dt = 50;
                break;
            case 'C':
                dt = 100;
                break;
            case 'D':
                dt = 500;
                break;
            case 'M':
                dt = 1000;
                break;
            }
            if (i == 0) {
                temp = dt;
            }
            if (dt > temp) {
                result = result - 2 * temp + dt;
            }
            else {
                result = result + dt;
            }
            temp = dt;
        }
        return result;
        }
};

int main() {
    Solution loh;
    string s;
    cin >> s;
    cout << loh.romanToInt(s);
    return 0;
}
