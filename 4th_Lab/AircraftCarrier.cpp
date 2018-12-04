#include "pch.h"
#include "AircraftCarrier.h"

namespace Aircraft�arrierGroup {

	//������������
	AircraftCarrier::AircraftCarrier(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp, int AmountPTmp, Aircraft* PlaneTmp, int AmountWTmp, Weapon* ArrWTmp) : Carrier(CallTmp, CommanderTmp, CrewTmp, MilitaryTmp, AmountPTmp, PlaneTmp) {
		AmountW = AmountWTmp;
		ArrW = new Weapon[AmountW];
		for (int i = 0; i < AmountW; i++)
			ArrW[i] = ArrWTmp[i];
	}

	//------------------------------------------------------------

	//���������� �����������
	AircraftCarrier::AircraftCarrier(const AircraftCarrier& AerocarrierTmp) {
		Call = AerocarrierTmp.Call;
		//---------------------------------
		Commander = AerocarrierTmp.Commander;
		//---------------------------------
		Speed = AerocarrierTmp.Speed;
		FuelConsumption = AerocarrierTmp.FuelConsumption;
		FuelReserve = AerocarrierTmp.FuelReserve;
		//---------------------------------
		AmountP = AerocarrierTmp.AmountP;
		Plane = new Aircraft[AmountP];
		for (int i = 0; i < AmountW; i++)
			Plane[i] = AerocarrierTmp.Plane[i];
		//---------------------------------
		AmountW = AerocarrierTmp.AmountW;
		ArrW = new Weapon[AmountW];
		for (int i = 0; i < AmountW; i++)
			ArrW[i] = AerocarrierTmp.ArrW[i];
	}

	//------------------------------------------------------------

	std::istream& AircraftCarrier::get(std::istream& is) {
		std::cout << " ***AircraftCarrier***" << std::endl;
		//---------------------------------
		std::cout << " Enter Call of Aircraft Carrier: ";
		is >> Call;
		//---------------------------------
		std::cout << "  *Commander*" << std::endl;
		std::cout << "  Enter name captain: ";
		is >> Commander.Name;
		std::cout << "  Enter rank captain: ";
		is >> Commander.Rank;
		std::cout << "  Enter experience captain --> ";
		is >> Commander.Experience;
		//---------------------------------
		std::cout << " Enter Crew of Aircraft Carrier --> ";
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
		//---------------------------------
		std::cout << " Enter Amount of Aircraft: ";
		is >> AmountP;
		Plane = new Aircraft[AmountP];
		for (int i = 0; i < AmountP; i++)
			is >> Plane[i];
		return is;
	}

	std::istream& operator >> (std::istream& is, AircraftCarrier& AerocarrierTmp) {
		return AerocarrierTmp.get(is);
	}

	//------------------------------------------------------------

	std::ostream& AircraftCarrier::show(std::ostream& os) const {
		os << "***AircraftCarrier*** " << Call << " ***" << std::endl;
		//---------------------------------
		os << " *Commander*" << std::endl;
		os << "   Name: " << Commander.Name << std::endl;
		os << "   Rank: " << Commander.Rank << std::endl;
		os << "   Experience: " << Commander.Experience << std::endl;
		//---------------------------------
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
		//---------------------------------
		os << " *Amount of Plane --> " << AmountP << std::endl;
		for (int i = 0; i < AmountP; i++) {
			os << std::endl;
			os << Plane[i];
		}
		os << "*** *** ***" << std::endl;
		return os;
	}

	std::ostream& operator << (std::ostream& os, const AircraftCarrier& AerocarrierTmp) {
		return AerocarrierTmp.show(os);
	}

	//------------------------------------------------------------

	std::ostream& AircraftCarrier::printInfoWeapon(std::ostream& os) const {
		os << " **Weapon of Aircraft Carrier**" << std::endl;
		if (!AmountW)
			os << "   No weapons on Aircraft Carrier" << std::endl;
		else
			for (int i = 0; i < AmountW; i++)
				os << ArrW[i];
		return os;
	}

	//------------------------------------------------------------

	AircraftCarrier& AircraftCarrier::WeaponModification(std::string NameWeaponTmp, Weapon& WeaponTmp) {
		Weapon* ptr = ArrW;
		while (ptr->GetWeapon() != WeaponTmp.GetWeapon())
			ptr++;
		*ptr = WeaponTmp;
		return*this;
	}

	//------------------------------------------------------------

	double AircraftCarrier::TimeFireAllWeapons() const {
		double max = 0;
		for (int i = 0; i < AmountW; i++) {
			double TimeTmp = ArrW[i].GetQuantityAmmunition() / ArrW[i].GetRateFire();
			if (TimeTmp - max < eps)
				max = TimeTmp;
		}
		return max;
	}

	//------------------------------------------------------------

	int AircraftCarrier::DamageAllWeapons() const {
		int Sum = 0;
		for (int i = 0; i < AmountW; i++)
			Sum += ArrW[i].GetDamage();
		return Sum;
	}
	
}
