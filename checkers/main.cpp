#include <iostream>

class Сage{
private:
    int x;
    int y;
    bool chess = false; //empty board before game
    bool lady = false; //zero ladies
    bool whiteCage = true; // before game all cages is white
    bool whiteChess = false; //zero chess after game
    bool eat = false;
public:
    void setX(int posX) {
        x = posX;
    }
    int getX(){
        return x;
    }
    void setY(int posY){
        y = posY;
    }
    int getY(){
        return y;
    }
    void setLady(){
        lady = true;
    }
    bool isLady(){
        return lady;
    }
    void chessAdd(){
        chess = true;
    }
    void chessDelete(){
        chess = false;
        lady = false;
        whiteChess = false;
    }
    bool isChess(){
        return chess;
    }
    void setBlackCage() {
        whiteCage = false;
    }
    bool isWhiteCage() {
        return whiteCage;
    }
    void setBlack(){
        whiteChess = false;
    }
    void setWhite() {
        whiteChess = true;
    }
    bool isWhite(){
        return whiteChess;
    }
    void setEat(){
        eat = true;
    }
    bool canEat(){
        return eat;
    }
    void step(bool newWhiteChess, bool newLady) {
        chess = true;
        whiteChess = newWhiteChess;
        lady = newLady;
    }
};
int charToInt(char tempX) {
    switch (tempX) {
        case 'a':
            return 1;
            break;
        case 'A':
            return 1;
            break;
        case 'b':
            return 2;
            break;
        case 'B':
            return 2;
            break;
        case 'c':
            return 3;
            break;
        case 'C':
            return 3;
            break;
        case 'd':
            return 4;
            break;
        case 'D':
            return 4;
            break;
        case 'e':
            return 5;
            break;
        case 'E':
            return 5;
            break;
        case 'f':
            return 6;
            break;
        case 'F':
            return 6;
            break;
        case 'g':
            return 7;
            break;
        case 'G':
            return 7;
            break;
        case 'h':
            return 8;
            break;
        case 'H':
            return 8;
            break;
        default:
            return 0;
            break;
    }
}
int main() {
    Сage gamingField[10][10];
    for (int i = 1; i < 8; i++) {
        for (int j = 1; j < 8; j++) {
            if ((i+j)%2==1){
                gamingField[i][j].setBlackCage();
                if (i < 4) {
                    gamingField[i][j].chessAdd();
                    gamingField[i][j].setWhite();
                }
                if (i > 5) {
                    gamingField[i][j].chessAdd();
                    gamingField[i][j].setBlack();
                }
            }
        }
    }
    std::string firstPlayer, secondPlayer;
    std::cout << "Enter first player name\n";
    std::cin >> firstPlayer;
    std::cout << "Enter second player name\n";
    std::cin >> secondPlayer;
    int countWhite = 12;
    int countBlack = 12;
    bool whiteStep = true;
    int stepCount = 0;
    bool needEat = false;
    char tempFirstY, tempSecondY;
    int firstX, secondX=0, firstY, secondY=0;
    while (countBlack != 0 || countWhite != 0) {
        for (int i = 1; i < 8; i++) {
            for (int j = 1; j < 8; j++) {
                if (gamingField[i][j].isLady()!=true){
                    if (gamingField[i+1][j+1].isWhiteCage() != true && gamingField[i+2][j+2].isWhiteCage() != true &&
                        gamingField[i+1][j+1].isChess()==true && gamingField[i][j].isWhite()!=gamingField[i+1][j+1].isWhite() && gamingField[i+2][j+2].isChess()==false) {
                        needEat = true;
                        gamingField[i][j].setEat();
                    }
                    if (gamingField[i+1][j-1].isWhiteCage() != true && gamingField[i+2][j-2].isWhiteCage() != true &&
                        gamingField[i+1][j-1].isChess()==true && gamingField[i][j].isWhite()!=gamingField[i+1][j-1].isWhite() && gamingField[i+2][j-2].isChess()==false) {
                        needEat = true;
                        gamingField[i][j].setEat();
                    }
                    if (gamingField[i-1][j-1].isWhiteCage() != true && gamingField[i-2][j-2].isWhiteCage() != true &&
                        gamingField[i-1][j-1].isChess()==true && gamingField[i][j].isWhite()!=gamingField[i-1][j-1].isWhite() && gamingField[i-2][j-2].isChess()==false) {
                        needEat = true;
                        gamingField[i][j].setEat();
                    }
                    if (gamingField[i+1][j-1].isWhiteCage() != true && gamingField[i+2][j-2].isWhiteCage() != true &&
                        gamingField[i+1][j-1].isChess()==true && gamingField[i][j].isWhite()!=gamingField[i+1][j-1].isWhite() && gamingField[i+2][j-2].isChess()==false) {
                        needEat = true;
                        gamingField[i][j].setEat();
                    }
                }
                else {
                    for (int k = 1; k < 6; k++){
                        if (gamingField[i+k][j+k+1].isWhiteCage() != true && gamingField[i+k+1][j+k+1].isWhiteCage() != true &&
                            gamingField[i+k][j+k].isChess()==true && gamingField[i][j].isWhite()!=gamingField[i+k][j+k].isWhite() && gamingField[i+k+1][j+k+1].isChess()==false) {
                            needEat = true;
                            gamingField[i][j].setEat();
                        }
                        if (gamingField[i+k][j-k].isWhiteCage() != true && gamingField[i+k+1][j-k-1].isWhiteCage() != true &&
                            gamingField[i+k][j-k].isChess()==true && gamingField[i][j].isWhite()!=gamingField[i+k][j-k].isWhite() && gamingField[i+k+1][j-k-1].isChess()==false) {
                            needEat = true;
                            gamingField[i][j].setEat();
                        }
                        if (gamingField[i-k][j-k].isWhiteCage() != true && gamingField[i-k-1][j-k-1].isWhiteCage() != true &&
                            gamingField[i-k][j-k].isChess()==true && gamingField[i][j].isWhite()!=gamingField[i-k][j-k].isWhite() && gamingField[i-k-1][j-k-1].isChess()==false) {
                            needEat = true;
                            gamingField[i][j].setEat();
                        }
                        if (gamingField[i+k][j-k].isWhiteCage() != true && gamingField[i+k+1][j-k-1].isWhiteCage() != true &&
                            gamingField[i+k][j-k].isChess()==true && gamingField[i][j].isWhite()!=gamingField[i+k][j-k].isWhite() && gamingField[i+2][j-2].isChess()==false) {
                            needEat = true;
                            gamingField[i][j].setEat();
                        }
                    }
                }
            }
        }
        if (gamingField[secondX][secondY].canEat() == false && stepCount > 0) {
            whiteStep = !whiteStep;
        }
        std::cout << "Choose chess\n";
        std::cin >> tempFirstY >> firstX;
        firstY = charToInt(tempFirstY);
        if (firstY <= 0 && firstX <=0 && firstY >= 9 && firstX >= 9) {
            std::cout << "Error unexcepted input\n";
            continue;
        }
        if (gamingField[firstX][firstY].isChess() != true) {
            std::cout << "Error empty cage\n";
            continue;
        }
        if (gamingField[firstX][firstY].isWhite() != whiteStep) {
            std::cout << "This cage can't stepping\n";
            continue;
        }
        std::cout << "Choose attack target\n";
        std::cin >> tempSecondY >> secondX;
        secondY = charToInt(tempSecondY);
        if (secondY <=0 && secondX <=0 && secondY >=9 && secondX >=9) {
            std::cout << "Error unexcepted input\n";
            continue;
        }
        if (gamingField[secondX][secondY].isChess() == true) {
            std::cout << "Error not empty cage\n";
            continue;
        }
        if (abs(firstX-secondX)==abs(firstY-secondY)!=0) {
            if (gamingField[firstX][firstY].isLady() == false) {
                if (gamingField[firstX][firstY].canEat() == false && abs(firstX-secondX) == 1) {
                    gamingField[firstX][firstY].chessDelete();
                    gamingField[secondX][secondY].step(gamingField[firstX][firstY].isWhite(), gamingField[firstX][firstY].isLady());
                }
                else if (abs(firstX-secondX) == 2 && gamingField[(firstX+secondX)/2][(firstY+secondY)/2].isWhite()!=gamingField[firstX][firstY].isWhite() && gamingField[(firstX+secondX)/2][(firstY+secondY)/2].isChess()==true)
                {
                    gamingField[firstX][firstY].chessDelete();
                    gamingField[secondX][secondY].step(gamingField[firstX][firstY].isWhite(), gamingField[firstX][firstY].isLady());
                    gamingField[(firstX+secondX)/2][(firstY+secondY)/2].chessDelete();
                    if (gamingField[firstX][firstY].isWhite() == true) {
                        countBlack -= 1;
                    }
                    else {
                        countWhite -= 1;
                    }
                }
                else {
                    std::cout << "Common chess can't do this step\n";
                }
            }
            else {
                if (gamingField[firstX][secondY].canEat() == false) {
                    if (firstX > secondX) {
                        if (firstY > secondY) {
                            for (int k = 1; k < abs(firstX-firstY); k++) {
                                if(gamingField[firstX-k][firstY-k].isChess() == true) {
                                    std::cout << "can't do this step\n";
                                    break;
                                }
                            }
                                gamingField[firstX][firstY].chessDelete();
                                gamingField[secondX][secondY].step(gamingField[firstX][firstY].isWhite(), gamingField[firstX][firstY].isLady());
                            
                        }
                        else {
                            for (int k = 1; k < abs(firstX-firstY); k++) {
                                if(gamingField[firstX-k][firstY+k].isChess() == true) {
                                    std::cout << "can't do this step\n";
                                    break;
                                }
                            }
                            gamingField[firstX][firstY].chessDelete();
                            gamingField[secondX][secondY].step(gamingField[firstX][firstY].isWhite(), gamingField[firstX][firstY].isLady());
                        }
                    }
                    else {
                        if (firstY > secondY) {
                            for (int k = 1; k < abs(firstX-firstY); k++) {
                                if(gamingField[firstX+k][firstY-k].isChess() == true) {
                                    std::cout << "can't do this step\n";
                                    break;
                                }
                            }
                            gamingField[firstX][firstY].chessDelete();
                            gamingField[secondX][secondY].step(gamingField[firstX][firstY].isWhite(), gamingField[firstX][firstY].isLady());
                        }
                        else {
                            for (int k = 1; k < abs(firstX-firstY); k++) {
                                if(gamingField[firstX+k][firstY+k].isChess() == true) {
                                    std::cout << "can't do this step\n";
                                    break;
                                }
                            }
                            gamingField[firstX][firstY].chessDelete();
                            gamingField[secondX][secondY].step(gamingField[firstX][firstY].isWhite(), gamingField[firstX][firstY].isLady());
                        }
                    }
                }
                else {
                    bool eaten = false;
                    if (firstX > secondX) {
                        if (firstY > secondY) {
                            for (int k = 1; k < abs(firstX-firstY); k++) {
                                if(gamingField[firstX-k][firstY-k].isChess() == true && eaten == false) {
                                    gamingField[firstX-k][firstY-k].chessDelete();
                                    if (gamingField[firstX][firstY].isWhite() == true) {
                                        countBlack -= 1;
                                    }
                                    else {
                                        countWhite -= 1;
                                    }
                                    
                                }
                                else {
                                    std::cout << "can't do this step\n";
                                    break;
                                }
                            }
                                gamingField[firstX][firstY].chessDelete();
                                gamingField[secondX][secondY].step(gamingField[firstX][firstY].isWhite(), gamingField[firstX][firstY].isLady());
                            
                        }
                        else {
                            for (int k = 1; k < abs(firstX-firstY); k++) {
                                if(gamingField[firstX-k][firstY+k].isChess() == true && eaten == false) {
                                    gamingField[firstX-k][firstY+k].chessDelete();
                                    if (gamingField[firstX][firstY].isWhite() == true) {
                                        countBlack -= 1;
                                    }
                                    else {
                                        countWhite -= 1;
                                    }
                                    
                                }
                                else {
                                    std::cout << "can't do this step\n";
                                    break;
                                }
                            }
                            gamingField[firstX][firstY].chessDelete();
                            gamingField[secondX][secondY].step(gamingField[firstX][firstY].isWhite(), gamingField[firstX][firstY].isLady());
                        }
                    }
                    else {
                        if (firstY > secondY) {
                            for (int k = 1; k < abs(firstX-firstY); k++) {
                                if(gamingField[firstX+k][firstY-k].isChess() == true && eaten == false) {
                                    gamingField[firstX+k][firstY-k].chessDelete();
                                    if (gamingField[firstX][firstY].isWhite() == true) {
                                        countBlack -= 1;
                                    }
                                    else {
                                        countWhite -= 1;
                                    }
                                    
                                }
                                else {
                                    std::cout << "can't do this step\n";
                                    break;
                                }
                            }
                            gamingField[firstX][firstY].chessDelete();
                            gamingField[secondX][secondY].step(gamingField[firstX][firstY].isWhite(), gamingField[firstX][firstY].isLady());
                        }
                        else {
                            for (int k = 1; k < abs(firstX-firstY); k++) {
                                if(gamingField[firstX+k][firstY+k].isChess() == true && eaten == false) {
                                    gamingField[firstX+k][firstY+k].chessDelete();
                                    if (gamingField[firstX][firstY].isWhite() == true) {
                                        countBlack -= 1;
                                    }
                                    else {
                                        countWhite -= 1;
                                    }
                                    
                                }
                                else {
                                    std::cout << "can't do this step\n";
                                    break;
                                }
                            }
                            gamingField[firstX][firstY].chessDelete();
                            gamingField[secondX][secondY].step(gamingField[firstX][firstY].isWhite(), gamingField[firstX][firstY].isLady());
                        }
                    }
                }
                
                }
            }
        if (gamingField[secondX][secondY].isWhite() && secondX == 8) {
                gamingField[secondX][secondY].setLady();
        }
        else if (!gamingField[secondX][secondY].isWhite() && secondX == 0) {
            gamingField[secondX][secondY].setLady();
        }
        for (int i = 1; i < 8; i++) {
            for (int j = 1; j < 8; j++) {
                if (gamingField[i][j].isChess()) {
                    if (gamingField[i][j].isWhite()) {
                        if (gamingField[i][j].isLady()) {
                            std::cout << 'W';
                        }
                        else {
                            std::cout << 'w';
                        }
                    }
                    else {
                        if (gamingField[i][j].isLady()) {
                            std::cout << 'B';
                        }
                        else {
                            std::cout << 'b';
                        }
                    }
                }
                else {
                    std::cout << 'n';
                }
            }
            std::cout << std::endl;
}
        stepCount++;
        }
    return 0;
}
