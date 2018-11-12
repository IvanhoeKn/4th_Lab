#ifndef _WEAPON_H_
#define _WEAPON_H_
#include <iostream>
#include <string>

namespace Aircraft�arrierGroup
{

	class Weapon {
	protected:
		std::string NameWeapon;
		std::string NameAmmunition;
		int RateFire, Damage;
	public:
		//������������
		Weapon() : NameWeapon(nullptr), NameAmmunition(nullptr), RateFire(0), Damage(0) {};

		Weapon(std::string Weapon, std::string Munition, int RateFireTmp, int DamageTmp) {
			NameWeapon = Weapon;
			NameAmmunition = Munition;
			RateFire = RateFireTmp;
			Damage = DamageTmp;
		};

		Weapon(Weapon& Arsenal) {
			NameWeapon = Arsenal.NameWeapon;
			NameAmmunition = Arsenal.NameAmmunition;
			RateFire = Arsenal.RateFire;
			Damage = Arsenal.Damage;
		};

		//����������
		~Weapon() {
			NameWeapon = nullptr;
			NameAmmunition = nullptr;
			RateFire = 0;
			Damage = 0;
		};

		//������ ������ ������
		Weapon& SetWeapon(std::string Weapon) { NameWeapon = Weapon; };

		Weapon& SetMunition(std::string Munition) { NameAmmunition = Munition; };

		Weapon& SetRateFire(int RateFireTmp) { RateFire = RateFireTmp; };

		Weapon& SetDamage(int DamageTmp) { Damage = DamageTmp; };

		std::string GetWeapon() const { return NameWeapon; };

		std::string GetMunition() const { return NameAmmunition; };

		int GetRateFire() const { return RateFire; };

		int GetDamage() const { return Damage; };

		//��������� ����/�����
		friend std::ostream& operator << (std::ostream&, const Weapon&);

		friend std::istream& operator >> (std::istream&, Weapon&);

		//������������� ���������
		Weapon& operator = (const Weapon& Arsenal);

		Weapon& operator = (Weapon&& Arsenal);
	};
}
#endif