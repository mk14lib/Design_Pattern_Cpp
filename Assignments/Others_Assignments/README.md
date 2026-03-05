# Quiz Game Application

A C++ quiz game application demonstrating the **Strategy** and **Singleton** design patterns.

## Design Patterns Used

### 1. Strategy Pattern
The Strategy pattern is implemented in [`QuestionSelectionStrategy.h`](QuestionSelectionStrategy.h) to allow different question selection algorithms:
- **SequentialSelectionStrategy**: Returns questions in the order they were added
- **RandomSelectionStrategy**: Returns questions in a random order using `std::shuffle`
- **DifficultyBasedSelectionStrategy**: Returns questions sorted by difficulty (ascending)

### 2. Singleton Pattern
The Singleton pattern is implemented in [`GameManager.h`](GameManager.h) to ensure only one instance of the game manager exists:
- Private static instance pointer
- Private constructor
- Deleted copy constructor and assignment operator
- Public static `getInstance()` method

## Project Structure

```
.
├── Question.h                      # Question class definition
├── QuestionSelectionStrategy.h     # Strategy pattern implementation
├── GameManager.h                   # Singleton pattern implementation
├── main.cpp                        # Main game logic and UI
├── CMakeLists.txt                  # CMake build configuration
└── README.md                       # This file
```

## Building the Project

### Using CMake (Recommended)

#### Windows (Visual Studio)

1. Create a build directory:
```powershell
mkdir build
cd build
```

2. Configure the project:
```powershell
cmake ..
```

3. Build the project:
```powershell
cmake --build . --config Release
```

Or open the generated `QuizGame.sln` in Visual Studio and build from there.

#### Linux/macOS

1. Create a build directory:
```bash
mkdir build
cd build
```

2. Configure the project:
```bash
cmake ..
```

3. Build the project:
```bash
cmake --build .
```

### Using g++ Directly

```bash
g++ -std=c++11 main.cpp -o quiz_game
```

## Running the Application

After building, run the executable:

**Windows:**
```powershell
.\build\bin\Release\quiz_game.exe
```

**Linux/macOS:**
```bash
./build/bin/quiz_game
```

Or if using g++ directly:
```bash
./quiz_game
```

## Game Features

- **6 sample questions** with varying difficulty levels (1-3)
- **3 question selection modes**:
  1. Sequential (questions in order)
  2. Random (questions shuffled)
  3. Difficulty-based (easy to hard)
- **Score tracking** with 10 points per correct answer
- **Input validation** for user answers
- **Play again** functionality
- **Performance feedback** based on final score

## How to Play

1. Run the application
2. Select a question selection mode (1, 2, or 3)
3. Answer each question by entering A, B, C, or D
4. Receive immediate feedback on your answer
5. View your final score and performance rating
6. Choose to play again or exit

## Requirements

- C++11 or later
- CMake 3.10 or later (for CMake build)
- g++ or compatible compiler

## License

This is a demonstration project for educational purposes.