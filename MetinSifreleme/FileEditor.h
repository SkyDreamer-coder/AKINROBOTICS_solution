#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace FileEditor {
	// dosya okuma - yazma iþlemlerinin implemente edildiði yer.
	class FileBuilder
	{
	public:
		FileBuilder();
		
		// kullanýcýdan aldýðý dosya adýnýna göre dosyayý okur.
		std::string Read(std::string filename) {

			std::string* val = new std::string();

			std::ifstream readedFile(filename, std::ios::in);
			if (readedFile.is_open()) {
				std::string data;
				std::cout << "Okunan dosya icerigi:\n";
				while (std::getline(readedFile, data)) { // Satýr satýr okuma
					val->append(data);
					std::cout << data << "\n";
				}
				readedFile.close(); // Dosya kapatýlýr

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