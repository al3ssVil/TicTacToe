# Tic-Tac-Toe

A simple C++ program that allows two players to play a command-line Tic-Tac-Toe game.

## Description

This project is a simple implementation of the classic Tic-Tac-Toe game in C++. It is a console-based game where two players take turns placing "X" or "O" on a 3x3 grid. The first player to align three of their symbols vertically, horizontally, or diagonally wins the game.

There are no external dependencies, and it can be compiled and run on any system with a C++ compiler.

## Example Usage

When you run the program, you will see a grid like this:

![image](https://github.com/user-attachments/assets/403a700c-3933-45a3-a20d-18fecc7542b4)


You can choose between playing with a friend (option 1) or playing against the computer (option 2). If you enter any other number or letter, it will show a message saying you didn't enter a valid option.

For the purpose of this demonstration, we will choose option **2** (One player vs Computer).

Next, the game will ask you whether you want to play as "X" or "O". After choosing your symbol, the game begins.

You will be shown a 3x3 grid again and asked to select where you want to place your symbol:
```
1 2 3
4 5 6
7 8 9
```

Each number corresponds to a position on the grid. You can choose the number where you want to place your symbol.

For example:
- If you enter **1**, your symbol will be placed in the top-left corner.
- If you enter **5**, your symbol will be placed in the center.

After all moves, the game will check if anyone has won (3 of the same symbols in a row, column, or diagonal) or if it's a tie. 

At the end of the game, it will display who won, or if it's a tie.
### Have fun!
