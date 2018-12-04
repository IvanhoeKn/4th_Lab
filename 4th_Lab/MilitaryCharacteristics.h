#ifndef _CHARACTERISTICS_H_
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
		MilitaryCharacteristics() : Speed(0), FuelReserve(0), FuelConsumption(0) {}

		MilitaryCharacteristics(int, int, int);

		//Копирующий конструктор
		MilitaryCharacteristics(const MilitaryCharacteristics&);

		//---------------------------------

		//Деструктор
		virtual ~MilitaryCharacteristics() {}

		//---------------------------------

		//Другие методы класса
		MilitaryCharacteristics& SetSpeed(int SpeedTmp) { Speed = SpeedTmp; return *this; }

		MilitaryCharacteristics& SetFuelReserve(int FuelReserveTmp) { FuelReserve = FuelReserveTmp; return *this; }

		MilitaryCharacteristics& SetFuelConsumption(int FuelConsumptionTmp) { FuelConsumption = FuelConsumptionTmp;  return *this; }

		int GetSpeed() const { return Speed; }

		int GetFuelReserve() const { return FuelReserve; }

		int GetFuelConsumption() const { return FuelConsumption; }

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream&, const MilitaryCharacteristics&);

		friend std::istream& operator >> (std::istream&, MilitaryCharacteristics&);

		//Перегруженные операторы
		MilitaryCharacteristics& operator = (const MilitaryCharacteristics& Military);

		MilitaryCharacteristics& operator = (MilitaryCharacteristics&& Military);
	};
}
#endif