#include "graphics.h"
#include "Button.h"
#include "Player.h"
#include <iostream>
#include <time.h>
#include <vector>
using namespace std;

GLdouble width, height;
bool rightRoomComplete = false;
int wd;
int counter = 0;
int expCounter = 0;
string userName;
Button spawn({1, 0, 0}, {250, 240}, 100, 50, userName);
Quad door1({0,0,1}, {0, 250}, 50, 100);
Quad door2({0,0,1}, {500, 250}, 50, 100);
Quad door3({0,0,1}, {250, 0}, 50, 100);
Quad door4({0,0,1}, {250, 500}, 50, 100);
Quad door5({0,0,1}, {250, 0}, 50, 100);
Quad door6({0,0,1}, {250, 500}, 50, 100);;//top2 bottom
Quad door7({0,0,1}, {250, 0}, 50, 100);//top2 top
Quad door8({0,0,1}, {0, 250}, 50, 100);//top2 left
Quad door9({0,0,1}, {500, 250}, 50, 100);//top2 right
Quad door10({0,0,1}, {0, 250}, 50, 100);//top2right left
Quad door11({0,0,1}, {500, 250}, 50, 100);//top2left right
Quad door12({0,0,1}, {250, 0}, 50, 100);//top2left top
Quad door13({0,0,1}, {250, 500}, 50, 100);//top3left bottom
Quad door14({0,0,1}, {500, 250}, 50, 100);//top3left right
Quad door15({0,0,1}, {0, 250}, 50, 100);//top3 left
Quad door16({0,0,1}, {250, 0}, 50, 100);//top3 top
Quad door17({0,0,1}, {500, 250}, 50, 100);//top3 right
Quad door18({0,0,1}, {0, 250}, 50, 100);//top3right left
Quad door19({0,0,1}, {500, 250}, 50, 100);//top3right right
Quad door20({0,0,1}, {0, 250}, 50, 100);//top3rightright left
Quad door21({0,0,1}, {250, 0}, 50, 100);//top3rightright top
Quad door22({0,0,1}, {250, 500}, 50, 100);//boss bottom
Quad door23({0,0,1}, {500, 250}, 50, 100);//boss left
Quad door24({0,0,1}, {0, 250}, 50, 100);//final right

Quad rightRoomObject ({0,.5,.5}, {250, 250}, 50, 50);
Quad leftRoomObject ({0,1,0}, {250, 250}, 50, 50);
Quad topRoomObject ({1,1,0}, {250, 250}, 50, 50);
Quad bottomRoomObject ({1,0,1}, {250, 250}, 50, 50);
Quad top2rightObject({1,1,1}, {250, 250}, 50, 50);
Quad top3rightObject({0.5,0,1}, {250, 250}, 50, 50);

//enemies
Quad rightEnemy({0,.5,.5}, {250, 250}, 50, 50);
Quad rightEnemyFight({0,.5,.5}, {150, 250}, 50, 50);
Quad topRoomEnemyQuad({0,1,0}, {100, 250}, 50, 50);
Quad topRoomEnemyFight({0,1,0}, {150, 250}, 50, 50);
Quad finalBossQuad({0,1,1}, {250, 250}, 100, 100);
Quad finalBossFight({0,1,1}, {150, 250}, 100, 100);
Quad top3EnemyOneQuad({.5,0,0}, {50,100}, 50, 50);
Quad top3EnemyOneFight({.5,0,0}, {150,250}, 50, 50);
Quad top3EnemyTwoQuad({1,1,0}, {250,100}, 50, 50);
Quad top3EnemyTwoFight({1,1,0}, {150,250}, 50, 50);

Quad exitDoor({0,1,1}, {250, 50}, 100, 100);

//battle graphics
Quad window1({1,1,1}, {250, 400},475, 175);
Quad window2({0,0,0}, {250, 400},450, 150);
Quad selector({1,1,1}, {375, 350},10, 10);
Quad seperator({1,1,1}, {375, 400},10, 150);

Quad playerHealth({0,1,0}, {430, 20},100, 10);
Quad enemyHealth({1,0,0}, {60, 20},100, 10);

Button button1({1,0,0}, {420, 350},50, 10, "");
Button button2({1,0,0}, {420, 380},50, 10, "");
Button button3({1,0,0}, {420, 410},50, 10, "");

// Player class
Player p;
Player enemyRightRoom(100, 5, 5, 1, 50);
Player enemyTopRoom(100, 5, 5, 1, 50);
Player finalBoss(250, 10, 10, 2, 100);
Player top3EnemyOne(150, 5, 5, 1, 50);
Player top3EnemyTwo(150, 5, 5, 1, 50);
string PlayerHealth;
string EnemyHealth;

vector<Quad> inventory;

enum screen {middle, leftSide, rightSide, top, bottom, endScreen, battleRight, top2, battleTop, top2right,
             top2left, top3left, top3, top3right, top3rightright, bossroom, final, battleFinalBoss,
             battletop3enemyone, battletop3enemytwo, winScreen, welcome};
screen currentScreen = welcome;
string endMessage = "You have been defeated...";
string secondEndMessage = "Game Over. Press 'Esc'";
string finalRoomMessage = "You found the exit to the dungeon. Go through it!";
string winMessage = "You escaped the dungeon!!!";
string youWin = "Press esc";
string hint2 = "I'm a potion! I heal 25 health! Press 'e' to pick me up. ";
string hint4 = "I'm also a potion. Press 'e' to pick me up!";
string inv = "Inventory: ";
string goal = "You are trapped in a dungeon, welcome to CubeQuest.";
string battleMessage = "A wild cube has appeared!";
string battleMessage2 = "What will you do?";
string battleMessage3 = "You have attacked!";
string rightRoomExperience = "You gained " + to_string(enemyRightRoom.getExperience())+ " experience!";
string bossRoomExperience = "You gained " + to_string(finalBoss.getExperience())+ " experience!";
string top3EnemyOneExperience = "You gained " + to_string(top3EnemyOne.getExperience())+ " experience!";
string top3EnemyTwoExperience = "You gained " + to_string(top3EnemyTwo.getExperience())+ " experience!";
string gameName = "CubeQuest";
string byline = "By: Josh Zuver and Donovan Lafontaine";
string gameStart = "Press 's' to start the game.";

string attack = "Attack";
string item = "Item";
string run = "Run";

bool playerIsAttacking = false;
bool enemyIsAttacking = false;
bool displayExpRightRoom = false;
bool displayExpTopRoom = false;
bool displayExpBossRoom = false;
bool displayExpTop3EnemyOne = false;
bool displayExpTop3EnemyTwo = false;

int numObjects = 0;

void init() {
    width = 500;
    height = 500;
    srand(time(0));
}

/* Initialize OpenGL Graphics */
void initGL() {
    // Set "clearing" or background color
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Black and opaque
}

void displayWelcome() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glColor3f(1, 1, 1);
    glRasterPos2i(50, 150);
    for (const char &letter : gameName) {
        glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(50, 200);
    for (const char &letter : byline) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(50, 200);
    for (const char &letter : byline) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(0, 1, 0);
    glRasterPos2i(50, 300);
    for (const char &letter : gameStart) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }



    glFlush();  // Render now
}

/* Handler for window-repaint event. Call back when the window first appears and
 whenever the window needs to be re-painted. */
void displayMiddle() {
    string objMessage = "Objects collected: " + to_string(numObjects);
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);
    
    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);
    
    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color
    
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glColor3f(1, 1, 1);
    glRasterPos2i(50, 350);
    for (const char &letter : goal) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    // draw
    spawn.draw();
    door1.draw();
    door2.draw();
    door3.draw();
    door4.draw();

    // draw inventory
    for(Quad &item : inventory){
        item.draw();
    }

    glFlush();  // Render now
}

void displayBattleRight(){
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    spawn.draw();
    rightEnemyFight.draw();
    window1.draw();
    window2.draw();
    selector.draw();
    button1.draw();
    button2.draw();
    button3.draw();
    seperator.draw();
    playerHealth.draw();
    enemyHealth.draw();

    // inventory
    // draw inventory and message
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
    for(Quad &item : inventory){
        item.draw();
    }

    
    glColor3f(1, 1, 1);
    glRasterPos2i(400, 350);
    for (const char &letter : attack) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(400, 380);
    for (const char &letter : item) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(400, 410);
    for (const char &letter : run) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);

    }
    if(!playerIsAttacking) {

        glColor3f(1, 1, 1);
        glRasterPos2i(30, 350);
        for (const char &letter : battleMessage) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        glColor3f(1, 1, 1);
        glRasterPos2i(30, 370);
        for (const char &letter : battleMessage2) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }else{
        glColor3f(1, 1, 1);
        glRasterPos2i(30, 350);
        for (const char &letter : battleMessage3) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    PlayerHealth = "Player Health: " + to_string(p.getHealth());
    EnemyHealth = "Enemy Health: " + to_string(enemyRightRoom.getHealth());

    enemyHealth.resize(enemyRightRoom.getHealth(),10);
    playerHealth.resize(p.getHealth(),10);

    glColor3f(1, 1, 1);
    glRasterPos2i(350, 10);
    for (const char &letter : PlayerHealth) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(0, 10);
    for (const char &letter : EnemyHealth) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    if(enemyRightRoom.getHealth() <= 0){
        currentScreen = rightSide;
        rightRoomComplete = true;
        displayExpRightRoom = true;
    }

    glFlush();
}

void displayBattleTop(){
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    spawn.draw();
    topRoomEnemyFight.draw();
    window1.draw();
    window2.draw();
    selector.draw();
    button1.draw();
    button2.draw();
    button3.draw();
    seperator.draw();
    playerHealth.draw();
    enemyHealth.draw();

    // inventory
    // draw inventory and message
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
    for(Quad &item : inventory){
        item.draw();
    }


    glColor3f(1, 1, 1);
    glRasterPos2i(400, 350);
    for (const char &letter : attack) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(400, 380);
    for (const char &letter : item) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(400, 410);
    for (const char &letter : run) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);

    }
    if(!playerIsAttacking) {

        glColor3f(1, 1, 1);
        glRasterPos2i(30, 350);
        for (const char &letter : battleMessage) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        glColor3f(1, 1, 1);
        glRasterPos2i(30, 370);
        for (const char &letter : battleMessage2) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }
    else{
        glColor3f(1, 1, 1);
        glRasterPos2i(30, 350);
        for (const char &letter : battleMessage3) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    PlayerHealth = "Player Health: " + to_string(p.getHealth());
    EnemyHealth = "Enemy Health: " + to_string(enemyTopRoom.getHealth());

    enemyHealth.resize(enemyTopRoom.getHealth(),10);
    playerHealth.resize(p.getHealth(),10);

    glColor3f(1, 1, 1);
    glRasterPos2i(350, 10);
    for (const char &letter : PlayerHealth) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(0, 10);
    for (const char &letter : EnemyHealth) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    if(enemyTopRoom.getHealth() <= 0){
        currentScreen = top;
        displayExpTopRoom = true;

    }

    glFlush();
}

void displayRight() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);


    // draw
    spawn.draw();
    // inventory
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
    for(Quad &item : inventory){
        item.draw();
    }

    if(!rightRoomComplete){
        rightEnemy.draw();
    }
    else if (displayExpRightRoom){
        glColor3f(1, 1, 1);
        glRasterPos2i(150, 150);
        for (const char &letter : rightRoomExperience) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }
    door1.draw();

    glFlush();
}

void displayLeft() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    glColor3f(1, 1, 1);
    glRasterPos2i(20, 350);
    for (const char &letter : hint2) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
    // draw inventory and message
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    // draw
    spawn.draw();
    leftRoomObject.draw();
    door2.draw();

    for(Quad &item : inventory){
        item.draw();
    }

    glFlush();
}

void displayTop() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //inventory display
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    // draw
    spawn.draw();
    //topRoomObject.draw();
    door4.draw();
    door5.draw();

    if(enemyTopRoom.getHealth() > 0){
        topRoomEnemyQuad.draw();
    }

    for(Quad &item : inventory){
        item.draw();
    }

    if (displayExpTopRoom){
        glColor3f(1, 1, 1);
        glRasterPos2i(150, 150);
        for (const char &letter : rightRoomExperience) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    glFlush();
}

void displayTop2() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //inventory display
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    // draw
    spawn.draw();
    door6.draw();
    //door7.draw();
    door8.draw();
    door9.draw();
    //topRoomObject.draw();


    for(Quad &item : inventory){
        item.draw();
    }

    glFlush();
}

void displayTop2Right() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //inventory display
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    // draw
    spawn.draw();
    door10.draw();
    top2rightObject.draw();

    //topRoomObject.draw();


    for(Quad &item : inventory){
        item.draw();
    }

    glFlush();
}
void displayTop2Left() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //inventory display
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    // draw
    spawn.draw();
    door11.draw();
    door12.draw();

    //topRoomObject.draw();


    for(Quad &item : inventory){
        item.draw();
    }

    glFlush();
}


void displayTop3Left() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //inventory display
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    // draw
    spawn.draw();
    door13.draw();
    door14.draw();

    if(top3EnemyOne.getHealth() > 0){
        top3EnemyOneQuad.draw();
    }

    if(top3EnemyTwo.getHealth() > 0){
        top3EnemyTwoQuad.draw();
    }


    for(Quad &item : inventory){
        item.draw();
    }

    if (displayExpTop3EnemyOne){
        glColor3f(1, 1, 1);
        glRasterPos2i(150, 150);
        for (const char &letter : top3EnemyOneExperience) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    if (displayExpTop3EnemyTwo){
        glColor3f(1, 1, 1);
        glRasterPos2i(150, 150);
        for (const char &letter : top3EnemyTwoExperience) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    glFlush();
}

void displayTop3() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //inventory display
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    // draw
    spawn.draw();
    door15.draw();
    //door16.draw();
    door17.draw();



    //topRoomObject.draw();


    for(Quad &item : inventory){
        item.draw();
    }

    glFlush();
}

void displayTop3Right() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //inventory display
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    // draw
    spawn.draw();
    door18.draw();
    door19.draw();
    top3rightObject.draw();

    for(Quad &item : inventory){
        item.draw();
    }

    glFlush();
}

void displayTop3RightRight() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //inventory display
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    // draw
    spawn.draw();
    door20.draw();
    door21.draw();



    //topRoomObject.draw();


    for(Quad &item : inventory){
        item.draw();
    }

    glFlush();
}

void displayBossRoom() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //inventory display
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    // draw
    spawn.draw();
    door22.draw();
    door23.draw();

    if(finalBoss.getHealth() > 0 ){
        finalBossQuad.draw();
    }
    // display exp message upon fight completion
    if (displayExpBossRoom){
        glColor3f(1, 1, 1);
        glRasterPos2i(150, 150);
        for (const char &letter : bossRoomExperience) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    for(Quad &item : inventory){
        item.draw();
    }

    glFlush();
}

void displayfinal() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    //inventory display
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(50, 350);
    for (const char &letter : finalRoomMessage) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }


    // draw
    spawn.draw();
    door24.draw();
    exitDoor.draw();



    //topRoomObject.draw();


    for(Quad &item : inventory){
        item.draw();
    }

    glFlush();
}


void displayBottom() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // display room hint and inventory message
    glColor3f(1, 1, 1);
    glRasterPos2i(100, 350);
    for (const char &letter : hint4) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    // draw
    spawn.draw();
    bottomRoomObject.draw();
    door3.draw();

    for(Quad &item : inventory){
        item.draw();
    }

    glFlush();
}

void displayEnd() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // display ending message
    glColor3f(1, 1, 1);
    glRasterPos2i(150, 150);
    for (const char &letter : endMessage) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(150, 300);
    for (const char &letter : secondEndMessage) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
    glFlush();
}

void displayWin() {
    // tell OpenGL to use the whole window for drawing
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    // display ending message
    glColor3f(1, 1, 1);
    glRasterPos2i(150, 150);
    for (const char &letter : winMessage) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(150, 300);
    for (const char &letter : youWin) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
    glFlush();
}

void displayBattleFinal(){
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    spawn.draw();
    finalBossFight.draw();
    window1.draw();
    window2.draw();
    selector.draw();
    button1.draw();
    button2.draw();
    button3.draw();
    seperator.draw();
    playerHealth.draw();
    enemyHealth.draw();

    // inventory
    // draw inventory and message
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
    for(Quad &item : inventory){
        item.draw();
    }


    glColor3f(1, 1, 1);
    glRasterPos2i(400, 350);
    for (const char &letter : attack) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(400, 380);
    for (const char &letter : item) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(400, 410);
    for (const char &letter : run) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);

    }
    if(!playerIsAttacking) {

        glColor3f(1, 1, 1);
        glRasterPos2i(30, 350);
        for (const char &letter : battleMessage) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        glColor3f(1, 1, 1);
        glRasterPos2i(30, 370);
        for (const char &letter : battleMessage2) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }else{
        glColor3f(1, 1, 1);
        glRasterPos2i(30, 350);
        for (const char &letter : battleMessage3) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    PlayerHealth = "Player Health: " + to_string(p.getHealth());
    EnemyHealth = "Enemy Health: " + to_string(finalBoss.getHealth());

    enemyHealth.resize(finalBoss.getHealth(),10);
    playerHealth.resize(p.getHealth(),10);

    glColor3f(1, 1, 1);
    glRasterPos2i(350, 10);
    for (const char &letter : PlayerHealth) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(0, 10);
    for (const char &letter : EnemyHealth) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    if(finalBoss.getHealth() <= 0){
        currentScreen = bossroom;
        displayExpBossRoom = true;
    }

    glFlush();
}

void displayBattleTop3One(){
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    spawn.draw();
    top3EnemyOneFight.draw();
    window1.draw();
    window2.draw();
    selector.draw();
    button1.draw();
    button2.draw();
    button3.draw();
    seperator.draw();
    playerHealth.draw();
    enemyHealth.draw();

    // inventory
    // draw inventory and message
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
    for(Quad &item : inventory){
        item.draw();
    }


    glColor3f(1, 1, 1);
    glRasterPos2i(400, 350);
    for (const char &letter : attack) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(400, 380);
    for (const char &letter : item) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(400, 410);
    for (const char &letter : run) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);

    }
    if(!playerIsAttacking) {

        glColor3f(1, 1, 1);
        glRasterPos2i(30, 350);
        for (const char &letter : battleMessage) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        glColor3f(1, 1, 1);
        glRasterPos2i(30, 370);
        for (const char &letter : battleMessage2) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }else{
        glColor3f(1, 1, 1);
        glRasterPos2i(30, 350);
        for (const char &letter : battleMessage3) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    PlayerHealth = "Player Health: " + to_string(p.getHealth());
    EnemyHealth = "Enemy Health: " + to_string(top3EnemyOne.getHealth());

    enemyHealth.resize(top3EnemyOne.getHealth(),10);
    playerHealth.resize(p.getHealth(),10);

    glColor3f(1, 1, 1);
    glRasterPos2i(350, 10);
    for (const char &letter : PlayerHealth) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(0, 10);
    for (const char &letter : EnemyHealth) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    if(top3EnemyOne.getHealth() <= 0){
        currentScreen = top3left;
        displayExpTop3EnemyOne = true;
    }

    glFlush();
}

void displayBattleTop3Two(){
    glViewport(0, 0, width, height);

    // do an orthographic parallel projection with the coordinate
    // system set to first quadrant, limited by screen/window size
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, width, height, 0.0, -1.f, 1.f);

    glClear(GL_COLOR_BUFFER_BIT);   // Clear the color buffer with current clearing color

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);

    spawn.draw();
    top3EnemyTwoFight.draw();
    window1.draw();
    window2.draw();
    selector.draw();
    button1.draw();
    button2.draw();
    button3.draw();
    seperator.draw();
    playerHealth.draw();
    enemyHealth.draw();

    // inventory
    // draw inventory and message
    glColor3f(1, 1, 1);
    glRasterPos2i(28, 470);
    for (const char &letter : inv) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }
    for(Quad &item : inventory){
        item.draw();
    }


    glColor3f(1, 1, 1);
    glRasterPos2i(400, 350);
    for (const char &letter : attack) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(400, 380);
    for (const char &letter : item) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(400, 410);
    for (const char &letter : run) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);

    }
    if(!playerIsAttacking) {

        glColor3f(1, 1, 1);
        glRasterPos2i(30, 350);
        for (const char &letter : battleMessage) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }

        glColor3f(1, 1, 1);
        glRasterPos2i(30, 370);
        for (const char &letter : battleMessage2) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }else{
        glColor3f(1, 1, 1);
        glRasterPos2i(30, 350);
        for (const char &letter : battleMessage3) {
            glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
        }
    }

    PlayerHealth = "Player Health: " + to_string(p.getHealth());
    EnemyHealth = "Enemy Health: " + to_string(top3EnemyTwo.getHealth());

    enemyHealth.resize(top3EnemyTwo.getHealth(),10);
    playerHealth.resize(p.getHealth(),10);

    glColor3f(1, 1, 1);
    glRasterPos2i(350, 10);
    for (const char &letter : PlayerHealth) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    glColor3f(1, 1, 1);
    glRasterPos2i(0, 10);
    for (const char &letter : EnemyHealth) {
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, letter);
    }

    if(top3EnemyTwo.getHealth() <= 0){
        currentScreen = top3left;
        displayExpTop3EnemyTwo = true;
    }

    glFlush();
}

void kbd(unsigned char key, int x, int y) {
    // escape
    if (key == 27) {
        glutDestroyWindow(wd);
        exit(0);
    }

    // logic for picking up items
    if(key == 'e'){
        if(rightRoomObject.isOverlapping(spawn) && currentScreen == rightSide){
            rightRoomObject.setColor(0,0,0);
            rightRoomObject.resize(1,1);
            // add small version of item to inventory
            inventory.push_back(Quad({0,.5,.5}, {110, 485}, 10, 10));
            ++numObjects;
        }
        else if(leftRoomObject.isOverlapping(spawn) && currentScreen == leftSide){
            leftRoomObject.setColor(0,0,0);
            leftRoomObject.resize(1,1);
            // add small version of item to inventory
            inventory.push_back(Quad({0,1,0}, {120, 466}, 10, 10));
            ++numObjects;
        }
        else if(bottomRoomObject.isOverlapping(spawn) && currentScreen == bottom){
            bottomRoomObject.setColor(0,0,0);
            bottomRoomObject.resize(1,1);
            // add small version of item to inventory
            inventory.push_back(Quad({1,0,1}, {140, 466}, 10, 10));
            ++numObjects;

        }
        else if(topRoomObject.isOverlapping(spawn) && currentScreen == top){
            topRoomObject.setColor(0,0,0);
            topRoomObject.resize(1,1);
            // add small version of item to inventory
            inventory.push_back(Quad({1,1,0}, {160, 466}, 10, 10));
            ++numObjects;
        }
        else if(top2rightObject.isOverlapping(spawn) && currentScreen == top2right){
            top2rightObject.setColor(0,0,0);
            top2rightObject.resize(1,1);
            // add small version of item to inventory
            inventory.push_back(Quad({1,1,1}, {180, 466}, 10, 10));
            ++numObjects;
        }
        else if(top3rightObject.isOverlapping(spawn) && currentScreen == top3right){
            top3rightObject.setColor(0,0,0);
            top3rightObject.resize(1,1);
            // add small version of item to inventory
            inventory.push_back(Quad({0.5,0,1}, {200, 466}, 10, 10));
            ++numObjects;
        }
    }

    if(key == 'b'){
        if(rightEnemy.isOverlapping(spawn) && currentScreen == rightSide){
            currentScreen = battleRight;
            spawn.move(100,0);
        }
        else if (topRoomEnemyQuad.isOverlapping(spawn) && currentScreen == top){
            currentScreen = battleTop;
            spawn.move(100,0);
        }
        else if(finalBossQuad.isOverlapping(spawn) && currentScreen == bossroom){
            currentScreen = battleFinalBoss;
            spawn.move(100, 20);
        }
        else if(top3EnemyOneQuad.isOverlapping(spawn) && currentScreen == top3left){
            currentScreen = battletop3enemyone;
            spawn.move(100, -20);
        }
        else if(top3EnemyTwoQuad.isOverlapping(spawn) && currentScreen == top3left){
            currentScreen = battletop3enemytwo;
            spawn.move(100, -20);
        }
    }


    if(key == 's' && (currentScreen == welcome)){
        currentScreen = middle;
    }

    if(key == 'i'){
        const string python = "python";
        string command = python + " ../display.py " + std::to_string(p.getAttackPower()) + " " + std::to_string(p.getDefensePower()) + " " + std::to_string(p.getExperience()) + " " + std::to_string(p.getHealth());
        system(command.c_str());
    }

    glutPostRedisplay();
}

void kbdS(int key, int x, int y) {
    switch(key) {
        case GLUT_KEY_DOWN:
            spawn.move(0, 20);
            break;
        case GLUT_KEY_LEFT:
            spawn.move(-20,0);
            break;
        case GLUT_KEY_RIGHT:
            spawn.move(20, 0);
            break;
        case GLUT_KEY_UP:
            spawn.move(0, -20);
            break;
    }
    
    glutPostRedisplay();
}

void cursor(int x, int y) {
    if(button1.isOverlapping(x,y))
    {
        button1.hover();
    }else{
        button1.release();
    }

    if(button2.isOverlapping(x,y))
    {
        button2.hover();
    }else{
        button2.release();
    }

    if(button3.isOverlapping(x,y))
    {
        button3.hover();
    }else{
        button3.release();
    }
    glutPostRedisplay();
}


void mouse(int button, int state, int x, int y) {

        // for right room enemy battle
        if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && button1.isOverlapping(x,y) && currentScreen == battleRight &&
           !playerIsAttacking) {
            p.attack(enemyRightRoom);
            playerIsAttacking = true;
        }
        // for top room enemy battle
        else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && button1.isOverlapping(x,y) && currentScreen == battleTop &&
                           !playerIsAttacking) {
                p.attack(enemyTopRoom);
                playerIsAttacking = true;
            }
        else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && button1.isOverlapping(x,y) && currentScreen == battleFinalBoss &&
                !playerIsAttacking) {
            p.attack(finalBoss);
            playerIsAttacking = true;
        }
        else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && button1.isOverlapping(x,y) && currentScreen == battletop3enemyone &&
                !playerIsAttacking) {
            p.attack(top3EnemyOne);
            playerIsAttacking = true;
        }
        else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && button1.isOverlapping(x,y) && currentScreen == battletop3enemytwo &&
                !playerIsAttacking) {
            p.attack(top3EnemyTwo);
            playerIsAttacking = true;
        }
        // potions usage
        else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && button2.isOverlapping(x,y)) {
            if(inventory.size() > 0){
                p.setHealth(p.getHealth() + 25);
                inventory.pop_back();
            }
        }
        // run
        else if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && button3.isOverlapping(x,y)) {
            currentScreen = middle;
            spawn.move(-170, 0);
        }

    glutPostRedisplay();
}


void timer(int dummy) {

    // logic to allow enemies to patrol
    if(dummy < 100){
        rightEnemy.move(0, 1);
        topRoomEnemyQuad.move(0, 1);
        finalBossQuad.move(1, 0);
        top3EnemyOneQuad.move(1,1);
        top3EnemyTwoQuad.move(0,2);
    }
    else if(dummy > 100 && dummy < 200){
        rightEnemy.move(0, -1);
        topRoomEnemyQuad.move(0, -1);
        finalBossQuad.move(-1, 0);
        top3EnemyOneQuad.move(-1,-1);
        top3EnemyTwoQuad.move(0,-2);
    }
    else if (dummy > 200){
        dummy = 0;
    }
    dummy++;

    // logic to allow for pause between enemy attacking and greyed out attack
    if(playerIsAttacking){
        counter++;
        button1.setColor(128.0/255,128.0/255,128.0/255);
        rightEnemyFight.setColor({0,.25,.25});
        topRoomEnemyFight.setColor({0,.5,0});
        finalBossFight.setColor({0,.5,.5});
        top3EnemyOneFight.setColor({.25,0,0});
        top3EnemyTwoFight.setColor({.5,.5,0});
        if (counter > 50){
            button1.setColor(1,0,0);
            rightEnemyFight.setColor({0,.5,.5});
            topRoomEnemyFight.setColor({0,1,0});
            finalBossFight.setColor({0,1,1});
            top3EnemyOneFight.setColor({.5,0,0});
            top3EnemyTwoFight.setColor({1,1,0});
            enemyRightRoom.attack(p);
            playerIsAttacking = false;
            counter = 0;
        }
    }

    // logic for displaying experience from right room enemy experience
    if(displayExpRightRoom){
        expCounter++;
        if(expCounter > 100){
            displayExpRightRoom = false;
            expCounter = 0;
        }
    }
    else if(displayExpTopRoom){
            expCounter++;
            if(expCounter > 100){
                displayExpTopRoom = false;
                expCounter = 0;
            }
        }
    else if(displayExpBossRoom){
        expCounter++;
        if(expCounter > 100){
            displayExpBossRoom = false;
            expCounter = 0;
        }
    }
    else if(displayExpTop3EnemyOne){
        expCounter++;
        if(expCounter > 100){
            displayExpTop3EnemyOne = false;
            expCounter = 0;
        }
    }
    else if(displayExpTop3EnemyTwo){
        expCounter++;
        if(expCounter > 100){
            displayExpTop3EnemyTwo = false;
            expCounter = 0;
        }
    }


    // logic for going between rooms
    if (currentScreen == middle && spawn.Quad::isOverlapping(door2)) {
        currentScreen = rightSide;
        spawn.move(-450, 0);
    }
    else if (currentScreen == leftSide && spawn.Quad::isOverlapping(door2)){
        currentScreen = middle;
        spawn.move(-450, 0);
    }
    else if (currentScreen == middle && spawn.Quad::isOverlapping(door1)){
        currentScreen = leftSide;
        spawn.move(450, 0);
    }
    else if(currentScreen == rightSide && spawn.Quad::isOverlapping(door1)){
        currentScreen = middle;
        spawn.move(450, 0);
    }
    else if (currentScreen == middle && door3.isOverlapping(spawn)){
        currentScreen = top;
        spawn.move(0, 350);
    }
    else if (currentScreen == top && door4.isOverlapping(spawn)){
        currentScreen = middle;
        spawn.move(0, -350);
    }
    else if (currentScreen == middle && door4.isOverlapping(spawn)){
        currentScreen = bottom;
        spawn.move(0, -350);
    }
    else if (currentScreen == bottom && door3.isOverlapping(spawn)){
        currentScreen = middle;
        spawn.move(0, 350);
    }
    else if (currentScreen == top && door5.isOverlapping(spawn)){
        currentScreen = top2;
        spawn.move(0, 350);
    }
    else if (currentScreen == top2 && door6.isOverlapping(spawn)){
        currentScreen = top;
        spawn.move(0, -350);
    }
    else if (currentScreen == top2 && spawn.Quad::isOverlapping(door9)){
        currentScreen = top2right;
        spawn.move(-450, 0);
    }
    else if (currentScreen == top2right && spawn.Quad::isOverlapping(door10)){
        currentScreen = top2;
        spawn.move(450, 0);
    }
    else if (currentScreen == top2 && spawn.Quad::isOverlapping(door8)){
        currentScreen = top2left;
        spawn.move(450, 0);
    }
    else if (currentScreen == top2left && spawn.Quad::isOverlapping(door11)){
        currentScreen = top2;
        spawn.move(-450, 0);
    }
    else if (currentScreen == top2left && door12.isOverlapping(spawn)){
        currentScreen = top3left;
        spawn.move(0, 350);
    }
    else if (currentScreen == top3left && door13.isOverlapping(spawn)){
        currentScreen = top2left;
        spawn.move(0, -350);
    }
    else if (currentScreen == top3left && spawn.Quad::isOverlapping(door14)){
        currentScreen = top3;
        spawn.move(-450, 0);
    }
    else if (currentScreen == top3 && spawn.Quad::isOverlapping(door15)){
        currentScreen = top3left;
        spawn.move(450, 0);
    }
    else if (currentScreen == top3 && spawn.Quad::isOverlapping(door17)){
        currentScreen = top3right;
        spawn.move(-450, 0);
    }
    else if (currentScreen == top3right && spawn.Quad::isOverlapping(door18)){
        currentScreen = top3;
        spawn.move(450, 0);
    }
    else if (currentScreen == top3right && spawn.Quad::isOverlapping(door19)){
        currentScreen = top3rightright;
        spawn.move(-450, 0);
    }
    else if (currentScreen == top3rightright && spawn.Quad::isOverlapping(door20)){
        currentScreen = top3right;
        spawn.move(450, 0);
    }

    else if (currentScreen == top3rightright && door21.isOverlapping(spawn)){
        currentScreen = bossroom;
        spawn.move(0, 350);
    }
    else if (currentScreen == bossroom && door22.Quad::isOverlapping(spawn)){
        currentScreen = top3rightright;
        spawn.move(0, -350);
    }
    else if (currentScreen == bossroom && spawn.Quad::isOverlapping(door23) && finalBoss.getHealth() <= 0){
        currentScreen = final;
        spawn.move(-450, 0);
    }
    else if (currentScreen == final && spawn.Quad::isOverlapping(door24)){
        currentScreen = bossroom;
        spawn.move(450, 0);
    }
    else if (currentScreen == final && exitDoor.Quad::isOverlapping(spawn)){
        currentScreen = winScreen;
    }
    else if(p.getHealth() == 0){
        currentScreen = endScreen;
    }





    // display appropriate screen
    if (currentScreen == middle) {
        glutDisplayFunc(displayMiddle);
    }
    else if(currentScreen == rightSide){
        glutDisplayFunc(displayRight);
    }
    else if(currentScreen == leftSide){
        glutDisplayFunc(displayLeft);
    }
    else if(currentScreen == top){
        glutDisplayFunc(displayTop);
    }
    else if(currentScreen == bottom){
        glutDisplayFunc(displayBottom);
    }
    else if(currentScreen == battleRight){
        glutDisplayFunc(displayBattleRight);
    }
    else if(currentScreen == battleTop){
        glutDisplayFunc(displayBattleTop);
    }
    else if(currentScreen == top2){
        glutDisplayFunc(displayTop2);
    }
    else if(currentScreen == top2right){
        glutDisplayFunc(displayTop2Right);
    }
    else if(currentScreen == top2left){
        glutDisplayFunc(displayTop2Left);
    }
    else if(currentScreen == top3left){
        glutDisplayFunc(displayTop3Left);
    }
    else if(currentScreen == top3){
        glutDisplayFunc(displayTop3);
    }
    else if(currentScreen == top3right){
        glutDisplayFunc(displayTop3Right);
    }
    else if(currentScreen == top3rightright){
        glutDisplayFunc(displayTop3RightRight);
    }
    else if(currentScreen == bossroom){
        glutDisplayFunc(displayBossRoom);
    }
    else if(currentScreen == final){
        glutDisplayFunc(displayfinal);
    }
    else if(currentScreen == endScreen){
        glutDisplayFunc(displayEnd);
    }

    else if(currentScreen == battleFinalBoss){
        glutDisplayFunc(displayBattleFinal);
    }

    else if(currentScreen == battletop3enemyone){
        glutDisplayFunc(displayBattleTop3One);
    }
    else if(currentScreen == battletop3enemytwo){
        glutDisplayFunc(displayBattleTop3Two);
    }
    else if(currentScreen == winScreen){
        glutDisplayFunc(displayWin);
    }
    else if(currentScreen == welcome){
        glutDisplayFunc(displayWelcome);
    }




    glutPostRedisplay();
    glutTimerFunc(30, timer, dummy);

}


int main(int argc, char** argv) {

        // get name from user, validate input
        cout << "Please enter your character name: ";
        while((!(cin >> userName)) || userName.length() > 8){
        cout << "Invalid input. Please enter a name that is <= 8 characters. \n";
        cin.clear();
        string junk;
        getline(cin, junk);
        }

        spawn.setLabel(userName);

        init();

        glutInit(&argc, argv);          // Initialize GLUT

        glutInitDisplayMode(GLUT_RGBA);

        glutInitWindowSize((int)width, (int)height);
        glutInitWindowPosition(100, 200); // Position the window's initial top-left corner

        wd = glutCreateWindow("CubeQuest - By Josh Zuver and Donovan Lafontaine" /* title */ );
        glutDisplayFunc(displayMiddle);

        // Our own OpenGL initialization
        initGL();

        // register keyboard press event processing function
        // works for numbers, letters, spacebar, etc.
        glutKeyboardFunc(kbd);

        // register special event: function keys, arrows, etc.
        glutSpecialFunc(kbdS);

        // handles mouse movement
        glutPassiveMotionFunc(cursor);

        // handles mouse click
        glutMouseFunc(mouse);

        // handles timer
        glutTimerFunc(0, timer, 0);



        // Enter the event-processing loop
        glutMainLoop();

    return 0;
}
