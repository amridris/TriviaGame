//
// Created by aamer on 5/3/19.
//

#ifndef TESTING_TRIVIAGAMEENGINE_H
#define TESTING_TRIVIAGAMEENGINE_H


#include <iostream>
#include "database.h"
#include "gameLogic.h"
#include "gameScore.h"
#include "player.h"
#include <random>

using namespace std;

class triviaGameEngine {
private:
    static triviaGameEngine *m_instance;
    string username;
    triviaGameEngine();
    triviaGameEngine(triviaGameEngine const&);
    triviaGameEngine &operator=(triviaGameEngine const&);
    database questions;
    gameLogic decision;
    gameScore scoring;
    player user;
    int round;
    int randomQuestion;


public:
    void print();
    static triviaGameEngine *instance();
    std::string getPlayerName();
    void setPlayerName(std::string name);
    void setNumberOfQuestion(int rounds);
    bool checkValue(int index, int currentQuestion);
    // for debugging
    void printQuestionAt(int index);
    std::string getChoiceA(int index);
    std::string getChoiceB(int index);
    std::string getChoiceC(int index);
    std::string getChoiceD(int index);
    std::string getQuestionat(int index);
    std::string getCorrectAns(int index);
    int databaseSize();
    int randomQuestionGenerator();
    void incrementScore();
    void incrementLoss();
    float winPercentageValue(int currentRound);
    int getCorrectAns();
    void reset();



};


#endif //TESTING_TRIVIAGAMEENGINE_H
