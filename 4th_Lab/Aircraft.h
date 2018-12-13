#ifndef _AIRCRAFT_H_
#define _AIRCRAFT_H_
#include <iostream>
#include <fstream>
#include "Weapon.h"
#include "MilitaryCharacteristics.h"

namespace Aircraft�arrierGroup
{

	class Aircraft : public MilitaryCharacteristics {
	protected:
		static const int QUOTA = 3;
		int Amount;
		Weapon *Arr;
	public:
		//������������
		Aircraft() : MilitaryCharacteristics(), Amount(0), Arr(nullptr) {}

		Aircraft(int SpeedTmp, int FuelReserveTmp, int FuelConsumptionTmp) : MilitaryCharacteristics(SpeedTmp, FuelConsumptionTmp, FuelReserveTmp), Amount(0), Arr(nullptr) {}

		Aircraft(int, int, int, int, Weapon*);

		Aircraft(const MilitaryCharacteristics&, int, Weapon*);
		
		//���������� �����������
		Aircraft(const Aircraft& Plane);

		//---------------------------------

		//����������
		~Aircraft() {
			delete [] Arr;
		};

		//---------------------------------

		//������ ������ ������
		Weapon& getWeaponAircraft(int) const;

		int getAmountWeapon() const { return Amount; }

		//��������� ����/�����
		friend std::ostream& operator << (std::ostream&, const Aircraft&);

		friend std::istream& operator >> (std::istream&, Aircraft&);

		//��������� ����/����� �� �����
		friend std::ofstream& operator << (std::ofstream&, const Aircraft&);

		friend std::ifstream& operator >> (std::ifstream&, Aircraft&);

		//������������� ���������
		Aircraft& operator = (const Aircraft& Plane);

		Aircraft& operator = (Aircraft&& Plane);
	};
}
#endif
