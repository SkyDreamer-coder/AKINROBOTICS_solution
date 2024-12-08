#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace FileEditor {
	// dosya yazma i�lemlerinin implemente edildi�i yer.
	class FileBuilder
	{
	public:
		FileBuilder();
		// kullan�c�dan ald��� veri ve dosya ad�n� kullanarak yazma i�lemi yapar.
		void Write(std::string filename, std::string input)
		{
			std::ofstream writedFile(filename);
			if (writedFile.is_open()) {
				writedFile << input;
				writedFile.close();
			}
			else
			{
				std::cerr << "dosyaya yazilamadi:\n";
			}
		}
		// kullan�c�dan ald��� dosya ad�n�na g�re dosyay� okur.
		void Read(std::string filename) {
			std::ifstream readedFile(filename);
			if (readedFile.is_open()) {
				std::string data;
				std::cout << "Dosya icerigi:\n";
				while (std::getline(readedFile, data)) { // Sat�r sat�r okuma
					std::cout << data << "\n";
				}
				readedFile.close(); // Dosya kapat�l�r
			}
			else {
				std::cerr << "dosya okunamadi.\n";
			}
		}			


	};

	FileBuilder::FileBuilder()
	{
	}

}