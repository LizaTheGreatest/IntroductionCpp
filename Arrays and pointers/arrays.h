#ifndef ARRAYS_H
#define ARRAYS_H



template <typename T>
void swap(T &element1, T &element2)
{
    T temp;
    temp = element1;
    element1 = element2;
    element2 = temp;
}

//template <typename T>
//void createMatrix(T** matrix, const int size)
//{
//    *matrix = (T*) malloc(size * sizeof(T));
//}

//template <typename T>
//void createMatrix(T*** matrix, const int rows, const int columns)
//{
//    *matrix = (T**) malloc(rows * sizeof(T*));
//    for(int i = 0; i < rows; ++i)
//        (*matrix)[i] = (T*) malloc(columns * sizeof (T));
//}




void sortAscending(int* array, int size, int left_border = 0);
void sortDescending(int* array, int size, int left_border = 0);

int minElement(int* array, int size, int left_border = 0);
int maxElement(int* array, int size, int left_border = 0);

void viewMatrix(int** matrix, const int rows, const int columns);
void viewMatrix(int* matrix, const int size);

void fillMatrix(int* matrix, int size);
void fillMatrix(int**, int rows, int columns);

void createMatrix(int** matrix, int size);
void createMatrix(int*** matrix, int rows, int columns);

int safeReadInt(const char* text = "Please, enter number: ");
void flush_stdin();

#endif // ARRAYS_H

