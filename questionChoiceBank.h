//
// Created by aamer on 5/3/19.
//

#ifndef TESTING_QUESTIONCHOICEBANK_H
#define TESTING_QUESTIONCHOICEBANK_H


#include <string>

class questionChoiceBank {

public:
    std::string question;
    std::string choice_a;
    std::string choice_b;
    std::string choice_c;
    std::string choice_d;
    std::string correct_choice;

    questionChoiceBank(){
        question = choice_a = choice_b = choice_c = choice_d = " ";
    }

    void reset(){
        question = choice_a = choice_b = choice_c = choice_d = " ";
    }
};


#endif //TESTING_QUESTIONCHOICEBANK_H
