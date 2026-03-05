#ifndef GAME_MANAGER_H
#define GAME_MANAGER_H

#include "Question.h"
#include "QuestionSelectionStrategy.h"
#include <vector>

using namespace std;

class GameManager {
private:
    static GameManager* instance;
    
    GameManager() : score(0), totalQuestions(0), strategy(nullptr) {}
    
    GameManager(const GameManager&) = delete;
    GameManager& operator=(const GameManager&) = delete;
    
    int score;
    int totalQuestions;
    QuestionSelectionStrategy* strategy;
    vector<Question> questions;

public:
    static GameManager& getInstance() {
        if (instance == nullptr) {
            instance = new GameManager();
        }
        return *instance;
    }
    
    void addScore(int points) {
        score += points;
    }
    
    int getScore() const {
        return score;
    }
    
    void resetGame() {
        score = 0;
    }
    
    void setStrategy(QuestionSelectionStrategy* strat) {
        strategy = strat;
    }
    
    void setQuestions(const vector<Question>& qs) {
        questions = qs;
        totalQuestions = qs.size();
    }
    
    Question getNextQuestion() {
        if (strategy != nullptr) {
            return strategy->getNextQuestion();
        }
        return Question("", {"", "", "", ""}, 'A', 1);
    }
    
    int getTotalQuestions() const {
        return totalQuestions;
    }
    
    ~GameManager() {
    }
};

GameManager* GameManager::instance = nullptr;

#endif // GAME_MANAGER_H