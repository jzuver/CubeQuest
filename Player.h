#ifndef FINAL_PROJECT_DLAFONTA_JZUVER_PLAYER_H
#define FINAL_PROJECT_DLAFONTA_JZUVER_PLAYER_H



class Player{
private:
    int health;
    int attackPower;
    int defensePower;
    int level;
    int experience;

public:

    // constructors
    Player();
    Player(int health, int attackPower, int defensePower, int level, int experience);

    // getters
    int getHealth();
    int getAttackPower();
    int getDefensePower();
    int getLevel();
    int getExperience();

    // setters
    void setHealth(int health);
    void setAttackPower(int power);
    void setDefensePower(int power);
    void setLevel(int level);
    void setExperience(int experience);

    // other functions
    void attack(Player & enemy);
    void levelUp();


};


#endif //FINAL_PROJECT_DLAFONTA_JZUVER_PLAYER_H
