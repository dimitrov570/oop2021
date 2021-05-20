#pragma once
#include <iostream>

template <class T>
class Matrix {
private:
    T** matrix;
    unsigned width;
    unsigned height;
    void erase();
    void allocateMemoryForMatrix(const unsigned&, const unsigned&);
public:
    Matrix();
    Matrix(const unsigned&, const unsigned&);
    Matrix(const Matrix<T>&);
    Matrix<T>& operator=(const Matrix<T>&);
    ~Matrix();
    bool setAt(const unsigned&, const unsigned&, T);
    T getAt(const unsigned&, const unsigned&);
    bool transpose();
    void print() const;
};

template <class T>
Matrix<T>::Matrix() {
    width = 2;
    height = 2;

    matrix = new T*[2];
    matrix[0] = new T[2];
    matrix[1] = new T[2];
}

template <class T>
void Matrix<T>::allocateMemoryForMatrix(const unsigned& width, const unsigned& height) {
    this->width = width;
    this->height = height;
    matrix = new T*[height];
    for (unsigned i = 0; i < height; ++i) {
        matrix[i] = new T[width];
    }
}

template <class T>
Matrix<T>::Matrix(const unsigned& width, const unsigned& height) {
    allocateMemoryForMatrix(width, height);
}

template <class T>
void Matrix<T>::erase() {
    for (unsigned i = 0; i < height; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& rhs) {
    if (rhs != nullptr) {
        allocateMemoryForMatrix(rhs.width, rhs.height);
        for (unsigned y = 0; y < height; ++ y) {
            for (unsigned x = 0; x < width; ++ x) {
                matrix[y][x] = rhs.matrix[y][x];
            }
        }
    }
}


template <class T> 
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
    if (rhs.matrix != nullptr) {
        erase();
        allocateMemoryForMatrix(rhs.width, rhs.height);
        for (unsigned y = 0; y < height; ++ y) {
            for (unsigned x = 0; x < width; ++ x) {
                matrix[y][x] = rhs.matrix[y][x];
            }
        }       
    }
    return *this;
}

template <class T>
Matrix<T>::~Matrix() {
    erase();
}

template <class T>
bool Matrix<T>::setAt(const unsigned& x, const unsigned& y, T value) {
    if (matrix != nullptr && x - 1 < width && y - 1 < height) {
        matrix[y - 1][x - 1] = value;
        return true;
    }
    return false;
}

template <class T>
T Matrix<T>::getAt(const unsigned& x, const unsigned& y) {
    return matrix[y - 1][x - 1];
}

template <class T>
bool Matrix<T>::transpose() { 

    T** newMatrix;
    newMatrix = new T*[width];
    for (unsigned i = 0; i < width; ++ i) {
        newMatrix[i] = new T[height];
    }
    for (unsigned y = 0; y < width; ++ y) {
        for (unsigned x = 0; x < height; ++ x) {
            newMatrix[y][x] = matrix[x][y];
        }
    } 
    
    std::swap(height, width);

    erase();
    matrix = newMatrix;
    return true;
}

template <class T>
void Matrix<T>::print() const {
    for (unsigned y = 0; y < height; ++ y) {
        for (unsigned x = 0; x < width; ++ x) {
            std :: cout << matrix[y][x] << " ";
        }
        std :: cout << std::endl;
    }

}