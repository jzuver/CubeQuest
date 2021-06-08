
#include <iostream>
#include "Player.h"
using namespace std;

Player testEnemyOne;
Player testEnemyTwo;
Player testEnemyLevelUpOne;
Player testEnemyLevelUpTwo;


bool testPlayerAttack();
bool testPlayerLevelUp();

int main(){
    cout << testPlayerAttack() << endl;
    cout << testPlayerLevelUp() << endl;
    return 0;
}

bool testPlayerAttack () {
    bool passed = true;

    testEnemyOne.attack(testEnemyTwo);

    if(testEnemyOne.getHealth() < testEnemyTwo.getHealth()){
        cout << "FAILED enemy has more health after attack test" << endl;
        passed = false;
    }

    if(testEnemyOne.getHealth() == testEnemyTwo.getHealth()){
        cout << "FAILED enemy lost no health during the attack test" << endl;
        passed = false;
    }

    return passed;

}

bool testPlayerLevelUp(){
    bool passed = true;
    testEnemyLevelUpOne.levelUp();

    if(testEnemyLevelUpOne.getLevel() == testEnemyLevelUpTwo.getLevel()){
        cout << "FAILED level up test" << endl;
        passed = false;
    }
    if(testEnemyLevelUpOne.getAttackPower() == testEnemyLevelUpTwo.getAttackPower()){
        cout << "FAILED increase attack power with level increase test" << endl;
        passed = false;
    }
    if(testEnemyLevelUpOne.getDefensePower() == testEnemyLevelUpTwo.getDefensePower()){
        cout << "FAILED increase defense power with level increase test" << endl;
        passed = false;
    }
    if(testEnemyLevelUpOne.getHealth() == testEnemyLevelUpTwo.getHealth()){
        cout << "FAILED increase health with level increase test" << endl;
        passed = false;
    }

    return passed;

}
