#include "pch.h"
#include "Carrier.h"

namespace Aircraft�arrierGroup {
	
	//������������
	Carrier::Carrier(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp, int AmountPTmp, Aircraft* PlaneTmp) : Ship(CallTmp, CommanderTmp, CrewTmp, MilitaryTmp) {
		AmountP = AmountPTmp;
		Plane = new Aircraft[AmountP];
		for (int i = 0; i < AmountP; i++)
			Plane[i] = PlaneTmp[i];
	}

	//------------------------------------------------------------

	//���������� �����������
	Carrier::Carrier(const Carrier& CarrierTmp) {
		Call = CarrierTmp.Call;
		Commander = CarrierTmp.Commander;
		Crew = CarrierTmp.Crew;
		//---------------------------------
		Speed = CarrierTmp.Speed;
		FuelConsumption = CarrierTmp.FuelConsumption;
		FuelReserve = CarrierTmp.FuelReserve;
		//---------------------------------
		AmountP = CarrierTmp.AmountP;
		Plane = new Aircraft[AmountP];
		for (int i = 0; i < AmountP; i++)
			Plane[i] = CarrierTmp.Plane[i];
	}

	//------------------------------------------------------------

	//������ ������ ������
	std::istream& Carrier::get(std::istream& is) {
		std::cout << " ***Carrier***" << std::endl;
		//---------------------------------
		std::cout << " Enter Call of Carrier: ";
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
		std::cout << " Enter Crew of Carrier --> ";
		is >> Crew;
		//---------------------------------
		std::cout << "  *Military characteristics*" << std::endl;
		MilitaryCharacteristics MilitaryTmp;
		is >> MilitaryTmp;
		Speed = MilitaryTmp.GetSpeed();
		FuelConsumption = MilitaryTmp.GetFuelConsumption();
		FuelReserve = MilitaryTmp.GetFuelReserve();
		//---------------------------------
		std::cout << " Enter Amount of Aircraft: ";
		is >> AmountP;
		Plane = new Aircraft[AmountP];
		for (int i = 0; i < AmountP; i++)
			is >> Plane[i];
		return is;
	}

	std::istream& operator >> (std::istream& is, Carrier& CarrierTmp) {
		return CarrierTmp.get(is);
	}

	//------------------------------------------------------------

	std::ostream& Carrier::show(std::ostream& os) const {
		os << "***Carrier*** " << Call << " ***" << std::endl;
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
		os << " *Amount of Plane --> " << AmountP << std::endl;
		for (int i = 0; i < AmountP; i++) {
			os << std::endl;
			os << Plane[i];
		}
		os << "*** *** ***" << std::endl;
		return os;
	}

	std::ostream& operator << (std::ostream& os, const Carrier& CarrierTmp) {
		return CarrierTmp.show(os);
	}

	//------------------------------------------------------------

	std::ifstream& Carrier::fread(std::ifstream& is) {
		int StrLn;
		char CallBuf[80] = "";
		MilitaryCharacteristics Military;
		is.read((char*) &StrLn, sizeof(int));
		is.read(CallBuf, StrLn);
		Call = CallBuf;
		is >> Commander;
		is.read((char*) &Crew, sizeof(int));
		is >> Military;
		SetSpeed(Military.GetSpeed());
		SetFuelReserve(Military.GetFuelReserve());
		SetFuelConsumption(Military.GetFuelConsumption());
		is.read((char*) &AmountP, sizeof(int));
		Plane = new Aircraft[AmountP];
		for (int i = 0; i < AmountP; i++)
			is >> Plane[i];
		return is;
	}

	//------------------------------------------------------------

	std::ofstream& Carrier::fprint(std::ofstream& os) const {
		int tmp;
		MilitaryCharacteristics Military(*this);
		tmp = Call.size();
		os.write((char*) &tmp, sizeof(int));
		os << Call;
		os << Commander;
		os.write((char*) &Crew, sizeof(int));
		os << Military;
		os.write((char*) &AmountP, sizeof(int));
		for (int i = 0; i < AmountP; i++)
			os << Plane[i];
		return os;
	}

	//------------------------------------------------------------

	std::ostream& Carrier::printInfoWeapon(std::ostream& os) const {
		os << " **Weapon of Carrier**" << std::endl;
		os << "   No weapons on Carrier" << std::endl;
		return os;
	}

	//------------------------------------------------------------
	
	int Carrier::DamageAllPlanes() const {
		int Sum = 0;
		for (int i = 0; i < AmountP; i++) {
			Aircraft PlaneTmp = Plane[i];
			for (int j = 0; j < PlaneTmp.getAmountWeapon(); j++)
				Sum += PlaneTmp.getWeaponAircraft(j).GetDamage();
		}
		return Sum;
	}

	//------------------------------------------------------------

	int Carrier::DamageAllWeapons() const {
		throw std::exception("No Weapons on Carrier\n");
	}

	//------------------------------------------------------------

	double Carrier::TimeFireAllWeapons() const {
		throw std::exception("No Weapons on Carrier\n");
	}

	//------------------------------------------------------------

	Carrier& Carrier::WeaponModification(std::string NameWeaponTmp, const Weapon& WeaponTmp) {
		throw std::exception("No Weapons on Carrier\n");
	}
}