#ifndef _SHAPE_H_
#define _SHAPE_H_
#include <iostream>
#include <string>

namespace AircraftСarrierGroup
{

	class Weapon {
	protected:
		std::string NameWeapon;
		std::string NameAmmunition;
		int RateFire, Damage;
	public:
		//Конструкторы
		Weapon() : NameWeapon(nullptr), NameAmmunition(nullptr), RateFire(0), Damage(0) {};

		Weapon(std::string Weapon, std::string Munition, int RateFireTmp, int DamageTmp) {
			NameWeapon = Weapon;
			NameAmmunition = Munition;
			RateFire = RateFireTmp;
			Damage = DamageTmp;
		}

		//Деструктор
		~Weapon() {
			NameWeapon = nullptr;
			NameAmmunition = nullptr;
			RateFire = 0;
			Damage = 0;
		}

		//Другие методы класса
		Weapon& SetWeapon(std::string Weapon) { NameWeapon = Weapon; };

		Weapon& SetMunition(std::string Munition) { NameAmmunition = Munition; };

		Weapon& SetRateFire(int RateFireTmp) { RateFire = RateFireTmp; };

		Weapon& SetDamage(int DamageTmp) { Damage = DamageTmp; };

		std::string GetWeapon() const { return NameWeapon; };

		std::string GetMunition() const { return NameAmmunition; };

		int GetRateFire() const { return RateFire; };

		int GetDamage() const { return Damage; };

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream&, const Weapon&);

		friend std::istream& operator >> (std::istream&, Weapon&);
	};
}
#endif