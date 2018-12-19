#include "stdafx.h"
#include "MilitaryCharacteristics.h"

namespace AircraftCarrierGroup {

	//Конструкторы
	MilitaryCharacteristics::MilitaryCharacteristics(int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp = 0) {
		Speed = SpeedTmp;
		FuelReserve = FuelReserveTmp;
		FuelConsumption = FuelConsumptionTmp;
	}

	//------------------------------------------------------------

	//Копирующий конструктор
	MilitaryCharacteristics::MilitaryCharacteristics(const MilitaryCharacteristics& Military) {
		Speed = Military.Speed;
		FuelReserve = Military.FuelReserve;
		FuelConsumption = Military.FuelConsumption;
	}

	//------------------------------------------------------------

	//Входной/выходной потоки
	std::ostream& operator << (std::ostream& os, const MilitaryCharacteristics& Military) {
		os << "   **Military Characteristics**" << std::endl;
		os << "   Speed --> " << Military.Speed << std::endl;
		os << "   Fuel Reserve --> " << Military.FuelReserve << std::endl;
		os << "   Fuel Consumption --> " << Military.FuelConsumption << std::endl;
		os << std::endl;
		return os;
	}

	//------------------------------------------------------------

	std::istream& operator >> (std::istream& is, MilitaryCharacteristics& Military) {
		std::cout << "   Speed --> ";
		is >> Military.Speed;
		std::cout << "   Fuel Reserve --> ";
		is >> Military.FuelReserve;
		std::cout << "   Fuel Consumption --> ";
		is >> Military.FuelConsumption;
		if (is.good())
			return is;
		else {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			return is;
		}
	}

	//------------------------------------------------------------

	//Потоковый ввод/вывод из файла
	std::ifstream& operator >> (std::ifstream& is, MilitaryCharacteristics& Military) {
		is.read((char*) &Military.Speed, sizeof(int));
		is.read((char*) &Military.FuelReserve, sizeof(int));
		is.read((char*) &Military.FuelConsumption, sizeof(int));
		return is;
	}

	//------------------------------------------------------------

	std::ofstream& operator << (std::ofstream& os, const MilitaryCharacteristics& Military) {
		os.write((char*) &Military.Speed, sizeof(int));
		os.write((char*) &Military.FuelReserve, sizeof(int));
		os.write((char*) &Military.FuelConsumption, sizeof(int));
		return os;
	}

	//------------------------------------------------------------

	//Перегруженные операторы
	MilitaryCharacteristics& MilitaryCharacteristics::operator = (const MilitaryCharacteristics& Military) {
		Speed = Military.Speed;
		FuelReserve = Military.FuelReserve;
		FuelConsumption = Military.FuelConsumption;
		return *this;
	}

	//------------------------------------------------------------

	MilitaryCharacteristics& MilitaryCharacteristics::operator = (MilitaryCharacteristics&& Military) {
		int SpeedTmp = Military.Speed;
		Military.Speed = Speed;
		Speed = SpeedTmp;
		//---------------------------------
		int FuelReserveTmp = Military.FuelReserve;
		Military.FuelReserve = FuelReserve;
		FuelReserve = FuelReserveTmp;
		//---------------------------------
		int FuelConsumptionTmp = Military.FuelConsumption;
		Military.FuelConsumption = FuelConsumption;
		FuelConsumption = FuelConsumptionTmp;
		return *this;
	}

}