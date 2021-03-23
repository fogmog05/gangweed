#include <iostream>

using namespace std;

class Enemy {
    public:
    string enemyName;
    int enemyHP;
    int maxEnemyHP;
    int enemyMoves[10];
    int enemyID;
};

class Ally {
    public:
    string allyName;
    int allyHP;
    int maxAllyHP;
    int allyMoves[10];
    int allyID;
};

void battleMove(int moveID, Enemy *target){
    switch(moveID) {
    case 0:
        break;
    case 1:
        target->enemyHP -= 22;
        break;


    }
}

int main() {
    Enemy johnChapin;
    johnChapin.enemyName = "John Chapin";
    johnChapin.enemyHP = 100;
    johnChapin.maxEnemyHP = 100;
    johnChapin.enemyID = 1;
    johnChapin.enemyMoves[1] = {1};
    
    Enemy kuronbo;
    kuronbo.enemyName = "Kuronbo";
    kuronbo.enemyHP = 100;
    kuronbo.maxEnemyHP = 100;
    kuronbo.enemyID = 2;
    kuronbo.enemyMoves[1] = {1};
    
    Enemy *enemySlots[2] = {&johnChapin,&kuronbo};

    Ally jesseDotson;

    int selectedMoveID;
    int selectedSlotID;
    while (johnChapin.enemyHP > 0 || kuronbo.enemyHP > 0) {
        cout << "Move id?" << endl;
        cin >> selectedMoveID;
        cout << "Slot id?" << endl;
        cin >> selectedSlotID;  
        battleMove(selectedMoveID, enemySlots[selectedSlotID-1]);
        cout << johnChapin.enemyName << ": " << johnChapin.enemyHP << endl;
        cout << kuronbo.enemyName << ": " << kuronbo.enemyHP << endl;
    }
    return 0;
}
