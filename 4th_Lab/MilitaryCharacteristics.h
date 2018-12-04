#ifndef _CHARACTERISTICS_H_
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
		MilitaryCharacteristics() : Speed(0), FuelReserve(0), FuelConsumption(0) {}

		MilitaryCharacteristics(int, int, int);

		//���������� �����������
		MilitaryCharacteristics(const MilitaryCharacteristics&);

		//---------------------------------

		//����������
		virtual ~MilitaryCharacteristics() {}

		//---------------------------------

		//������ ������ ������
		MilitaryCharacteristics& SetSpeed(int SpeedTmp) { Speed = SpeedTmp; return *this; }

		MilitaryCharacteristics& SetFuelReserve(int FuelReserveTmp) { FuelReserve = FuelReserveTmp; return *this; }

		MilitaryCharacteristics& SetFuelConsumption(int FuelConsumptionTmp) { FuelConsumption = FuelConsumptionTmp;  return *this; }

		int GetSpeed() const { return Speed; }

		int GetFuelReserve() const { return FuelReserve; }

		int GetFuelConsumption() const { return FuelConsumption; }

		//��������� ����/�����
		friend std::ostream& operator << (std::ostream&, const MilitaryCharacteristics&);

		friend std::istream& operator >> (std::istream&, MilitaryCharacteristics&);

		//������������� ���������
		MilitaryCharacteristics& operator = (const MilitaryCharacteristics& Military);

		MilitaryCharacteristics& operator = (MilitaryCharacteristics&& Military);
	};
}
#endif