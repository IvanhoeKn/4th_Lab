#ifndef _SHIP_H_
#define _SHIP_H_
#include <string>
#include <iostream>
#include "stdio.h"
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

		friend std::istream& operator >> (std::istream& is, Captain& Commander) {
			std::cout << " ***Commander***" << std::endl;
			std::cout << " Enter Name: ";
			std::cin >> Commander.Name;
			std::cout << " Enter Rank: ";
			std::cin >> Commander.Rank;
			std::cout << " Enter Experience --> ";
			std::cin >> Commander.Experience;
			return is;
		}

		friend std::ostream& operator << (std::ostream& os, const Captain& Commander) {
			std::cout << " ***Commander***" << std::endl;
			std::cout << " Name: " << Commander.Name << std::endl;
			std::cout << " Rank: " << Commander.Rank << std::endl;
			std::cout << " Experience --> " << Commander.Experience << std::endl;
			return os;
		}

		friend std::ifstream& operator >> (std::ifstream& is, Captain& Commander) {
			int StrLn;
			char NameBuf[80] = "";
			char RankBuf[80] = "";
			is.read((char*) &StrLn, sizeof(int));
			is.read(NameBuf, StrLn);
			Commander.Name = NameBuf;
			is.read((char*) &StrLn, sizeof(int));
			is.read(RankBuf, StrLn);
			Commander.Rank = RankBuf;
			is.read((char*) &Commander.Experience, sizeof(int));
			return is;
		}

		friend std::ofstream& operator << (std::ofstream& os, const Captain& Commander) {
			int tmp;
			tmp = Commander.Name.size();
			os.write((char*) &tmp, sizeof(int));
			os << Commander.Name;
			tmp = Commander.Rank.size();
			os.write((char*) &tmp, sizeof(int));
			os << Commander.Rank;
			os.write((char*) &Commander.Experience, sizeof(int));
			return os;
		}
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
		//---------------------------------
		virtual std::ofstream& fprint(std::ofstream&) const = 0;
		virtual std::ifstream& fread(std::ifstream&) = 0;
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

		//���������� ������ ���������� � ����� �� �����
		friend std::ofstream& operator << (std::ofstream& os, const Ship& ShipTmp) {
			return ShipTmp.fprint(os);
		}
		
		//����� ������ ���������� � ����� � ����
		friend std::ifstream& operator >> (std::ifstream& is, Ship& ShipTmp) {
			return ShipTmp.fread(is);
		}

		//����� ���������� � ����������
		virtual std::ostream& printInfoWeapon(std::ostream&) const = 0;

		//����� ���������� ����������
		virtual int AmountWeapon() const = 0;

		//����������� ��������� �� ������
		virtual Weapon* getWeapon(std::string) const = 0;

		//����������� ���������� �������
		virtual Ship& WeaponModification(std::string, const Weapon&) = 0;

		//��� �������
		virtual int TypeShip() const = 0;

		//����� ���������� ���������
		virtual int AmountAircraft() const = 0;

		//����� ������������� �������
		virtual std::string GetDisguised() const = 0;
	};
}
#endif