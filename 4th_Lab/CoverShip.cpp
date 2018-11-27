#include "pch.h"
#include "CoverShip.h"

namespace Aircraft—arrierGroup {

	std::ostream& operator << (std::ostream& os, const CoverShip& CoverShipTmp) {
		return CoverShipTmp.printInfoShip(os);
	};

	std::ostream& CoverShip::printInfoShip(std::ostream& os) const {
		os << std::endl << "***CoverShip***" << Call << " ***" << std::endl;
		os << " *Commander*" << std::endl;
		os << "   Name: " << Commander->Name << std::endl;
		os << "   Rank: " << Commander->Rank << std::endl;
		os << "   Experience: " << Commander->Experience << std::endl;
		os << " *Amount of people in Crew: " << Crew << std::endl;
		os << " *Covered ship: " << Disguised->getCall() << std::endl;
		os << " *Military Characteristics of CoverShip*" << std::endl;
		os << "   Speed--> " << Speed << std::endl;
		os << "   Fuel Consumption--> " << FuelConsumption << std::endl;
		os << "   Fuel Reserve--> " << FuelReserve << std::endl;
		return os;
	};

	std::ostream& CoverShip::printInfoWeapon(std::ostream& os) const {
		os << " **Weapon of Cover Ship**" << std::endl;
		if (!AmountW)
			os << "   No weapons on Cover Ship" << std::endl;
		else
			for (int i = 0; i < AmountW; i++)
				os << ArrW[i];
		return os;
	};

	CoverShip& CoverShip::WeaponModification(std::string NameWeaponTmp, Weapon& WeaponTmp) {
		Weapon* ptr = ArrW;
		while (ptr->GetWeapon() != WeaponTmp.GetWeapon())
			ptr++;
		*ptr = WeaponTmp;
		return* this;
	};

	double CoverShip::TimeFireAllWeapons() const {
		double max = 0;
		for (int i = 0; i < AmountW; i++) {
			double TimeTmp = ArrW[i].GetQuantityAmmunition() / ArrW[i].GetRateFire();
			if (TimeTmp - max < eps)
				max = TimeTmp;
		}
		return max;
	};

	int CoverShip::DamageAllPlanes() const {
		throw std::exception("No Planes on Cover Ship\n");
	};

	int CoverShip::DamageAllWeapons() const {
		int Sum = 0;
		for (int i = 0; i < AmountW; i++)
			Sum += ArrW[i].GetDamage();
		return Sum;
	};

}