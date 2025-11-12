#include <limits>
#include <vector>
#include <iostream>

using namespace std;

typedef std::vector<std::vector<char>> Board;

class Tictactoe {
private:
    Board board;

    char player;
    bool gameover;

    bool IsMoveValid(int row, int col) {
        return row >= 0 && row < 3 && col >= 0 && col < 3 && board[row][col] == ' ';
    }
public:
    Tictactoe() : board(3, vector<char>(3, ' ')), player('X'), gameover(false) {}

    void Display() {
        cout << "___________";
        for (int i = 0; i < 3; i++) {
            cout << " " << board[i][0] << " | " << board[i][1] << " | " << board[i][2] << " \n";
            cout << "___________";
        }
    }

    void Move(int row, int col) {
        if (IsMoveValid(row, col)) {
            board[row][col] = player;
        }
    }

    bool checkWin() {
        // Проверка строк
        for (int i = 0; i < 3; i++) {
            if (board[i][0] == player && board[i][1] == player && board[i][2] == player) {
                return true;
            }
        }

        // Проверка столбцов
        for (int i = 0; i < 3; i++) {
            if (board[0][i] == player && board[1][i] == player && board[2][i] == player) {
                return true;
            }
        }

        // Проверка диагоналей
        if (board[0][0] == player && board[1][1] == player && board[2][2] == player) {
            return true;
        }
        if (board[0][2] == player && board[1][1] == player && board[2][0] == player) {
            return true;
        }

        return false;
    }
    bool checkDraw() {
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    return false;
                }
            }
        }
        return true;
    }

    void Switch() {
      player = (player == 'X') ? 'O' : 'X';
    }

    void playGame() {
        cout << "=== КРЕСТИКИ-НОЛИКИ ===\n";
        cout << "Игрок 1: X\n";
        cout << "Игрок 2: O\n";
        cout << "Для хода введите номер строки и столбца (0-2)\n";

        while (!gameover) {
            Display();
            cout << "Ход игрока " << player << "\n";

            int row, col;
            bool validInput = false;

            // Ввод и проверка корректности ввода
            while (!validInput) {
                cout << "Введите строку (0-2): ";
                if (!(cin >> row)) {
                    cout << "Ошибка ввода! Введите число.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                cout << "Введите столбец (0-2): ";
                if (!(cin >> col)) {
                    cout << "Ошибка ввода! Введите число.\n";
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    continue;
                }

                if (IsMoveValid(row, col)) {
                    validInput = true;
                } else {
                    cout << "Неверный ход! Попробуйте снова.\n";
                }
            }

            // Выполнение хода
            Move(row, col);

            // Проверка условий окончания игры
            if (checkWin()) {
                Display();
                cout << "Игрок " << player << " победил! Поздравляем!\n";
                gameover = true;
            } else if (checkDraw()) {
                Display();
                cout << "Ничья! Игра окончена.\n";
                gameover = true;
            } else {
                Switch();
            }
        }
    }

    // Сброс игры для новой партии
    void resetGame() {
        board = vector<vector<char>>(3, vector<char>(3, ' '));
        player = 'X';
        gameover = false;
    }
};
