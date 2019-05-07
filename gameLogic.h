//
// Created by aamer on 5/3/19.
//

#ifndef TESTING_GAMELOGIC_H
#define TESTING_GAMELOGIC_H


class gameLogic {
    bool correct;

public:
    gameLogic(){
        correct = false;
    }

    bool check_user_choice(int index, const std::string value){
        int correct_index = returnCorrectIndex(value);

        if(index == correct_index){
            return true;
        } else{
            return false;
        }
    }

    int returnCorrectIndex(std::string value){
        int correct_index = 0;

        if(value == "A"){
            correct_index = 1;
        }
        else if(value == "B"){
            correct_index = 2;
        }
        else if(value == "C"){
            correct_index = 3;
        }
        else{
            correct_index = 4;
        }

        return correct_index;
    }

    void reset(){
        correct = false;
    }

};


#endif //TESTING_GAMELOGIC_H
