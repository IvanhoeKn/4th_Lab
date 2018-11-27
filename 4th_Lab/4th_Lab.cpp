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

int Add(Fleet&), Find(Fleet&), Remove(Fleet&), ShowAll(Fleet&);

int(*Funcs[])(Fleet &) = { nullptr, Add, Find, Remove, ShowAll};

const int Num = sizeof(Menu) / sizeof(Menu[0]);

//------------------------------------------------------------

int main() {
	Fleet Navy;
	int index;
	try {
		while (index = Answer(Menu, Num))
			Funcs[index](Navy);
		std::cout << "That's all. Buy!" << std::endl;
	}
	catch (const std::exception &er) {
		std::cout << er.what() << std::endl;
	}
	return 0;
}

//------------------------------------------------------------

int Answer(const std::string alt[], int n)
{
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

const std::string Sh[] = { "1. Cover Ship", "2. Carrier",  "3. Aircraft Carrier", "0. Quit" };
const int NumSh = sizeof(Sh) / sizeof(Sh[0]);

int Add(Fleet& FleetTmp)
{
	Ship* ptr = nullptr;
	CoverShip CoverShipTmp;
	Carrier CarrierTmp;
	AircraftCarrier AircraftCarrier;
	std::string CallTmp;
	int ans;
	while (ans = Answer(Sh, NumSh)) {
		std::cout << "Enter a ship name: --> ";
		std::cin >> CallTmp;
			if (!std::cin.good())
				throw std::exception("Error when a shape name was entered");
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
		std::cin.ignore(80, '\n');
		if (FleetTmp.insert(CallTmp, ptr))
			std::cout << "Ok" << std::endl;
		else
			std::cout << "Duplicate name" << std::endl;
	}
	return 0;
}
