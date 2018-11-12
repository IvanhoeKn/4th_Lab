#ifndef _AIRCRAFT_H_
#define _AIRCRAFT_H_
#include <iostream>
#include "Weapon.h"
#include "MilitaryCharacteristics.h"

namespace AircraftСarrierGroup
{

	class Aircraft : public MilitaryCharacteristics {
	private:
		static const int QUOTA = 3;
		int Amount;
		Weapon *Arr;
	public:
		//Конструкторы
		Aircraft() : MilitaryCharacteristics(), Amount(0), Arr(nullptr) {};

		Aircraft(int SpeedTmp, int FuelReserveTmp, int FuelConsumptionTmp) : Amount(0), Arr(nullptr) {
			MilitaryCharacteristics(SpeedTmp, FuelConsumptionTmp, FuelReserveTmp);
		};

		Aircraft(int SpeedTmp, int FuelReserveTmp, int FuelConsumptionTmp, int AmountTmp = 0, Weapon* ArrTmp = nullptr) {
			MilitaryCharacteristics(SpeedTmp, FuelConsumptionTmp, FuelReserveTmp);
			if (Amount > QUOTA)
				throw std::exception("Exceeded the maximum number of weapons\n");
			else {
				Amount = AmountTmp;
				Arr = new Weapon[Amount];
				for (int i = 0; i < Amount; i++)
					Arr[i] = ArrTmp[i];
			}
		};

		Aircraft(MilitaryCharacteristics& Military, int AmountTmp = 0, Weapon* ArrTmp = nullptr) {
			Speed = Military.GetSpeed();
			FuelReserve = Military.GetFuelReserve();
			FuelConsumption = Military.GetFuelConsumption();
			if (Amount > QUOTA)
				throw std::exception("Exceeded the maximum number of weapons\n");
			else {
				Amount = AmountTmp;
				Arr = new Weapon[Amount];
				for (int i = 0; i < Amount; i++)
					Arr[i] = ArrTmp[i];
			}
		};
		
		Aircraft(const Aircraft& Plane) {
			MilitaryCharacteristics(Plane.Speed, Plane.FuelConsumption, Plane.FuelReserve);
			Amount = Plane.Amount;
			for (int i = 0; i < Amount; i++)
				Arr[i] = Plane.Arr[i];
		};

		Aircraft(Aircraft&& Plane) {
			MilitaryCharacteristics(Plane.Speed, Plane.FuelConsumption, Plane.FuelReserve);
			Amount = Plane.Amount;
			Arr = Plane.Arr;
		};

		//Деструктор
		~Aircraft() {
			Amount = 0;
			delete [] Arr;
		};

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream&, const Aircraft&);

		friend std::istream& operator >> (std::istream&, Aircraft&);

		//Перегруженные операторы
		Aircraft& operator = (const Aircraft& Plane);

		Aircraft& operator = (Aircraft&& Plane);
	};
}
#endif
