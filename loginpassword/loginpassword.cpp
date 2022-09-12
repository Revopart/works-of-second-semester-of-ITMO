#include <iostream>
#include <fstream>
#include <string>

using namespace std;

bool IsLoggedIn() {
	string password, username, un, pw;

	cout << "Enter usrename: ";
	cin >> username;
	cout << "Enter password: ";
	cin >> password;

	ifstream read(username + ".txt");
	getline(read, un);
	getline(read, pw);

	if (un == username && pw == password) {
		return true;
	}
	else {
		return false;
	}
}

int main() {
	int choice;
	cout << "1. register\n2. login\n your choice:";
	cin >> choice;

	if (choice == 1) {
		string username, password;
		cout << "select a username: ";
		cin >> username;
		cout << "select a password: ";
		cin >> password;

		ofstream file;
		file.open(username + ".txt");
		file << username << endl << password;
		file.close();
		main();
	}
	else if (choice == 2) {
		bool status = IsLoggedIn();

		if (status != true) {
			cout << "False" << endl;
			system("pause");
			return 0;
		}
		else {
			cout << "Acces allowed" << endl;
			system("pause");
			return 1;
		}
	}
}