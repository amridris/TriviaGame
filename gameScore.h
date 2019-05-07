//
// Created by aamer on 5/3/19.
//

#ifndef TESTING_GAMESCORE_H
#define TESTING_GAMESCORE_H


class gameScore {
private:
    float wins, loss;

    float winPercentage;


public:
    gameScore(){
        wins = loss = 0;
        winPercentage = 0.0;
    }

    void correct_increment(){
        wins++;
    }

    void loss_increment(){
        loss++;
    }

    void resetScore(){
        wins = loss = 0;
        winPercentage = 0.0;
    }


    int getWins(){
        return wins;
    }

    int getLosses(){
        return loss;
    }

    float getWinsPercentage(int current_round){

        winPercentage = wins/current_round;

        return winPercentage;
    }
};


#endif //TESTING_GAMESCORE_H
