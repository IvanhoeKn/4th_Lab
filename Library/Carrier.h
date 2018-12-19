/**
@file Carrier.h
@brief ������������ ���� � ��������� ������
@detailed ������ ���� �������� � ���� ����������� ������ Carrier
*/
#ifndef _CARRIER_H_
#define _CARRIER_H_

#include <iostream>
#include "Ship.h"
#include "Aircraft.h"

/**
namespace AircraftCarrierGroup
@brief ������������ ���� AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
/**
@brief ����� ��� �������� ���������
@detailed ������������ �������� ���� ���������� �������� � �������� �������, �������������� ��� ���������
*/
	class Carrier : public Ship {
	protected:
		int AmountP;
		Aircraft* Plane;
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
		Carrier() : Ship(), AmountP(0), Plane(nullptr) {}
/**
@brief ���������������� �����������
@param CallTmp �������� �������
@param ComanderTmp ������� �����
@param CrewTmp ���������� ������� � �������
@param MilitaryTmp ������ ����� �������������� �������
@param AmountPTmp ���������� ��������� �� ������ �������
@param PlaneTmp �������� ��������� ������� �� ���������
*/
		Carrier(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp, int AmountPTmp = 0, Aircraft* PlaneTmp = nullptr);
/**
@brief ���������� �����������
@param CarrierTmp ��������� ���������
*/
		Carrier(const Carrier& CarrierTmp);
/**
@brief ����������
*/
		virtual ~Carrier() {
			delete[] Plane;
		}
/**
@brief ������� ��� ���������� ��� ���� ������� �� �����
*/
		std::ostream& printInfoWeapon(std::ostream& os) const;
/**
@brief ���������� ������ ����������, ������� ����� ������� ��� �������� ����� �������� ���� �� ������� �������
*/
		int DamageAllPlanes() const;
/**
@brief ���������� ������ ����������, ������� ����� ������� ��� ������ ����� �������� ���� �� ������� �������
@throw InvalidOperation ��� ������� �������� �����, ���������� ����� �������� �����, ��������� ���� ��� �������� 
�� ����� ����� ���������� �� �����
*/
		virtual int DamageAllWeapons() const { throw std::exception("No Weapons on Carrier\n"); }
/**
@brief ���������� ������� ������� ������� ���� ����� �������� ����� � ������ �����������������
@throw InvalidOperation ��� ������� �������� ������ ������� ����� �������� �����, ��������� ���� ��� ��������
�� ����� ����� ���������� �� �����
*/
		virtual double TimeFireAllWeapons() const { throw std::exception("No Weapons on Carrier\n"); }
/**
@brief ������� ������������ ���������, �� ��������� �� �������, ������
@param NameWeaponTmp �������� ������, ������� ���� ��������������
@param WeaponTmp ����� ������
@throw InvalidOperation ��� ������� ����������� ������ �����, ��������� ���� ��� ��������
�� ����� ����� ���������� �� �����
*/
		virtual Carrier& WeaponModification(std::string NameWeaponTmp, const Weapon& WeaponTmp) { throw std::exception("No Weapons on Carrier\n"); }
/**
@brief ��������� ������ �������
@return ���������� ��������� �� ������� ������, � ������� �������� ����� ����� �������
*/
		virtual Carrier* clone() const { return new Carrier(*this); }
/**
@brief ������� �������� ��������� ������ �� ��� ��������
@param Name �������� ������
@return ���������� ��������� �� ������� ������, � ������� �������� ��������� ���������� ������
@throw InvalidOperation ��� ������� �������� ��������� ������ ������� �� ��� ��������, ��������� ���� ��� �������� 
�� ����� ����� ���������� �� �����
*/
		virtual Weapon* getWeapon(std::string Name) const { throw std::exception("No Weapons on Carrier\n"); }
/**
@brief ���������� ���������� ���������� �� �����
@throw InvalidOperation ��� ������� �������� ���������� ������ �� �������, ��������� ���� ��� ��������
�� ����� ����� ���������� �� �����
*/
		virtual int AmountWeapon() const { throw std::exception("No Weapons on Carrier\n"); }
/**
@brief ��� ������� �������
*/
		virtual int TypeShip() const { return 2; }
/**
@brief ��������� ��������� �� ��������� �������� �� ��� ������
*/
		Aircraft* getAir(int Number) const;
/**
@brief ��������� ���������� ��������� �� ������
*/
		int AmountAircraft() const { return AmountP; }
/**
@brief ���������� ���������� �������� �� ������ �������
@param PlaneTmp ��������� ��������
*/
		Carrier& AddAircraft(const Aircraft& PlaneTmp);
/**
@brief ���������� �������� �������� � �������
@detailed ������ ������� ���������� ����� ����� �������� �� ��� ������, � ������ ������ �������� � �������� ����������
(��� ���������� ��� ������� �������� �������� � ������ ������� �� ������), � ����� ���������� ��� �������� � ����� �������
@param[out] DeletedAircraft ����� ���������� ��������
*/
		Carrier& DeleteAircraft(Aircraft* DeletedAircraft = nullptr);
/**
@brief ���������� ������� ������� �������������� ������ ���� ��������� �������
*/
		double MaxAircraftFlyght() const;
/**
@brief ���������� ������� ������� �������� ���� ��������� �������
*/
		double MaxRadiusFlyght() const;
/**
@brief ������� ��������� �������� ������������� �������
@throw InvalidShipType ��� ������� �������� �������� ������������� �������, ��������� ���� ��� �������� �� ����� ����� ������������� �������
*/
		std::string GetDisguised() const { throw std::exception("This type of ship can't have Disguised ships\n"); }

		//��������� ����/�����
		friend std::ostream& operator << (std::ostream&, const Carrier&);
		friend std::istream& operator >> (std::istream&, Carrier&);

		//��������� ����/����� �� �����
		friend std::ofstream& operator << (std::ofstream& os, const Carrier& ShipTmp) { return ShipTmp.fprint(os); }
		friend std::ifstream& operator >> (std::ifstream& is, Carrier& ShipTmp) { return ShipTmp.fread(is); }
	};

}
#endif //_CARRIER_H_

