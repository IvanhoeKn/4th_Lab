#include "pch.h"
#include "Weapon.h"

namespace AircraftСarrierGroup {

	//Конструкторы
	Weapon::Weapon(std::string Weapon, std::string Munition, int RateFireTmp, int QuantityAmmunitionTmp, int DamageTmp) {
		NameWeapon = Weapon;
		NameAmmunition = Munition;
		RateFire = RateFireTmp;
		QuantityAmmunition = QuantityAmmunitionTmp;
		Damage = DamageTmp;
	}

	//------------------------------------------------------------

	//Копирующий конструктор
	Weapon::Weapon(const Weapon& Arsenal) {
		NameWeapon = Arsenal.NameWeapon;
		NameAmmunition = Arsenal.NameAmmunition;
		RateFire = Arsenal.RateFire;
		QuantityAmmunition = Arsenal.QuantityAmmunition;
		Damage = Arsenal.Damage;
	}

	//------------------------------------------------------------

	//Входной/выходной потоки
	std::ostream& operator << (std::ostream& os, const Weapon& Arsenal) {
		os << " **Weapon**" << std::endl;
		os << " Characteristics:" << std::endl;
		os << " Name of the Weapon: \"" << Arsenal.NameWeapon << "\"" << std::endl;
		os << " Name of the Ammunition: \"" << Arsenal.NameAmmunition << "\"" << std::endl;
		os << " Rate of Fire --> " << Arsenal.RateFire << std::endl;
		os << " Damage --> " << Arsenal.Damage << std::endl;
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
			return is;
		}
	}

	//------------------------------------------------------------

	//Перегруженные операторы
	Weapon& Weapon::operator = (const Weapon& Arsenal) {
		NameWeapon = Arsenal.NameWeapon;
		NameAmmunition = Arsenal.NameAmmunition;
		RateFire = Arsenal.RateFire;
		Damage = Arsenal.Damage;
		return *this;
	}

	//------------------------------------------------------------

	Weapon& Weapon::operator = (Weapon&& Arsenal) {
		std::string NameWeaponTmp = Arsenal.NameWeapon;
		Arsenal.NameWeapon = NameWeapon;
		NameWeapon = NameWeaponTmp;

		std::string NameAmmunitionTmp = Arsenal.NameAmmunition;
		Arsenal.NameAmmunition = NameAmmunition;
		NameAmmunition = NameAmmunitionTmp;

		int RateFireTmp = Arsenal.RateFire;
		Arsenal.RateFire = RateFire;
		RateFire = RateFireTmp;

		int DamageTmp = Arsenal.Damage;
		Arsenal.Damage = Damage;
		Damage = DamageTmp;
		return *this;
	}

}