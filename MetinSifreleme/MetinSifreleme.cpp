// MetinSifreleme.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Umut Can Altıntaş 09/12/2024

// Metin Şifreleme

#include <iostream>
#include <string>
#include <cmath>
#include <utility>
#include "FileEditor.h"

static std::pair<std::string, int> ReshapeAndFindSize(std::string& input) {

    std::pair<std::string, int>* reshaped = new std::pair<std::string, int>();

    for (int i = 0; i < input.length(); i++) {
        if (isblank(input[i]))
            input.erase(i, 1);
    }

    *reshaped = std::make_pair(input, input.size() - 1);
    
    return *reshaped;
}

// matrix satır ve sütun blogların bulunması
static std::pair<int, int> FindMatrixCols(int l)
{
    int m = 0;
    int n = 0;

    m = std::ceil(std::sqrt(l));
    n = std::ceil(std::sqrt(l));
    return std::make_pair(m, n);
}

// string ifadeden 2 boyutlu char array 'a değer atanıp ekrana yazılması
static void PrintMatrix(std::string& input, int m, int n)
{
    // 2 boyutlu dinamik char array
    char** array = new char* [m];
    for (int i = 0; i < m; i++) {
        array[i] = new char[n]; 
    }

    std::cout << "\nMatrixlenmis hali:\n";
    int index = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (index <= input.size() - 1) // out of index error kontrolü
            {
                array[i][j] = input[index++];
                std::cout << array[i][j];
            }
        }
        std::cout << std::endl;
    }

    // dinamik belleği serbest bırakma işlemi
    for (int i = 0; i < m; i++) {
        delete[] array[i];
    }
    delete[] array;
}

int main()
{    
    // Türkçe karakter veri uygunluğu
    std::setlocale(LC_ALL, "tr_TR.UTF-8");
    FileEditor::FileBuilder fb;

    std::string* rs = new std::string();
    std::pair<std::string, int>* reshaped = new std::pair<std::string, int>();

    // dosya okuma işlemleri
    *rs = fb.Read("metin2.txt");

    // verinin reshape ve size işlemleri
    *reshaped = ReshapeAndFindSize(*rs);
    std::cout << "\nbosluklar silinmis ve resize edilmis hali ve uzunlugu(l):\n";
    std::cout << reshaped->first << "," << reshaped->second << std::endl;

    std::pair<int,int> cols = FindMatrixCols(reshaped->second);
    std::cout << "\narray matrisleri:\n";
    std::cout << cols.first << "," << cols.second << std::endl;

    // 2 boyutlu matris'in yazdırılması
    PrintMatrix(reshaped->first, cols.first, cols.second);

}

