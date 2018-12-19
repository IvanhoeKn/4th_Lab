/**
@file Aircraft.h
@brief ������������ ���� � ��������� ������
@detailed ������ ���� �������� � ���� ����������� ������ Aircraft
*/
#ifndef _AIRCRAFT_H_
#define _AIRCRAFT_H_

#include <iostream>
#include <fstream>
#include "Weapon.h"
#include "MilitaryCharacteristics.h"

/**
namespace AircraftCarrierGroup
@brief ������������ ���� AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
/**
@brief ����� ��� �������� ��������
@detailed ������������ �������� ���� ���������� �������� � �������� �������, �������������� ��� ���������
*/
	class Aircraft : public MilitaryCharacteristics {
	protected:
		static const int QUOTA = 3;
		int Amount;
		Weapon *Arr;
	public:
/**
@brief ����������� �� ���������
*/
		Aircraft() : MilitaryCharacteristics(), Amount(0), Arr(nullptr) {}
/**
@brief ���������������� �����������
@param SpeedTmp ��������
@param FuelReserveTmp ����� �������
@param FuelConsumptionTmp ������ �������
@throw InvalidQuota ���� ���������� ������������ ������ ��������� QUOTA
*/
		Aircraft(int SpeedTmp, int FuelReserveTmp, int FuelConsumptionTmp) : MilitaryCharacteristics(SpeedTmp, FuelConsumptionTmp, FuelReserveTmp), Amount(0), Arr(nullptr) {}
/**
@brief ���������������� �����������
@param SpeedTmp ��������
@param FuelReserveTmp ����� �������
@param FuelConsumptionTmp ������ �������
@param AmountTmp ���������� ������
@param ArrTmp ������, � ������� �������� ��������� ������� ������
@throw InvalidQuota ���� ���������� ������������ ������ ��������� QUOTA
*/
		Aircraft(int SpeedTmp, int FuelReserveTmp, int FuelConsumptionTmp, int AmountTmp, Weapon* ArrTmp);
/**
@brief ���������������� �����������
@param Military ������ ����� �������������� �������
@param AmountTmp ���������� ����������
@param ArrTmp ������, � ������� �������� ��������� ������� ������
@throw InvalidQuota ���� ���������� ������������ ������ ��������� QUOTA
*/
		Aircraft(const MilitaryCharacteristics& Military, int AmountTmp, Weapon* ArrTmp);
/**
@brief ���������� �����������
@param Plane ��������� ��������
*/
		Aircraft(const Aircraft& Plane);
/**
@brief ����������
*/
		~Aircraft() {
			delete [] Arr;
		}	
/**
@brief ���������� ��������� ������ �� ��� ������
@param Number ����� ������
@throw InvalidNumberWeapon ���� ��� ����� �������� ����� ������
*/
		Weapon& getWeaponAircraft(int Number) const;
/**
@brief ���������� ���������� ���������� � ��������
*/
		int getAmountWeapon() const { return Amount; }

		//��������� ����/�����
		friend std::ostream& operator << (std::ostream& os, const Aircraft& Plane);
		friend std::istream& operator >> (std::istream& is, Aircraft& Plane);

		//��������� ����/����� �� �����
		friend std::ofstream& operator << (std::ofstream& os, const Aircraft& Plane);
		friend std::ifstream& operator >> (std::ifstream& is, Aircraft& Plane);

		//������������� ���������
		Aircraft& operator = (const Aircraft& Plane);
		Aircraft& operator = (Aircraft&& Plane);
		Aircraft* operator * () { return this; }
	};
}
#endif //_AIRCRAFT_H_
