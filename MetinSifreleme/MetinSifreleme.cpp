// MetinSifreleme.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Umut Can Altıntaş 14/12/2024

// Metin Şifreleme

#include <iostream>
#include <string>
#include <cmath>
#include <utility>
#include "FileEditor.h"

static std::pair<std::wstring, int> ReshapeAndFindSize(std::wstring& input) {

    std::pair<std::wstring, int>* reshaped = new std::pair<std::wstring, int>();

    for (int i = 0; i < input.length(); i++) {
        if (isblank(input[i]))
            input.erase(i, 1);
    }

    *reshaped = std::make_pair(input, input.size());
    
    return *reshaped;
}

// matrix satır ve sütun blogların bulunması
static std::pair<int, int> FindMatrixCols(int l)
{
    int m = std::floor(std::sqrt(l)); // m değerini alt değere yuvarlama
    int n = std::ceil(std::sqrt(l)); // n değerini üst değere yuvarlama

    if (m * n < l) // m x n matrixin değer uzunluğa uygunluk kontrolü
        m = std::ceil(std::sqrt(l)); // uygunluk sağlanmadığında m değerini üste yuvarlama

    return std::make_pair(m, n);
}

// wstring ifadenin "m x n" array matrisli şekilde yazılması
static void PrintMatrix(std::wstring& input, int m, int n)
{
    // 2 boyutlu dinamik wchar_t(16 bitlik unicode değerler için) array oluştur
    wchar_t** matrix = new wchar_t* [m];
    for (int i = 0; i < m; i++) {
        matrix[i] = new wchar_t[n];
    }

    int index = 0;
    // Matrisi yazdır
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (index < input.size()) {
                matrix[i][j] = input.at(index++);
                std::wcout << matrix[i][j];
            }            
        }
        std::cout << std::endl;
    }

    // Belleği temizle
    for (int i = 0; i < m; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    
}

int main()
{    
    // Türkçe karakter veri uygunluğu
    std::setlocale(LC_ALL, "tr_TR.UTF-8");
    FileEditor::FileBuilder fb;

    // okunan verinin unicode değerleri tutan yapı
    std::wstring* rs = new std::wstring();
    std::pair<std::wstring, int>* reshaped = new std::pair<std::wstring, int>(); // okunan verinin reshaped halini ve yeni size ı tutan yapı.

    // dosya okuma işlemleri
    *rs = fb.Read("metin.txt");

    // verinin reshape ve size işlemleri
    *reshaped = ReshapeAndFindSize(*rs);
    std::cout << "\nbosluklar silinmis ve resize edilmis hali ve uzunlugu(l):\n";
    std::wcout << reshaped->first << "," << reshaped->second << std::endl;

    std::pair<int,int> cols = FindMatrixCols(reshaped->second);
    std::cout << "\narray matrisleri:\n";
    std::cout << cols.first << "," << cols.second << std::endl;

    // 2 boyutlu matris'in yazdırılması
    PrintMatrix(reshaped->first, cols.first, cols.second);

}

