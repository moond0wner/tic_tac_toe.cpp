#include <iostream>
#include <vector>
#include <Windows.h>

using namespace std;

size_t m = 3, n = 3;
vector<vector<char>> matrix = {
    {'_', '_', '_'},
    {'_', '_', '_'},
    {'_', '_', '_'}
};

void show_game() {
    for (size_t i = 0; i < m; ++i) {
            for (size_t j = 0; j < n; ++j) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
}
int main()
{   
    // Установка кодировки консоли в UTF-8
  SetConsoleOutputCP(CP_UTF8);
  SetConsoleCP(CP_UTF8);

// Установка локали для поддержки русского языка
  setlocale(LC_ALL, "ru_RU.UTF-8");
    

    cout << "Поле 3x3 для крестиков и ноликов" << endl;
    char currentPlayer = 'X';
    bool isFullX = false;
    while (!isFullX) {
        show_game();

        int pos_column, pos_row;
        cout << "Введите сначала номер столбца, а затем номер позицию в этом столбце" << endl;
        cin >> pos_column >> pos_row;
        if (pos_column >= 1 && pos_column <= m && pos_row >= 1 && pos_row <= n && matrix[pos_column - 1][pos_row - 1] == '_') { 
            matrix[pos_column - 1][pos_row - 1] = currentPlayer;

            isFullX = true;
            for (size_t i = 0; i < matrix[0].size(); ++i) {
                    if (matrix[0][i] != 'X') {
                        isFullX = false;
                        break;
                    } 
            }

            if (isFullX) {
                cout << "Вы выиграли! Вы заполнили первую строчку!" << endl;
                show_game();
                break;

            }

            isFullX = true;
            for (size_t i = 0; i < matrix[1].size(); ++i) {
                    if (matrix[1][i] != 'X') {
                        isFullX = false;
                        break;
                    } 
            }

            if (isFullX) {
                cout << "Вы выиграли! Вы заполнили вторую строчку!" << endl;
                show_game();
                break;
            }
            isFullX = true;
            for (size_t i = 0; i < matrix[2].size(); ++i) {
                    if (matrix[2][i] != 'X') {
                        isFullX = false;
                        break;
                    }
            }

            if (isFullX) {
                cout << "Вы выиграли! Вы заполнили третью строчку!" << endl;
                show_game();
                break;
            }

            if (matrix[0][0] == 'X' && matrix[1][1] == 'X' && matrix[2][2] == 'X') {
                cout << "Ничего себе, вы заполнили главную диагональ. Вы выиграли!" << endl;
                show_game();
                break;
            } 
            if (matrix[0][2] == 'X' && matrix[1][1] == 'X' && matrix[2][0] == 'X') {
                cout << "Ничего себе, вы заполнили побочную диагональ. Вы выиграли!" << endl;
                show_game();
                break;
            }
        } else {
            cout << "Неправильный ввод!" << endl;
            continue;
        }
    }

       

}
