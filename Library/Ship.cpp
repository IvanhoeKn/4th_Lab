#include "stdafx.h"
#include "Ship.h"

namespace AircraftСarrierGroup {

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

	Ship::Ship(std::string CallTmp, std::string NameTmp, std::string RankTmp, int ExperienceTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp) : MilitaryCharacteristics(MilitaryTmp), Commander(NameTmp, RankTmp, ExperienceTmp){
		Call = CallTmp;
		Crew = CrewTmp;
	}

	Ship::Ship(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp) : MilitaryCharacteristics(SpeedTmp, FuelConsumptionTmp, FuelReserveTmp), Commander(CommanderTmp){
		Call = CallTmp;
		Crew = CrewTmp;
	}

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