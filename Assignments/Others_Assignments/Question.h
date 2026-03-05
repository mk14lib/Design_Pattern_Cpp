#ifndef QUESTION_H
#define QUESTION_H

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Question {
private:
    string questionText;
    vector<string> options;
    char correctAnswer;
    int difficulty;

public:
    Question(const string& text, const vector<string>& opts,
             char correct, int diff)
        : questionText(text), options(opts), correctAnswer(correct), difficulty(diff) {}

    string getQuestionText() const { return questionText; }
    vector<string> getOptions() const { return options; }
    char getCorrectAnswer() const { return correctAnswer; }
    int getDifficulty() const { return difficulty; }

    void display() const {
        cout << "\n" << questionText << endl;
        cout << "Difficulty: " << difficulty << endl;
        for (size_t i = 0; i < options.size(); ++i) {
            cout << static_cast<char>('A' + i) << ". " << options[i] << endl;
        }
    }
};

#endif // QUESTION_H