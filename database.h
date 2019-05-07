//
// Created by aamer on 5/3/19.
//

#ifndef TESTING_DATABASE_H
#define TESTING_DATABASE_H

#include "questionChoiceBank.h"
#include <vector>
#include "json.hpp"
#include <fstream>


class database {
private:
    std::vector<questionChoiceBank> questionsAndChoices;

public:
    database(){
        questionsAndChoices = {};
    }

   void readQuestionsFromJson() {
       nlohmann::json value;
       questionChoiceBank questions;
       try{
           std::ifstream ifs("questions.json");
           value = nlohmann::json::parse(ifs);
       }catch(std::exception &e){
           std::cout<<e.what()<<std::endl;
       }

       for (auto &x: value) {
           questions.question = x["question"].get<std::string>();
           questions.choice_a = x["A"].get<std::string>();
           questions.choice_b = x["B"].get<std::string>();
           questions.choice_c = x["C"].get<std::string>();
           questions.choice_d = x["D"].get<std::string>();
           questions.correct_choice = x["answer"].get<std::string>();
           questionsAndChoices.push_back(questions);
       }
   }

   void print(){
        for(auto &x: questionsAndChoices){
            std::cout<<x.question<<std::endl;
            std::cout<<x.choice_a<<std::endl;
            std::cout<<x.choice_b<<std::endl;
            std::cout<<x.choice_c<<std::endl;
            std::cout<<x.choice_d<<std::endl;
            std::cout<<x.correct_choice<<std::endl;

        }
    }

    void printQuestionNum(int index){
        std::cout<<getQuestionAt(index).question<<std::endl<<std::endl;
        std::cout<<getChoiceA_at(index)<<std::endl;
        std::cout<<getChoiceB_at(index)<<std::endl;
        std::cout<<getChoiceC_at(index)<<std::endl;
        std::cout<<getChoiceD_at(index)<<std::endl;
    }


    questionChoiceBank getQuestionAt(long unsigned int index){
        if(index >= 0 && index < questionsAndChoices.size()) {
            return questionsAndChoices.at(index);
        }
        else{
            questionChoiceBank null;
            return null;
        }
    }

    std::string getChoiceA_at(long unsigned int index){
        if(index >= 0 && index < questionsAndChoices.size()) {
            return questionsAndChoices.at(index).choice_a;
        }
        else{
            return "Out of range error";
        }
    }

    std::string getChoiceB_at(long unsigned int index){
        if(index >= 0 && index < questionsAndChoices.size()) {
            return questionsAndChoices.at(index).choice_b;
        }
        else{
            return "Out of range error";
        }
    }

    std::string getChoiceC_at(long unsigned int index){
        if(index >= 0 && index < questionsAndChoices.size()) {
            return questionsAndChoices.at(index).choice_c;
        }
        else{
            return "Out of range error";
        }
    }

    std::string getChoiceD_at(long unsigned int index){
        if(index >= 0 && index < questionsAndChoices.size()) {
            return questionsAndChoices.at(index).choice_d;
        }
        else{
            return "Out of range error";
        }
    }

    std::string getCorrectAns(long unsigned int index){
        if(index >= 0 && index < questionsAndChoices.size()) {
            return questionsAndChoices.at(index).correct_choice;
        }
        else{
            return "Out of range error";
        }
    }

    int size(){
       return questionsAndChoices.size();
    }


};


#endif //TESTING_DATABASE_H
