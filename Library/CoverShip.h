/**
@file CoverShip.h
@brief ������������ ���� � ��������� ������
@detailed ������ ���� �������� � ���� ����������� ������ CoverShip
*/
#ifndef _COVER_H_
#define _COVER_H_

#include <iostream>
#include <fstream>
#include "Ship.h"

/**
namespace AircraftCarrierGroup
@brief ������������ ���� AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
/**
@brief ����� ��� �������� ����� ���������
@detailed ������������ �������� ���� ���������� ����� ��������� � �������� �������, �������������� ��� ���������
*/
	class CoverShip : public Ship {
	protected:
		int AmountW;
		Weapon *ArrW;
		std::string Disguised;
		//---------------------------------
		virtual std::ostream& show(std::ostream& os) const;
		virtual std::istream& get(std::istream&);
		//---------------------------------
		virtual std::ofstream& fprint(std::ofstream&) const;
		virtual std::ifstream& fread(std::ifstream&);
	public:
/**
@brief ����������� �� ���������
*/
		CoverShip() : Ship(), Disguised("Covered Ship default"), AmountW(0), ArrW(nullptr) {}
/**
@brief ���������������� �����������
@param CallTmp �������� �������
@param ComanderTmp ������� �����
@param CrewTmp ���������� ������� � �������
@param MilitaryTmp ������ ����� �������������� �������
@param DisguisedTmp �������� ������������� �������
@param AmountTmp ���������� ���������� �� �������
@param ArrTmp ������ ��������� ������� ������ �� �������
*/
		CoverShip(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp, std::string DisguisedTmp, int AmountTmp, Weapon *ArrTmp);
/**
@brief ���������� �����������
@param CoverShipTmp ��������� ������� ���������
*/
		CoverShip(const CoverShip &CoverShipTmp);
/**
@brief ����������
*/
		~CoverShip() {
			delete[] ArrW;
		}
/**
@brief ������� ��� ���������� ��� ���� ������� �� �����
*/
		std::ostream& printInfoWeapon(std::ostream& os) const;
/**
@brief ������� ������������ ���������, �� ��������� �� �������, ������
@param NameWeaponTmp �������� ������, ������� ���� ��������������
@param WeaponTmp ����� ������
*/
		CoverShip& WeaponModification(std::string NameWeaponTmp, const Weapon& WeaponTmp);
/**
@brief ���������� ������� ������� ������� ���� ����� �������� ����� � ������ �����������������
*/
		double TimeFireAllWeapons() const;
/**
@brief ���������� ������ ����������, ������� ����� ������� ��� �������� ����� �������� ���� �� ������� �������
@throw InvalidShipType ��� ������� �������� ����� ����� ��������� �� �������� �����, 
��������� ���� ��� �������� �� ����� ����� ��������� �� ������
*/
		int DamageAllPlanes() const { throw std::exception("No Planes on Cover Ship\n"); }
/**
@brief ���������� ������ ����������, ������� ����� ������� ��� ������ ����� �������� ���� �� ������� �������
*/
		int DamageAllWeapons() const;
/**
@brief ��������� ������ �������
@return ���������� ��������� �� ������� ������, � ������� �������� ����� ����� �������
*/
		CoverShip* clone() const { return new CoverShip(*this); }
/**
@brief ������� �������� ��������� ������ �� ��� ��������
@param Name �������� ������
@return ���������� ��������� �� ������� ������, � ������� �������� ��������� ���������� ������
*/
		Weapon* getWeapon(std::string Name) const;
/**
@brief ���������� ���������� ���������� �� �����
*/
		int AmountWeapon() const { return AmountW; }
/**
@brief ��� ������� �������
*/
		int TypeShip() const { return 1; }
/**
@brief ��������� ���������� ��������� �� ������
@throw InvalidShipType ��� ������� �������� ���������� ���������, ��������� ���� ��� �������� �� ����� ����� ��������� �� ������
*/
		int AmountAircraft() const { throw std::exception("No Aircrafts on Cover Ship\n"); }
/**
@brief ��������� �������� ������������� �������
*/
		std::string GetDisguised() const { return Disguised; }

		//��������� ����/�����
		friend std::ostream& operator << (std::ostream&, const CoverShip&);
		friend std::istream& operator >> (std::istream&, CoverShip&);

		//��������� ����/����� �� �����
		friend std::ofstream& operator << (std::ofstream& os, const CoverShip& ShipTmp) { return ShipTmp.fprint(os); }
		friend std::ifstream& operator >> (std::ifstream& is, CoverShip& ShipTmp) { return ShipTmp.fread(is); }
	};
}
#endif //_COVER_H_
