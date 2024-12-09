#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "FileEditor.h"

namespace StandartString
{
	// std::string operatör iþlemlerinin implemente edildiði yer.
	class StringBuilder
	{
		std::string stringVal;

	public:
		StringBuilder();
		StringBuilder(std::string s) {
			stringVal = s;
			_undo = stringVal;
		};
		// string deðiþkeni ekrana yazdýrýr.
		void Print()
		{
			std::cout << stringVal << std::endl;
		}
		// deðiþkenin ilk k adet karakteri yazýlýr
		void Print(int k) {
			if (!stringVal.empty()) {
				std::cout << stringVal.substr(0, k);
			}
			else {
				std::cerr << "deger bos." << std::endl;
			}
			
		}
		// strik deðiþkene ekleme yapar.
		void Add(std::string input) {
			_undo = stringVal;
			stringVal.append(input);
			Print();
		}
		// string deðiþkende sondan k kadar elemaný siler.
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

		// bir önceki yapýlan deðiþiklikleri geri alýr
		void Undo() {
			stringVal = _undo;
			Print();
		}

		// string deðiþkenin içindeki veriye bir .txt dosyasýna yazar.
		void Save(std::string filename) {
			FileEditor::FileBuilder fb;
			fb.Write(filename, stringVal);
			std::cout << "data saved succesfully" << std::endl;
		}

		~StringBuilder() { std::cout << "destructor method executed" << std::endl; }

	private:
		// undo iþlemleri için string deðiþkeninin önceki deðerini tutar.
		std::string _undo;
	};

	StringBuilder::StringBuilder()
	{
	}


}

