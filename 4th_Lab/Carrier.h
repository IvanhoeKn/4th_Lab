#ifndef _CARRIER_H_
#define _CARRIER_H_
#include <iostream>
#include "Ship.h"
#include "Aircraft.h"

namespace AircraftСarrierGroup
{

	class Carrier : public Ship {
	protected:
		int AmountP;
		Aircraft* Plane;
		//---------------------------------
		virtual std::ostream& show(std::ostream& os) const;
		virtual std::istream& get(std::istream&);
	public:
		//Конструкторы
		Carrier() : Ship(), AmountP(0), Plane(nullptr) {}

		Carrier(std::string, const Captain&, int, const MilitaryCharacteristics&, int, Aircraft*);

		//Копирующий конструктор
		Carrier(const Carrier&);

		//---------------------------------

		//Деструктор
		virtual ~Carrier() {
			delete[] Plane;
		}

		//---------------------------------

		//Другие методы класса
		friend std::ostream& operator << (std::ostream&, const Carrier&);

		friend std::istream& operator >> (std::istream&, Carrier&);

		std::ostream& printInfoWeapon(std::ostream&) const;

		int DamageAllPlanes() const;

		int DamageAllWeapons() const;

		double TimeFireAllWeapons() const;

		Carrier& WeaponModification(std::string, const Weapon&);

		virtual Carrier* clone() const {
			return new Carrier(*this);
		}
	};
}
#endif

