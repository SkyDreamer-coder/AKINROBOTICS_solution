#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <codecvt>

namespace FileEditor {
	// dosya okuma - yazma iþlemlerinin implemente edildiði yer.
	class FileBuilder
	{
	public:
		FileBuilder();
		
		// kullanýcýdan aldýðý dosya adýnýna göre dosyayý okur.
		// wstring tipi türkçe karakter okuma ve size iþlemlerini doðru bulma için gerekli
		std::wstring Read(std::string filename) {	

			std::wifstream readedFile(filename);
			readedFile.imbue(std::locale("tr_TR.UTF-8")); // okunan dosya içeriðini tr utf-8 formatýna set ediyoruz.

			if (readedFile.is_open()) {
				std::wstring* data = new std::wstring();
				std::cout << "Okunan dosya icerigi:\n";
				while (std::getline(readedFile, *data)) { // Satýr satýr okuma
					std::wcout << *data << "\n";
				}
				readedFile.close(); // Dosya kapatýlýr

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