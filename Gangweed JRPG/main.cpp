#include <iostream>
#include <unistd.h>
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
    short maxAllyHP;
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

    int selectedMoveID;
    int selectedSlotID;
    while (johnChapin.enemyHP > 0 || kuronbo.enemyHP > 0) {
        cout << "Move id?" << endl;
        cin >> selectedMoveID;
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
