// HedefKonumMesafesi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

// Umut Can Altıntaş 06/12/2024

#include <iostream>
#include<random>
#include<list>

// rastgele sayı üretme (gezilecek point ler için)
static int NumberGenarator()
{
	std::random_device rd;
	std::mt19937 gen(rd());
	std::uniform_int_distribution<> generateTravelDistance(6, 10);

	return generateTravelDistance(gen);
}

// cirle yapısı
struct Circle {

	int numberOfPoints = 21;

};

// robot yapısı 
struct Robot {

	int numberOfTravel = 10;

	int currentPoint = 0;
	Circle* cr = new Circle();

	int Move(int position, int step) {

		return ((position + step)) % cr->numberOfPoints;
	}
};


int main()
{
	Robot* rb = new Robot();

	// ziyaret edilen pointler
	std::list<int> visitedPoints;

	std::cout << "Mini Ada robot gezisi baslatiliyor...\n";

	// robot gezdirme
	for (int i = 0; i < rb->numberOfTravel; i++) {

		// rastgele robot adım sayısı belirleme
		int step = NumberGenarator();

		rb->currentPoint = rb->Move(rb->currentPoint, step);

		if (visitedPoints.empty()) {
			visitedPoints.push_back(rb->currentPoint);
		}
		else
		{
			int target = rb->currentPoint;
			// aynı noktaya gelme validasyonu
			bool found = std::any_of(visitedPoints.begin(), visitedPoints.end(), [target](int elem) {
				return elem == target;
				});
			
			if (!found) {
				visitedPoints.push_back(rb->currentPoint);
			}
			else {		
				rb->currentPoint++;
				visitedPoints.push_back(rb->currentPoint);				
			}
		}
	}

	// ziyaret edilen noktaları yazdırma
	std::cout << "Robotun ugradigi noktalar: \n";
	for (int elem : visitedPoints) {
		std::cout << elem << " ";
	}
	std::cout << std::endl;

	return 0;

}
