#include "pch.h"
#include <iostream>
#include "Fleet.h"
#include "Ship.h"
#include "CoverShip.h"
#include "Carrier.h"
#include "AircraftCarrier.h"

using namespace AircraftСarrierGroup;

const std::string Names[] = { "Cover Ship", "Carrier", "Aircraft Carrier" };

const std::string Menu[] = { "1. Add a ship", "2. Find a ship", "3. Delete a ship", "4. Show all", "0. Quit" },
				  Choice = "Make your choice",
				  Msg = "You are wrong; repeate please";

int Answer(const std::string alt[], int n);

int Add(Fleet&); 
int Find(Fleet&);
int Remove(Fleet&);
int ShowAll(Fleet&);

int(*Funcs[])(Fleet &) = { nullptr, Add, Find, Remove, ShowAll};

const int Num = sizeof(Menu) / sizeof(Menu[0]);

const std::string Sh[] = { "1. Cover Ship", "2. Carrier",  "3. Aircraft Carrier", "0. Quit" };
const int NumSh = sizeof(Sh) / sizeof(Sh[0]);

//------------------------------------------------------------

int main() {
	Fleet Navy;
	Ship* ptr = nullptr;
	CoverShip CoverShipTmp;
	Carrier CarrierTmp;
	AircraftCarrier AircraftCarrierTmp;
	int index;
	int ans;
	try {
		while (index = Answer(Menu, Num))
			Funcs[index](Navy);
		std::cout << "Size of Navy: " << Navy.SizeFleet() << std::endl;
		std::cout << "That's all. Buy!" << std::endl;
	}
	catch (const std::exception &er) {
		std::cout << er.what() << std::endl;
	}
	return 0;
}

//------------------------------------------------------------

int Answer(const std::string alt[], int n){
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

int Add(Fleet& FleetTmp){
	Ship* ptr = nullptr;
	CoverShip CoverShipTmp;
	Carrier CarrierTmp;
	AircraftCarrier AircraftCarrier;
	std::string CallTmp;
	int ans;
	while (ans = Answer(Sh, NumSh)) {
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

int Find(Fleet& FleetTmp){
	std::string name;
	Fleet::Const_Iterator it;
	const Ship* ptr = nullptr;
	std::cout << "Enter a shape name: --> ";
	std::cin >> name;
	if (!std::cin.good())
		throw std::exception("Error when a shape name was entered");
	it = FleetTmp.find(name);
	if (it == FleetTmp.end()) {
		std::cout << "The Ship with Name \"" << name << "\" is absent in container"
			<< std::endl;
		return -1;
	}
	ptr = (*it).second;
	std::cout << (*ptr) << std::endl;
	return 0;
}

int Remove(Fleet& FleetTmp){
	std::string name;
	const Ship *ptr = nullptr;
	std::cout << "Enter a shape name: --> ";
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

int ShowAll(Fleet& FleetTmp){
	Fleet::Const_Iterator it;
	for (it = FleetTmp.begin(); it != FleetTmp.end(); ++it)
		std::cout << (*it) << std::endl;
	return 0;
}
