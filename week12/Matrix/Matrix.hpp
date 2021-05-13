#pragma once
#include <iostream>

template <class T>
class Matrix {
private:
    T** matrix;
    unsigned sizeX;
    unsigned sizeY;
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
    sizeX = 2;
    sizeY = 2;

    matrix = new T*[2];
    matrix[0] = new T[2];
    matrix[1] = new T[2];
}

template <class T>
void Matrix<T>::allocateMemoryForMatrix(const unsigned& sizeX, const unsigned& sizeY) {
    this -> sizeX = sizeX;
    this -> sizeY = sizeY;
    matrix = new T*[sizeY];
    for (unsigned i = 0; i < sizeY; ++ i) {
        matrix[i] = new T[sizeX];
    }
}

template <class T>
Matrix<T>::Matrix(const unsigned& sizeX, const unsigned& sizeY) {
    allocateMemoryForMatrix(sizeX, sizeY);
}

template <class T>
void Matrix<T> :: erase() {
    for (unsigned i = 0; i < sizeY; ++i) {
        delete[] matrix[i];
    }
    delete[] matrix;
}

template <class T>
Matrix<T>::Matrix(const Matrix<T>& rhs) {
    if (rhs != nullptr) {
        allocateMemoryForMatrix(rhs.sizeX, rhs.sizeY);
        for (unsigned y = 0; y < sizeY; ++ y) {
            for (unsigned x = 0; x < sizeX; ++ x) {
                matrix[y][x] = rhs.matrix[y][x];
            }
        }
    }
}


template <class T> 
Matrix<T>& Matrix<T>::operator=(const Matrix<T>& rhs) {
    if (rhs.matrix != nullptr) {
        erase();
        allocateMemoryForMatrix(rhs.sizeX, rhs.sizeY);
        for (unsigned y = 0; y < sizeY; ++ y) {
            for (unsigned x = 0; x < sizeX; ++ x) {
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
    if (matrix != nullptr && x - 1 < sizeX && y - 1 < sizeY) {
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
    newMatrix = new T*[sizeX];
    for (unsigned i = 0; i < sizeX; ++ i) {
        newMatrix[i] = new T[sizeY];
    }
    for (unsigned y = 0; y < sizeX; ++ y) {
        for (unsigned x = 0; x < sizeY; ++ x) {
            newMatrix[y][x] = matrix[x][y];
        }
    } 
    
    std :: swap(sizeY, sizeX);

    erase();
    matrix = newMatrix;
    return true;
}

template <class T>
void Matrix<T>::print() const {
    for (unsigned y = 0; y < sizeY; ++ y) {
        for (unsigned x = 0; x < sizeX; ++ x) {
            std :: cout << matrix[y][x] << " ";
        }
        std :: cout << std::endl;
    }

}