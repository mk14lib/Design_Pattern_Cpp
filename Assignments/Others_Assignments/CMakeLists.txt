# CMakeLists.txt for Quiz Game Application
# This project demonstrates Strategy and Singleton design patterns in C++

cmake_minimum_required(VERSION 3.10)
project(QuizGame VERSION 1.0.0 LANGUAGES CXX)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Set output directories
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

# Compiler warnings
if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# Source files
set(SOURCES
    main.cpp
)

# Header files
set(HEADERS
    Question.h
    QuestionSelectionStrategy.h
    GameManager.h
)

# Create executable
add_executable(quiz_game ${SOURCES} ${HEADERS})

# Set target properties
set_target_properties(quiz_game PROPERTIES
    OUTPUT_NAME "quiz_game"
    VERSION ${PROJECT_VERSION}
)

# Installation rules
install(TARGETS quiz_game
    RUNTIME DESTINATION bin
)

# Print configuration summary
message(STATUS "")
message(STATUS "Quiz Game Configuration:")
message(STATUS "  Version: ${PROJECT_VERSION}")
message(STATUS "  C++ Standard: ${CMAKE_CXX_STANDARD}")
message(STATUS "  Build Type: ${CMAKE_BUILD_TYPE}")
message(STATUS "")