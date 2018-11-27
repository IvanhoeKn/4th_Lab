#include "pch.h"
#include "Ship.h"

namespace AircraftСarrierGroup {

	//Конструкторы структуры Captain
	Captain::Captain() {
			Name = "Captain default";
			Rank = "Ordinary";
			Experience = 0;
		};

	Captain::Captain(std::string NameTmp, std::string RankTmp, int ExperienceTmp) {
			Name = NameTmp;
			Rank = RankTmp;
			Experience = ExperienceTmp;
		};

	//Копирующий конструктор структуры Captain
	Captain::Captain(Captain &CommanderTmp) {
			Name = CommanderTmp.Name;
			Rank = CommanderTmp.Rank;
			Experience = CommanderTmp.Experience;
		};

	//------------------------------------------------------------

	//Деструктор структуры Captain
	Captain::~Captain() {
			Name = nullptr;
			Rank = nullptr;
			Experience = NULL;
		};

	//------------------------------------------------------------

	//Перегруженные операторы
	Captain& Captain::operator = (Captain &CommanderTmp) {
			Name = CommanderTmp.Name;
			Rank = CommanderTmp.Rank;
			Experience = CommanderTmp.Experience;
			return* this;
		};

	//------------------------------------------------------------
	//------------------------------------------------------------

	//Конструкторы класса Ship
	Ship::Ship() :Commander(new Captain()), MilitaryCharacteristics() {
		Crew = 0;
		Call = "Ship default";
	};

	Ship::Ship(Captain& CommanderTmp, std::string CallTmp, int CrewTmp, MilitaryCharacteristics& CharacteristicsTmp) {
		Commander = new Captain(CommanderTmp);
		Call = CallTmp;
		Crew = CrewTmp;
		MilitaryCharacteristics(CharacteristicsTmp.GetSpeed(), CharacteristicsTmp.GetFuelConsumption(), CharacteristicsTmp.GetFuelReserve());
	};

	Ship::Ship(std::string NameTmp, std::string RankTmp, int ExperienceTmp, std::string CallTmp, int CrewTmp, MilitaryCharacteristics& CharacteristicsTmp) {
		Commander = new Captain(NameTmp, RankTmp, ExperienceTmp);
		Call = CallTmp;
		Crew = CrewTmp;
		MilitaryCharacteristics(CharacteristicsTmp.GetSpeed(), CharacteristicsTmp.GetFuelConsumption(), CharacteristicsTmp.GetFuelReserve());
	};

	Ship::Ship(Captain& CommanderTmp, std::string CallTmp, int CrewTmp, int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp) {
		Commander = new Captain(CommanderTmp);
		Call = CallTmp;
		Crew = CrewTmp;
		MilitaryCharacteristics(SpeedTmp, FuelConsumptionTmp, FuelReserveTmp);
	};

	Ship::Ship(std::string NameTmp, std::string RankTmp, int ExperienceTmp, std::string CallTmp, int CrewTmp, int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp) {
		Commander = new Captain(NameTmp, RankTmp, ExperienceTmp);
		Call = CallTmp;
		Crew = CrewTmp;
		MilitaryCharacteristics(SpeedTmp, FuelConsumptionTmp, FuelReserveTmp);
	};

	//Копирующий конструктор
	Ship::Ship(Ship& ShipTmp) {
		Commander = new Captain(*ShipTmp.Commander);
		Call = ShipTmp.Call;
		Crew = ShipTmp.Crew;
		MilitaryCharacteristics(ShipTmp.Speed, ShipTmp.FuelConsumption, ShipTmp.FuelReserve);
	};

	//------------------------------------------------------------

	//Деструктор класса Ship
	Ship::~Ship() {
		Crew = NULL;
		Call = nullptr;
		Commander->~Captain();
	};

	//------------------------------------------------------------

	//Другие методы класса Ship
	Ship& Ship::setNewCommander(Captain& CommanderTmp) {
		Commander = new Captain;
		*Commander = CommanderTmp;
		return *this;
	};

	Ship& Ship::setNewCall(std::string CallTmp) {
		Call = CallTmp;
		return *this;
	};

	Ship& Ship::setNewCrew(int CrewTmp) {
		Crew = CrewTmp;
		return *this;
	};

	double Ship::maxRangeTtransition() const {
		double CruisingRange = FuelReserve / FuelConsumption;
		double Distance = Speed * CruisingRange;
		return Distance;
	};

}