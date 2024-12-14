#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>

namespace FileEditor {
	// dosya okuma - yazma i�lemlerinin implemente edildi�i yer.
	class FileBuilder
	{
	public:
		FileBuilder();
		
		// kullan�c�dan ald��� dosya ad�n�na g�re dosyay� okur.
		// wstring tipi t�rk�e karakter okuma ve size i�lemlerini do�ru bulma i�in gerekli
		std::wstring Read(std::string filename) {	

			std::wifstream readedFile(filename);
			readedFile.imbue(std::locale("tr_TR.UTF-8")); // okunan dosya i�eri�ini tr utf-8 format�na set ediyoruz.

			if (readedFile.is_open()) {
				std::wstring* data = new std::wstring();
				std::cout << "Okunan dosya icerigi:\n";
				while (std::getline(readedFile, *data)) { // Sat�r sat�r okuma
					std::wcout << *data << "\n";
				}
				readedFile.close(); // Dosya kapat�l�r

				return *data;
			}
			else {
				std::cerr << "dosya okunamadi.\n";
				exit(0);
			}
		}


	};

	FileBuilder::FileBuilder()
	{
	}

}