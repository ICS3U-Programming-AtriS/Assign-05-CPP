// Copyright (c) 2025 Atri Sarker All rights reserved.
// .
// Created By: Atri S
// Date: May 28, 2025
// Game: Merge the Numbers

#include <iostream>
#include <list>

// Class for the game
class Game {
    // Everything is going to be public because im lazy
    public:
        int rowCount;
        int colCount;
        std::list<std::list<int>> gameMatrix;
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
        std::list<std::list<int>> EmptyMatrix() {
            // INITIALIZE AN EMPTY LIST
            std::list<std::list<int>> resultMatrix;
            // FOR LOOP [CREATE (rowCount) rows]
            for (int rowNum = 0; rowNum < rowCount; rowNum++) {
                // INITIALIZE A NEW ROW
                std::list<int> newRow;
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
        
};

int main() {
    // Code Goes Here
}
