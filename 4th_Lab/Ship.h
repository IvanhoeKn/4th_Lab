#ifndef _SHIP_H_
#define _SHIP_H_
#include <string>
#include <iostream>
#include "Weapon.h"
#include "MilitaryCharacteristics.h"


namespace Aircraft�arrierGroup
{
	const double eps = 1e-9;

	struct Captain {
		std::string Name;
		std::string Rank;
		int Experience;

		//�����������
		Captain();

		Captain(std::string, std::string, int);

		//���������� �����������
		Captain(Captain&);

		//------------------------------------------------------------

		//����������
		~Captain();

		//------------------------------------------------------------

		//������������� ���������
		Captain& operator = (Captain&);

	};

	//------------------------------------------------------------
	//------------------------------------------------------------

	class Ship : public MilitaryCharacteristics {
	protected:
		Captain* Commander;
		std::string Call;
		int Crew;
	public:
		//������������
		Ship();

		Ship(Captain&, std::string, int, MilitaryCharacteristics&);

		Ship(std::string, std::string, int, std::string, int, MilitaryCharacteristics&);

		Ship(Captain&, std::string, int, int, int, int);

		Ship(std::string, std::string, int, std::string, int, int, int, int);

		//���������� �����������
		Ship(Ship&);

		//------------------------------------------------------------

		//����������
		~Ship();

		//------------------------------------------------------------

		//������ ������ ������
		virtual Ship* clone() const = 0;

		Ship& setNewCommander(Captain&);

		Ship& setNewCall(std::string);

		Ship& setNewCrew(int);

		Captain getCommander() const { return* Commander; };

		std::string getCall() const { return Call; };

		int getCrew() const { return Crew; };

		//������������ �������
		double maxRangeTtransition() const ;

		//����� ������� ���� ����� ��������
		virtual double TimeFireAllWeapons() const = 0;

		//����������, ��������� ����� ���������� ������� �� ������� �������
		virtual int DamageAllPlanes() const = 0;

		//����������, ��������� ���� ����������� ������� �� �������� �������
		virtual int DamageAllWeapons() const = 0;

		//����� ������ ���������� � ����� � �����
		virtual std::ostream& printInfoShip(std::ostream&) const = 0;

		//����� ���������� � ����������
		virtual std::ostream& printInfoWeapon(std::ostream&) const = 0;

		//����������� ���������� �������
		virtual Ship& WeaponModification(std::string, Weapon&) = 0;
	};
}
#endif