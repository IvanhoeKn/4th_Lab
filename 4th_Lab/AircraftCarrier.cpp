#include "pch.h"
#include "AircraftCarrier.h"

namespace Aircraft—arrierGroup {

	std::ostream& operator << (std::ostream& os, const AircraftCarrier& AircraftCarrierTmp) {
		return AircraftCarrierTmp.printInfoShip(os);
	};

	std::ostream& AircraftCarrier::printInfoShip(std::ostream& os) const {
		os << std::endl << "***AircraftCarrier***" << Call << " ***" << std::endl;
		os << " *Commander*" << std::endl;
		os << "   Name: " << Commander->Name << std::endl;
		os << "   Rank: " << Commander->Rank << std::endl;
		os << "   Experience: " << Commander->Experience << std::endl;
		os << " *Amount of people in Crew: " << Crew << std::endl;
		os << " *Military Characteristics of AircraftCarrier*" << std::endl;
		os << "   Speed--> " << Speed << std::endl;
		os << "   Fuel Consumption--> " << FuelConsumption << std::endl;
		os << "   Fuel Reserve--> " << FuelReserve << std::endl;
		return os;
	};

	std::ostream& AircraftCarrier::printInfoWeapon(std::ostream& os) const {
		os << " **Weapon of Aircraft Carrier**" << std::endl;
		if (!AmountW)
			os << "   No weapons on Aircraft Carrier" << std::endl;
		else
			for (int i = 0; i < AmountW; i++)
				os << ArrW[i];
		return os;
	};

	AircraftCarrier& AircraftCarrier::WeaponModification(std::string NameWeaponTmp, Weapon& WeaponTmp) {
		Weapon* ptr = ArrW;
		while (ptr->GetWeapon() != WeaponTmp.GetWeapon())
			ptr++;
		*ptr = WeaponTmp;
		return*this;
	};

	double AircraftCarrier::TimeFireAllWeapons() const {
		double max = 0;
		for (int i = 0; i < AmountW; i++) {
			double TimeTmp = ArrW[i].GetQuantityAmmunition() / ArrW[i].GetRateFire();
			if (TimeTmp - max < eps)
				max = TimeTmp;
		}
		return max;
	};

	int AircraftCarrier::DamageAllWeapons() const {
		int Sum = 0;
		for (int i = 0; i < AmountW; i++)
			Sum += ArrW[i].GetDamage();
		return Sum;
	};
	
}
