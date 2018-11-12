#include "pch.h"
#include "Aircraft.h"

namespace AircraftСarrierGroup
{

	//Входной/выходной потоки
	std::ostream& operator << (std::ostream& os, const Aircraft& Plane) {
		os << " **Airplane**" << std::endl;
		os << " Speed --> " << Plane.Speed << std::endl;
		os << " Fuel Reserve --> " << Plane.FuelReserve << std::endl;
		os << " Fuel Consumption --> " << Plane.FuelConsumption << std::endl;
		os << "		**Info about Weapon of this Airplane**" << std::endl;
		if (Plane.Amount == 0)
			os << "		No weapons on this plane!" << std::endl;
		else {
			for (int i = 0; i < Plane.Amount; i++)
				os << "		" << i + 1 << "th " << Plane.Arr[i];
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
		else
			for (int i = 0; i < Plane.Amount; i++)
				is >> Plane.Arr[i];
		if (is.good())
			return is;
		else {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

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
	};

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
	};

}