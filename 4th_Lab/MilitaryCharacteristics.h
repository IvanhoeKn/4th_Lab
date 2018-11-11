#ifndef _WEAPON_H_
#define _CHARACTERISTICS_H_
#include <iostream>

namespace AircraftСarrierGroup
{

	class MilitaryCharacteristics {
	protected:
		int Speed;
		int FuelReserve;
		int FuelConsumption;
	public:
		//Конструкторы
		MilitaryCharacteristics() : Speed(0), FuelReserve(0), FuelConsumption(0) {};

		MilitaryCharacteristics(int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp = 0) {
			Speed = SpeedTmp;
			FuelReserve = FuelReserveTmp;
			FuelConsumption = FuelConsumptionTmp;
		};

		//Деструктор
		~MilitaryCharacteristics() {
			Speed = 0;
			FuelReserve = 0;
			FuelConsumption = 0;
		};

		//Другие методы класса
		MilitaryCharacteristics& SetWeapon(int SpeedTmp) { Speed = SpeedTmp; };

		MilitaryCharacteristics& SetMunition(int FuelReserveTmp) { FuelReserve = FuelReserveTmp; };

		MilitaryCharacteristics& SetRateFire(int FuelConsumptionTmp) { FuelConsumption = FuelConsumptionTmp; };

		int GetSpeed() const { return Speed; };

		int GetFuelReserve() const { return FuelReserve; };

		int GetFuelConsumption() const { return FuelConsumption; };

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream&, const MilitaryCharacteristics&);

		friend std::istream& operator >> (std::istream&, MilitaryCharacteristics&);
	};
}
#endif