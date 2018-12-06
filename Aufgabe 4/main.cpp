// Labyrinth Backtracking
// Autor: Suayb Yurdakul
// Datum: 2018-12-06

#include <iostream>
#include <array>
#include <vector>
#include <cstdlib>
using namespace std;

const int MAZE_SIZE = 14;
const int X_START = 3;
const int Y_START = 1;

void mazeTraversal(array< array< char, MAZE_SIZE >, MAZE_SIZE >&, int, int);
void printMaze(const array< array< char, MAZE_SIZE >, MAZE_SIZE >&);

int exitCounter = 0;

int main() {
    array< array< char, MAZE_SIZE >, MAZE_SIZE > maze =
    { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.',
      '.', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '.',
      '.', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', '.',
      '.', ' ', ' ', '#', ' ', '#', ' ', '#', '#', '#', '#', ' ', '#', '.',
      '.', '#', '#', '#', ' ', '#', ' ', ' ', ' ', ' ', '#', ' ', '#', '.',
      '.', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', ' ', '#', ' ', ' ', '.',
      '.', '#', '#', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '.',
      '.', '#', ' ', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '.',
      '.', '#', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', ' ', '#', '.',
      '.', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', '#', '.',
      '.', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', ' ', '#', '.',
      '.', '#', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '.',
      '.', '#', '#', '#', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '.',
      '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' };

    mazeTraversal(maze, X_START, Y_START);
}

void mazeTraversal(array< array< char, MAZE_SIZE >, MAZE_SIZE >& maze, int xStart, int yStart) {
    vector<string> exitStored;

    if (maze[xStart][yStart] == '.') {
        cout << "Ausgang " << exitCounter + 1 << " bei X: " << xStart << " Y: " << yStart << "\n";
        exitCounter++;
        cin.ignore();
    }
    else if (maze[xStart][yStart] == ' ') {
        maze[xStart][yStart] = 'X';
        printMaze(maze);

        mazeTraversal(maze, xStart, yStart + 1); // right
        mazeTraversal(maze, xStart - 1, yStart); // up
        mazeTraversal(maze, xStart, yStart - 1); // left
        mazeTraversal(maze, xStart + 1, yStart); // down
    }
    else if (maze[xStart][yStart] == '#' || maze[xStart][yStart] == 'X') {
        return; // Backtracking
    }
}

void printMaze(const array< array< char, MAZE_SIZE >, MAZE_SIZE >& maze) {
    system("cls");
    for (unsigned int i = 0; i < MAZE_SIZE; i++) {
        cout << "\n";
        for (unsigned int j = 0; j < MAZE_SIZE; j++) {
            cout << maze[i][j] << " ";
        }
    }
    cin.ignore();
}