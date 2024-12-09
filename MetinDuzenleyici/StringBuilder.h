#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "FileEditor.h"

namespace StandartString
{
	// std::string operat�r i�lemlerinin implemente edildi�i yer.
	class StringBuilder
	{
		std::string stringVal;

	public:
		StringBuilder();
		StringBuilder(std::string s) {
			stringVal = s;
			_undo = stringVal;
		};
		// string de�i�keni ekrana yazd�r�r.
		void Print()
		{
			std::cout << stringVal << std::endl;
		}
		// de�i�kenin ilk k adet karakteri yaz�l�r
		void Print(int k) {
			if (!stringVal.empty()) {
				std::cout << stringVal.substr(0, k);
			}
			else {
				std::cerr << "deger bos." << std::endl;
			}
			
		}
		// strik de�i�kene ekleme yapar.
		void Add(std::string input) {
			_undo = stringVal;
			stringVal.append(input);
			Print();
		}
		// string de�i�kende sondan k kadar eleman� siler.
		void Delete(int n) {
			_undo = stringVal;
			if (!stringVal.empty()) {
				if (n > stringVal.size())
				{
					std::cerr << "index boyutu gecildi." << std::endl;
				}
				else
				{
					stringVal.erase(stringVal.size() - n);
					Print();
				}				
			}
			else {
				std::cerr << "deger zaten bos" << std::endl;
			}
		}

		// bir �nceki yap�lan de�i�iklikleri geri al�r
		void Undo() {
			stringVal = _undo;
			Print();
		}

		// string de�i�kenin i�indeki veriye bir .txt dosyas�na yazar.
		void Save(std::string filename) {
			FileEditor::FileBuilder fb;
			fb.Write(filename, stringVal);
			std::cout << "data saved succesfully" << std::endl;
		}

		~StringBuilder() { std::cout << "destructor method executed" << std::endl; }

	private:
		// undo i�lemleri i�in string de�i�keninin �nceki de�erini tutar.
		std::string _undo;
	};

	StringBuilder::StringBuilder()
	{
	}


}

