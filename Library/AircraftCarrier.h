/**
@file AircraftCarrier.h
@brief ������������ ���� � ��������� ������
@detailed ������ ���� �������� � ���� ����������� ������ AircraftCarrier
*/
#ifndef _AIRCRAFT_CARRIER_H_
#define _AIRCRAFT_CARRIER_H_

#include <iostream>
#include "Carrier.h"

/**
namespace AircraftCarrierGroup
@brief ������������ ���� AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
/**
@brief ����� ��� �������� ������������ ��������
@detailed ������������ �������� ���� ���������� ������������ �������� � �������� �������, �������������� ��� ���������
*/
	class AircraftCarrier : public Carrier {
	protected:
		int AmountW;
		Weapon *ArrW;
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
		AircraftCarrier() : Carrier(), AmountW(0), ArrW(nullptr) {}
/**
@brief ���������������� �����������
@param CallTmp �������� �������
@param ComanderTmp ������� �����
@param CrewTmp ���������� ������� � �������
@param MilitaryTmp ������ ����� �������������� �������
@param AmountPTmp ���������� ��������� �� ������ �������
@param PlaneTmp �������� ��������� ������� �� ���������
@param AmountWTmp ���������� ���������� �� �������
@param ArrWTmp ������ ��������� ������� ������ �� �������
*/
		AircraftCarrier(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp, int AmountPTmp, Aircraft* PlaneTmp, int AmountWTmp, Weapon* ArrWTmp);
/**
@brief ���������� �����������
@param AerocarrierTmp ��������� ������������ ��������
*/
		AircraftCarrier(const AircraftCarrier& AerocarrierTmp);
/**
@brief ����������
*/
		~AircraftCarrier() {
			delete[] ArrW;
		}
/**
@brief ������� ��� ���������� ��� ���� ������� �� �����
*/
		std::ostream& printInfoWeapon(std::ostream& os) const;
/**
@brief ���������� ������ ����������, ������� ����� ������� ��� ������ ����� �������� ���� �� ������� �������
*/
		int DamageAllWeapons() const;
/**
@brief ���������� ������� ������� ������� ���� ����� �������� ����� � ������ �����������������
*/
		double TimeFireAllWeapons() const;
/**
@brief ������� ������������ ���������, �� ��������� �� �������, ������
@param NameWeaponTmp �������� ������, ������� ���� ��������������
@param WeaponTmp ����� ������
*/
		AircraftCarrier& WeaponModification(std::string NameWeaponTmp, Weapon& WeaponTmp);
/**
@brief ��������� ������ �������
@return ���������� ��������� �� ������� ������, � ������� �������� ����� ����� �������
*/
		AircraftCarrier* clone() const { return new AircraftCarrier(*this); }
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
		int TypeShip() const { return 3; }
/**
@brief ������� ��������� �������� ������������� �������
@throw InvalidShipType ��� ������� �������� �������� ������������� �������, ��������� ���� ��� �������� �� ����� ����� ������������� �������
*/
		std::string GetDisguised() const { throw std::exception("This type of ship can't have Disguised ships\n"); }

		//��������� ����/�����
		friend std::ostream& operator << (std::ostream&, const AircraftCarrier&);
		friend std::istream& operator >> (std::istream&, AircraftCarrier&);

		//��������� ����/����� �� �����
		friend std::ofstream& operator << (std::ofstream& os, const AircraftCarrier& ShipTmp) { return ShipTmp.fprint(os); }
		friend std::ifstream& operator >> (std::ifstream& is, AircraftCarrier& ShipTmp) { return ShipTmp.fread(is); }
	};
}
#endif //_AIRCRAFT_CARRIER_H_

