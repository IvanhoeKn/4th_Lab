#ifndef _COVER_H_
#define _COVER_H_
#include <iostream>
#include "Ship.h"

namespace AircraftСarrierGroup
{

	class CoverShip : public Ship {
	protected:
		int AmountW;
		Weapon *ArrW;
		std::string Disguised;
		//---------------------------------
		virtual std::ostream& show(std::ostream& os) const;
		virtual std::istream& get(std::istream&);
	public:
		//Конструкторы
		CoverShip() : Ship(), Disguised("Covered Ship default"), AmountW(0), ArrW(nullptr) {}

		CoverShip(std::string, const Captain&, int, const MilitaryCharacteristics&, std::string, int, Weapon *);

		//Копирующий конструктор
		CoverShip(const CoverShip &CoverShipTmp);

		//---------------------------------

		//Деструктор
		~CoverShip() {
			delete[] ArrW;
		}

		//---------------------------------

		//Другие методы класса
		friend std::ostream& operator << (std::ostream&, const CoverShip&);

		friend std::istream& operator >> (std::istream&, CoverShip&);

		std::ostream& printInfoWeapon(std::ostream&) const;

		CoverShip& WeaponModification(std::string, const Weapon&);

		double TimeFireAllWeapons() const;

		int DamageAllPlanes() const;

		int DamageAllWeapons() const;

		virtual CoverShip* clone() const {
			return new CoverShip(*this);
		}
	};
}
#endif
