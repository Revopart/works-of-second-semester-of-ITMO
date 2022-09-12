using namespace std;
#include <iostream>
#include <vector>
#include <cmath>

int main() {
    int row, collumn;
    cin >> row >> collumn;

    vector<vector<double>> matrix(row, vector<double>(collumn));
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < collumn; j++) {
            cin >> matrix[i][j];
        }
    }
    for (int step = 0; step < row - 1; step++) {
        for (int i = 1; i < row - step; i++) {
            double lbm = matrix[step + i][step] / matrix[step][step];
            for (int j = 0; j < collumn; j++) {
                matrix[step+i][j] = matrix[step + i][j] - lbm * matrix[step][j];
            }
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < collumn; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }
    vector <double> solution;
    cout << endl;
    cout << solution.size();
    if (row < collumn - 1) {
        for (int i = row; i < collumn; i++) {
        double temp = 0;
        solution.push_back(temp);
        }
    }
    double temp = 0;
    for (int i = row - 1; i > -1; i--) {
        for (int j = collumn - 2; j > collumn - 2 - solution.size(); j--) {
            if (solution.size() > 0) {
                temp = temp + matrix[i][j] * solution[solution.size() -1];
            }
            else {
                temp = 0;
            }
        }
        double sol = (matrix[row - 1 - solution.size()][collumn - 1] - temp) / matrix[i][i];
        solution.push_back(sol);
        temp = 0;
    }
    for (int i = solution.size(); i > 0; i--) {
        if (abs(solution[solution.size() - i] - 0) < 0.01) {
            solution[solution.size() - i] = 0;
        }
        cout << "x" << solution.size() - i + 1 << "=" << solution[solution.size() - i] << endl;
    }
        return 0;
}

