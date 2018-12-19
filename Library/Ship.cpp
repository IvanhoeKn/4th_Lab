#include "stdafx.h"
#include "Ship.h"

namespace AircraftCarrierGroup {

	//Конструкторы структуры Captain
	Captain::Captain(std::string NameTmp, std::string RankTmp, int ExperienceTmp) {
			Name = NameTmp;
			Rank = RankTmp;
			Experience = ExperienceTmp;
		}

	//------------------------------------------------------------

	//Копирующий конструктор структуры Captain
	Captain::Captain(const Captain& CommanderTmp) {
			Name = CommanderTmp.Name;
			Rank = CommanderTmp.Rank;
			Experience = CommanderTmp.Experience;
		}

	//------------------------------------------------------------

	std::istream& operator >> (std::istream& is, Captain& Commander) {
		std::cout << " ***Commander***" << std::endl;
		std::cout << " Enter Name: ";
		std::cin >> Commander.Name;
		std::cout << " Enter Rank: ";
		std::cin >> Commander.Rank;
		std::cout << " Enter Experience --> ";
		std::cin >> Commander.Experience;
		return is;
	}

	//------------------------------------------------------------

	std::ostream& operator << (std::ostream& os, const Captain& Commander) {
		std::cout << " ***Commander***" << std::endl;
		std::cout << " Name: " << Commander.Name << std::endl;
		std::cout << " Rank: " << Commander.Rank << std::endl;
		std::cout << " Experience --> " << Commander.Experience << std::endl;
		return os;
	}

	//------------------------------------------------------------

	std::ifstream& operator >> (std::ifstream& is, Captain& Commander) {
		int StrLn;
		char NameBuf[80] = "";
		char RankBuf[80] = "";
		is.read((char*)&StrLn, sizeof(int));
		is.read(NameBuf, StrLn);
		Commander.Name = NameBuf;
		is.read((char*)&StrLn, sizeof(int));
		is.read(RankBuf, StrLn);
		Commander.Rank = RankBuf;
		is.read((char*)&Commander.Experience, sizeof(int));
		return is;
	}

	//------------------------------------------------------------

	std::ofstream& operator << (std::ofstream& os, const Captain& Commander) {
		int tmp;
		tmp = Commander.Name.size();
		os.write((char*)&tmp, sizeof(int));
		os << Commander.Name;
		tmp = Commander.Rank.size();
		os.write((char*)&tmp, sizeof(int));
		os << Commander.Rank;
		os.write((char*)&Commander.Experience, sizeof(int));
		return os;
	}

	//------------------------------------------------------------

	//Перегруженные операторы структуры Captain
	Captain& Captain::operator = (const Captain& CommanderTmp) {
			Name = CommanderTmp.Name;
			Rank = CommanderTmp.Rank;
			Experience = CommanderTmp.Experience;
			return* this;
		}

	Captain& Captain::operator = (Captain&& CommanderTmp) {
		std::string NameTmp = Name;
		Name = CommanderTmp.Name;
		CommanderTmp.Name = NameTmp;
		//---------------------------------
		std::string RankTmp = Rank;
		Rank = CommanderTmp.Rank;
		CommanderTmp.Rank = RankTmp;
		//---------------------------------
		int ExperienceTmp = Experience;
		Experience = CommanderTmp.Experience;
		CommanderTmp.Experience = ExperienceTmp;
		return *this;
	}

	//------------------------------------------------------------
	//------------------------------------------------------------

	//Конструкторы класса Ship

	Ship::Ship(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp) : MilitaryCharacteristics(MilitaryTmp){
		Call = CallTmp;
		Commander = CommanderTmp;
		Crew = CrewTmp;
	};

	//------------------------------------------------------------

	Ship::Ship(std::string CallTmp, std::string NameTmp, std::string RankTmp, int ExperienceTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp) : MilitaryCharacteristics(MilitaryTmp), Commander(NameTmp, RankTmp, ExperienceTmp){
		Call = CallTmp;
		Crew = CrewTmp;
	}

	//------------------------------------------------------------

	Ship::Ship(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp) : MilitaryCharacteristics(SpeedTmp, FuelConsumptionTmp, FuelReserveTmp), Commander(CommanderTmp){
		Call = CallTmp;
		Crew = CrewTmp;
	}

	//------------------------------------------------------------

	Ship::Ship(std::string CallTmp, std::string NameTmp, std::string RankTmp, int ExperienceTmp, int CrewTmp, int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp) : MilitaryCharacteristics(SpeedTmp, FuelConsumptionTmp, FuelReserveTmp), Commander(NameTmp, RankTmp, ExperienceTmp){
		Call = CallTmp;
		Crew = CrewTmp;
	}

	//------------------------------------------------------------

	//Копирующий конструктор класса Ship
	Ship::Ship(const Ship& ShipTmp) : MilitaryCharacteristics(ShipTmp.Speed, ShipTmp.FuelConsumption, ShipTmp.FuelReserve), Commander(ShipTmp.Commander){
		Call = ShipTmp.Call;
		Crew = ShipTmp.Crew;
	}

	//------------------------------------------------------------

	//Другие методы класса Ship
	double Ship::maxRangeTtransition() const {
		double CruisingRange = double(FuelReserve) / FuelConsumption;
		double Distance = Speed * CruisingRange;
		return Distance;
	}

}