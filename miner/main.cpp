#include<ctime>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    srand(time(NULL));
    const int SIZE = 8;
    int arr[SIZE][SIZE];
    int newRandValue;
    int countmines = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) {
            newRandValue = rand() % 6;
            arr[i][j] = newRandValue;

        }
    }
    

    int k = 0;
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) {
            if (arr[i][j] < 5) {

                if (i == 0 && j == 0)
                {
                    if (arr[i][j + 1] == 5) {
                        k++;
                    }
                    if (arr[i + 1][j + 1] == 5) {
                        k++;//pravo nij ugol
                    }
                    if (arr[i + 1][j] == 5) {
                        k++;//vniz element
                    }
                }
                else if (j == 0 && i > 0 && i < SIZE - 1) {//leviy perviy stolb do lastovogo elementa
                    if (arr[i - 1][j] == 5) {
                        k++;//vverh element
                    }
                    if (arr[i - 1][j + 1] == 5) {
                        k++;//verh pravo
                    }
                    if (arr[i][j + 1] == 5) {
                        k++;//
                    }
                    if (arr[i + 1][j + 1] == 5) {
                        k++;//pravo nij ugol
                    }
                    if (arr[i + 1][j] == 5) {
                        k++;//vniz element
                    }
                }
                else if (j == 0 && i == SIZE - 1) {//1 stolb nij elemnt
                    if (arr[i - 1][j] == 5) {
                        k++;//vverh element
                    }
                    if (arr[i - 1][j + 1] == 5) {
                        k++;//verh pravo
                    }
                    if (arr[i][j + 1] == 5) {
                        k++;
                    }
                }
                else if (i == SIZE - 1 && j > 0 && j < SIZE - 1) {//nij ryad do last elementa
                    if (arr[i][j - 1] == 5) {
                        k++;//sleva tot je ryad
                    }
                    if (arr[i - 1][j - 1] == 5) {
                        k++;//leviy verh ugol
                    }
                    if (arr[i - 1][j] == 5) {
                        k++;//vverh element
                    }
                    if (arr[i - 1][j + 1] == 5) {
                        k++;//verh pravo
                    }
                    if (arr[i][j + 1] == 5) {
                        k++;
                    }
                }
                else if (j == SIZE - 1 && i == SIZE - 1) {//last element vprincipe
                    if (arr[i][j - 1] == 5) {
                        k++;//sleva tot je ryad
                    }
                    if (arr[i - 1][j - 1] == 5) {
                        k++;//leviy verh ugol
                    }
                    if (arr[i - 1][j] == 5) {
                        k++;//vverh element
                    }
                }
                else if (j == SIZE - 1 && i > 0 && i < SIZE - 1) {//last stolb
                    if (arr[i][j - 1] == 5) {
                        k++;//sleva tot je ryad
                    }
                    if (arr[i - 1][j - 1] == 5) {
                        k++;//leviy verh ugol
                    }
                    if (arr[i - 1][j] == 5) {
                        k++;//vverh element
                    }
                    if (arr[i + 1][j - 1] == 5) {
                        k++;//levo niz ugol
                    }
                    if (arr[i + 1][j] == 5) {
                        k++;//vniz element

                    }
                }
                else if (j == SIZE - 1 && i == 0)
                {//last stolb 1 elem
                    if (arr[i][j - 1] == 5) {
                        k++;//sleva tot je ryad
                    }
                    if (arr[i + 1][j - 1] == 5) {
                        k++;//levo niz ugol
                    }
                    if (arr[i + 1][j] == 5) {
                        k++;//vniz element
                    }
                }
                else if (i == 0 && j > 0 && j < SIZE - 1)
                {//verh stroka
                    if (arr[i][j - 1] == 5) {
                        k++;//sleva tot je ryad
                    }
                    if (arr[i + 1][j - 1] == 5) {
                        k++;//levo niz ugol
                    }
                    if (arr[i + 1][j] == 5) {
                        k++;//vniz element
                    }
                    if (arr[i + 1][j + 1] == 5) {
                        k++;//pravo nij ugol
                    }
                    if (arr[i][j + 1] == 5) {
                        k++;// СЃРїСЂР°РІР° С‚РѕС‚ Р¶Рµ СЂСЏРґ
                    }
                }
                else {//centr
                    if (arr[i][j - 1] == 5) {
                        k++;//sleva tot je ryad
                    }
                    if (arr[i - 1][j - 1] == 5) {
                        k++;//leviy verh ugol
                    }
                    if (arr[i - 1][j] == 5) {
                        k++;//vverh element
                    }
                    if (arr[i + 1][j - 1] == 5) {
                        k++;//levo niz ugol
                    }
                    if (arr[i + 1][j] == 5) {
                        k++;//vniz element
                    }
                    if (arr[i + 1][j + 1] == 5) {
                        k++;//pravo nij ugol
                    }
                    if (arr[i][j + 1] == 5) {
                        k++;
                    }if (arr[i - 1][j + 1] == 5) {
                        k++;//verh pravo
                    }

                }

                if (k > 0) {
                    arr[i][j] = k;
                }
                else {
                    arr[i][j] = 0;
                }
                k = 0;

            }
            if (arr[i][j] == 5) {
                countmines++;
            }
        }
    }
    //sozdanie setki s minami
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    bool arrbool[SIZE][SIZE];
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) {
            arrbool[i][j] = false;
        }
    }
    
    
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++) {
            cout << "@" << " ";
        }
        cout << endl;
    }
    int step = 0;
    while (true) {
        bool lose = false;
        bool win = false;
        int l, m;
        int countsymbols = 0;
        //cout << "Enter number of line: ";
        cin >> l;
        //cout << "Enter number of row:  ";
        cin >> m;

        for (int i = 0; i < SIZE; i++)
        {
            if ((l > SIZE - 1) || (m > SIZE - 1)) {
                cout << "Numbers of line or row not in range" << endl
                    << "Enter again numbers in range 0 to 7: " << endl;
                break;
            }
            for (int j = 0; j < SIZE; j++) {

                if (l == i && m == j) {
                    while (step<64) {
                        for (int ii = 0; ii < SIZE; ii++)
                        {
                            for (int jj = 0; jj < SIZE; jj++) {

                                if (arr[l][m] == 0) {
                                    if (l == 0 && m == 0)
                                    {//Р»РµРІС‹Р№ СѓРіРѕР», С‡С‚РѕР±С‹ РЅРµ РІС‹С…РѕРґРёР»Рѕ Р·Р° РєСЂР°СЏ РїРѕР»СЏ
                                        arrbool[l][m] = true;
                                        arrbool[l][m + 1] = true;
                                        arrbool[l + 1][m + 1] = true;
                                        arrbool[l + 1][m] = true;
                                    }
                                    else if (m == 0 && l > 0 && l < SIZE - 1) {//leviy perviy stolb do lastovogo elementa
                                        arrbool[l][m] = true;
                                        arrbool[l - 1][m] = true;
                                        arrbool[l - 1][m + 1] = true;
                                        arrbool[l][m + 1] = true;
                                        arrbool[l + 1][m + 1] = true;
                                        arrbool[l + 1][m] = true;
                                    }
                                    else if (m == 0 && l == SIZE - 1) {
                                        arrbool[l][m] = true;
                                        arrbool[l - 1][m] = true;
                                        arrbool[l - 1][m + 1] = true;
                                        arrbool[l][m + 1] = true;
                                    }


                                    else if (l == SIZE - 1 && m > 0 && m < SIZE - 1) {//nij ryad do last elementa
                                        arrbool[l][m] = true;
                                        arrbool[l][m - 1] = true;
                                        arrbool[l - 1][m - 1] = true;
                                        arrbool[l - 1][m] = true;

                                        arrbool[l - 1][m + 1] = true;

                                        arrbool[l][m + 1] = true;
                                    }
                                    else if (m == SIZE - 1 && l == SIZE - 1) {//last element vprincipe
                                        arrbool[l][m] = true;
                                        arrbool[l][m - 1] = true;
                                        arrbool[l - 1][m - 1] = true;
                                        arrbool[l - 1][m] = true;
                                    }
                                    else if (m == SIZE - 1 && l > 0 && l < SIZE - 1) {//last stolb
                                        arrbool[l][m] = true;
                                        arrbool[l][m - 1] = true;
                                        arrbool[l - 1][m - 1] = true;
                                        arrbool[l - 1][m] = true;
                                        arrbool[l + 1][m - 1] = true;
                                        arrbool[l + 1][m] = true;
                                    }
                                    else if (m == SIZE - 1 && l == 0)

                                    {//last stolb 1 elem
                                        arrbool[l][m] = true;
                                        arrbool[l][m - 1] = true;
                                        arrbool[l + 1][m - 1] = true;
                                        arrbool[l + 1][m] = true;
                                    }
                                    else if (l == 0 && m > 0 && m < SIZE - 1)
                                    {//verh stroka
                                        arrbool[l][m] = true;
                                        arrbool[l][m - 1] = true;
                                        arrbool[l + 1][m - 1] = true;
                                        arrbool[l + 1][m] = true;
                                        arrbool[l + 1][m + 1] = true;
                                        arrbool[l][m + 1] = true;
                                    }
                                    else {//centr
                                        arrbool[l][m] = true;
                                        arrbool[l][m - 1] = true;
                                        arrbool[l - 1][m - 1] = true;
                                        arrbool[l - 1][m] = true;
                                        arrbool[l + 1][m - 1] = true;
                                        arrbool[l + 1][m] = true;
                                        arrbool[l + 1][m + 1] = true;
                                        arrbool[l][m + 1] = true;
                                        arrbool[l - 1][m + 1] = true;

                                    }
                                }
                                else {
                                    arrbool[l][m] = true;
                                }

                                
                                if (arrbool[ii][jj] == true && arr[ii][jj]==0) {
                                    if (ii == 0 && jj == 0)
                                    {//Р»РµРІС‹Р№ СѓРіРѕР», С‡С‚РѕР±С‹ РЅРµ РІС‹С…РѕРґРёР»Рѕ Р·Р° РєСЂР°СЏ РїРѕР»СЏ
                                        arrbool[ii][jj] = true;
                                        arrbool[ii][jj + 1] = true;
                                        arrbool[ii + 1][jj + 1] = true;
                                        arrbool[ii + 1][jj] = true;
                                    }
                                    else if (jj == 0 && ii > 0 && ii < SIZE - 1) {//leviy perviy stolb do lastovogo elementa
                                        arrbool[ii][jj] = true;
                                        arrbool[ii - 1][jj] = true;
                                        arrbool[ii - 1][jj + 1] = true;
                                        arrbool[ii][jj + 1] = true;
                                        arrbool[ii + 1][jj + 1] = true;
                                        arrbool[ii + 1][jj] = true;
                                    }
                                    else if (jj == 0 && ii == SIZE - 1) {
                                        arrbool[ii][jj] = true;
                                        arrbool[ii - 1][jj] = true;
                                        arrbool[ii - 1][jj + 1] = true;
                                        arrbool[ii][jj + 1] = true;
                                    }


                                    else if (ii == SIZE - 1 && jj > 0 && jj < SIZE - 1) {//nij ryad do last elementa
                                        arrbool[ii][jj] = true;
                                        arrbool[ii][jj - 1] = true;
                                        arrbool[ii - 1][jj - 1] = true;
                                        arrbool[ii - 1][jj] = true;

                                        arrbool[ii - 1][jj + 1] = true;

                                        arrbool[ii][jj + 1] = true;
                                    }
                                    else if (jj == SIZE - 1 && ii == SIZE - 1) {//last element vprincipe
                                        arrbool[ii][jj] = true;
                                        arrbool[ii][jj - 1] = true;
                                        arrbool[ii - 1][jj - 1] = true;
                                        arrbool[ii - 1][jj] = true;
                                    }
                                    else if (jj == SIZE - 1 && ii > 0 && ii < SIZE - 1) {//last stolb
                                        arrbool[ii][jj] = true;
                                        arrbool[ii][jj- 1] = true;
                                        arrbool[ii - 1][jj - 1] = true;
                                        arrbool[ii - 1][jj] = true;
                                        arrbool[ii + 1][jj - 1] = true;
                                        arrbool[ii + 1][jj] = true;
                                    }
                                    else if (jj == SIZE - 1 && ii == 0)

                                    {//last stolb 1 elem
                                        arrbool[ii][jj] = true;
                                        arrbool[ii][jj - 1] = true;
                                        arrbool[ii + 1][jj - 1] = true;
                                        arrbool[ii + 1][jj] = true;
                                    }
                                    else if (ii == 0 && jj > 0 && jj < SIZE - 1)
                                    {//verh stroka
                                        arrbool[ii][jj] = true;
                                        arrbool[ii][jj - 1] = true;
                                        arrbool[ii + 1][jj - 1] = true;
                                        arrbool[ii + 1][jj] = true;
                                        arrbool[ii + 1][jj + 1] = true;
                                        arrbool[ii][jj + 1] = true;
                                    }
                                    else {//centr
                                        arrbool[ii][jj] = true;
                                        arrbool[ii][jj - 1] = true;
                                        arrbool[ii - 1][jj - 1] = true;
                                        arrbool[ii - 1][jj] = true;
                                        arrbool[ii + 1][jj - 1] = true;
                                        arrbool[ii + 1][jj] = true;
                                        arrbool[ii + 1][jj + 1] = true;
                                        arrbool[ii][jj + 1] = true;
                                        arrbool[ii - 1][jj + 1] = true;

                                    }
                                }
                                
                            }
                            
                        }
                        step++;
                        if (arr[l][m]==5)
                        {
                            lose = true;
                        }
                    }
                }
                
                

                if (arrbool[i][j] == false) {
                    countsymbols++;
                }
                step = 0;
            }


            
        }
        for (int i = 0; i < SIZE; i++)
        {
            for (int j = 0; j < SIZE; j++) {
                if (arrbool[i][j] == true) {
                    cout << arr[i][j] << " ";
                }
                else {
                    cout << "@" << " ";
                }
            }
            cout << endl;
        }
        if (countsymbols == countmines) {
            cout << "Congratulations! u win! ";
            return 0;
        }

        if (lose == true) {
            cout << "Game over! " << endl;
            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++) {
                    if (arr[i][j] != 5) {
                        cout << arr[i][j] << " ";
                    }
                    else { cout << "*" << " "; }
                }
                cout << endl;
            }
        }


    }

}
