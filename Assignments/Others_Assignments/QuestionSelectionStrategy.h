#ifndef QUESTION_SELECTION_STRATEGY_H
#define QUESTION_SELECTION_STRATEGY_H

#include "Question.h"
#include <vector>
#include <algorithm>
#include <random>

using namespace std;

class QuestionSelectionStrategy {
public:
    virtual Question getNextQuestion() = 0;
    
    virtual ~QuestionSelectionStrategy() {}
};

class SequentialSelectionStrategy : public QuestionSelectionStrategy {
private:
    const vector<Question>& questions;
    size_t currentIndex;

public:
    SequentialSelectionStrategy(const vector<Question>& qs)
        : questions(qs), currentIndex(0) {}

    Question getNextQuestion() override {
        if (currentIndex >= questions.size()) {
            return Question("", {"", "", "", ""}, 'A', 1);
        }
        return questions[currentIndex++];
    }
};

class RandomSelectionStrategy : public QuestionSelectionStrategy {
private:
    vector<Question> shuffledQuestions;
    size_t currentIndex;

public:
    RandomSelectionStrategy(const vector<Question>& qs)
        : shuffledQuestions(qs), currentIndex(0) {
        random_device rd;
        mt19937 g(rd());
        shuffle(shuffledQuestions.begin(), shuffledQuestions.end(), g);
    }

    Question getNextQuestion() override {
        if (currentIndex >= shuffledQuestions.size()) {
            return Question("", {"", "", "", ""}, 'A', 1);
        }
        return shuffledQuestions[currentIndex++];
    }
};

class DifficultyBasedSelectionStrategy : public QuestionSelectionStrategy {
private:
    vector<Question> filteredQuestions;
    size_t currentIndex;

public:
    DifficultyBasedSelectionStrategy(const vector<Question>& qs, int difficultyLevel)
        : currentIndex(0) {
        for (const auto& q : qs) {
            if (q.getDifficulty() == difficultyLevel) {
                filteredQuestions.push_back(q);
            }
        }
    }

    Question getNextQuestion() override {
        if (currentIndex >= filteredQuestions.size()) {
            return Question("", {"", "", "", ""}, 'A', 1);
        }
        return filteredQuestions[currentIndex++];
    }
    
    size_t getFilteredQuestionCount() const {
        return filteredQuestions.size();
    }
};

#endif // QUESTION_SELECTION_STRATEGY_H