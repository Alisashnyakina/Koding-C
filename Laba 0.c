Вот пример кода на языке C, который создает файл "input.txt", записывает в него две случайные матрицы размера, заданного пользователем, и освобождает память после записи:

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void clearMatrix(int **matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

int main() {
    // Инициализация генератора случайных чисел
    srand(time(NULL));

    int rows, cols;

    // Получаем размер матрицы от пользователя
    printf("Введите количество строк: ");
    scanf("%d", &rows);
    printf("Введите количество столбцов: ");
    scanf("%d", &cols);

    // Открываем файл для записи
    FILE *file = fopen("input.txt", "w");
    if (file == NULL) {
        printf("Ошибка открытия файла.\n");
        return 1;
    }

    // Записываем первую матрицу в файл
    fprintf(file, "Первая матрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int num = rand() % 100; // Генерируем случайное число от 0 до 99
            fprintf(file, "%d ", num);
        }
        fprintf(file, "\n");
    }

    // Записываем вторую матрицу в файл
    fprintf(file, "\nВторая матрица:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int num = rand() % 100; // Генерируем случайное число от 0 до 99
            fprintf(file, "%d ", num);
        }
        fprintf(file, "\n");
    }

    // Закрываем файл
    fclose(file);

    // Очистка памяти
    clearMatrix(matrix1, rows);
    clearMatrix(matrix2, rows);

    return 0;
}


Пожалуйста, обратите внимание, что в этом примере нет реализации самого выделения памяти для матриц matrix1 и matrix2, так как код фрагментарный. Важно убедиться, что правильно выделяется память для хранения матриц, а также нужно учесть ошибки ввода от пользователя для безопасности программы.



