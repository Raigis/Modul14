// Задание 2. Крестики-нолики
// Что нужно сделать
// Старая добрая игра на страницах всех школьных тетрадей. 
// Поле размером 3 × 3 представлено в виде двумерного массива с типом элементов char. 
// Участвуют два игрока, они ходят по очереди и ставят в указанные ими в стандартном вводе координаты свой символ — X или O (буквы латинского алфавита). 
// Как только у одного из игроков будет установлено подряд три крестика или три нолика, он побеждает. 
// Если свободных клеток не осталось, а трёх совпадающих элементов не найдено, то объявляется ничья.

// Изначально всё поле инициализируется символом пробела — ‘ ‘(для обозначения пробела кавычки одинарные и в одну сторону). 
// Это можно сделать сразу при объявлении либо с помощью вложенного цикла. 
// На каждом ходе при занятой клетке или при неверных координатах этой клетки должно быть выведено сообщение, и игрок должен указать координаты клетки повторно. 
// После каждого хода надо выводить в консоль текущее состояние всего игрового поля для наглядности.

#include <iostream>

void print(char field[][8]){
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++){
            std::cout << field[i][j];
        }
        std::cout << std::endl;
    }
}

bool win (bool BF[][3]) {
    if (       (BF[0][0] && BF[1][0] && BF[2][0])
            || (BF[0][1] && BF[1][1] && BF[2][1])
            || (BF[0][2] && BF[1][2] && BF[2][2])
            || (BF[0][0] && BF[0][1] && BF[0][2])
            || (BF[1][0] && BF[1][1] && BF[1][2])
            || (BF[2][0] && BF[2][1] && BF[2][2])
            || (BF[0][0] && BF[1][1] && BF[2][2])
            || (BF[0][2] && BF[1][1] && BF[2][0])) {
        return true;
    }
    return false;
}

void change_field(bool BFP[][3], bool BF[][3], char CF[][8], int x, int y, char mark){
    BFP[x-1][y-1] = true;
    BF[x-1][y-1] = true;
    CF[x*2][y*2] = mark;
}

bool is_correct(bool BF[][3], int x, int y) {
    if(BF[x-1][y-1] || x < 1 || x > 3 || y < 1 || y > 3){
        std::cout << "Incorrect input. Please, try again.\n";
        return true;
    }
    return false;
}

void play(bool BFP[][3], bool BF[][3],char CF[][8], int id){
    std::string player = (id == 0 ? "First player" : "Second player");
    char mark = (id == 0 ? 'X' : 'O');
    char x,y;
    do{
        std::cout << player << " turn!\nEnter the coordinates (Left Up):\n";
        std::cin >> x >> y;
    } while (is_correct(BF, x - '0', y - '0'));
    change_field(BFP, BF, CF, x - '0', y - '0', mark);
}

int main() {
    char charField[8][8] {{' ', ' ', '1', ' ', '2', ' ', '3', ' '},
                          {' ', ' ', '-', '-', '-', '-', '-', ' '},
                          {'1', '|', ' ', '|', ' ', '|', ' ', '|'},
                          {' ', '|', '-', '+', '-', '+', '-', '|'},
                          {'2', '|', ' ', '|', ' ', '|', ' ', '|'},
                          {' ', '|', '-', '+', '-', '+', '-', '|'},
                          {'3', '|', ' ', '|', ' ', '|', ' ', '|'},
                          {' ', ' ', '-', '-', '-', '-', '-', ' '}};

    bool boolField[3][3] {{false, false, false},
                          {false, false, false},
                          {false, false, false}}, 
    boolFieldFP[3][3] {{false, false, false},
                       {false, false, false},
                       {false, false, false}}, 
    boolFieldSP[3][3] {{false, false, false},
                       {false, false, false},
                       {false, false, false}};

    int player;
    int count = 0;
    while(true){
        print(charField);
        player = count % 2;
        play((player == 0 ? boolFieldFP : boolFieldSP), boolField, charField, player);
        if (count >= 4) {
            if (win(player == 0 ? boolFieldFP : boolFieldSP)) {
                std::cout << "\033[1J\033[2;2H";
                print(charField);
                std::cout << (player == 0 ? "First player" : "Second player") << " win!";
                return 0;
            } else if (count == 8) {
                std::cout << "\033[1J\033[2;2H";
                print(charField);
                std::cout << "Draw!";
                return 0;
            }
        }
        count++;
        std::cout << "\033[1J\033[2;2H";
    }
}