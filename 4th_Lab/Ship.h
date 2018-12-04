#ifndef _SHIP_H_
#define _SHIP_H_
#include <string>
#include <iostream>
#include "Weapon.h"
#include "MilitaryCharacteristics.h"


namespace Aircraft�arrierGroup
{
	const double eps = 1e-9;

	//------------------------------------------------------------
	//------------------------------------------------------------

	struct Captain {
		std::string Name;
		std::string Rank;
		int Experience;

		//�����������
		Captain() : Name("Captain default"), Rank("Ordinary"), Experience(0) {};

		Captain(std::string, std::string, int);

		//���������� �����������
		Captain(const Captain&);

		//---------------------------------

		//����������
		~Captain() {}

		//---------------------------------

		//������������� ���������
		Captain& operator = (const Captain&);
		Captain& operator = (Captain&&);
	};

	//------------------------------------------------------------
	//------------------------------------------------------------

	class Ship : public MilitaryCharacteristics {
	protected:
		Captain Commander;
		std::string Call;
		int Crew;
		//---------------------------------
		virtual std::istream& get(std::istream&) = 0;
		virtual std::ostream& show(std::ostream&) const = 0;
	public:
		//������������
		Ship() : MilitaryCharacteristics(), Call("Ship default"), Commander(), Crew(0) {}

		Ship(const std::string, const Captain&,  int, const MilitaryCharacteristics&);

		Ship(std::string, std::string, std::string, int, int, const MilitaryCharacteristics&);

		Ship(std::string, const Captain&, int, int, int, int);

		Ship(std::string, std::string, std::string, int, int, int, int, int);

		//���������� �����������
		Ship(const Ship&);

		//---------------------------------

		//����������
		virtual ~Ship() {}

		//---------------------------------

		//������ ������ ������
		virtual Ship* clone() const = 0;

		Ship& setNewCommander(const Captain& CommanderTmp) { Commander = CommanderTmp; return *this; }

		Ship& setNewCall(std::string CallTmp) { Call = CallTmp; return *this; }

		Ship& setNewCrew(int CrewTmp) { Crew = CrewTmp; return *this; }

		Captain getCommander() const { return Commander; }

		std::string getCall() const { return Call; }

		int getCrew() const { return Crew; }

		//������������ �������
		double maxRangeTtransition() const;

		//����� ������� ���� ����� ��������
		virtual double TimeFireAllWeapons() const = 0;

		//����������, ��������� ����� ���������� ������� �� ������� �������
		virtual int DamageAllPlanes() const = 0;

		//����������, ��������� ���� ����������� ������� �� �������� �������
		virtual int DamageAllWeapons() const = 0;

		//����� ������ ���������� � ����� � �����
		friend std::ostream& operator << (std::ostream& os, const Ship& ShipTmp) {
			return ShipTmp.show(os);
		}

		//���� ������ ���������� � ����� �� ������
		friend std::istream& operator >> (std::istream& is, Ship& ShipTmp) {
			return ShipTmp.get(is);
		}

		//����� ���������� � ����������
		virtual std::ostream& printInfoWeapon(std::ostream&) const = 0;

		//����������� ���������� �������
		virtual Ship& WeaponModification(std::string, const Weapon&) = 0;
	};
}
#endif