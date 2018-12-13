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
		//---------------------------------
		virtual std::ofstream& fprint(std::ofstream&) const;
		virtual std::ifstream& fread(std::ifstream&);
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

		friend std::ofstream& operator << (std::ofstream& os, const Carrier& ShipTmp) {
			return ShipTmp.fprint(os);
		}

		friend std::ifstream& operator >> (std::ifstream& is, Carrier& ShipTmp) {
			return ShipTmp.fread(is);
		}

		std::ostream& printInfoWeapon(std::ostream&) const;

		int DamageAllPlanes() const;

		int DamageAllWeapons() const;

		double TimeFireAllWeapons() const;

		Carrier& WeaponModification(std::string, const Weapon&);

		virtual Carrier* clone() const {
			return new Carrier(*this);
		}

		Weapon* getWeapon(std::string Name) const {
			throw std::exception("No Weapons on Carrier\n");
		}

		int AmountWeapon() const {
			throw std::exception("No Weapons on Carrier\n");
		}

		virtual int TypeShip() const {
			return 2;
		}

		Carrier& AddAircraft(const Aircraft& PlaneTmp) {
			Aircraft* ArrTmp;
			ArrTmp = new Aircraft[AmountP + 1];
			for (int i = 0; i < AmountP; i++)
				ArrTmp[i] = Plane[i];
			ArrTmp[AmountP] = PlaneTmp;
			delete[] Plane;
			AmountP++;
			Plane = ArrTmp;
			return *this;
		}

		Aircraft AircraftDefault;
		Carrier& DeleteAircraft(Aircraft* DeletedAircraft = nullptr) {
			std::cout << " **Aircaft in \"" << Call << "\" **" << std::endl;
			if (AmountP) {
				int Number;
				int Index = 0;
				for (int i = 0; i < AmountP; i++)
					std::cout << " ** №" << i + 1 << "th " << Plane[i];
				std::cout << " Enter number of aircraft to remove --> ";
				std::cin >> Number;
				Aircraft* ArrTmp;
				ArrTmp = new Aircraft[AmountP - 1];
				for (int i = 0; i < AmountP; i++)
					if (i + 1 != Number) {
						ArrTmp[Index] = Plane[i];
						Index++;
					}
				*DeletedAircraft = Plane[Number - 1];
				delete[] Plane;
				Plane = ArrTmp;
				AmountP--;
			}
			return *this;
		}

		double MaxAircraftFlyght() const {
			double MaxFlyght = 0;
			if (AmountP) {
				for (int i = 0; i < AmountP; i++)
					if (Plane[i].GetFuelReserve() / Plane[i].GetFuelConsumption() > MaxFlyght)
						MaxFlyght = Plane[i].GetFuelReserve() / Plane[i].GetFuelConsumption();
				return MaxFlyght;
			}
			else
				return 0;
		}

		double MaxRadiusFlyght() const{
			double MaxRadius = 0;
			if (AmountP) {
				for (int i = 0; i < AmountP; i++)
					if (Plane[i].GetFuelReserve() / Plane[i].GetFuelConsumption() * Plane[i].GetSpeed() > MaxRadius)
						MaxRadius = Plane[i].GetFuelReserve() / Plane[i].GetFuelConsumption() * Plane[i].GetSpeed();
				return MaxRadius;
			}
			else
				return 0;
		}
	};

}
#endif

