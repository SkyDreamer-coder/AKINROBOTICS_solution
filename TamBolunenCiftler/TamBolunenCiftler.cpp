// TamBolunenCiftler.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
// Umut Can Altıntaş 07/12/2024

//toplamları k tam sayısına tam bölünebilen dizi indis çiftleri bulma [(i<j) olma şartı ile]

#include <iostream>
#include <random>
#include <list>
#include <utility> // listeyi küme haline alıyoruz

// random sayı generate etme
static int randomNumberGenerator()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> generateNumber(-999, 1000);

	return generateNumber(gen);
}

static std::list<std::pair<int, int>> findDivisibleByDivisor(int *arr, int size, int divisor) {
	
	std::list<std::pair<int, int>> indices;

	for (int i = 0; i < size; i++) {
		for (int j = i; j < size; j++) { // j indisi i den başlıyor valide etmeye gerek yok.
			if (j != i && (arr[i] + arr[j]) % divisor == 0) {
				indices.push_back(std::make_pair(i, j)); // listeyi küme haline alıyoruz.
			}				
		}
	}
	return indices;
}


int main()
{
	int n, k;

	//bölünebilen indisleri tutan liste.
	std::list<std::pair<int, int>> divisibles;

	// array boyutu
	std::cout << "array boyutunu giriniz: (n) \n";
	std::cin >> n;

	// bölme değeri
	std::cout << "bolmek istediginiz sayiyi giriniz: (k)\n";
	std::cin >> k;

	int* arr = new int[n];	

	// random veri oluşturulup array a atanması.
	for (int i = 0; i < n; i++) {
		arr[i] = randomNumberGenerator();
	}

	// bölünebilen indislerin alınması
	divisibles = findDivisibleByDivisor(arr, n, k);

	std::cout << "array boyutu(n): " << n << " bolunen sayi(k): " << k << "\n\n";
	// oluşturulan array ın yazdırılması
	std::cout << "olusturulan array: \n";

	for (int i = 0; i < n; i++) {
		std::cout << arr[i] << std::endl;
	}
	// k'ya tam bölünebilen indislerin yazdırılması
	std::cout << "\nk'ya tam bolunebilen indisler:\n\n";
	for (const auto& idx : divisibles) {
		std::cout << "(" << idx.first << ", " << idx.second << ")\n";
	}

	return 0;
}


