#include <iostream>
#include <ctime>

int main() {
    const int N = 5; // размерность массива
    int array[N][N]; // двумерный массив

    // Заполнение массива так, чтобы элемент с индексами i и j был равен i + j
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            array[i][j] = i + j;
        }
    }

    // Вывод массива в консоль
    std::cout << "array " << N << "x" << N << ":\n";
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << array[i][j] << " ";
        }
        std::cout << "\n";
    }

    // Получение текущей даты и вычисление индекса строки для суммирования
    std::time_t now = std::time(0);
    std::tm ltm; // переменная для хранения результата
    localtime_s(&ltm, &now); // безопасное использование localtime
    int current_day = ltm.tm_mday; // текущее число календаря
    int row_index = current_day % N; // индекс строки

    // Вычисление суммы элементов в указанной строке
    int row_sum = 0;
    for (int j = 0; j < N; j++) {
        row_sum += array[row_index][j];
    }

    // Вывод суммы элементов в строке с индексом row_index
    std::cout << "Sum elmetns" << row_index << "(index determined based on current day): " << row_sum << "\n";

    return 0;
}
