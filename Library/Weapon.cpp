#include "stdafx.h"
#include "Weapon.h"

namespace AircraftCarrierGroup {

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
		os << " QuantityAmmunition --> " << Arsenal.QuantityAmmunition << std::endl;
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
		std::cout << " QuantityAmmunition --> ";
		is >> Arsenal.QuantityAmmunition;
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

	//Потоковый ввод/вывод из файла
	std::ifstream& operator >> (std::ifstream& is, Weapon& Arsenal) {
		int StrLn;
		char NameWpBuf[80] = "";
		char NameAmmoBuf[80] = "";
		is.read((char*) &StrLn, sizeof(int));
		is.read(NameWpBuf, StrLn);
		Arsenal.NameWeapon = NameWpBuf;
		is.read((char*) &StrLn, sizeof(int));
		is.read(NameAmmoBuf, StrLn);
		Arsenal.NameAmmunition = NameAmmoBuf;
		is.read((char*) &Arsenal.RateFire, sizeof(int));
		is.read((char*) &Arsenal.QuantityAmmunition, sizeof(int));
		is.read((char*) &Arsenal.Damage, sizeof(int));
		return is;
	}

	//------------------------------------------------------------

	std::ofstream& operator << (std::ofstream& os, const Weapon& Arsenal) {
		int tmp;
		tmp = Arsenal.NameWeapon.size();
		os.write((char*) &tmp, sizeof(int));
		os << Arsenal.NameWeapon;
		tmp = Arsenal.NameAmmunition.size();
		os.write((char*) &tmp, sizeof(int));
		os << Arsenal.NameAmmunition;
		tmp = Arsenal.RateFire;
		os.write((char*) &tmp, sizeof(int));
		tmp = Arsenal.QuantityAmmunition;
		os.write((char*) &tmp, sizeof(int));
		tmp = Arsenal.Damage;
		os.write((char*) &tmp, sizeof(int));		
		return os;
	}

	//------------------------------------------------------------

	//Перегруженные операторы
	Weapon& Weapon::operator = (const Weapon& Arsenal) {
		NameWeapon = Arsenal.GetWeapon();
		NameAmmunition = Arsenal.GetMunition();
		RateFire = Arsenal.GetRateFire();
		QuantityAmmunition = Arsenal.GetQuantityAmmunition();
		Damage = Arsenal.GetDamage();
		return *this;
	}

	//------------------------------------------------------------

	Weapon& Weapon::operator = (Weapon&& Arsenal) {
		std::string NameWeaponTmp = Arsenal.GetWeapon();
		Arsenal.SetWeapon(NameWeapon);
		NameWeapon = NameWeaponTmp;

		std::string NameAmmunitionTmp = Arsenal.GetMunition();
		Arsenal.SetMunition(NameAmmunition);
		NameAmmunition = NameAmmunitionTmp;

		int RateFireTmp = Arsenal.GetRateFire();
		Arsenal.SetRateFire(RateFire);
		RateFire = RateFireTmp;

		int QuantityAmmunitionTmp = Arsenal.GetQuantityAmmunition();
		Arsenal.SetQuantityAmmunition(QuantityAmmunition);
		QuantityAmmunition = QuantityAmmunitionTmp;

		int DamageTmp = Arsenal.GetDamage();
		Arsenal.SetDamage(Damage);
		Damage = DamageTmp;
		return *this;
	}

}