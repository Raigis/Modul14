// Задание 4. Умножение матрицы на вектор
// Реализуйте частный случай умножения матрицы на матрицу, а именно умножение вектора на матрицу. 
// Эта операция распространена в компьютерной индустрии в целом и в компьютерной графике в частности, поэтому это будет хорошим упражнением.

// Итак, у нас есть четырёхкомпонентный вектор b, представленный с помощью массива, и матрица a размером 4 × 4, представленная в виде двумерного массива. 
// Их произведением будет новый четырёхэлементный вектор c. 
// Его компоненты будут суммой произведений элемента вектора b на строку матрицы a. 
// Индекс столбца при этом равен индексу соответствующей компоненты вектора b, который мы и рассчитываем.

// Все входные данные, матрица a и вектор b вносятся из пользовательского ввода.  
// Итоговый вектор c надо вывести в консоль (std::cout). 
// Тип данных элементов — всегда float. 
// Желательно реализовать этот алгоритм с помощью вложенного цикла на умножение колонки.

#include <iostream>

void input(std::string text, int matrix[][4]) {
    std::cout << "Enter the " << text << " :\n";
    for (int i = 0; i < 4; i++) {
        std::cout << "\tEnter the " << 1+i << " row of 4 numbers:\n\t";
        std::cin >> matrix[i][0] >> matrix[i][1] >> matrix[i][2] >> matrix[i][3];
    }
    std::cout << std::endl;
}

void input(std::string text, int vector[]) {
    std::cout << "Enter the " << text << " :\n";
    std::cout << "\tEnter the row of 4 numbers:\n\t";
    std::cin >> vector[0] >> vector[1] >> vector[2] >> vector[3];
}

void multiplication(int a[][4], int b[], int c[]){
    for(int i = 0; i < 4; i++){
        for(int y = 0; y < 4; y++){
            c[i] += a[i][y] * b[y];
        }
    }
}

void print(int vector[]) {
    std::cout << "Result:\n";
    std::cout << "(" << vector[0] << ", " << vector[1] << ", " << vector[2] << ", " << vector[3] << ")" << std::endl;
}

int main() {
    int a[4][4], b[4], c[4] {0, 0, 0, 0};
    input("matrix", a);
    input("vector", b);
    multiplication(a, b, c);
    print(c);
}