// MetinDuzenleyici.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Umut Can Altıntaş 08/12/2024

// Metin Düzenleyici

#include <iostream>
#include <vector>
#include <cstdlib>
#include "StringBuilder.h"
#include "FileEditor.h"

// kullanıcı menü yapısı
static void Menu() {
    std::cout << "\nLutfen komut giriniz\n";
    std::cout << "append (a)\n";
    std::cout << "delete (d)\n";
    std::cout << "print (p)\n";
    std::cout << "undo (u)\n";
    std::cout << "save (s)\n";
    std::cout << "read (r)\n";
    std::cout << "exit (e)\n";
}

int main()
{
    // program çalıştırıldığında boş bir custom stringbuilder değeri oluşturur.
    StandartString::StringBuilder sb;

    FileEditor::FileBuilder fb;
    std::string saveFileName, readFileName;
    std::string input;

    std::cout << "Metin duzenlemeye hos geldiniz." << std::endl;

    char command;     
    while (true) {

        Menu();
        std::cin >> command;

        switch (command)
        {
        case 'a':
            std::cout << "girmek istediginiz metni yazin: ";
            // std::cin fonksiyonunun '\n' değerini ignore eder.
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

            std::getline(std::cin, input);
            sb.Add(input);

            break;
        // delete işlemi
        case 'd':
            int k;
            std::cout << "sondan kac karakter silmek istiyorsunuz: ";
            std::cin >> k;
            sb.Delete(k);

            break;
        // print işlemi
        case 'p':
            int l;
            std::cout << "kac karaktere kadar yazdirmak istiyorsunuz: ";
            std::cin >> l;
            sb.Print(l);

            break;
        // undo işlemi
        case 'u':
            sb.Undo();

            break;
        // save işlemi
        case 's':
            std::cout << "kaydedilecek dosya adini girin: (orn. (Metinler.txt))\n";
            std::cin >> saveFileName;
            sb.Save(saveFileName);

            break;
        // read işlemi
        case 'r':
            std::cout << "okunacak dosya adini girin: (orn. (Metinler.txt))\n";
            std::cin >> readFileName;
            sb.Add(fb.Read(readFileName));

            break;
        // program sonlandırma işlemi.
        case 'e':
            std::cout << "program kapatiliyor." << std::endl;
            exit(0);
            break;
        default:
            break;
        }
    }


    return 0;
}

