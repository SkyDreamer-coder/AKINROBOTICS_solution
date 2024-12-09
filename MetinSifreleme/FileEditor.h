#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace FileEditor {
	// dosya okuma - yazma i�lemlerinin implemente edildi�i yer.
	class FileBuilder
	{
	public:
		FileBuilder();
		
		// kullan�c�dan ald��� dosya ad�n�na g�re dosyay� okur.
		std::string Read(std::string filename) {

			std::string* val = new std::string();

			std::ifstream readedFile(filename, std::ios::in);
			if (readedFile.is_open()) {
				std::string data;
				std::cout << "Okunan dosya icerigi:\n";
				while (std::getline(readedFile, data)) { // Sat�r sat�r okuma
					val->append(data);
					std::cout << data << "\n";
				}
				readedFile.close(); // Dosya kapat�l�r

				return *val;
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