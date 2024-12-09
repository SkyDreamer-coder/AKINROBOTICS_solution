#pragma once
#include <iostream>
#include <fstream>
#include <string>

namespace FileEditor {
	// dosya yazma iþlemlerinin implemente edildiði yer.
	class FileBuilder
	{
	public:
		FileBuilder();
		// kullanýcýdan aldýðý veri ve dosya adýný kullanarak yazma iþlemi yapar.
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
		// kullanýcýdan aldýðý dosya adýnýna göre dosyayý okur.
		std::string Read(std::string filename) {
			std::string val;
			std::ifstream readedFile(filename);
			if (readedFile.is_open()) {
				std::string data;
				std::cout << "Dosya icerigi:\n";
				while (std::getline(readedFile, data)) { // Satýr satýr okuma
					val.append(data);
					std::cout << data << "\n";
				}
				readedFile.close(); // Dosya kapatýlýr
				return val;
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