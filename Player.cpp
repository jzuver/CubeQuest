#include "Player.h"
#include <stdlib.h>

Player::Player() {
    this->attackPower =  15;
    this-> defensePower = 15;
    this-> level = 1;
    this-> health = level * 100;
    this-> experience = 0;
}

Player::Player(int health, int attackPower, int defensePower, int level, int experience) {
    setHealth(health);
    setAttackPower(attackPower);
    setDefensePower(defensePower);
    setLevel(level);
    setExperience(experience);
}

// getters
int Player::getHealth() {
    return this->health;
}
int Player::getAttackPower() {
    return this->attackPower;
}
int Player::getDefensePower() {
    return this->defensePower;
}
int Player::getLevel() {
    return this->level;
}
int Player::getExperience() {
    return this->experience;
}

// setters
void Player::setHealth(int health) {
    this->health = health;
}
void Player::setAttackPower(int power) {
    this->attackPower = power;
}
void Player::setDefensePower(int power) {
    this->defensePower = power;
}
void Player::setLevel(int level) {
    this->level = level;
}
void Player::setExperience(int experience) {
    this->experience = experience;
}

// other functions
void Player::attack(Player &enemy) {
    int damage = this->attackPower;
    enemy.setHealth(enemy.getHealth() - (rand() % damage + 1));
    // if dead add experience
    if (enemy.getHealth() <= 0) {
        this->experience += 50 * enemy.getLevel();
        // if experience over threshold level up player
        if (experience >= this->level * 100) {
            this->levelUp();
            this->experience = 0;
        }

    }
}

void Player::levelUp() {
    ++level;
    attackPower = attackPower*level;
    defensePower = defensePower*level;
    health = health + 10;
}
