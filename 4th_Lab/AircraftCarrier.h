#ifndef _AIRCRAFT_CARRIER_H_
#define _AIRCRAFT_CARRIER_H_
#include <iostream>
#include "Carrier.h"

namespace Aircraft�arrierGroup
{

	class AircraftCarrier : public Carrier {
	protected:
		int AmountW;
		Weapon *ArrW;
		//---------------------------------
		virtual std::ostream& show(std::ostream& os) const;
		virtual std::istream& get(std::istream&);
	public:
		AircraftCarrier() : Carrier(), AmountW(0), ArrW(nullptr) {}

		AircraftCarrier(std::string, const Captain&, int, const MilitaryCharacteristics&, int, Aircraft*, int, Weapon*);

		//���������� �����������
		AircraftCarrier(const AircraftCarrier&);

		//---------------------------------

		//����������
		~AircraftCarrier() {
			delete[] ArrW;
		}

		//---------------------------------

		//������ ������ ������
		friend std::ostream& operator << (std::ostream&, const AircraftCarrier&);

		friend std::istream& operator >> (std::istream&, AircraftCarrier&);

		std::ostream& printInfoWeapon(std::ostream&) const;

		int DamageAllWeapons() const;

		double TimeFireAllWeapons() const;

		AircraftCarrier& WeaponModification(std::string, Weapon&);

		virtual AircraftCarrier* clone() const {
			return new AircraftCarrier(*this);
		}
	};
}
#endif

