#ifndef _WEAPON_H_
#define _CHARACTERISTICS_H_
#include <iostream>

namespace Aircraft�arrierGroup
{

	class MilitaryCharacteristics {
	protected:
		int Speed;
		int FuelReserve;
		int FuelConsumption;
	public:
		//������������
		MilitaryCharacteristics() : Speed(0), FuelReserve(0), FuelConsumption(0) {};

		MilitaryCharacteristics(int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp = 0) {
			Speed = SpeedTmp;
			FuelReserve = FuelReserveTmp;
			FuelConsumption = FuelConsumptionTmp;
		};

		//����������
		~MilitaryCharacteristics() {
			Speed = 0;
			FuelReserve = 0;
			FuelConsumption = 0;
		};

		//������ ������ ������
		MilitaryCharacteristics& SetWeapon(int SpeedTmp) { Speed = SpeedTmp; };

		MilitaryCharacteristics& SetMunition(int FuelReserveTmp) { FuelReserve = FuelReserveTmp; };

		MilitaryCharacteristics& SetRateFire(int FuelConsumptionTmp) { FuelConsumption = FuelConsumptionTmp; };

		int GetSpeed() const { return Speed; };

		int GetFuelReserve() const { return FuelReserve; };

		int GetFuelConsumption() const { return FuelConsumption; };

		//��������� ����/�����
		friend std::ostream& operator << (std::ostream&, const MilitaryCharacteristics&);

		friend std::istream& operator >> (std::istream&, MilitaryCharacteristics&);
	};
}
#endif