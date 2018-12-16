#include "pch.h"
#include <iostream>
#include "..\Library\Fleet.h"
#include "..\Library\Ship.h"
#include "..\Library\CoverShip.h"
#include "..\Library\Carrier.h"
#include "..\Library\AircraftCarrier.h"

//------------------------------------------------------------

using namespace AircraftСarrierGroup;

//------------------------------------------------------------

const std::string Menu[] = { "1. Work with Navy", "2. Work with specific Ship", "3. Interaction between two Ships", "4. Work with File",
							 "5. Finish work with this Navy", "0. Quit" };
const std::string NavyMenu[] = { "1.  Add a ship", "2.  Delete a ship", "3.  Add Aircraft", "4.  Delete Aircraft",
								 "5.  Get Ship description with call-sign", "6.  Amount of Ships", "7.  Number Ships of a certain type",
								 "8.  Show Navy", "9.  Max duration flight", "10. Max radius flight", "0. Exit from this NavyMenu" };
const std::string ShipMenu[] = { "1. All info", "2. Work with Characteristics", "3. Work with Weapon"/*, "4. Work with Aircrafts on Ship"*/,
								 "4. Max Range Transition", "5. Time Fire with all weapons on Ship", "6. Damage All Weapons on Ship",
								 "7. Damage All Aircrafts on Ship" , "0. Exit from this ShipMenu" };
const std::string TwoShipMenu[] = { "1. Transfer fuel", "2. Transfer Aircraft" , "0. Exit from this TwoShipMenu" };
const std::string FileMenu[] = { "1. Load File", "2. Save File", "0. Exit from this FileMenu" };
const std::string PickShip[] = { "1. Cover Ship", "2. Carrier",  "3. Aircraft Carrier", "0. Quit" };
const std::string ShipConfig[] = { "1. Call", "2. Captain", "3. Crew", "4. Speed", "5. Fuel Reserve", "6. Fuel Consumption", "0, Quit" };
const std::string ShipConfigMenu[] = { "1. Show", "2. Сhange", "0. Quit" };
const std::string WeaponConfigMenu[] = { "1. Name Weapon", "2. Name Ammunition", "3. Rate Fire", "4. Quantity Ammunition",
										 "5. Damage", "0. Quit" };
const std::string AircraftConfigMenu[] = { "1. Speed", "2. Fuel Reserve", "3. Fuel Consumption", "4. Quit" },
Choice = "Make your choice",
Msg = "You are wrong; repeate please";

//------------------------------------------------------------

int Answer(const std::string alt[], int n);
int NavyWork(Fleet&);
int ShipWork(Fleet&);
int TwoShipWork(Fleet&);
int FileWork(Fleet&);
int ClearNavy(Fleet&);

//------------------------------------------------------------

int Add(Fleet&);
int Remove(Fleet&);
int AddAircraft(Fleet&);
int DeleteAircraft(Fleet&);
int GetShipDescription(Fleet&);
int AmountShip(Fleet&);
int Type(Fleet&);
int ShowAll(Fleet&);
int MaxDurationFlight(Fleet&);
int MaxRadiusFlight(Fleet&);

//------------------------------------------------------------

int AllInfo(Fleet::Const_Iterator);
int ShipSetting(Fleet::Const_Iterator);
//---------------------------------
int D_Call(Fleet::Const_Iterator&);
int D_Captain(Fleet::Const_Iterator&);
int D_Crew(Fleet::Const_Iterator&);
int D_Speed(Fleet::Const_Iterator&);
int D_FuelReserve(Fleet::Const_Iterator&);
int D_FuelConsumption(Fleet::Const_Iterator&);
//---------------------------------
int WeaponSetting(Fleet::Const_Iterator);
//---------------------------------
int D_NameWeapon(Weapon*);
int D_NameAmmunition(Weapon*);
int D_RateFire(Weapon*);
int D_QuantityAmmunition(Weapon*);
int D_Damage(Weapon*);
//---------------------------------
//int AircraftSetting(Fleet::Const_Iterator&);
//---------------------------------
/*int D_Speed(Aircraft*);
int D_FuelReserve(Aircraft*);
int D_FuelConsumption(Aircraft*);*/
//---------------------------------
int MaxRange(Fleet::Const_Iterator);
int TimeFireShip(Fleet::Const_Iterator);
int DamageAllShipWeapon(Fleet::Const_Iterator);
int DamageAllShipPlane(Fleet::Const_Iterator);

//------------------------------------------------------------

int TransferFuel(Fleet&, Fleet::Const_Iterator&, Fleet::Const_Iterator&);
int TransferAircraft(Fleet&, Fleet::Const_Iterator&, Fleet::Const_Iterator&);

//------------------------------------------------------------

int LoadNavy(Fleet&);
int SaveNavy(Fleet&);

//------------------------------------------------------------

int Find(Fleet&);
int ShowShipWithAircraft(Fleet&);
int ShowShipWithWeapon(Fleet&);

//------------------------------------------------------------

int(*Funcs[])(Fleet&) = { nullptr, NavyWork, ShipWork, TwoShipWork, FileWork, ClearNavy };
int(*NavyFuncs[])(Fleet&) = { nullptr, Add, Remove, AddAircraft, DeleteAircraft, GetShipDescription, AmountShip,
							 Type, ShowAll, MaxDurationFlight, MaxRadiusFlight };
int(*ShipFuncs[])(Fleet::Const_Iterator) = { nullptr, AllInfo, ShipSetting, WeaponSetting, /*AircraftSetting,*/ MaxRange, TimeFireShip,
							  DamageAllShipWeapon, DamageAllShipPlane };
int(*TwoShipFuncs[])(Fleet&, Fleet::Const_Iterator&, Fleet::Const_Iterator&) = { nullptr, TransferFuel, TransferAircraft };
int(*FileFuncs[])(Fleet&) = { nullptr, LoadNavy, SaveNavy };

int(*ShipConfigs[])(Fleet::Const_Iterator&) = { nullptr, D_Call, D_Captain, D_Crew, D_Speed, D_FuelReserve, D_FuelConsumption };
int(*WeaponConfigs[])(Weapon*) = { nullptr, D_NameWeapon, D_NameAmmunition, D_RateFire, D_QuantityAmmunition, D_Damage };
//int(*AircraftConfigs[])(Aircraft*) = { nullptr, D_Speed, D_FuelReserve, D_FuelConsumption };

//------------------------------------------------------------

const int Num = sizeof(Menu) / sizeof(Menu[0]);
const int NavyNum = sizeof(NavyMenu) / sizeof(NavyMenu[0]);
const int ShipNum = sizeof(ShipMenu) / sizeof(ShipMenu[0]);
const int TwoShipNum = sizeof(TwoShipMenu) / sizeof(TwoShipMenu[0]);
const int FileNum = sizeof(FileMenu) / sizeof(FileMenu[0]);

const int PickNum = sizeof(PickShip) / sizeof(PickShip[0]);
const int ShipConfigNum = sizeof(ShipConfig) / sizeof(ShipConfig[0]);
const int ShipConfigMenuNum = sizeof(ShipConfigMenu) / sizeof(ShipConfigMenu[0]);
const int WeaponConfigMenuNum = sizeof(WeaponConfigMenu) / sizeof(WeaponConfigMenu[0]);
const int AircraftConfigNum = sizeof(AircraftConfigMenu) / sizeof(AircraftConfigMenu[0]);

//------------------------------------------------------------

int main() {
	Fleet Navy;
	int index;
	try {
		while (index = Answer(Menu, Num))
			Funcs[index](Navy);
		std::cout << "That's all. Buy!" << std::endl;
	}
	catch (const std::exception& er) {
		std::cout << er.what() << std::endl;
	}
	return 0;
}

//------------------------------------------------------------

int Answer(const std::string alt[], int n) {
	int answer;
	std::string prompt = Choice;
	std::cout << "\nWhat do you want to do:" << std::endl;
	for (int i = 0; i < n; i++)
		std::cout << alt[i].c_str() << std::endl;
	do {
		std::cout << prompt.c_str() << ": -> ";
		prompt = Msg;
		std::cin >> answer;
		if (!std::cin.good()) {
			std::cout << "Error when number of choice was entered; \nRepeat, please." << std::endl;
			std::cin.ignore(80, '\n');
			std::cin.clear();
		}
	} while (answer < 0 || answer >= n);
	std::cin.ignore(80, '\n');
	return answer;
}

int NavyWork(Fleet& FleetTmp) {
	int index;
	try {
		while (index = Answer(NavyMenu, NavyNum))
			NavyFuncs[index](FleetTmp);
	}
	catch (const std::exception& er) {
		std::cout << er.what() << std::endl;
	}
	return 0;
}

int ShipWork(Fleet& FleetTmp) {
	std::string name;
	Fleet::Const_Iterator it;
	std::cout << "Enter a ship name: ";
	std::cin >> name;
	if (!std::cin.good())
		throw std::exception("Error when a shape name was entered");
	it = FleetTmp.find(name);
	if (it == FleetTmp.end()) {
		std::cout << "The Ship with Name \"" << name << "\" is absent in container" << std::endl;
		return -1;
	}
	else {
		int index;
		try {
			while (index = Answer(ShipMenu, ShipNum))
				ShipFuncs[index](it);
		}
		catch (const std::exception& er) {
			std::cout << er.what() << std::endl;
		}
		return 0;
	}
}

int TwoShipWork(Fleet& FleetTmp) {
	if (FleetTmp.SizeFleet() > 1) {
		Fleet::Const_Iterator itFr, itTo;
		std::string ShipFrom, ShipTo;
		std::cout << " Enter name ship from transfer: ";
		std::cin >> ShipFrom;
		itFr = FleetTmp.find(ShipFrom);
		if (itFr == FleetTmp.end()) {
			std::cout << "The Ship with Name \"" << ShipFrom << "\" is absent in container" << std::endl;
			return -1;
		}
		else {
			std::cout << " Eenter name ship to transfer: ";
			std::cin >> ShipTo;
			itTo = FleetTmp.find(ShipTo);
			if (itTo == FleetTmp.end()) {
				std::cout << "The Ship with Name \"" << ShipTo << "\" is absent in container" << std::endl;
				return -1;
			}
			else {
				int index;
				try {
					while (index = Answer(TwoShipMenu, TwoShipNum))
						TwoShipFuncs[index](FleetTmp, itFr, itTo);
				}
				catch (const std::exception& er) {
					std::cout << er.what() << std::endl;
				}

			}
		}
	}
	else
		std::cout << " There are not enough Ship in Navy!" << std::endl;
	return 0;
}

int FileWork(Fleet& FleetTmp) {
	int index;
	try {
		while (index = Answer(FileMenu, FileNum))
			FileFuncs[index](FleetTmp);
	}
	catch (const std::exception& er) {
		std::cout << er.what() << std::endl;
	}
	return 0;
}

int ClearNavy(Fleet& FleetTmp) {
	FleetTmp.clear();
	return 0;
}

//------------------------------------------------------------

int Add(Fleet& FleetTmp) {
	Ship* ptr = nullptr;
	CoverShip CoverShipTmp;
	Carrier CarrierTmp;
	AircraftCarrier AircraftCarrier;
	std::string CallTmp;
	int ans;
	while (ans = Answer(PickShip, PickNum)) {
		std::cout << "Enter a ship name: ";
		std::cin >> CallTmp;
		if (!std::cin.good()) {
			std::cin.ignore(80, '\n');
			throw std::exception("Error when a ship name was entered");
		}
		switch (ans) {
		case 1:
			ptr = &CoverShipTmp;
			break;
		case 2:
			ptr = &CarrierTmp;
			break;
		case 3:
			ptr = &AircraftCarrier;
			break;
		}
		std::cin >> (*ptr);
		if (!std::cin.good())
			throw std::exception("Error when ship was entered");
		if (FleetTmp.insert(CallTmp, ptr))
			std::cout << "Ok" << std::endl;
		else
			std::cout << "Duplicate name" << std::endl;
	}
	return 0;
}

//------------------------------------------------------------

int Remove(Fleet& FleetTmp) {
	std::string name;
	std::cout << "Enter a ship name: ";
	std::cin >> name;
	if (!std::cin.good())
		throw std::exception("Error when a shape name was entered");
	if (FleetTmp.remove(name))
		std::cout << "Ok" << std::endl;
	else
		std::cout << "The Ship with Name \"" << name << "\" is absent in container"
		<< std::endl;
	return 0;
}

//------------------------------------------------------------

int AddAircraft(Fleet& FleetTmp) {
	if (!ShowShipWithAircraft(FleetTmp)) {
		std::string Name;
		Aircraft Plane;
		std::cout << " Enter name of ship to which you want to add the plane: ";
		std::cin >> Name;
		std::cout << " Enter Aircaft:" << std::endl;
		std::cin >> Plane;
		if (FleetTmp.AddPlane(Plane, Name))
			return 0;
		else
			return -1;
	}
	else
		return -1;
}

//------------------------------------------------------------

int DeleteAircraft(Fleet& FleetTmp) {
	if (!ShowShipWithAircraft(FleetTmp)) {
		std::string Name;
		std::cout << " Enter name of ship on which you want to delete the plane: ";
		std::cin >> Name;
		FleetTmp.DeletePlane(Name);
		return 0;
	}
	else
		return -1;
}

//------------------------------------------------------------

int GetShipDescription(Fleet& FleetTmp) {
	std::string Name;
	std::cout << " Enter the name of the ship: ";
	std::cin >> Name;
	Fleet::Const_Iterator it;
	it = FleetTmp.find(Name);
	if (it == FleetTmp.end()) {
		std::cout << "The Ship with Name \"" << Name << "\" is absent in container" << std::endl;
		return -1;
	}
	else {
		std::cout << (*it).second;
		return 0;
	}
}

//------------------------------------------------------------

int AmountShip(Fleet& FleetTmp) {
	std::cout << " Amount of Ships in Navy --> " << FleetTmp.SizeFleet();
	return 0;
}

//------------------------------------------------------------

int Type(Fleet& FleetTmp) {
	Ship* ptr = nullptr;
	int ans, Amount;
	while (ans = Answer(PickShip, PickNum)) {
		switch (ans) {
		case 1:
			Amount = FleetTmp.TypeCoverShip();
			break;
		case 2:
			Amount = FleetTmp.TypeCarrier();
			break;
		case 3:
			Amount = FleetTmp.TypeAircraftCarrier();
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------

int ShowAll(Fleet& FleetTmp) {
	FleetTmp.Show();
	return 0;
}

//------------------------------------------------------------

int MaxDurationFlight(Fleet& FleetTmp) {
	if (!ShowShipWithAircraft(FleetTmp)) {
		std::cout << " **Max duration of flights of all aircraft --> ";
		std::cout << FleetTmp.MaxDurationPlaneFligth() << std::endl;
		return 0;
	}
	else
		return -1;
}

//------------------------------------------------------------

int MaxRadiusFlight(Fleet& FleetTmp) {
	if (!ShowShipWithAircraft(FleetTmp)) {
		std::cout << " **Max radius of flights of all aircraft --> ";
		std::cout << FleetTmp.MaxRadiusPlaneFligth() << std::endl;
		return 0;
	}
	else
		return -1;
}

//------------------------------------------------------------

int AllInfo(Fleet::Const_Iterator it) {
	std::cout << *((*it).second);
	return 0;
}

//------------------------------------------------------------

int ShipSetting(Fleet::Const_Iterator it) {
	int index;
	try {
		while (index = Answer(ShipConfig, ShipConfigNum))
			ShipConfigs[index](it);
	}
	catch (const std::exception& er) {
		std::cout << er.what() << std::endl;
	}
	return 0;
}

//------------------------------------------------------------

int D_Call(Fleet::Const_Iterator& it) {
	int ans;
	while (ans = Answer(ShipConfigMenu, ShipConfigMenuNum)) {
		switch (ans) {
		case 1:
			std::cout << " Call: \"" << (*it).second->getCall() << "\"" << std::endl;
			break;
		case 2:
			std::string name;
			std::cout << " Enter new Call of Ship: ";
			std::cin >> name;
			(*it).second->setNewCall(name);
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------

int D_Captain(Fleet::Const_Iterator& it) {
	int ans;
	while (ans = Answer(ShipConfigMenu, ShipConfigMenuNum)) {
		switch (ans) {
		case 1:
			std::cout << (*it).second->getCommander();
			break;
		case 2:
			Captain Commander;
			std::cout << " Enter new Commander: ";
			std::cin >> Commander;
			(*it).second->setNewCommander(Commander);
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------

int D_Crew(Fleet::Const_Iterator& it) {
	int ans;
	while (ans = Answer(ShipConfigMenu, ShipConfigMenuNum)) {
		switch (ans) {
		case 1:
			std::cout << " Crew --> " << (*it).second->getCrew() << std::endl;
			break;
		case 2:
			int Crew;
			std::cout << " Enter new Crew --> ";
			std::cin >> Crew;
			(*it).second->setNewCrew(Crew);
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------

int D_Speed(Fleet::Const_Iterator& it) {
	int ans;
	while (ans = Answer(ShipConfigMenu, ShipConfigMenuNum)) {
		switch (ans) {
		case 1:
			std::cout << " Speed --> " << (*it).second->GetSpeed() << std::endl;
			break;
		case 2:
			int Speed;
			std::cout << " Enter new Speed --> ";
			std::cin >> Speed;
			(*it).second->SetSpeed(Speed);
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------

int D_FuelReserve(Fleet::Const_Iterator& it) {
	int ans;
	while (ans = Answer(ShipConfigMenu, ShipConfigMenuNum)) {
		switch (ans) {
		case 1:
			std::cout << " Fuel Reserve --> " << (*it).second->GetFuelReserve() << std::endl;
			break;
		case 2:
			int FuelReserve;
			std::cout << " Enter new Fuel Reserve --> ";
			std::cin >> FuelReserve;
			(*it).second->SetFuelReserve(FuelReserve);
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------

int D_FuelConsumption(Fleet::Const_Iterator& it) {
	int ans;
	while (ans = Answer(ShipConfigMenu, ShipConfigMenuNum)) {
		switch (ans) {
		case 1:
			std::cout << " Fuel Fuel Consumption --> " << (*it).second->GetFuelConsumption() << std::endl;
			break;
		case 2:
			int FuelConsumption;
			std::cout << " Enter new Fuel Consumption --> ";
			std::cin >> FuelConsumption;
			(*it).second->SetFuelConsumption(FuelConsumption);
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------

int WeaponSetting(Fleet::Const_Iterator it) {
	if ((*it).second->TypeShip() != 2) {
		if ((*it).second->AmountWeapon() > 0) {
			int index;
			try {
				std::string Name;
				Weapon* Modify = (*it).second->getWeapon(Name);
				if (Modify != nullptr) {
					while (index = Answer(WeaponConfigMenu, WeaponConfigMenuNum))
						WeaponConfigs[index](Modify);
				}
				else
					std::cout << " Weapon wasn't found!" << std::endl;
			}
			catch (const std::exception& er) {
				std::cout << er.what() << std::endl;
			}
		}
		else
			std::cout << "There are not weapon" << std::endl;
	}
	else
		std::cout << " This Ship can't have weapon!" << std::endl;
	return 0;
}

//------------------------------------------------------------

int D_NameWeapon(Weapon* Arsenal) {
	int ans;
	while (ans = Answer(ShipConfigMenu, ShipConfigMenuNum)) {
		switch (ans) {
		case 1:
			std::cout << " Name Weapon: \"" << Arsenal->GetWeapon() << "\"" << std::endl;
			break;
		case 2:
			std::string Name;
			std::cout << " Enter Name Weapon: ";
			std::cin >> Name;
			Arsenal->SetWeapon(Name);
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------

int D_NameAmmunition(Weapon* Arsenal) {
	int ans;
	while (ans = Answer(ShipConfigMenu, ShipConfigMenuNum)) {
		switch (ans) {
		case 1:
			std::cout << " Name Ammunition: \"" << Arsenal->GetMunition() << "\"" << std::endl;
			break;
		case 2:
			std::string Name;
			std::cout << " Enter Name Ammunition: ";
			std::cin >> Name;
			Arsenal->SetMunition(Name);
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------

int D_RateFire(Weapon* Arsenal) {
	int ans;
	while (ans = Answer(ShipConfigMenu, ShipConfigMenuNum)) {
		switch (ans) {
		case 1:
			std::cout << " Rate Fire --> " << Arsenal->GetRateFire() << std::endl;
			break;
		case 2:
			int RateFire;
			std::cout << " Enter Rate Fire --> ";
			std::cin >> RateFire;
			Arsenal->SetRateFire(RateFire);
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------

int D_QuantityAmmunition(Weapon* Arsenal) {
	int ans;
	while (ans = Answer(ShipConfigMenu, ShipConfigMenuNum)) {
		switch (ans) {
		case 1:
			std::cout << " Quantity Ammunition --> " << Arsenal->GetQuantityAmmunition() << std::endl;
			break;
		case 2:
			int QuantityAmmunition;
			std::cout << " Enter Quantity Ammunition --> ";
			std::cin >> QuantityAmmunition;
			Arsenal->SetQuantityAmmunition(QuantityAmmunition);
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------

int D_Damage(Weapon* Arsenal) {
	int ans;
	while (ans = Answer(ShipConfigMenu, ShipConfigMenuNum)) {
		switch (ans) {
		case 1:
			std::cout << " Damage --> " << Arsenal->GetDamage() << std::endl;
			break;
		case 2:
			int Damage;
			std::cout << " Enter Damage --> ";
			std::cin >> Damage;
			Arsenal->SetDamage(Damage);
			break;
		}
	}
	return 0;
}

//------------------------------------------------------------

int MaxRange(Fleet::Const_Iterator it) {
	double tmp = (*it).second->maxRangeTtransition();
	std::cout << " Max Range of transition of this Ship --> " << tmp << std::endl;
	return 0;
}

//------------------------------------------------------------

int TimeFireShip(Fleet::Const_Iterator it) {
	if ((*it).second->TypeShip() != 2)
		std::cout << " Time Fire all Weapons on Ship --> " << (*it).second->TimeFireAllWeapons();
	else
		std::cout << " This Ship can't have Weapon!" << std::endl;
	return 0;
}

//------------------------------------------------------------

int DamageAllShipWeapon(Fleet::Const_Iterator it) {
	if ((*it).second->TypeShip() != 2)
		std::cout << " Damage of all Weapons on Ship --> " << (*it).second->DamageAllWeapons();
	else
		std::cout << " This Ship can't have Weapon!" << std::endl;
	return 0;
}

//------------------------------------------------------------

int DamageAllShipPlane(Fleet::Const_Iterator it) {
	if ((*it).second->TypeShip() != 1)
		std::cout << " Damage of all Aircrafts on Ship --> " << (*it).second->DamageAllPlanes();
	else
		std::cout << " This Ship can't have Aircraft!" << std::endl;
	return 0;
}

//------------------------------------------------------------

int TransferFuel(Fleet& FleetTmp, Fleet::Const_Iterator& From, Fleet::Const_Iterator& To) {
	int Fuel;
	std::cout << " Enter amount of fuel --> ";
	std::cin >> Fuel;
	FleetTmp.transferFuel(From, To, Fuel);
	return 0;
}

//------------------------------------------------------------

int TransferAircraft(Fleet& FleetTmp, Fleet::Const_Iterator& From, Fleet::Const_Iterator& To) {
	FleetTmp.TransferAircraft(From, To);
	return 0;
}

//------------------------------------------------------------

int ShowShipWithAircraft(Fleet& FleetTmp) {
	std::cout << " **Ships in the Navy**" << std::endl;
	if (FleetTmp.SizeFleet() - FleetTmp.TypeCoverShip() > 0) {
		Fleet::Const_Iterator it;
		for (it = FleetTmp.begin(); it != FleetTmp.end(); ++it)
			if ((*it).second->TypeShip() != 1) {
				std::cout << "Name: \"" << (*it).first << "\"  Type: ";
				switch ((*it).second->TypeShip()) {
				case 2:
					std::cout << "Carrier" << std::endl;
					break;
				case 3:
					std::cout << "Aircraft Carrier" << std::endl;
					break;
				}
			}
		return 0;
	}
	else {
		std::cout << " Еhere are no ships that can carry aircrafts!" << std::endl;
		return -1;
	}
}

//------------------------------------------------------------

int ShowShipWithWeapon(Fleet& FleetTmp) {
	std::cout << " **Ships in the Navy**" << std::endl;
	if (FleetTmp.SizeFleet() - FleetTmp.TypeCarrier() > 0) {
		Fleet::Const_Iterator it;
		for (it = FleetTmp.begin(); it != FleetTmp.end(); ++it)
			if ((*it).second->TypeShip() != 2) {
				std::cout << "Name: \"" << (*it).first << "\"  Type: ";
				switch ((*it).second->TypeShip()) {
				case 1:
					std::cout << "Cover Ship" << std::endl;
					break;
				case 3:
					std::cout << "Aircraft Carrier" << std::endl;
					break;
				}
			}
		return 0;
	}
	else {
		std::cout << " Еhere are no ships with weapon!" << std::endl;
		return -1;
	}
}

//------------------------------------------------------------

int LoadNavy(Fleet& FleetTmp) {
	std::string FileName;
	std::cout << " Enter name of file: " << std::endl;
	std::cin >> FileName;
	if (!std::cin.good()) {
		std::cout << "Invalid enter!" << std::endl;
		return -1;
	}
	std::ifstream is;
	is.open(FileName + ".bin", std::ios::binary);
	if (!is) {
		std::cerr << " Can't open file!" << std::endl;
		return -1;
	}
	is >> FleetTmp;
	std::cout << FleetTmp;
	is.close();
	std::cout << " Information about Fleet was loaded from file!" << std::endl;
	return 0;
}

//------------------------------------------------------------

int SaveNavy(Fleet& FleetTmp) {
	std::string FileName;
	std::cout << " Enter name of file: " << std::endl;
	std::cin >> FileName;
	if (!std::cin.good()) {
		std::cout << " Invalid enter!" << std::endl;
		return -1;
	}
	std::ofstream os;
	os.open(FileName + ".bin", std::ios::binary);
	if (!os) {
		std::cerr << " Can't open file!" << std::endl;
		return -1;
	}
	os << FleetTmp;
	os.close();
	std::cout << " Information about Fleet was uploaded to file!" << std::endl;
	return 0;
}

//------------------------------------------------------------

/*int AircraftSetting(Fleet::Const_Iterator& it) {
	if ((*it).second->TypeShip() == 1)
		std::cout << " This Ship can't have Aircrfats!" << std::endl;
	else {
		if ((*it).second->AmountAircraft() > 0) {
			int index;
			try {
				int Number;
				std::cout << "Enter Number of Aircraft --> ";
				std::cin >> Number;
				if (Number < 1 || Number >(*it).second->AmountAircraft())
					std::cout << "Invalid Number of Aircraft!" << std::endl;
				else {
					Aircraft* Plane = (*it).second.
					while (index = Answer(AircraftConfigMenu, AircraftConfigNum))
						AircraftConfigs[index](Modify);

				}
			}
			catch (const std::exception& er) {
				std::cout << er.what() << std::endl;
			}

		}
	}
	return 0;
}*/

//------------------------------------------------------------

int Find(Fleet& FleetTmp) {
	std::string name;
	Fleet::Const_Iterator it;
	const Ship* ptr = nullptr;
	std::cout << "Enter a shape name: --> ";
	std::cin >> name;
	if (!std::cin.good())
		throw std::exception("Error when a shape name was entered");
	it = FleetTmp.find(name);
	if (it == FleetTmp.end()) {
		std::cout << "The Ship with Name \"" << name << "\" is absent in container" << std::endl;
		return -1;
	}
	ptr = (*it).second;
	std::cout << (*ptr) << std::endl;
	return 0;
}