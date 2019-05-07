//
// Created by aamer on 5/3/19.
//

#ifndef TESTING_PLAYER_H
#define TESTING_PLAYER_H

#include <string>

class player {
private:
    std::string playerName;
    int age;

public:
    void setName(std::string name){
        playerName = name;
    }

    void setAge(int user_age){
        age = user_age;
    }

    std::string getName(){
        return playerName;
    }

    int getAge(){
        return age;
    }

    void reset(){
        playerName = " ";
        age = 0;
    }

};


#endif //TESTING_PLAYER_H
