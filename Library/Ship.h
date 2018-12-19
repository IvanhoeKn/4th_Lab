/**
@file Ship.h
@brief ������������ ���� � ��������� ������
@detailed ������ ���� �������� � ���� ����������� ������ CoverShip
*/
#ifndef _SHIP_H_
#define _SHIP_H_

#include <string>
#include <iostream>
#include "stdio.h"
#include "Weapon.h"
#include "MilitaryCharacteristics.h"

/**
namespace AircraftCarrierGroup
@brief ������������ ���� AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
	const double eps = 1e-9;

/**
@brief ��������� ��� �������� ��������
@detailed ������������ �������� ���� ���������� ��������� ����� ��� �����
*/
	struct Captain {
		std::string Name;
		std::string Rank;
		int Experience;
/**
@brief ����������� �� ���������
*/
		Captain() : Name("Captain default"), Rank("Ordinary"), Experience(0) {};
/**
@brief ���������������� �����������
@param NameTmp ��� ��������
@param RankTmp ���� ��������
@param ExperienceTmp ����
*/
		Captain(std::string NameTmp, std::string RankTmp, int ExperienceTmp);
/**
@brief ���������� �����������
@param CommanderTmp ���������� � ���������, ���������� �����������
*/
		Captain(const Captain& CommanderTmp);
/**
@brief ����������
*/
		~Captain() {}

		//��������� ����/�����
		friend std::istream& operator >> (std::istream& is, Captain& Commander);
		friend std::ostream& operator << (std::ostream& os, const Captain& Commander);

		//��������� ����/����� �� �����
		friend std::ifstream& operator >> (std::ifstream& is, Captain& Commander);
		friend std::ofstream& operator << (std::ofstream& os, const Captain& Commander);

		//������������� ���������
		Captain& operator = (const Captain&);
		Captain& operator = (Captain&&);
	};

/**
@brief ����������� ����� ��� �������� ��������
@detailed ������������ �������� ����� ���������� �������� � �������� �������, �������������� ��� ���������
*/
	class Ship : public MilitaryCharacteristics {
	protected:
		Captain Commander;
		std::string Call;
		int Crew;
		//---------------------------------
		virtual std::istream& get(std::istream&) = 0;
		virtual std::ostream& show(std::ostream&) const = 0;
		//---------------------------------
		virtual std::ofstream& fprint(std::ofstream&) const = 0;
		virtual std::ifstream& fread(std::ifstream&) = 0;
	public:
/**
@brief ����������� �� ���������
*/
		Ship() : MilitaryCharacteristics(), Call("Ship default"), Commander(), Crew(0) {}
/**
@brief ���������������� �����������
@param CallTmp �������� �������
@param ComanderTmp ������� �����
@param CrewTmp ���������� ������� � �������
@param MilitaryTmp ������ ����� �������������� �������
*/
		Ship(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp);
/**
@brief ���������������� �����������
@param CallTmp �������� �������
@param NameTmp ��� ��������
@param RankTmp ���� ��������
@param ExperienceTmp ���� ��������� �����
@param CrewTmp ���������� ������� � �������
@param MilitaryTmp ������ ����� �������������� �������
*/
		Ship(std::string CallTmp, std::string NameTmp, std::string RankTmp, int ExperienceTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp);
/**
@brief ���������������� �����������
@param CallTmp �������� �������
@param CommanderTmp ���������� � ��������� �����
@param CrewTmp ���������� ������� � �������
@param SpeedTmp �������� �������
@param FuelReserveTmp ����� ������� �����
@param FuelConsumptionTmp ������ ������� �������
*/
		Ship(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp);
/**
@brief ���������������� �����������
@param CallTmp �������� �������
@param NameTmp ��� ��������
@param RankTmp ���� ��������
@param ExperienceTmp ���� ��������� �����
@param CrewTmp ���������� ������� � �������
@param SpeedTmp �������� �������
@param FuelReserveTmp ����� ������� �����
@param FuelConsumptionTmp ������ ������� �������
*/
		Ship(std::string CallTmp, std::string NameTmp, std::string RankTmp, int ExperienceTmp, int CrewTmp, int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp);
/**
@brief ���������� �����������
@param ShipTmp ��������� �������
*/
		Ship(const Ship& ShipTmp);
/**
@brief ����������
*/
		virtual ~Ship() {}
/**
@brief ������������� ������ �������� ��� �������
@param[in] CommanderTmp ���������� � ����� �����������
@return ���������� ���������� ��������� �������
*/
		Ship& setNewCommander(const Captain& CommanderTmp) { Commander = CommanderTmp; return *this; }
/**
@brief ������������� ������ �������� ��� �������
@param[in] CallTmp �������� �������
@return ���������� ���������� ��������� �������
*/
		Ship& setNewCall(std::string CallTmp) { Call = CallTmp; return *this; }
/**
@brief ������������� ���������� ������ �������
@param[in] CrewTmp ���������� ������� � �������
@return ���������� ���������� ��������� �������
*/
		Ship& setNewCrew(int CrewTmp) { Crew = CrewTmp; return *this; }
/**
@brief ���������� ���������� � �������� �����
*/
		Captain getCommander() const { return Commander; }
/**
@brief ���������� �������� �������
*/
		std::string getCall() const { return Call; }
/**
@brief ���������� ���������� ������ ������� �����
*/
		int getCrew() const { return Crew; }
/**
@brief ���������� ������� ������������ ��������� �������� ��� ��������� ���������� �������
*/
		double maxRangeTtransition() const;
/**
@brief ���������� ������� ������� ������� ���� ����� �������� �����
*/
		virtual double TimeFireAllWeapons() const = 0;
/**
@brief ������� ���� �����������, ��������� ����� ���������� ������� �� ������� �������
*/
		virtual int DamageAllPlanes() const = 0;
/**
@brief ������� ���� �����������, ��������� ���� ����������� ������� �� �������� �������
*/
		virtual int DamageAllWeapons() const = 0;
/**
@brief ��������� ���������� ���������� �� �������
*/		
		virtual int AmountWeapon() const = 0;
/**
@brief ��������� ��������� �� ������� ������, � ������� �������� ��� ���������� � ��������� ������
@param NameTmp �������� ������, �� �������� ����� ������������� �����
*/
		virtual Weapon* getWeapon(std::string NameTmp) const = 0;
/**
@brief ������� ������������ ���������, �� ��������� �� �������, ������
@param NameWeaponTmp �������� ������, ������� ���� ��������������
@param WeaponTmp ����� ������
*/
		virtual Ship& WeaponModification(std::string NameWeaponTmp, const Weapon& WeaponTmp) = 0;
/**
@brief ��������� ��� �������
*/
		virtual int TypeShip() const = 0;
/**
@brief ��������� ���������� ��������� �� �����
*/
		virtual int AmountAircraft() const = 0;
/**
@brief ��������� �������� ������������� �������
*/
		virtual std::string GetDisguised() const = 0;
/**
@brief ��������� ������ � �������
*/
		virtual Ship* clone() const = 0;
/**
@brief ����� ���� ���������� �� ��������� ���������� �� �����
*/
		virtual std::ostream& printInfoWeapon(std::ostream&) const = 0;

		//��������� ����/�����
		friend std::ostream& operator << (std::ostream& os, const Ship& ShipTmp) { return ShipTmp.show(os); }
		friend std::istream& operator >> (std::istream& is, Ship& ShipTmp) { return ShipTmp.get(is); }

		//��������� ����/����� �� �����
		friend std::ofstream& operator << (std::ofstream& os, const Ship& ShipTmp) { return ShipTmp.fprint(os); }
		friend std::ifstream& operator >> (std::ifstream& is, Ship& ShipTmp) { return ShipTmp.fread(is); }
	};
}
#endif //_SHIP_H_