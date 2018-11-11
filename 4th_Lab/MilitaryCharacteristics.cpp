#include "pch.h"
#include "MilitaryCharacteristics.h"

namespace AircraftÑarrierGroup
{

	//Âõîäíîé/âûõîäíîé ïîòîêè
	std::ostream& operator << (std::ostream& os, const MilitaryCharacteristics& Military) {
		os << " **Military Characteristics**" << std::endl;
		os << " Speed --> " << Military.Speed << std::endl;
		os << " Fuel Reserve --> " << Military.FuelReserve << std::endl;
		os << " Fuel Consumption --> " << Military.FuelConsumption << std::endl;
		os << std::endl;
		return os;
	}

	//------------------------------------------------------------

	std::istream& operator >> (std::istream& is, MilitaryCharacteristics& Military) {
		std::cout << " Speed --> ";
		is >> Military.Speed;
		std::cout << " Fuel Reserve --> ";
		is >> Military.FuelReserve;
		std::cout << " Fuel Consumption --> ";
		is >> Military.FuelConsumption;
		if (is.good())
			return is;
		else {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}
}