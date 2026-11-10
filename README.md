# Rock Paper Scissors

A C++ console-based Rock Paper Scissors game where the player competes against the computer across multiple rounds.

## Features

- Choose the number of rounds from 1 to 10
- Player vs. computer gameplay
- Random computer choices
- Input validation
- Automatic winner detection for each round
- Tracks player wins
- Tracks computer wins
- Tracks draws
- Determines the final game winner
- Option to play again after the game ends

## Game Choices

The player can choose:

```text
1 - Rock
2 - Paper
3 - Scissors
```

The computer randomly selects one of the three choices.

## Game Rules

- Rock beats Scissors
- Scissors beats Paper
- Paper beats Rock
- Same choices result in a draw

## Technologies

- **C++**
- Enums
- Structs
- Functions
- Loops
- Conditional statements
- Random number generation
- Input validation

## Project Structure

```text
Rock-Paper-Scissors/
│
├── main.cpp
└── README.md
```

## How to Run

Make sure you have a C++ compiler such as `g++` installed.

Compile the program:

```bash
g++ main.cpp -o rock_paper_scissors
```

Run the program:

```bash
./rock_paper_scissors
```

## How It Works

The game first asks the player how many rounds they want to play.

For every round:

1. The player chooses Rock, Paper, or Scissors.
2. The computer randomly generates its choice.
3. The program compares both choices.
4. The winner of the round is determined.
5. The result is displayed.
6. The corresponding score is updated.

After all rounds are completed, the program displays the total results and determines the final winner.

## Result Tracking

The game keeps track of:

- Number of rounds
- Player wins
- Computer wins
- Draws
- Final winner

After the game is over, the player can choose to play again.

## Purpose

This project was built to practice C++ programming concepts by combining multiple concepts into a complete console-based game.

## Author

**Mohamed**
