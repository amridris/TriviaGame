//
// Created by aamer on 5/3/19.
//

#include "triviaGameEngine.h"


triviaGameEngine *triviaGameEngine::m_instance = 0;

triviaGameEngine::triviaGameEngine() {
    questions.readQuestionsFromJson();

}

triviaGameEngine::triviaGameEngine(triviaGameEngine const &) {}

triviaGameEngine& triviaGameEngine::operator=(triviaGameEngine const &) {}

triviaGameEngine* triviaGameEngine::instance() {
    if(m_instance == nullptr){
        m_instance = new triviaGameEngine();
    }
    else{
        cout<<"This instance already exists"<<endl;
    }
    return m_instance;
}

void triviaGameEngine::print() {
    questions.print();
}

std::string triviaGameEngine::getPlayerName() {
    return user.getName();
}

void triviaGameEngine::setPlayerName(std::string name) {
    user.setName(name);
}


void triviaGameEngine::setNumberOfQuestion(int rounds) {
    rounds = rounds;
}

bool triviaGameEngine::checkValue(int index, int currentQuestion) {
    auto current_question = questions.getCorrectAns(currentQuestion);
    return decision.check_user_choice(index, current_question);
}

void triviaGameEngine::printQuestionAt(int index) {
    questions.printQuestionNum(index);
}


std::string triviaGameEngine::getChoiceA(int index){
    return questions.getChoiceA_at(index);
}

std::string triviaGameEngine::getChoiceB(int index){
    return questions.getChoiceB_at(index);
}

std::string triviaGameEngine::getChoiceC(int index){
    return questions.getChoiceC_at(index);
}

std::string triviaGameEngine::getChoiceD(int index){
    return questions.getChoiceD_at(index);
}

std::string triviaGameEngine::getQuestionat(int index){
    return questions.getQuestionAt(index).question;
}

int triviaGameEngine::databaseSize(){
    return questions.size();
}


int triviaGameEngine::randomQuestionGenerator(){
    srand(time(nullptr));
    randomQuestion = rand() % databaseSize();
    return randomQuestion;
}

std::string triviaGameEngine::getCorrectAns(int index){
    return questions.getCorrectAns(index);
}

void incrementScore();
    void incrementLoss();
    void winPercentageValue();

void triviaGameEngine::incrementScore(){
    scoring.correct_increment();
}

void triviaGameEngine::incrementLoss(){
    scoring.loss_increment();
}

float triviaGameEngine::winPercentageValue(int currentRound){
    return scoring.getWinsPercentage(currentRound);
}

int triviaGameEngine::getCorrectAns(){
    return scoring.getWins();
}

void triviaGameEngine::reset(){
    scoring.resetScore();
    decision.reset();
    user.reset();
}
