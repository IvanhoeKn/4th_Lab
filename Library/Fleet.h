/**
@file Fleet.h
@brief ������������ ���� � ��������� ������ � ��� ���������
@detailed ������ ���� �������� � ���� ����������� ������ Fleet
*/
#ifndef _FLEET_H_
#define _FLEET_H

#include "_map.h"
#include <iostream>
#include <fstream>
#include "Ship.h"
#include "CoverShip.h"
#include "Carrier.h"
#include "AircraftCarrier.h"

/**
namespace AircraftCarrierGroup
@brief ������������ ���� AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
/**
@brief �����-�������� ��� ������ Fleet
@detailed ��� ��� ������ �������������� ������ � ��������� ���������� ������ Fleet
*/
	class ConstFleetIt {
	private:
		_map<std::string, Ship*>::_map_const_it cur;
	public:
/**
@brief ����������� �� ���������
*/
		ConstFleetIt() {}
/**
@brief ���������������� �����������
@param it ����������� �������� ������ Fleet
*/
		ConstFleetIt(_map<std::string, Ship*>::_map_const_it it) :cur(it) {}
		//������������� ���������
		int operator != (const ConstFleetIt&) const;
		int operator == (const ConstFleetIt&) const;
		const _pair<std::string, Ship*>& operator * ();
		const _pair<std::string, Ship*>* operator -> ();
		ConstFleetIt& operator ++ ();
		ConstFleetIt operator ++ (int);
	};

/**
@brief ����� ��� �������� �����
@detailed ������������ �������� ���������� ���� �������� ����� � �������� �������, ����������� ����������������� � ��������� �����
*/
	class Fleet {
	private:
		Captain Admiral;
		_map<std::string, Ship*> ArrShip;
	public:
/**
@brief ����������� �� ���������
*/
		Fleet() {}
/**
@brief ���������� �����������
@param CoverShipTmp ��������� ������� ���������
*/
		Fleet(const Fleet& Navy);
/**
@brief ����������
*/
		~Fleet();
		//------------------------------------------------------------
		friend class ConstFleetIt;
		typedef ConstFleetIt Const_Iterator;
		Const_Iterator find(const std::string&) const;
		Const_Iterator begin() const;
		Const_Iterator end() const;
		//------------------------------------------------------------
/**
@brief ���������� ���������� �������� �� �����
*/
		int SizeFleet() const { return ArrShip.size(); }
/**
@brief ��������� ����� ������� �� ����
@param CallTmp �������� ������ �������
@param ShipTmp ��������� �� ������� ������, � ������� �������� ��� ���������� � �������
*/
		bool insert (std::string& CallTmp, Ship* ShipTmp);
/**
@brief ������� ������� �� �����
@param CallTmp �������� ���������� �������
*/
		bool remove(std::string& CallTmp);
/**
@brief ������������ ������� ������� � ������ ������� �� ������
@param itFr �������, � �������� ������� �������
@param itTo �������, �� ������� ����������� �������
@param Fuel ���������� �������, ������� ���������� ���������
*/
		int transferFuel(Fleet::Const_Iterator& itFr, Fleet::Const_Iterator& itTo, const int Fuel);
/**
@brief ���������� ���������� �������� ��������� � ������
*/
		int TypeCoverShip();
/**
@brief ���������� ���������� ����������� �������� � ������
*/
		int TypeCarrier();
/**
@brief ���������� ���������� ����������� ��������� � ������
*/
		int TypeAircraftCarrier();
/**
@brief ���������� �������� � ����������� ������
@param Plane �������, ���������� � ������� ���������� ������ � ������
@param ShipTmp �������, �� ������� ����� ����������� �������
*/
		bool AddPlane(const Aircraft& Plane, const std::string& ShipTmp);
/**
@brief �������� �������� � �������
@param ShipTmp �������, � �������� ����� ������������� �������� ��������
*/
		bool DeletePlane(const std::string& ShipTmp);
/**
@brief ���������� ������� ������������� ������� ������ ���� ��������� ����������
*/
		double MaxDurationPlaneFligth();
/**
@brief ���������� ������� ������������� ������ ������ ���� ��������� ����������
*/
		double MaxRadiusPlaneFligth();
/**
@brief ������������ ������� �������� � ������ ������� �� ������
@param From �������, � �������� ������� �������
@param To �������, �� ������� ����������� �������
*/		
		int TransferAircraft(Fleet::Const_Iterator& From, Fleet::Const_Iterator& To);
/**
@brief ������� ����������, � ������� �������� ���������� ��� ���� �������� ����������� ������
*/
		void clear();
/**
@brief ����� ���������� ��� ���� �������� �����
*/
		void Show();

		//double MaxRangeShip(const std::string& ShipTmp);
		//double TimeFireAllWeapons(const std::string& ShipTmp);
		//int DamageAllShipWeapon(const std::string& ShipTmp);
		//int DamageAllShipAircraft(const std::string& ShipTmp);

		//��������� �����
		friend std::ostream& operator << (std::ostream&, const Fleet&);

		//��������� ����/����� �� �����
		friend std::ifstream& operator >> (std::ifstream&, Fleet&);
		friend std::ofstream& operator << (std::ofstream&, const Fleet&);

		//���������� ����������
		Fleet& operator = (const Fleet&);
	};
}
#endif //_FLEET_H_