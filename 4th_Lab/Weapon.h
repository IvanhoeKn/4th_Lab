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
		Weapon() : NameWeapon(nullptr), NameAmmunition(nullptr), RateFire(0), QuantityAmmunition(0), Damage(0) {};

		Weapon(std::string Weapon, std::string Munition, int RateFireTmp, int QuantityAmmunitionTmp, int DamageTmp) {
			NameWeapon = Weapon;
			NameAmmunition = Munition;
			RateFire = RateFireTmp;
			QuantityAmmunition = QuantityAmmunitionTmp;
			Damage = DamageTmp;
		};

		Weapon(Weapon& Arsenal) {
			NameWeapon = Arsenal.NameWeapon;
			NameAmmunition = Arsenal.NameAmmunition;
			RateFire = Arsenal.RateFire;
			QuantityAmmunition = Arsenal.QuantityAmmunition;
			Damage = Arsenal.Damage;
		};

		//Деструктор
		~Weapon() {
			NameWeapon = nullptr;
			NameAmmunition = nullptr;
			RateFire = 0;
			QuantityAmmunition = 0;
			Damage = 0;
		};

		//Другие методы класса
		Weapon& SetWeapon(std::string Weapon) { NameWeapon = Weapon; };

		Weapon& SetMunition(std::string Munition) { NameAmmunition = Munition; };

		Weapon& SetRateFire(int RateFireTmp) { RateFire = RateFireTmp; };

		Weapon& SetQuantityAmmunition(int QuantityAmmunitionTmp) { QuantityAmmunition = QuantityAmmunitionTmp; };
		
		Weapon& SetDamage(int DamageTmp) { Damage = DamageTmp; };

		std::string GetWeapon() const { return NameWeapon; };

		std::string GetMunition() const { return NameAmmunition; };

		int GetRateFire() const { return RateFire; };

		int GetQuantityAmmunition() const { return QuantityAmmunition; };

		int GetDamage() const { return Damage; };

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream&, const Weapon&);

		friend std::istream& operator >> (std::istream&, Weapon&);

		//Перегруженные операторы
		Weapon& operator = (const Weapon& Arsenal);

		Weapon& operator = (Weapon&& Arsenal);
	};
}
#endif