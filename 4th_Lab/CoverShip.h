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
		Ship *Disguised;
	public:
		//Конструкторы
		CoverShip() {
			AmountW = 0;
			ArrW = nullptr;
			Disguised = nullptr;
			Crew = NULL;
			Call = "Ship default";	
			MilitaryCharacteristics();
			Commander = new Captain();
		};

		CoverShip(Captain& CommanderTmp, std::string CallTmp, int CrewTmp, MilitaryCharacteristics& CharacteristicsTmp, int AmountTmp, Weapon *ArrTmp, Ship *DisguisedTmp) {
			Call = CallTmp;
			Crew = CrewTmp;
			Commander = new Captain(CommanderTmp);
			AmountW = AmountTmp;
			ArrTmp = new Weapon[AmountW];
			for (int i; i < AmountW; i++)
				ArrW[i] = ArrTmp[i];
			Disguised = DisguisedTmp;
			new MilitaryCharacteristics(CharacteristicsTmp);
		};

		//Копирующий конструктор
		CoverShip(const CoverShip &CoverShipTmp) {
			AmountW = CoverShipTmp.AmountW;
			ArrW = new Weapon[AmountW];
			for (int i = 0; i < AmountW; i++)
				ArrW[i] = CoverShipTmp.ArrW[i];
			Disguised = CoverShipTmp.Disguised;
			MilitaryCharacteristics(CoverShipTmp.Speed, CoverShipTmp.FuelConsumption, CoverShipTmp.FuelReserve);
			Call = CoverShipTmp.Call;
			Crew = CoverShipTmp.Crew;
			Commander = new Captain(*CoverShipTmp.Commander);
		};

		//Деструктор
		~CoverShip() {
			AmountW = NULL;
			delete[] ArrW;
			Disguised = nullptr;
		};

		//Другие методы класса
		friend std::ostream& operator << (std::ostream&, const CoverShip&);

		std::ostream& printInfoWeapon(std::ostream&) const;

		std::ostream& printInfoShip(std::ostream&) const;

		CoverShip& WeaponModification(std::string, Weapon&);

		double TimeFireAllWeapons() const;

		int DamageAllPlanes() const;

		int DamageAllWeapons() const;

		virtual CoverShip* clone() const {
			return new CoverShip(*this);
		}
	};
}
#endif
