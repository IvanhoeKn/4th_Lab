#include "stdafx.h"
#include "CoverShip.h"

namespace AircraftÑarrierGroup {

	//Êîíñòðóêòîðû
	CoverShip::CoverShip(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp, std::string DisguisedTmp, int AmountTmp, Weapon *ArrTmp) : Ship(CallTmp, CommanderTmp, CrewTmp, MilitaryTmp) {
		Disguised = DisguisedTmp;
		AmountW = AmountTmp;
		ArrW = new Weapon[AmountW];
		for (int i = 0; i < AmountW; i++) 
			ArrW[i] = ArrTmp[i];
	}

	//------------------------------------------------------------

	//Êîïèðóþùèé êîíñòðóêòîð
	CoverShip::CoverShip(const CoverShip &CoverShipTmp) {
		Call = CoverShipTmp.Call;
		//---------------------------------
		Commander = CoverShipTmp.Commander;
		Crew = CoverShipTmp.Crew;
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

	std::ifstream& CoverShip::fread(std::ifstream& is) {
		int StrLn;
		char CallBuf[80] = "";
		char DsgBuf[80] = "";
		MilitaryCharacteristics Military;
		is.read((char*) &StrLn, sizeof(int));
		is.read(CallBuf, StrLn);
		Call = CallBuf;
		is >> Commander;
		is.read((char*) &StrLn, sizeof(int));
		is.read(DsgBuf, StrLn);
		Disguised = DsgBuf;
		is.read((char*) &Crew, sizeof(int));
		is >> Military;
		SetSpeed(Military.GetSpeed());
		SetFuelReserve(Military.GetFuelReserve());
		SetFuelConsumption(Military.GetFuelConsumption());
		is.read((char*) &AmountW, sizeof(int));
		ArrW = new Weapon[AmountW];
		for (int i = 0; i < AmountW; i++)
			is >> ArrW[i];
		return is;
	}

	//------------------------------------------------------------

	std::ofstream& CoverShip::fprint(std::ofstream& os) const {
		int tmp;
		MilitaryCharacteristics Military(*this);
		tmp = Call.size();
		os.write((char*) &tmp, sizeof(int));
		os << Call;
		os << Commander;
		tmp = Disguised.size();
		os.write((char*) &tmp, sizeof(int));
		os << Disguised;
		os.write((char*) &Crew, sizeof(int));
		os << Military;
		os.write((char*) &AmountW, sizeof(int));
		for (int i = 0; i < AmountW; i++)
			os << ArrW[i];
		return os;
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
		for (int i = 0; i < AmountW; i++)
			if (ArrW[i].GetWeapon() == NameWeaponTmp) {
				ArrW[i] = WeaponTmp;
				break;
			}
		return* this;
	}

	//------------------------------------------------------------

	double CoverShip::TimeFireAllWeapons() const {
		double min = std::numeric_limits<double>::max();
		if (AmountW == 0)
			min = 0;
		else {
			for (int i = 0; i < AmountW; i++) {
				double TimeTmp = double(ArrW[i].GetQuantityAmmunition()) / ArrW[i].GetRateFire();
				if ( min - TimeTmp > eps)
					min = TimeTmp;
			}
		}
		return min;
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