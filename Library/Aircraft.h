#ifndef _AIRCRAFT_H_
#define _AIRCRAFT_H_
#include <iostream>
#include <fstream>
#include "Weapon.h"
#include "MilitaryCharacteristics.h"

namespace AircraftСarrierGroup
{

	class Aircraft : public MilitaryCharacteristics {
	protected:
		static const int QUOTA = 3;
		int Amount;
		Weapon *Arr;
	public:
		//Конструкторы
		Aircraft() : MilitaryCharacteristics(), Amount(0), Arr(nullptr) {}

		Aircraft(int SpeedTmp, int FuelReserveTmp, int FuelConsumptionTmp) : MilitaryCharacteristics(SpeedTmp, FuelConsumptionTmp, FuelReserveTmp), Amount(0), Arr(nullptr) {}

		Aircraft(int, int, int, int, Weapon*);

		Aircraft(const MilitaryCharacteristics&, int, Weapon*);
		
		//Копирующий конструктор
		Aircraft(const Aircraft& Plane);

		//---------------------------------

		//Деструктор
		~Aircraft() {
			delete [] Arr;
		};

		//---------------------------------

		//Другие методы класса
		Aircraft* operator * () {
			return this;
		}

		Weapon& getWeaponAircraft(int) const;

		int getAmountWeapon() const { return Amount; }

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream&, const Aircraft&);

		friend std::istream& operator >> (std::istream&, Aircraft&);

		//Потоковый ввод/вывод из файла
		friend std::ofstream& operator << (std::ofstream&, const Aircraft&);

		friend std::ifstream& operator >> (std::ifstream&, Aircraft&);

		//Перегруженные операторы
		Aircraft& operator = (const Aircraft& Plane);

		Aircraft& operator = (Aircraft&& Plane);
	};
}
#endif
