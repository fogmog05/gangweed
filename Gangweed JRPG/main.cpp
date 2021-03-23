#include <iostream>
#include <conio.h>

using namespace std;

class Enemy {
    public:
    string enemyName;
    int enemyHP;
    int maxEnemyHP;
    int enemyMoves[10];
    int enemySlot;
};
class Ally {
    public:
    string allyName;
    int allyHP;
    int maxAllyHP;
    int allyMoves[10];
    int allySlot;
};

int battleMove(int moveID, int enemyHP){
    switch(moveID) {

    case 0:
        break;

    case 1:
        enemyHP = enemyHP - 22;
        return enemyHP;
        break;

    case 5:
        enemyHP = enemyHP - 30;
        return enemyHP;
        break;

    default:
        return enemyHP;
        break;


    }
}

int main(){

    Enemy johnChapin;
    johnChapin.enemyName = "John Chapin";
    johnChapin.enemyHP = 100;
    johnChapin.maxEnemyHP = 100;
    johnChapin.enemySlot = 1;
    johnChapin.enemyMoves[0] = {1};

    Ally jesseDotson;
    jesseDotson.allyName="Jesse Dotson";
    jesseDotson.allyHP = 100;
    jesseDotson.maxAllyHP = 100;
    jesseDotson.allySlot = 1;
    jesseDotson.allyMoves[0] = {1};
    jesseDotson.allyMoves[1] = {5};


    int selectedMoveID;
    int selectedSlotID;

    cout << "Move id?" << endl;
    cout << jesseDotson.allyMoves[0] << endl;
    cout << jesseDotson.allyMoves[1] << endl;
    cin >> selectedMoveID;
    johnChapin.enemyHP = battleMove(selectedMoveID, johnChapin.enemyHP);
    system("cls");
    cout << "Jesse Dotson HP: " << jesseDotson.allyHP << " | John Chapin HP: " << johnChapin.enemyHP;
    return 0;
};
