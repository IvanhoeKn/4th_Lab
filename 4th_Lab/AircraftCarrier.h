#ifndef _AIRCRAFT_CARRIER_H_
#define _AIRCRAFT_CARRIER_H_
#include <iostream>
#include "Carrier.h"

namespace AircraftСarrierGroup
{

	class AircraftCarrier : public Carrier {
	protected:
		int AmountW;
		Weapon *ArrW;
		//---------------------------------
		virtual std::ostream& show(std::ostream& os) const;
		virtual std::istream& get(std::istream&);
		//---------------------------------
		virtual std::ofstream& fprint(std::ofstream&) const;
		virtual std::ifstream& fread(std::ifstream&);
	public:
		AircraftCarrier() : Carrier(), AmountW(0), ArrW(nullptr) {}

		AircraftCarrier(std::string, const Captain&, int, const MilitaryCharacteristics&, int, Aircraft*, int, Weapon*);

		//Копирующий конструктор
		AircraftCarrier(const AircraftCarrier&);

		//---------------------------------

		//Деструктор
		~AircraftCarrier() {
			delete[] ArrW;
		}

		//---------------------------------

		//Другие методы класса
		friend std::ostream& operator << (std::ostream&, const AircraftCarrier&);

		friend std::istream& operator >> (std::istream&, AircraftCarrier&);

		friend std::ofstream& operator << (std::ofstream& os, const AircraftCarrier& ShipTmp) {
			return ShipTmp.fprint(os);
		}

		friend std::ifstream& operator >> (std::ifstream& is, AircraftCarrier& ShipTmp) {
			return ShipTmp.fread(is);
		}

		std::ostream& printInfoWeapon(std::ostream&) const;

		int DamageAllWeapons() const;

		double TimeFireAllWeapons() const;

		AircraftCarrier& WeaponModification(std::string, Weapon&);

		virtual AircraftCarrier* clone() const {
			return new AircraftCarrier(*this);
		}

		Weapon* getWeapon(std::string Name) const {
			for (int i = 0; i < AmountW; i++)
				if (ArrW[i].GetWeapon() == Name)
					return *ArrW[i];
			return nullptr;
		}

		int AmountWeapon() const {
			return AmountW;
		}

		virtual int TypeShip() const {
			return 3;
		}
	};
}
#endif

