#ifndef _AIRCRAFT_CARRIER_H_
#define _AIRCRAFT_CARRIER_H_
#include <iostream>
#include "Carrier.h"

namespace Aircraft—arrierGroup
{

	class AircraftCarrier : public Carrier {
	protected:
		int AmountW;
		Weapon *ArrW;
	public:
		AircraftCarrier() :Carrier() {
			int AmountW = 0;
			ArrW = nullptr;
		};

		AircraftCarrier(Captain& CommanderTmp, std::string CallTmp, int CrewTmp, MilitaryCharacteristics& CharacteristicsTmp, int AmountPTmp, Aircraft* PlaneTmp, int AmountWTmp, Weapon* ArrWTmp) {
			Carrier(CommanderTmp, CallTmp, CrewTmp, CharacteristicsTmp, AmountPTmp, PlaneTmp);
			AmountW = AmountWTmp;
			ArrW = new Weapon[AmountW];
			for (int i = 0; i < AmountW; i++)
				ArrW[i] = ArrWTmp[i];

		};

		// ÓÔËÛ˛˘ËÈ ÍÓÌÒÚÛÍÚÓ
		AircraftCarrier(const AircraftCarrier& AircraftCarrierTmp) {
			const Carrier* ptr = &AircraftCarrierTmp;
			new Carrier(*ptr);
			AmountW = AircraftCarrierTmp.AmountW;
			ArrW = new Weapon[AmountW];
			for (int i = 0; i < AmountW; i++)
				ArrW[i] = AircraftCarrierTmp.ArrW[i];
		};

		//ƒÂÒÚÛÍÚÓ
		~AircraftCarrier() {
			AmountW = NULL;
			delete[] ArrW;
		};

		//ƒÛ„ËÂ ÏÂÚÓ‰˚ ÍÎ‡ÒÒ‡
		friend std::ostream& operator << (std::ostream&, const Carrier&);

		std::ostream& printInfoWeapon(std::ostream&) const;

		std::ostream& printInfoShip(std::ostream&) const;

		int DamageAllWeapons() const;

		double TimeFireAllWeapons() const;

		AircraftCarrier& WeaponModification(std::string, Weapon&);

		virtual AircraftCarrier* clone() const {
			return new AircraftCarrier(*this);
		}
	};
}
#endif

