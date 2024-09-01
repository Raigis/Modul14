// Задание 5. Пупырка
// После посылки из Китая осталась спецплёнка для бережной перевозки груза — пупырка. 
// Всего в пупырке 12 на 12 шариков-пузырьков. 
// Состояние любого пузырька: он либо целый, либо нет, то есть true или false (тип массива — bool).
// Для начала требуется реализовать отдельную функцию инициализации пупырки начальным состоянием: полностью целая пупырка, все элементы true.

// Программа заключается в последовательном лопании целых регионов пузырьков. 
// Перед каждым таким лопанием надо показывать пользователю полностью всю плёнку: o — это целый пузырёк, x — лопнутый. 
// Это тоже надо выделить в отдельную функцию. Итак, как выглядит само лопание. Пользователь вводит две координаты: начала региона и конца региона. 
// Процедура лопания пузырей должна быть реализована с помощью отдельной функции, все аргументы должны проверяться на валидность, что они в в рамках диапазона возможных значений, иначе должна быть выведена ошибка. 
// После лопания каждого пузыря, который не был ещё лопнут до того, в консоль должно выводиться сообщение “Pop!”.

// Лопание должно продолжаться до последнего пузырька. 
// Как только вся пупырка потрачена, программа заканчивает выполнение. 
// Вы можете подсчитать окончание в самой функции по отображению пузырьков плёнки, так как функция выполняется после каждого лопания.

#include <iostream>
#include <chrono>
#include <thread>

using namespace std::this_thread;
using namespace std::chrono_literals;

void filling(bool arr[][12]){
    for (int i = 0; i < 12; i++) {
        for(int y = 0; y < 12; y++) arr[i][y] = true;
    }
}

bool intact(bool arr[][12]) {
    for (int i = 0; i < 12; i++) {
        for(bool y : arr[i]){
            if (y) return true;
        }
    }
    return false;
}

void print(bool arr[][12]) {
    for (int i = 0; i < 12; i++){
        for (bool y : arr[i]) {
            if (y) {
                std::cout << "o "; 
            } else {
                std::cout << "x ";
            }
        }
        std::cout << std::endl;
    }
}

void input(std::string text, int coor[]) {
    bool isCorrect;
    do{
        std::cout << "Enter the coordinates of the " << text << " :\n";
        std::cin >> coor[0] >> coor[1];
        if (isCorrect = coor[0] < 1 || coor[0] > 12 || coor[1] < 1 || coor[1] > 12)
        std::cout << "Incorrect input. Please, try again.\n";
    } while(isCorrect);
}

void pop(bool arr[][12], int st[], int fin[]){
    for(int i = st[0]; i <= fin[0]; i++) {
        for(int y = st[1]; y <= fin[1]; y++) {
            if(arr[i][y]) {
                std::cout << "\033[1J\033[2;2H";
                arr[i][y] = false;
                std::cout << "POP!\n";
                print(arr);
                sleep_for(200ms);
            } else {
                std::cout << "\033[1J\033[2;2H";
                print(arr);
                sleep_for(200ms);
            }
        }
    }
}

int main() {
    bool bubbleWrap[12][12];
    filling(bubbleWrap);
    int start[2], finish[2];
    print(bubbleWrap);
    while(intact(bubbleWrap)){
        input("start", start);
        input("finish", finish);
        for (int i = 0; i < 2; i++){
            start[i]--;
            finish[i]--;
        }
        pop(bubbleWrap, start, finish);
    }
}