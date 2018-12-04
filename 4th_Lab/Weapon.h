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
		int RateFire, QuantityAmmunition, Damage;
	public:
		//������������
		Weapon() : NameWeapon("Name default"), NameAmmunition("Name ammo default"), RateFire(0), QuantityAmmunition(0), Damage(0) {}

		Weapon(std::string Weapon, std::string Munition, int RateFireTmp, int QuantityAmmunitionTmp, int DamageTmp);

		//���������� �����������
		Weapon(const Weapon& Arsenal);

		//---------------------------------

		//����������
		virtual ~Weapon() {}

		//---------------------------------

		//������ ������ ������
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

		//��������� ����/�����
		friend std::ostream& operator << (std::ostream&, const Weapon&);

		friend std::istream& operator >> (std::istream&, Weapon&);

		//������������� ���������
		Weapon& operator = (const Weapon& Arsenal);

		Weapon& operator = (Weapon&& Arsenal);
	};
}
#endif