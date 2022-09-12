using namespace std;
#include <iostream>
#include <vector>
#include <cmath>


class Solution {
public:
    string intToRoman(int num) {
        string result;
        vector <int> nums= { 1000, 500, 100, 50, 10, 5, 1 };
        vector <string> lets = { "M", "D","C","L" ,"X" ,"V" ,"I" };
        int step = 0;
        for (int i = 0; i < nums.size(); i++) {
            step++;
            string temp;
            int count = num / nums[i];
            if (count > 0) {
                if (count == 9) {
                        result = result + lets[i] + lets[i-2];
                        num = num - nums[i] * count;
                }
                else if (count == 4 ) {
                    result = result + lets[i] + lets[i-1];
                    num = num - nums[i] * count;
                }
                else{
                    if (lets[i] == "I" || (lets[i] != "I" && num / nums[i+1] != 9)) {
                        for (int j = 0; j < count; j++) {
                            result = result + lets[i];
                            num = num - nums[i] * count;
                        }
                    }
                }
            }
            if (step % 2 == 1) {
                temp = lets[i];
            }
        }
        return result;
    }
};

int main() {
    Solution s;
    int num;
    cin >> num;
    cout << s.intToRoman(num);
}