#include "Rational.hpp"
#include <iostream>
#include <fstream>

// ВАЖНО! Ако искате да четете/пишете числата от бинарния файл на определена позиция,
// трябва да знаете, че първо има записан един int (4 байта) 
// и след него са рационалните числа. Т.е. отместването трябва да се направи по следния начин:
// const int HEADER_SIZE = 4; големината на хедъра на бинарния файл в байтове, т.е. допълнителната
// информация, която пазим преди данните.
// seekg(HEADER_SIZE + n*sizeof(Rational), std::ios::beg)

// Тези функции за конвертиране се отнасят само за файловете с рационални числа.
void convertBinaryToTextFile(const char* inputFilename, const char* outputFileName)
{
    // Отваряме файловете.
    std::ifstream fi(inputFilename, std::ios::in | std::ios::binary);
    std::ofstream fo(outputFileName);
    
    int n;
    
    // Четем колко числа има във файла.
    fi.read((char *)&n, sizeof(int));

    fo << n << '\n'; // Записваме колко числа ще има във файла.

    Rational current;
    for (int i = 0; i < n; ++i)
    {
        // Четем от файла sizeof(Rational) байта и ги записваме в променливата current.
        fi.read((char *)&current, sizeof(Rational)); 

        // Записваме current във файла, т.е. записваме ASCII кодовете на цифрите и наклонената черта.
        fo << current << '\n';
    }
}

void convertTextToBinaryFile(const char* inputFilename, const char* outputFileName)
{
    // Отваряме файловете.
    std::ifstream fi(inputFilename);
    std::ofstream fo(outputFileName, std::ios::out | std::ios::binary);
    
    int n;
    
    // Четем колко числа има във файла.
    fi >> n;
    
    // Записваме колко числа ще има във файла.
    fo.write((const char*)&n, sizeof(int));

    Rational current;
    for (int i = 0; i < n; ++i)
    {
        // Четем рационално число от файла. Тук се извиква operator>>,
        // който предефинирахме за класа Rational.
        fi >> current; // еквивалентно на operator>>(fi, current);
    
        // Записваме байтовете, които се намират в променливата current, във файла.
        fo.write((const char*)&current, sizeof(Rational));
    }
}

void computeFromBinaryFile(const char* filename)
{
    std::ifstream fi(filename, std::ios::in | std::ios::binary);

    int n;
    fi.read((char *)&n, sizeof(int)); // Четем колко числа има във файла.

    Rational result(1,1); // 1/1 е нулева стойност за операцията умножение.
    Rational current;
    for (int i = 0; i < n; ++i)
    {
        // Четем от файла sizeof(Rational) байта и ги записваме в променливата current.
        fi.read((char *)&current, sizeof(Rational)); 
        result *= current;
    }

    std::cout << "Result is " << result << '\n';
}

void computeFromTextFile(const char* filename)
{
    std::ifstream fi(filename);

    int n;
    fi >> n; // Четем колко числа има във файла.

    Rational result(1,1); // 1/1 е нулева стойност за операцията умножение.
    Rational current;
    for (int i = 0; i < n; ++i)
    {
        // Четем рационално число от файла. Тук се извиква operator>>,
        // който предефинирахме за класа Rational.
        fi >> current; // еквивалентно на operator>>(fi, current);
        result *= current;
    }

    std::cout << "Result is " << result << '\n';
}

int main(int argc, char* argv[])
{

   // convertTextToBinaryFile("input.txt", "input.bin");
   // convertBinaryToTextFile("input.bin", "input.txt");
   // computeFromTextFile("input.txt");
    computeFromBinaryFile("input.bin");

    return 0;
}