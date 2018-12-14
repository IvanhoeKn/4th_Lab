#ifndef _COVER_H_
#define _COVER_H_
#include <iostream>
#include <fstream>
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
		//---------------------------------
		virtual std::ofstream& fprint(std::ofstream&) const;
		virtual std::ifstream& fread(std::ifstream&);
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

		friend std::ofstream& operator << (std::ofstream& os, const CoverShip& ShipTmp) {
			return ShipTmp.fprint(os);
		}

		friend std::ifstream& operator >> (std::ifstream& is, CoverShip& ShipTmp) {
			return ShipTmp.fread(is);
		}

		std::ostream& printInfoWeapon(std::ostream&) const;

		CoverShip& WeaponModification(std::string, const Weapon&);

		double TimeFireAllWeapons() const;

		int DamageAllPlanes() const;

		int DamageAllWeapons() const;

		virtual CoverShip* clone() const {
			return new CoverShip(*this);
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
			return 1;
		}

		int AmountAircraft() const {
			throw std::exception("No Aircrafts on Cover Ship\n");
		}
	};
}
#endif
