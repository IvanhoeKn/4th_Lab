#include "stdafx.h"
#include "Aircraft.h"

namespace AircraftСarrierGroup {

	//Конструкторы
	Aircraft::Aircraft(int SpeedTmp, int FuelReserveTmp, int FuelConsumptionTmp, int AmountTmp, Weapon* ArrTmp) : MilitaryCharacteristics(SpeedTmp, FuelConsumptionTmp, FuelReserveTmp) {
		if (Amount > QUOTA) {
			Amount = 0;
			Arr = nullptr;
			throw std::exception("Exceeded the maximum number of weapons\n");
		}
		else {
			Amount = AmountTmp;
			Arr = new Weapon[Amount];
			for (int i = 0; i < Amount; i++)
				Arr[i] = ArrTmp[i];
		}
	}

	Aircraft::Aircraft(const MilitaryCharacteristics& Military, int AmountTmp = 0, Weapon* ArrTmp = nullptr) : MilitaryCharacteristics(Military) {
		if (Amount > QUOTA) {
			Amount = 0;
			Arr = nullptr;
			throw std::exception("Exceeded the maximum number of weapons\n");
		}
		else {
			Amount = AmountTmp;
			Arr = new Weapon[Amount];
			for (int i = 0; i < Amount; i++)
				Arr[i] = ArrTmp[i];
		}
	}

	//------------------------------------------------------------

	//Копирующий конструктор
	Aircraft::Aircraft(const Aircraft& Plane) : MilitaryCharacteristics(Plane.Speed, Plane.FuelConsumption, Plane.FuelReserve) {
		Amount = Plane.Amount;
		Arr = new Weapon[Amount];
		for (int i = 0; i < Amount; i++)
			Arr[i] = Plane.Arr[i];
	}

	//------------------------------------------------------------

	//Входной/выходной потоки
	std::ostream& operator << (std::ostream& os, const Aircraft& Plane) {
		os << " **Airplane**" << std::endl;
		os << " Speed --> " << Plane.Speed << std::endl;
		os << " Fuel Reserve --> " << Plane.FuelReserve << std::endl;
		os << " Fuel Consumption --> " << Plane.FuelConsumption << std::endl;
		os << " **Info about Weapon of this Airplane**" << std::endl;
		if (Plane.Amount == 0)
			os << "    No weapons on this plane!" << std::endl;
		else {
			for (int i = 0; i < Plane.Amount; i++)
				os << "  " << i + 1 << "th " << Plane.Arr[i];
		}
		os << std::endl;
		return os;
	}

	//------------------------------------------------------------

	std::istream& operator >> (std::istream& is, Aircraft& Plane) {
		std::cout << " Speed --> ";
		is >> Plane.Speed;
		std::cout << " Fuel Reserve --> ";
		is >> Plane.FuelReserve;
		std::cout << " Fuel Consumption --> ";
		is >> Plane.FuelConsumption;
		std::cout << " Amount of Weapons --> ";
		is >> Plane.Amount;
		if (Plane.Amount < 0 || Plane.Amount > 3)
			is.setstate(std::ios::failbit);
		else{
			Plane.Arr = new Weapon[Plane.Amount];
			for (int i = 0; i < Plane.Amount; i++) {
				std::cout << " First Weapon:\n";
				is >> Plane.Arr[i];
			}
		}
		if (!is.good()) {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
		return is;
	}

	//------------------------------------------------------------

	//Потоковый ввод/вывод из файла
	std::ifstream& operator >> (std::ifstream& is, Aircraft& Plane) {
		MilitaryCharacteristics Military;
		is >> Military;
		Plane.Speed = Military.GetSpeed();
		Plane.FuelReserve = Military.GetFuelReserve();
		Plane.FuelConsumption = Military.GetFuelConsumption();
		is.read((char*) &Plane.Amount, sizeof(int));
		Plane.Arr = new Weapon[Plane.Amount];
		for (int i = 0; i < Plane.Amount; i++)
			is >> Plane.Arr[i];
		return is;
	}

	//------------------------------------------------------------

	std::ofstream& operator << (std::ofstream& os, const Aircraft& Plane) {
		MilitaryCharacteristics Military(Plane);
		os << Military;
		os.write((char*) &Plane.Amount, sizeof(int));
		for (int i = 0; i < Plane.Amount; i++)
			os << Plane.Arr[i];
		return os;
	}

	//------------------------------------------------------------

	//Перегруженные операторы
	Aircraft& Aircraft::operator = (const Aircraft& Plane) {
		Speed = Plane.Speed;
		FuelReserve = Plane.FuelReserve;
		FuelConsumption = Plane.FuelConsumption;
		Amount = Plane.Amount;
		Arr = new Weapon[Amount];
		for (int i = 0; i < Amount; i++)
			Arr[i] = Plane.Arr[i];
		return *this;
	}

	//------------------------------------------------------------

	Aircraft& Aircraft::operator = (Aircraft&& Plane) {
		int SpeedTmp = Plane.Speed;
		Plane.Speed = Speed;
		Speed = SpeedTmp;

		int FuelReserveTmp = Plane.FuelReserve;
		Plane.FuelReserve = FuelReserve;
		FuelReserve = FuelReserveTmp;

		int FuelConsumptionTmp = Plane.FuelConsumption;
		Plane.FuelConsumption = FuelConsumption;
		FuelConsumption = FuelConsumptionTmp;

		int AmountTmp = Plane.Amount;
		Plane.Amount = Amount;
		Amount = AmountTmp;

		Weapon *ArrTmp = Plane.Arr;
		Plane.Arr = Arr;
		Arr = ArrTmp;
		return *this;
	}

	//------------------------------------------------------------

	Weapon& Aircraft::getWeaponAircraft(int Number) const {
		if (Number < 0 || Number > Amount)
			throw std::exception("Invalid Number of Weapon\n");
		else
			return Arr[Number - 1];
	}

}