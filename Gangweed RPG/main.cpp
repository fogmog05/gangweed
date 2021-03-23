#include <iostream>


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

void battleMove(slotID, moveID){
    switch(moveID) {
    case 0:
        break;
    case 1:

        johnChapin.enemyHP = johnChapin.enemyHP - 22;
        break;


    }
}

int main(){

    Enemy johnChapin;
    johnChapin.enemyName = "John Chapin";
    johnChapin.enemyHP = 100;
    johnChapin.maxEnemyHP = 100;
    johnChapin.enemySlot = 1;
    johnChapin.enemyMoves[] = {1};


    Ally jesseDotson;

    int selectedMoveID;
    int selectedSlotID;

    cout << "Move id?" << endl;
    cin >> selectedMoveID;
    cout << "Slot id?";
    cin >> selectedSlotID;
    battleMove(selectedSlotID, selectedMoveID);
    cout << johnChapin.enemyHP;
    return 0;
}
