/**
@file MilitaryCharacteristics.h
@brief ������������ ���� � ��������� ������
@detailed ������ ���� �������� � ���� ����������� ������ MilitaryCharacteristics
*/
#ifndef _CHARACTERISTICS_H_
#define _CHARACTERISTICS_H_

#include <iostream>
#include <fstream>

/**
namespace AircraftCarrierGroup
@brief ������������ ���� AircraftCarrierGroup
*/
namespace AircraftCarrierGroup{

/**
@brief ����� ��� �������� ��������� ��������� �������
@detailed ������������ �������� � ��������� ��������� ������������� �������
*/
	class MilitaryCharacteristics {
	protected:
		int Speed;
		int FuelReserve;
		int FuelConsumption;
	public:
/**
@brief ����������� �� ���������
*/
		MilitaryCharacteristics() : Speed(0), FuelReserve(0), FuelConsumption(0) {}
/**
@brief ���������������� �����������
@param SpeedTmp ��������
@param FuelReserveTmp ����� �������
@param FuelConsumptionTmp ������ �������
*/
		MilitaryCharacteristics(int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp);
/**
@brief ���������� �����������
@param Military ������ ������, ��� �������� ����� ����������� �����������
*/
		MilitaryCharacteristics(const MilitaryCharacteristics& Military);
/**
@brief ����������
*/
		virtual ~MilitaryCharacteristics() {}
/**
@brief ������������� �������� �������
@param[in] SpeedTmp ��������, �� ������� ����� ��������
@return ���������� ���������� ��������� �������
*/
		MilitaryCharacteristics& SetSpeed(int SpeedTmp) { Speed = SpeedTmp; return *this; }
/**
@brief ������������� ����� ������� � �������
@param[in] FuelReserveTmp ����� �������
@return ���������� ���������� ��������� �������
*/
		MilitaryCharacteristics& SetFuelReserve(int FuelReserveTmp) { FuelReserve = FuelReserveTmp; return *this; }
/**
@brief ������������� ������ ������� � �������
@param[in] FuelConsumptionTmp ����� �������
@return ���������� ���������� ��������� �������
*/
		MilitaryCharacteristics& SetFuelConsumption(int FuelConsumptionTmp) { FuelConsumption = FuelConsumptionTmp;  return *this; }
/**
@brief ���������� �������� �������
*/
		int GetSpeed() const { return Speed; }
/**
@brief ���������� ����� �������
*/
		int GetFuelReserve() const { return FuelReserve; }
/**
@brief ���������� ������ �������
*/
		int GetFuelConsumption() const { return FuelConsumption; }

		//��������� ����/�����
		friend std::ostream& operator << (std::ostream& os, const MilitaryCharacteristics& Military);
		friend std::istream& operator >> (std::istream& is, MilitaryCharacteristics& Military);

		//��������� ����/����� �� �����
		friend std::ofstream& operator << (std::ofstream& os, const MilitaryCharacteristics& Military);
		friend std::ifstream& operator >> (std::ifstream& is, MilitaryCharacteristics& Military);

		//������������� ���������
		MilitaryCharacteristics& operator = (const MilitaryCharacteristics& Military);
		MilitaryCharacteristics& operator = (MilitaryCharacteristics&& Military);
	};
}
#endif //_CHARACTERISTICS_H_