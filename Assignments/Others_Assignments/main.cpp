#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
#include <limits>
#include "Question.h"
#include "QuestionSelectionStrategy.h"
#include "GameManager.h"

using namespace std;

vector<Question> initializeQuestions() {
    vector<Question> questions;
   
    questions.push_back(Question(
        "What is the capital of France?",
        {"London", "Berlin", "Paris", "Madrid"},
        'C', 1
    ));
    
    questions.push_back(Question(
        "Which planet is known as the Red Planet?",
        {"Venus", "Mars", "Jupiter", "Saturn"},
        'B', 1
    ));
    
    questions.push_back(Question(
        "What is the largest ocean on Earth?",
        {"Atlantic Ocean", "Indian Ocean", "Arctic Ocean", "Pacific Ocean"},
        'D', 2
    ));
    
    questions.push_back(Question(
        "Who wrote 'Romeo and Juliet'?",
        {"Charles Dickens", "William Shakespeare", "Jane Austen", "Mark Twain"},
        'B', 2
    ));
    
    questions.push_back(Question(
        "What is the chemical symbol for Gold?",
        {"Go", "Gd", "Au", "Ag"},
        'C', 3
    ));
    
    questions.push_back(Question(
        "In which year did World War II end?",
        {"1943", "1944", "1945", "1946"},
        'C', 3
    ));
    
    return questions;
}

void displayWelcome() {
    cout << "========================================\n";
    cout << "       WELCOME TO THE QUIZ GAME!       \n";
    cout << "========================================\n\n";
    cout << "Instructions:\n";
    cout << "- Answer each question by entering A, B, C, or D\n";
    cout << "- Each correct answer earns you 10 points\n";
    cout << "- Try to get the highest score possible!\n\n";
}

char getValidAnswer() {
    char answer;
    while (true) {
        cout << "\nYour answer (A/B/C/D): ";
        cin >> answer;
        answer = toupper(answer);
        
        if (cin.fail() || (answer != 'A' && answer != 'B' &&
            answer != 'C' && answer != 'D')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter A, B, C, or D.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return answer;
        }
    }
}

int getStrategyChoice() {
    int choice;
    while (true) {
        cout << "\nSelect Question Selection Mode:\n";
        cout << "1. Sequential (questions in order)\n";
        cout << "2. Random (questions shuffled)\n";
        cout << "3. Difficulty-based (select specific difficulty)\n";
        cout << "Enter your choice (1-3): ";
        cin >> choice;
        
        if (cin.fail() || (choice < 1 || choice > 3)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter 1, 2, or 3.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

int getDifficultyLevel() {
    int difficulty;
    while (true) {
        cout << "\nSelect Difficulty Level:\n";
        cout << "1. Easy\n";
        cout << "2. Medium\n";
        cout << "3. Hard\n";
        cout << "Enter your choice (1-3): ";
        cin >> difficulty;
        
        if (cin.fail() || (difficulty < 1 || difficulty > 3)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter 1, 2, or 3.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return difficulty;
        }
    }
}

bool askToPlayAgain() {
    char choice;
    while (true) {
        cout << "\nWould you like to play again? (Y/N): ";
        cin >> choice;
        choice = toupper(choice);
        
        if (cin.fail() || (choice != 'Y' && choice != 'N')) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input! Please enter Y or N.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice == 'Y';
        }
    }
}

void playGame() {
    GameManager& gameManager = GameManager::getInstance();
    
	vector<Question> questions = initializeQuestions();
    gameManager.setQuestions(questions);
    
    int strategyChoice = getStrategyChoice();
    
    QuestionSelectionStrategy* strategy = nullptr;
    int totalQuestionsToAsk = gameManager.getTotalQuestions();
    
    switch (strategyChoice) {
        case 1:
            strategy = new SequentialSelectionStrategy(questions);
            cout << "\nSequential mode selected!\n";
            break;
        case 2:
            strategy = new RandomSelectionStrategy(questions);
            cout << "\nRandom mode selected!\n";
            break;
        case 3: {
            int difficultyLevel = getDifficultyLevel();
            strategy = new DifficultyBasedSelectionStrategy(questions, difficultyLevel);
            DifficultyBasedSelectionStrategy* diffStrategy = static_cast<DifficultyBasedSelectionStrategy*>(strategy);
            totalQuestionsToAsk = diffStrategy->getFilteredQuestionCount();
            cout << "\nDifficulty-based mode selected (Level " << difficultyLevel << ")!\n";
            break;
        }
    }
    gameManager.setStrategy(strategy);
    
    gameManager.resetGame();
    
    if (totalQuestionsToAsk == 0) {
        cout << "\nNo questions available for the selected difficulty level!\n";
        delete strategy;
        return;
    }
    
    cout << "\nStarting quiz with " << totalQuestionsToAsk
              << " questions...\n";
    cout << "Press Enter to start...";
    cin.get();
    
    for (int i = 0; i < totalQuestionsToAsk; ++i) {
        cout << "\n----------------------------------------\n";
        cout << "Question " << (i + 1) << " of " << gameManager.getTotalQuestions();
        cout << "\n----------------------------------------";
        
        Question currentQuestion = gameManager.getNextQuestion();
        currentQuestion.display();
        
        char userAnswer = getValidAnswer();
        vector<string> options = currentQuestion.getOptions();
  
        if (userAnswer == currentQuestion.getCorrectAnswer()) {
            cout << "\nCorrect! +10 points\n";
            gameManager.addScore(10);
        } else {
            cout << "\nIncorrect! The correct answer was "
                      << currentQuestion.getCorrectAnswer() << ". "
					  << options[currentQuestion.getCorrectAnswer() - 'A']
					  << "\n";
        }
        
        cout << "Current Score: " << gameManager.getScore() << "\n";
    }
    
    cout << "\n========================================\n";
    cout << "           QUIZ COMPLETED!             \n";
    cout << "========================================\n";
    cout << "Final Score: " << gameManager.getScore() << " / "
              << (totalQuestionsToAsk * 10) << "\n";
    
    int percentage = (gameManager.getScore() * 100) / (totalQuestionsToAsk * 10);
    cout << "Percentage: " << percentage << "%\n";
    
    if (percentage >= 80) {
        cout << "Excellent performance!\n";
    } else if (percentage >= 60) {
        cout << "Good job! Keep practicing!\n";
    } else {
        cout << "Keep trying! You'll do better next time!\n";
    }
    
    delete strategy;
}

int main() {
    displayWelcome();
    
    do {
        playGame();
    } while (askToPlayAgain());
    
    cout << "\nThank you for playing! Goodbye!\n";
    
    return 0;
}