#ifndef _WEAPON_H_
#define _WEAPON_H_
#include <iostream>
#include <string>

namespace AircraftСarrierGroup
{

	class Weapon {
	protected:
		std::string NameWeapon;
		std::string NameAmmunition;
		int RateFire, QuantityAmmunition, Damage;
	public:
		//Конструкторы
		Weapon() : NameWeapon("Name default"), NameAmmunition("Name ammo default"), RateFire(0), QuantityAmmunition(0), Damage(0) {}

		Weapon(std::string Weapon, std::string Munition, int RateFireTmp, int QuantityAmmunitionTmp, int DamageTmp);

		//Копирующий конструктор
		Weapon(const Weapon& Arsenal);

		//---------------------------------

		//Деструктор
		virtual ~Weapon() {}

		//---------------------------------

		//Другие методы класса
		Weapon& SetWeapon(std::string Weapon) { NameWeapon = Weapon; return *this; }

		Weapon& SetMunition(std::string Munition) { NameAmmunition = Munition; return *this; }

		Weapon& SetRateFire(int RateFireTmp) { RateFire = RateFireTmp; return *this; }

		Weapon& SetQuantityAmmunition(int QuantityAmmunitionTmp) { QuantityAmmunition = QuantityAmmunitionTmp; return *this; }
		
		Weapon& SetDamage(int DamageTmp) { Damage = DamageTmp; return *this; }

		std::string GetWeapon() const { return NameWeapon; }

		std::string GetMunition() const { return NameAmmunition; }

		int GetRateFire() const { return RateFire; }

		int GetQuantityAmmunition() const { return QuantityAmmunition; }

		int GetDamage() const { return Damage; }

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream&, const Weapon&);

		friend std::istream& operator >> (std::istream&, Weapon&);

		//Перегруженные операторы
		Weapon& operator = (const Weapon& Arsenal);

		Weapon& operator = (Weapon&& Arsenal);
	};
}
#endif