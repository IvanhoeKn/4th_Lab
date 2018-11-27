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
	public:
		//Конструкторы
		Carrier() {
			AmountP = NULL;
			Plane = nullptr;
			Crew = NULL;
			Call = "Ship default";
			MilitaryCharacteristics();
			Commander = new Captain();
		};

		Carrier(Captain& CommanderTmp, std::string CallTmp, int CrewTmp, MilitaryCharacteristics& CharacteristicsTmp, int AmountPTmp, Aircraft* PlaneTmp) {
			Call = CallTmp;
			Crew = CrewTmp;
			Commander = new Captain(CommanderTmp);
			AmountP = AmountPTmp;
			Plane = new Aircraft[AmountP];
			for (int i = 0; i < AmountP; i++)
				Plane[i] = PlaneTmp[i];
			new MilitaryCharacteristics(CharacteristicsTmp);
		};

		//Копирующий конструктор
		Carrier(const Carrier& CarrierTmp) {
			Call = CarrierTmp.Call;
			Crew = CarrierTmp.Crew;
			Commander = new Captain(*CarrierTmp.Commander);
			AmountP = CarrierTmp.AmountP;
			Plane = new Aircraft[AmountP];
			for (int i = 0; i < AmountP; i++)
				Plane[i] = CarrierTmp.Plane[i];
			new MilitaryCharacteristics(CarrierTmp.Speed, CarrierTmp.FuelConsumption, CarrierTmp.FuelReserve);
		}

		~Carrier() {
			AmountP = NULL;
			delete[] Plane;
		};

		//Другие методы класса
		friend std::ostream& operator << (std::ostream&, const Carrier&);

		std::ostream& printInfoWeapon(std::ostream&) const;

		std::ostream& printInfoShip(std::ostream&) const;

		int DamageAllPlanes() const;

		int DamageAllWeapons() const;

		double TimeFireAllWeapons() const;

		Carrier& WeaponModification(std::string, Weapon&);

		virtual Carrier* clone() const {
			return new Carrier(*this);
		}
	};
}
#endif

