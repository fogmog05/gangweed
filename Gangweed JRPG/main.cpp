#include <iostream>
#include <unistd.h>
#include <algorithm>
#include <iterator>
using namespace std;

class Enemy {
    public:
    string enemyName;
    short enemyHP;
    short enemyMaxHP;
    char enemyMoves[10];
    int enemyID;
};

class Ally {
    public:
    string allyName;
    short allyHP;
    short allyMaxHP;
    char allyMoves[10];
    int allyID;
};

void battleMove(char moveID, Enemy *target){
    int damage;
    switch(moveID) {
    case 0:
        break;
    case 1:
        damage = 22;
        break;
    case 2:
        damage = 44;
        break;
    }
    target->enemyHP -= damage;
    cout << target->enemyName << " took " << damage << " damage!" << endl;
}

int main() {
    Enemy johnChapin;
    johnChapin.enemyName = "John Chapin";
    johnChapin.enemyHP = 100;
    johnChapin.enemyMaxHP = 100;
    johnChapin.enemyID = 1;
    johnChapin.enemyMoves[1] = {1};

    Enemy kuronbo;
    kuronbo.enemyName = "Kuronbo";
    kuronbo.enemyHP = 100;
    kuronbo.enemyMaxHP = 100;
    kuronbo.enemyID = 2;
    kuronbo.enemyMoves[1] = {1};

    Enemy *enemySlots[2] = {&johnChapin,&kuronbo};

    Ally jesseDotson;
    jesseDotson.allyName = "Jesse Dotson";
    jesseDotson.allyHP = 100;
    jesseDotson.allyMaxHP = 100;
    jesseDotson.allyID = 1;
    jesseDotson.allyMoves[1] = {1};

    int selectedMoveID;
    int selectedSlotID;
    while (johnChapin.enemyHP > 0 || kuronbo.enemyHP > 0) {
        select_move:
        cout << "Move id?" << endl;
        cin >> selectedMoveID;
        // Checks to see if ally has selected move.
        bool allyHasMove = std::find(std::begin(jesseDotson.allyMoves), std::end(jesseDotson.allyMoves), selectedMoveID) != std::end(jesseDotson.allyMoves);
        if (!allyHasMove){
            cout << "Invalid move." << endl;
            goto select_move;
        }
        cout << "Slot id?" << endl;
        cin >> selectedSlotID;
        battleMove(selectedMoveID, enemySlots[selectedSlotID]);
        if (johnChapin.enemyHP > 0) {
            cout << johnChapin.enemyName << ": " << johnChapin.enemyHP << endl;
        }
        if (kuronbo.enemyHP > 0) {
            cout << kuronbo.enemyName << ": " << kuronbo.enemyHP << endl;
        }
        usleep(5000);
    }
    return 0;
}
