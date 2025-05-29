// Copyright (c) 2025 Atri Sarker All rights reserved.
// .
// Created By: Atri S
// Date: May 28, 2025
// Game: Merge the Numbers

#include <iostream>
#include <random>
#include <string>
#include <vector>

// Colors
const char BLACK[] = "\033[0;30m";       // BLACK
const char RED[] = "\033[0;31m";         // RED
const char GREEN[] = "\033[0;32m";       // GREEN
const char YELLOW[] = "\033[0;33m";      // YELLOW
const char BLUE[] = "\033[0;34m";        // BLUE
const char PURPLE[] = "\033[0;35m";      // PURPLE
const char CYAN[] = "\033[0;36m";        // CYAN
const char WHITE[] = "\033[0;37m";       // WHITE
const char GREY[] = "\033[38;5;240m";    // GREY
const char ORANGE[] = "\033[38;5;208m";  // ORANGE

// COLOR PRINT FUNCTIONS
void Black(std::string msg = "") {
    // APPLY COLOR
    std::cout << BLACK;
    // PRINT MESSAGE
    std::cout << msg;
}

void Red(std::string msg = "") {
    // APPLY COLOR
    std::cout << RED;
    // PRINT MESSAGE
    std::cout << msg;
}

void Green(std::string msg = "") {
    // APPLY COLOR
    std::cout << GREEN;
    // PRINT MESSAGE
    std::cout << msg;
}

void Yellow(std::string msg = "") {
    // APPLY COLOR
    std::cout << YELLOW;
    // PRINT MESSAGE
    std::cout << msg;
}

void Blue(std::string msg = "") {
    // APPLY COLOR
    std::cout << BLUE;
    // PRINT MESSAGE
    std::cout << msg;
}

void Purple(std::string msg = "") {
    // APPLY COLOR
    std::cout << PURPLE;
    // PRINT MESSAGE
    std::cout << msg;
}

void Cyan(std::string msg = "") {
    // APPLY COLOR
    std::cout << CYAN;
    // PRINT MESSAGE
    std::cout << msg;
}

void White(std::string msg = "") {
    // APPLY COLOR
    std::cout << WHITE;
    // PRINT MESSAGE
    std::cout << msg;
}

void Grey(std::string msg = "") {
    // APPLY COLOR
    std::cout << GREY;
    // PRINT MESSAGE
    // With a flush, since I am using it in Pause()
    std::cout << msg << std::flush;
}

void Orange(std::string msg = "") {
    // APPLY COLOR
    std::cout << ORANGE;
    // PRINT MESSAGE
    std::cout << msg;
}

// Function that clears the Terminal
void ClearTerminal() {
    // Clears the Terminal
    // std::system("clear");
}

// Function that displays the title
void DisplayTitle() {
    Yellow("##################################\n");
    Yellow("######## Merge the Numbers ########\n");
    Yellow("##################################\n");
}

// FUNCTION THAT RETURNS THE RGB CODE TEXT EFFECT,
// ACCORDING TO THE NUMBER PROVIDED
std::string GetColorFromNumber(int num) {
    // Color variables
    int red = 0;
    int green = 0;
    int blue = 0;
    // MATCH NUMBER TO THE COLOR CODE
    switch (num) {
        case 0:
            red = 255;
            green = 255;
            blue = 255;
            break;
        case 2:
            red = 30;
            green = 190;
            blue = 70;
            break;
        case 4:
            red = 255;
            green = 203;
            blue = 164;
            break;
        case 8:
            red = 180;
            blue = 90;
            break;
        case 16:
            red = 240;
            blue = 160;
            break;
        case 32:
            red = 50;
            blue = 150;
        case 64:
            red = 170;
            green = 70;
            blue = 170;
            break;
        case 128:
            red = 150;
            green = 150;
            break;
        case 256:
            red = 200;
            blue = 50;
            break;
        case 512:
            green = 220;
            blue = 40;
            break;
        case 1024:
            red = 200;
            blue = 200;
            break;
        case 2048:
            green = 255;
            blue = 255;
            break;
        case 4096:
            red = 255;
            break;
        // DEFAULT [for numbers over 4096]
        default:
            red = 255;
            // DYNAMIC COLOR BASED ON THE NUMBER
            green = num / 7;
    }
    // RETURN THE COLOR SEQUENCE
    return "\033[38;2;" + std::to_string(red) + ";" +
           std::to_string(green) + ";" +
           std::to_string(blue) + "m";
}

// Class for the game
class Game {
    // Everything is going to be public because im lazy
   public:
    int rowCount;
    int colCount;
    std::vector<std::vector<int>> gameMatrix;
    int score;
    // CONSTRUCTOR
    Game(int numRows, int numCols) {
        // SET row and column counts, according to the provided values
        rowCount = numRows;
        colCount = numCols;
        // Initialize the game board as an empty grid
        gameMatrix = EmptyMatrix();
        // Set starting score to 0
        score = 0;
    }

    // FUNCTION THAT RETURNS A MATRIX OF SIZE [rowCount * colCount]
    // WITH EVERY ELEMENT BEING A 0
    std::vector<std::vector<int>> EmptyMatrix() {
        // INITIALIZE AN EMPTY VECTOR [MATRIX]
        std::vector<std::vector<int>> resultMatrix;
        // FOR LOOP [CREATE (rowCount) rows]
        for (int rowNum = 0; rowNum < rowCount; rowNum++) {
            // INITIALIZE A NEW ROW
            std::vector<int> newRow;
            // FOR LOOP [CREATE (colCount) columns]
            for (int colNum = 0; colNum < colCount; colNum++) {
                // APPEND AN EMPTY SLOT
                newRow.push_back(0);
            }
            // Append the new row to the result matrix
            resultMatrix.push_back(newRow);
        }
        // RETURN THE EMPTY MATRIX
        return resultMatrix;
    }

    // FUNCTION THAT SPAWNS A VALUE OF 2 or 4 into the game matrix
    void SpawnBox() {
        // GET AMOUNT OF EMPTY SPACES WITHIN THE GAME MATRIX
        int numEmptySpaces = 0;
        // LOOP THROUGH EVERY ELEMENT IN THE GRID
        for (std::vector<int> row : gameMatrix) {
            for (int col : row) {
                // CHECK IF THE ELEMENT IS A 0
                if (col == 0) {
                    // IF IT IS, INCREMENT THE COUNT
                    numEmptySpaces += 1;
                }
            }
        }
        // GENERATE a random number between 0 and num_empty_spaces
        // RANDOM SEED
        std::random_device seed;
        // MERSENNE TWISTER
        std::mt19937 mt(seed());
        // Distribution that contains the range of numbers between 0 and num_empty_spaces
        std::uniform_int_distribution<int> randIndex(0, numEmptySpaces - 1);
        // Generate the random number
        int randNum = randIndex(mt);
        // LOOP THROUGH EVERY ELEMENT POSITION
        for (int index = 0; index < (rowCount * colCount); index++) {
            // GET ROW AND COLUMN INDICES
            int rowIndex = index / colCount;
            int colIndex = index % colCount;
            // CHECK IF THE ELEMENT FOUND AT THE GRID POSITION IS EMPTY
            if (gameMatrix[rowIndex][colIndex] == 0) {
                // CHECK IF the random number has reached 0
                if (randNum == 0) {
                    // Distribution that contains the range of numbers
                    // between 0 and 9 [INCLUSIVE]
                    std::uniform_int_distribution<int> randDigit(0, 9);
                    // Generate a random number between 0 and 9
                    int randInt = randDigit(mt);
                    // GENERATE THE RANDOM NUMBER THAT WILL SPAWN
                    int randBoxNum = (randInt == 9) ? 4 : 2;
                    // UPDATE SCORE BASED ON THE GENERATED NUMBER
                    score += randBoxNum;
                    // ADD THE NUMBER TO THE BOARD
                    gameMatrix[rowIndex][colIndex] = randBoxNum;
                    // BREAK
                    break;
                } else {
                    // OTHERWISE, DECREMENT the random number
                    randNum -= 1;
                }
            }
        }
    }

    // FUNCTION THAT DISPLAYS THE GAME BOARD [GAME MATRIX]
    void DisplayBoard() {
        // LOOP THROUGH EVERY ROW
        for (std::vector<int> row : gameMatrix) {
            // LOOP THROUGH EVERY COLUMN IN THE ROW
            for (int col : row) {
                // GET THE COLOR FOR THE NUMBER
                std::string textColor = GetColorFromNumber(col);
                // CHECK IF NUMBER IS SMALL ENOUGH
                if (col < 100000) {
                    printf("\033[1m%s%6d", textColor.c_str(), col);
                } else {
                    // IF IT ISN't, SHORTEN IT USING SCIENTIFIC NOTATION
                    printf("\033[1m%s%.0e", textColor.c_str(), col);
                }
            }
            // PRINT A NEWLINE
            printf("\n");
        }
        // RESET TEXT STYLE
        White("\033[0m");
    }

    // FUNCTION THAT DISPLAYS THE STATE OF THE GAME
    void DisplayGame() {
        // CLEAR TERMINAL
        ClearTerminal();
        // DISPLAY TITLE
        DisplayTitle();
        // DISPLAY SCORE
        Purple();
        printf("SCORE: %i\n", score);
        // DISPLAY BOARD
        DisplayBoard();
    }

    // GAME LOOP
    void GameLoop() {
        // SPAWN A BOX
        SpawnBox();
        // CHECK IF THE GAME IS OVER
        if (IsGameOver()) {
            // IF IT IS, STOP THE GAME LOOP BY RETURNING
            return;
        }
        // DISPLAY THE GAME
        DisplayGame();
        // HANDLE USER'S ACTION
        while (true) {
            // GET THE USER'S ACTION
            std::string userAction = GetAction();
            // CHECK IF THE ACTION DOES SOMETHING
            if (gameMatrix == HandleAction(userAction)) {
                // IF IT DOESN'T, ASK THE USER FOR AN ACTION AGAIN
                // Reset the terminal display
                DisplayGame();
                continue;
            } else {
                // CHANGE Game matrix, according to the user's action
                // 2nd argument is true, because this move actually counts
                // towards the player's score
                gameMatrix = HandleAction(userAction, true);
                // BREAK THE LOOP
                break;
            }
        }
    }

    // FUNCTION THAT PLAYS THE GAME
    void play() {
        while (true) {
            // GAME LOOP
            GameLoop();
            // CHECK IF THE GAME IS OVER
            if (IsGameOver()) {
                // IF IT IS, STOP THE LOOP AND DISPLAY THE LOSING MESSAGE
                // DISPLAY THE FINAL GAME STATE
                DisplayGame();
                // DISPLAY THE LOSING MESSAGE
                Red();
                printf("GAME OVER. FINAL SCORE : %i\n", score);
                // BREAK
                break;
            }
        }
    }

    // FUNCTION THAT GETS AND RETURNS THE USER'S ACTION
    std::string GetAction() {
        // DISPLAY PROMPT
        printf("Enter a keypress (WASD/ARROW KEYS): \n");
        while (true) {
            // Wait for any key press
            char key = getchar();
            // Match the key with the movement
            switch (key) {
                case 'w':
                case 'W':
                    return "UP";
                    break;
                case 'a':
                case 'A':
                    return "LEFT";
                    break;
                case 's':
                case 'S':
                    return "DOWN";
                    break;
                case 'd':
                case 'D':
                    return "RIGHT";
                    break;
                // ARROW KEYS
                case '\x1b': {
                    // Arrow keys are composed of 3 characters in sequence
                    // The first character was '\x1b'
                    // The next 2 characters determine the direction
                    // Match the 2 characters following "\x1b"
                    char secondChar = getchar();
                    char thirdChar = getchar();
                    std::string arrowIdentity = "" + secondChar + thirdChar;
                    if (arrowIdentity == "[A") {
                        // [A is the up arrow
                        return "UP";
                    } else if (arrowIdentity == "[D") {
                        // [D is the left arrow
                        return "LEFT";
                    } else if (arrowIdentity == "[B") {
                        // [B is the down arrow
                        return "DOWN";
                    } else if (arrowIdentity == "[C") {
                        // [C is the down arrow
                        return "RIGHT";
                    } else {
                        // Incase it's not an arrow sequence
                        // pass <do nothing>
                    }
                }
                default:
                    // pass <do nothing>
                    break;
            }
        }
    }

    // Function that returns the future game board,
    // according to the action
    std::vector<std::vector<int>>
    HandleAction(std::string action, bool updateScore = false) {
        // MATCH THE ACTION WITH THE MOVEMENT
        if (action == "UP") {
            return MoveUp(updateScore);
        } else if (action == "LEFT") {
            return MoveLeft(updateScore);
        } else if (action == "DOWN") {
            return MoveDown(updateScore);
        } else if (action == "RIGHT") {
            return MoveRight(updateScore);
        }
    }

    // UP
    std::vector<std::vector<int>>
    MoveUp(bool updateScore = false) {
        // Initialize an empty matrix
        std::vector<std::vector<int>> newMatrix = EmptyMatrix();
        // Loop through all the column positions
        printf("ColCount : %i \n", colCount);
        for (int colIndex = 0; colIndex < colCount; colIndex++) {
            std::cout << colIndex;
            // Get column
            std::vector<int> col;
            for (std::vector<int> row : gameMatrix) {
                col.push_back(row[colIndex]);
            }
            // Initialize an empty vector
            std::vector<int> newCol;
            // Extract all the non-zero numbers
            for (int num : col) {
                if (num != 0) {
                    printf("Num Added: %i\n", num);
                    newCol.push_back(num);
                }
            }
            // Loop through the extracted numbers, excluding the last
            for (int rowIndex = 0; (2 + rowIndex) < (newCol.size() + 1);
                 rowIndex++) {
                printf("%i", rowIndex);
                // Check if 2 adjacent numbers are the same
                if (newCol[rowIndex] == newCol[rowIndex + 1]) {
                    // MERGE
                    newCol[rowIndex] *= 2;
                    newCol[rowIndex + 1] = 0;
                    // If updateScore is true, update the score
                    if (updateScore) {
                        score += newCol[rowIndex];
                    }
                }
            }
            int realIndex = 0;
            for (int rowIndex = 0; rowIndex < newCol.size();
                 rowIndex++) {
                // Ignore Zeroes
                if (newCol[rowIndex] != 0) {
                    newMatrix[realIndex][colIndex] = newCol[rowIndex];
                    realIndex += 1;
                }
            }
        }
        return newMatrix;
    }

    // LEFT
    std::vector<std::vector<int>>
    MoveLeft(bool updateScore = false) {
        return gameMatrix;
    }

    // DOWN
    std::vector<std::vector<int>>
    MoveDown(bool updateScore = false) {
        return gameMatrix;
    }

    // RIGHT
    std::vector<std::vector<int>>
    MoveRight(bool updateScore = false) {
        return gameMatrix;
    }

    // FUNCTION THAT DETERMINES WHETHER THE GAME IS OVER OR NOT
    bool IsGameOver() {
        // GIANT BOOLEAN EXPRESSION
        // CHECKS IF THERE ARE ANY POSSIBLE MOVEMENTS
        return (gameMatrix == MoveLeft()) &&
               (gameMatrix == MoveRight()) &&
               (gameMatrix == MoveUp()) &&
               (gameMatrix == MoveDown());
    }
};

// PROBLEM FUNCTION CALL
void SummationGame(int numRows, int numCols) {
    // Instantiate the game
    Game newGame = Game(numRows, numCols);
    // Play the Game
    newGame.play();
}

// MAIN
int main() {
    // Code Goes Here
    SummationGame(3, 3);
}
