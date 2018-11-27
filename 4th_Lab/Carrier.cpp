#include "pch.h"
#include "Carrier.h"

namespace Aircraft—arrierGroup {

	std::ostream& operator << (std::ostream& os, const Carrier& CarrierTmp) {
		return CarrierTmp.printInfoShip(os);
	};

	std::ostream& Carrier::printInfoShip(std::ostream& os) const {
		os << std::endl << "***Carrier***" << Call << " ***" << std::endl;
		os << " *Commander*" << std::endl;
		os << "   Name: " << Commander->Name << std::endl;
		os << "   Rank: " << Commander->Rank << std::endl;
		os << "   Experience: " << Commander->Experience << std::endl;
		os << " *Amount of people in Crew: " << Crew << std::endl;
		os << " *Military Characteristics of Carrier*" << std::endl;
		os << "   Speed--> " << Speed << std::endl;
		os << "   Fuel Consumption--> " << FuelConsumption << std::endl;
		os << "   Fuel Reserve--> " << FuelReserve << std::endl;
		return os;
	};

	std::ostream& Carrier::printInfoWeapon(std::ostream& os) const {
		os << " **Weapon of Carrier**" << std::endl;
		os << "   No weapons on Carrier" << std::endl;
		return os;
	};
	
	int Carrier::DamageAllPlanes() const {
		int Sum = 0;
		for (int i = 0; i < AmountP; i++) {
			Aircraft PlaneTmp = Plane[i];
			for (int j = 0; j < PlaneTmp.getAmountWeapon(); j++)
				Sum += PlaneTmp.getWeaponAircraft(j).GetDamage();
		}
		return Sum;
	};

	int Carrier::DamageAllWeapons() const {
		throw std::exception("No Weapons on Carrier\n");
	};

	double Carrier::TimeFireAllWeapons() const {
		throw std::exception("No Weapons on Carrier\n");
	};

	Carrier& Carrier::WeaponModification(std::string NameWeaponTmp, Weapon& WeaponTmp) {
		throw std::exception("No Weapons on Carrier\n");
	};
}