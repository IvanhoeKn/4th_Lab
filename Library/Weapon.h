/**
@file Weapon.h
@brief ������������ ���� � ��������� ������
@detailed ������ ���� �������� � ���� ����������� ������ Weapon
*/
#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <iostream>
#include <fstream>
#include <string>

/**
namespace AircraftCarrierGroup
@brief ������������ ���� AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
/**
@brief ����� ��� �������� ����������
@detailed ������������ �������� ���� ���������� ������������ �������� � �������� �������, �������������� ��� ���������
*/
	class Weapon {
	protected:
		std::string NameWeapon;
		std::string NameAmmunition;
		int RateFire, QuantityAmmunition, Damage;
	public:
/**
@brief ����������� �� ���������
*/
		Weapon() : NameWeapon("Name default"), NameAmmunition("Name ammo default"), RateFire(0), QuantityAmmunition(0), Damage(0) {}
/**
@brief ���������������� �����������
@param Weapon �������� ������
@param Munition �������� ����������
@param RateFireTmp ���������������� ������
@param QuantityAmmunitionTmp ���������� �����������
@param DamageTmp ����������, ��������� ���� ��� ����� ������� ���������
*/
		Weapon(std::string Weapon, std::string Munition, int RateFireTmp, int QuantityAmmunitionTmp, int DamageTmp);
/**
@brief ���������� �����������
@param Arsenal ��������� ����������� ������
*/
		Weapon(const Weapon& Arsenal);
/**
@brief ����������
*/
		virtual ~Weapon() {}
/**
@brief ������������� �������� ������
@param[in] Weapon ����� �������� ������
@return ���������� ���������� ��������� ������
*/
		Weapon& SetWeapon(std::string Weapon) { NameWeapon = Weapon; return *this; }
/**
@brief ������������� �������� ����������
@param[in] Munition ����� �������� ����������, ����������� ��� ����� ������
@return ���������� ���������� ��������� ������
*/
		Weapon& SetMunition(std::string Munition) { NameAmmunition = Munition; return *this; }
/**
@brief ������������� ���������������� ������
@param[in] RateFireTmp ����� �������� ����������������
@return ���������� ���������� ��������� ������
*/
		Weapon& SetRateFire(int RateFireTmp) { RateFire = RateFireTmp; return *this; }
/**
@brief ������������� ����� ���������� �����������
@param[in] QuantityAmmunitionTmp ����� ���������� �����������
@return ���������� ���������� ��������� ������
*/
		Weapon& SetQuantityAmmunition(int QuantityAmmunitionTmp) { QuantityAmmunition = QuantityAmmunitionTmp; return *this; }
/**
@brief ������������� ���� ������, ���������� �� ���� �� ���������
@param[in] DamageTmp ����������� ����
@return ���������� ���������� ��������� ������
*/
		Weapon& SetDamage(int DamageTmp) { Damage = DamageTmp; return *this; }
/**
@brief ���������� �������� ������
*/
		std::string GetWeapon() const { return NameWeapon; }
/**
@brief ���������� �������� ����������
*/
		std::string GetMunition() const { return NameAmmunition; }
/**
@brief ���������� ���������������� ������
*/
		int GetRateFire() const { return RateFire; }
/**
@brief ���������� ���������� ����������� ��� ������� ������
*/
		int GetQuantityAmmunition() const { return QuantityAmmunition; }
/**
@brief ���������� ����, ��������� ���� ��� ����� ������� ���������
*/
		int GetDamage() const { return Damage; }

		//��������� ����/�����
		friend std::ostream& operator << (std::ostream&, const Weapon&);
		friend std::istream& operator >> (std::istream&, Weapon&);

		//��������� ����/����� �� �����
		friend std::ofstream& operator << (std::ofstream&, const Weapon&);
		friend std::ifstream& operator >> (std::ifstream&, Weapon&);

		//������������� ���������
		Weapon& operator = (const Weapon& Arsenal);
		Weapon& operator = (Weapon&& Arsenal);
		Weapon* operator *() { return this; }
	};
}
#endif //_WEAPON_H_