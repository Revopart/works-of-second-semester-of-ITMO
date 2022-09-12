using namespace std;
#include <iostream>
#include <set>
#include <map>
#include <string>
#include <vector>

int main() {
	string uncoded;
	cin >> uncoded;
	int left_count;
	set <char> letters{ uncoded.begin(), uncoded.end() };
	multiset <char> myltiletters{ uncoded.begin(), uncoded.end() };
	string* arrL = new string[letters.size()];
	int cn = 0;
	string* arrCode = new string[letters.size()];
	for (auto now = letters.begin(); now != letters.end(); now++) {
		arrL[cn] = *now;
		cn++;
	}
	int* arrC = new int[letters.size()];
	for (int i = 0; i < letters.size(); i++) {
		int count = 0;
		for (auto now = myltiletters.lower_bound(arrL[i][0]); now != myltiletters.upper_bound(arrL[i][0]); now++) {
			count++;
		}
		arrC[i] = count;
	}
	int cnt = letters.size();
	int start = 0;
	while (cnt != 1) {
		for (int j = 0; j < letters.size(); j++) {
			int num_min = j;
			for (int i = j; i < letters.size(); i++) {
				if (arrC[i] < arrC[num_min]) {
					num_min = i;
				}
			}
			int temp;
			temp = arrC[j];
			arrC[j] = arrC[num_min];
			arrC[num_min] = temp;
			string tempe;
			tempe = arrL[j];
			arrL[j] = arrL[num_min];
			arrL[num_min] = tempe;
		}
		arrC[start + 1] = arrC[start] + arrC[start + 1];
		arrL[start + 1] = arrL[start] + arrL[start + 1];
		if (cnt == 2) {
			string temp = arrL[start];
			left_count = temp.length();
		}
		arrC[start] = 0;
		arrL[start] = "";
		start++;
		cnt--;
	}
	string temp_code = "00";
	arrCode[0] = temp_code;
	for (int i = 1; i < left_count + 1; i++) {
		if (temp_code[temp_code.length() - 1] == '0') {
			if (i != left_count - 1) {
				temp_code[temp_code.length() - 1] = '1';
				temp_code = temp_code + '0';
				arrCode[i] = temp_code;
			}
			else {
				temp_code[temp_code.length() - 1] = '1';
				arrCode[i] = temp_code;
			}
		}
	}
	temp_code = "11";
	arrCode[letters.size() - 1] = temp_code;
	for (int i = letters.size() - 2; i > left_count; i--) {
		if (temp_code[temp_code.length() - 1] == '1') {
			if (i != left_count - 1) {
				temp_code[temp_code.length() - 1] = '0';
				temp_code = temp_code + '1';
				arrCode[i] = temp_code;
			}
			else {
				temp_code[temp_code.length() - 1] = '0';
				arrCode[i] = temp_code;
			}
		}
	}
	for (int i = 0; i < letters.size(); i++) {
		cout << arrCode[i] << " ";
	}
	cout << endl;
	for (int i = 0; i < uncoded.length(); i++) {
		for (int j = 0; j < letters.size(); j++) {
			if (uncoded[i] == arrL[start][j]) {
				cout << arrCode[j] << " ";
				break;
			}
		}
	}
	map <int, string> code;
	delete[] arrL;
	delete[] arrC;
	return 0;
}