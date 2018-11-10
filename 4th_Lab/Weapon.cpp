#include "pch.h"
#include "Weapon.h"

#include "Weapon.h"

namespace AircraftÑarrierGroup {

	//Âõîäíîé/âûõîäíîé ïîòîêè
	std::ostream& operator << (std::ostream& os, const Weapon& Arsenal) {
		os << " **Weapon**" << std::endl;
		os << " Characteristics:" << std::endl;
		os << " Name of the Weapon: \"" << Arsenal.NameWeapon << "\"" << std::endl;
		os << " Name of the Ammunition: \"" << Arsenal.NameAmmunition << "\"" << std::endl;
		os << " Rate of Fire --> " << Arsenal.RateFire << std::endl;
		os << " Damage --> " << Arsenal.Damage << std::endl;
		os << std::endl;
		return os;
	}

	//------------------------------------------------------------

	std::istream& operator >> (std::istream& is, Weapon& Arsenal) {
		std::cout << " Name of the Weapon: ";
		is >> Arsenal.NameWeapon;
		std::cout << " Name of the Ammunition: ";
		is >> Arsenal.NameAmmunition;
		std::cout << " Rate of Fire --> ";
		is >> Arsenal.RateFire;
		std::cout << " Damage --> ";
		is >> Arsenal.Damage;
		if (is.good())
			return is;
		else {
			is.clear();
			is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}
	}

}