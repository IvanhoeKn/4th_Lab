#include "pch.h"
#include "CoverShip.h"

namespace Aircraft�arrierGroup {

	//������������
	CoverShip::CoverShip(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp, std::string DisguisedTmp, int AmountTmp, Weapon *ArrTmp) : Ship(CallTmp, CommanderTmp, CrewTmp, MilitaryTmp) {
		Disguised = DisguisedTmp;
		AmountW = AmountTmp;
		ArrTmp = new Weapon[AmountW];
		for (int i = 0; i < AmountW; i++)
			ArrW[i] = ArrTmp[i];
	}

	//------------------------------------------------------------

	//���������� �����������
	CoverShip::CoverShip(const CoverShip &CoverShipTmp) {
		Call = CoverShipTmp.Call;
		//---------------------------------
		Commander = CoverShipTmp.Commander;
		Disguised = CoverShipTmp.Disguised;
		//---------------------------------
		Speed = CoverShipTmp.Speed;
		FuelConsumption = CoverShipTmp.FuelConsumption;
		FuelReserve = CoverShipTmp.FuelReserve;
		//---------------------------------
		AmountW = CoverShipTmp.AmountW;
		ArrW = new Weapon[AmountW];
		for (int i = 0; i < AmountW; i++)
			ArrW[i] = CoverShipTmp.ArrW[i];
	}

	//------------------------------------------------------------

	std::istream& CoverShip::get(std::istream& is) {
		std::cout << " ***CoverShip***" << std::endl;
		//---------------------------------
		std::cout << " Enter Call of Cover Ship: ";
		is >> Call;
		std::cout << " Enter Call of Disguised Ship: ";
		is >> Disguised;
		//---------------------------------
		std::cout << "  *Commander*" << std::endl;
		std::cout << "  Enter name captain: ";
		is >> Commander.Name;
		std::cout << "  Enter rank captain: ";
		is >> Commander.Rank;
		std::cout << "  Enter experience captain --> ";
		is >> Commander.Experience;
		//---------------------------------
		std::cout << " Enter Crew of Cover Ship --> ";
		is >> Crew;
		//---------------------------------
		std::cout << "  *Military characteristics*" << std::endl;
		MilitaryCharacteristics MilitaryTmp;
		is >> MilitaryTmp;
		Speed = MilitaryTmp.GetSpeed();
		FuelConsumption = MilitaryTmp.GetFuelConsumption();
		FuelReserve = MilitaryTmp.GetFuelReserve();
		//---------------------------------
		std::cout << " Enter Amount of Weapon: ";
		is >> AmountW;
		ArrW = new Weapon[AmountW];
		for (int i = 0; i < AmountW; i++)
			is >> ArrW[i];
		return is;
	}

	std::istream& operator >> (std::istream& is, CoverShip& CoverShipTmp) {
		return CoverShipTmp.get(is);
	}

	//------------------------------------------------------------

	std::ostream& CoverShip::show(std::ostream& os) const {
		os << "***CoverShip*** " << Call << " ***" << std::endl;
		//---------------------------------
		os << " *Commander*" << std::endl;
		os << "   Name: " << Commander.Name << std::endl;
		os << "   Rank: " << Commander.Rank << std::endl;
		os << "   Experience: " << Commander.Experience << std::endl;
		//---------------------------------
		os << " *Disguised Ship: " << Disguised << std::endl;
		os << " *Amount of people in Crew: " << Crew << std::endl;
		//---------------------------------
		os << " *Military Characteristics of Carrier*" << std::endl;
		os << "   Speed --> " << Speed << std::endl;
		os << "   Fuel Consumption --> " << FuelConsumption << std::endl;
		os << "   Fuel Reserve --> " << FuelReserve << std::endl;
		//---------------------------------
		os << " *Amount of Weapon --> " << AmountW << std::endl;
		for (int i = 0; i < AmountW; i++) {
			os << std::endl;
			os << ArrW[i];
		}
		os << "*** *** ***" << std::endl;
		return os;
	}

	std::ostream& operator << (std::ostream& os, const CoverShip& CoverShipTmp) {
		return CoverShipTmp.show(os);
	}

	//------------------------------------------------------------

	std::ostream& CoverShip::printInfoWeapon(std::ostream& os) const {
		os << " **Weapon of Cover Ship**" << std::endl;
		if (!AmountW)
			os << "   No weapons on Cover Ship" << std::endl;
		else
			for (int i = 0; i < AmountW; i++)
				os << ArrW[i];
		return os;
	}

	//------------------------------------------------------------

	CoverShip& CoverShip::WeaponModification(std::string NameWeaponTmp, const Weapon& WeaponTmp) {
		Weapon* ptr = ArrW;
		while (ptr->GetWeapon() != WeaponTmp.GetWeapon())
			ptr++;
		*ptr = WeaponTmp;
		return* this;
	}

	//------------------------------------------------------------

	double CoverShip::TimeFireAllWeapons() const {
		double max = 0;
		for (int i = 0; i < AmountW; i++) {
			double TimeTmp = ArrW[i].GetQuantityAmmunition() / ArrW[i].GetRateFire();
			if (TimeTmp - max < eps)
				max = TimeTmp;
		}
		return max;
	}

	//------------------------------------------------------------

	int CoverShip::DamageAllPlanes() const {
		throw std::exception("No Planes on Cover Ship\n");
	}

	//------------------------------------------------------------

	int CoverShip::DamageAllWeapons() const {
		int Sum = 0;
		for (int i = 0; i < AmountW; i++)
			Sum += ArrW[i].GetDamage();
		return Sum;
	}

}