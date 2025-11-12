#include "game.cpp"

int main() {
    Tictactoe game;
    char playAgain;

    do {
        game.playGame();

        cout << "\nХотите сыграть еще раз? (y/n): ";
        cin >> playAgain;

        if (playAgain == 'y' || playAgain == 'Y') {
            game.resetGame();
        }

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Спасибо за игру! До свидания!\n";
    return 0;
}
