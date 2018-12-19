#include "stdafx.h"
#include "Fleet.h"

namespace AircraftCarrierGroup {

	std::ostream& operator <<(std::ostream& os, const std::pair<const std::string, Ship*> &ptr) {
		return os << '"' << ptr.first << '"' << " - " << (*ptr.second);
	}

	//------------------------------------------------------------

	Fleet::Fleet(const Fleet& FleetTmp) {
		_map<std::string, Ship*>::_map_const_it ptr;
		for (ptr = FleetTmp.ArrShip.begin(); ptr != FleetTmp.ArrShip.end(); ++ptr)
			ArrShip.insert(ptr.get()->first, ptr.get()->second);
	}
	
	//------------------------------------------------------------

	Fleet::~Fleet() {
		_map<std::string, Ship*>::_map_const_it ptr;
		for (ptr = ArrShip.begin(); ptr != ArrShip.end(); ++ptr) {
			delete ptr->second;
			ptr.get()->second = nullptr;
		}
	}

	//------------------------------------------------------------

	Fleet& Fleet::operator = (const Fleet& FleetTmp){
		_map<std::string, Ship*>::_map_const_it ptr;
		if (this != &FleetTmp) {
			//Освобождение памяти, занятой объектом слева
			for (ptr = ArrShip.begin(); ptr != ArrShip.end(); ++ptr)
				delete ptr->second;
			ArrShip.clear();
			//копирование кораблей из контейнера справа от присваивания в контейнер слева из присваивания
			_map<std::string, Ship*>::_map_const_it pptr;
			for (pptr = ArrShip.begin(); pptr != ArrShip.end(); ++pptr)
				ArrShip.insert(pptr.get()->first, pptr.get()->second->clone());
		}
		return *this;
	}
	
	//------------------------------------------------------------

	bool Fleet::insert(std::string& CallTmp, Ship* ShipTmp) {
		bool res = false;
		_map<std::string, Ship*>::_map_const_it ptr = ArrShip.find(CallTmp);
		//Поиск неуспешен
		if (ptr == ArrShip.end()) { 
			bool pptr = ArrShip.insert(CallTmp, ShipTmp->clone());////
			if (!pptr)
				throw std::exception("can't insert new item into map");
			res = true;
		}
		return res;
	}

	//------------------------------------------------------------

	bool Fleet::remove(std::string& CallTmp) {
		bool res = false;
		_map<std::string, Ship*>::_map_const_it ptr = ArrShip.find(CallTmp); //arr.erase(s);
		//Поиск успешен
		if (ptr != ArrShip.end()) {
			delete ptr->second;
			ptr.get()->second = nullptr;
			ArrShip.erase(ptr.get()->first); //Удаление элемента из контейнера
			res = true;
		}
		return res;
	}

	//------------------------------------------------------------

	Fleet::Const_Iterator Fleet::find(const std::string& CallTmp) const {
		_map<std::string, Ship*>::_map_const_it ptr = ArrShip.find(CallTmp);
		return ConstFleetIt(ptr);
	}

	//------------------------------------------------------------

	Fleet::Const_Iterator Fleet::begin() const {
		return ConstFleetIt(ArrShip.begin());
	}

	//------------------------------------------------------------

	Fleet::Const_Iterator Fleet::end() const {
		return ConstFleetIt(ArrShip.end());
	}

	//------------------------------------------------------------
	
	int ConstFleetIt::operator != (const ConstFleetIt& it) const {
		return cur != it.cur;
	}

	//------------------------------------------------------------

	int ConstFleetIt::operator == (const ConstFleetIt& it) const {
		return cur == it.cur;
	}

	//------------------------------------------------------------

	const _pair<std::string, Ship*>& ConstFleetIt::operator * () {
		return *cur;
	}

	const _pair<std::string, Ship*>* ConstFleetIt::operator -> () {
		return &*cur;
	}

	//------------------------------------------------------------

	ConstFleetIt& ConstFleetIt::operator ++ () {
		++cur;
		return *this;
	}

	//------------------------------------------------------------

	ConstFleetIt ConstFleetIt::operator ++ (int) {
		ConstFleetIt res(*this);
		++cur;
		return res;
	}

	//------------------------------------------------------------

	std::ifstream& operator >> (std::ifstream& is, Fleet& FleetTmp){
		CoverShip ShipTmpF;
		Carrier ShipTmpS;
		AircraftCarrier ShipTmpT;
		int Size;
		is.read((char*) &Size, sizeof(int));
		FleetTmp.ArrShip.clear();
		for (int i = 0; i < Size; i++){
			int StrLn, type;
			char NameBuf[80] = "";
			std::string nmm(NameBuf);
			std::string name;
			is.read((char*) &StrLn, sizeof(int));
			is.read(NameBuf, StrLn);
			is.read((char*) &type, sizeof(int));
			switch (type) {
			case 1:
				is >> ShipTmpF;
				FleetTmp.insert(nmm, &ShipTmpF);
				break;
			case 2:
				is >> ShipTmpS;
				FleetTmp.insert(nmm, &ShipTmpS);
				break;
			case 3:
				is >> ShipTmpT;
				FleetTmp.insert(nmm, &ShipTmpT);
				break;
			default:
				throw std::exception(" Invalid type of Ship\n");
				return is;
				break;
			}
		}
		return is;
	}

	//------------------------------------------------------------

	std::ofstream& operator << (std::ofstream& os, const Fleet& FleetTmp){
		int tmp;
		tmp = FleetTmp.SizeFleet();
		os.write((char*) &tmp, sizeof(int));
		Fleet::Const_Iterator it;
		for (it = FleetTmp.begin(); it != FleetTmp.end(); ++it) {
			tmp = (*it).first.size();
			os.write((char*) &tmp, sizeof(int));
			os << (*it).first;
			tmp = (*it).second->TypeShip();
			os.write((char*) &tmp, sizeof(int));
			os << *(*it).second;
		}
		return os;
	}

	//------------------------------------------------------------

	std::ostream& operator << (std::ostream& os, const Fleet& FleetTmp) {
		std::cout << "  ***Navy***" << std::endl;
		Fleet::Const_Iterator it;
		for (it = FleetTmp.begin(); it != FleetTmp.end(); ++it) {
			std::cout << " Callsign of Ship: \"" << (*it).first << "\"" << std::endl;
			std::cout << *(*it).second;
		}
		return os;
	}

	//------------------------------------------------------------

	int Fleet::transferFuel(Fleet::Const_Iterator& itFr, Fleet::Const_Iterator& itTo, const int Fuel) {
		int FuelTmp = (*itFr).second->GetFuelReserve() - Fuel;
		(*itFr).second->SetFuelReserve(FuelTmp);
		FuelTmp = (*itTo).second->GetFuelReserve() + Fuel;
		(*itTo).second->SetFuelReserve(FuelTmp);
		return true;
	}

	//------------------------------------------------------------

	int Fleet::TypeCoverShip() {
		Const_Iterator it;
		int Sum = 0;
		for (it = begin(); it != end(); ++it) {
			if ((*it).second->TypeShip() == 1)
				Sum++;
		}
		return Sum;
	}

	//------------------------------------------------------------

	int Fleet::TypeCarrier() {
		Const_Iterator it;
		int Sum = 0;
		for (it = begin(); it != end(); ++it) {
			if ((*it).second->TypeShip() == 2)
				Sum++;
		}
		return Sum;
	}

	//------------------------------------------------------------

	int Fleet::TypeAircraftCarrier() {
		Const_Iterator it;
		int Sum = 0;
		for (it = begin(); it != end(); ++it) {
			if ((*it).second->TypeShip() == 3)
				Sum++;
		}
		return Sum;
	}

	//------------------------------------------------------------

	bool Fleet::AddPlane(const Aircraft& Plane, const std::string& ShipTmp) {
		Const_Iterator it;
		it = find(ShipTmp);
		if (it != end()) {
			if ((*it).second->TypeShip() == 1)
				return false;
			else {
				Ship* pptr = (*it).second;
				Carrier* ptr;
				ptr = static_cast<Carrier*>(pptr);
				ptr->AddAircraft(Plane);
				return true;
			}
		}
		else {
			std::cout << "The Ship with Name \"" << ShipTmp << "\" is absent in container" << std::endl;
			return false;
		}
	}

	//------------------------------------------------------------

	bool Fleet::DeletePlane(const std::string& ShipTmp) {
		Const_Iterator it;
		it = find(ShipTmp);
		if (it != end()) {
			if ((*it).second->TypeShip() == 1)
				return false;
			else {
				Ship* pptr = (*it).second;
				Carrier* ptr;
				ptr = static_cast<Carrier*>(pptr);
				ptr->DeleteAircraft();
				return true;
			}
		}
		else {
			std::cout << "The Ship with Name \"" << ShipTmp << "\" is absent in container" << std::endl;
			return false;
		}
	}

	//------------------------------------------------------------

	double Fleet::MaxDurationPlaneFligth() {
		double MaxFlight = 0;
		Const_Iterator it;
		if (SizeFleet() - TypeCoverShip() > 0) {
			for (it = begin(); it != end(); ++it)
				if ((*it).second->TypeShip() != 1) {
					Ship* pptr = (*it).second;
					Carrier* ptr;
					ptr = static_cast<Carrier*>(pptr);
					if (ptr->MaxAircraftFlyght() > MaxFlight)
						MaxFlight = ptr->MaxAircraftFlyght();
				}
			return MaxFlight;
		}
		else {
			std::cout << " Еhere are no ships that can carry aircrafts! --> " << std::endl;
			return 0;
		}
	}

	//------------------------------------------------------------

	double Fleet::MaxRadiusPlaneFligth() {
		double MaxRadius = 0;
		Const_Iterator it;
		if (SizeFleet() - TypeCoverShip() > 0) {
			for (it = begin(); it != end(); ++it)
				if ((*it).second->TypeShip() != 1) {
					Ship* pptr = (*it).second;
					Carrier* ptr;
					ptr = static_cast<Carrier*>(pptr);
					if (ptr->MaxRadiusFlyght() > MaxRadius)
						MaxRadius = ptr->MaxRadiusFlyght();
				}
			return MaxRadius;
		}
		else {
			std::cout << " Еhere are no ships that can carry aircrafts! --> " << std::endl;
			return 0;
		}
	}

	//------------------------------------------------------------

	int Fleet::TransferAircraft(Fleet::Const_Iterator& From, Fleet::Const_Iterator& To) {
		if ((*From).second->TypeShip() == 1 || (*To).second->TypeShip() == 1)
			std::cout << "Ship types do not correspond to aircraft movement operations" << std::endl;
		else {
			Ship* pptr = (*From).second;
			Carrier* ptr;
			Aircraft PlaneTmp;
			ptr = static_cast<Carrier*>(pptr);
			ptr->DeleteAircraft(&PlaneTmp);
			pptr = (*To).second;
			ptr = static_cast<Carrier*>(pptr);
			ptr->AddAircraft(PlaneTmp);
		}
		return 0;
	}

	//------------------------------------------------------------

	/*int Fleet::DamageAllShipAircraft(const std::string& ShipTmp) {
		Const_Iterator it;
		it = find(ShipTmp);
		if (it == end()) {
			std::cout << "The Ship with Name \"" << ShipTmp << "\" is absent in container" << std::endl;
			return 0;
		}
		else
			if ((*it).second->TypeShip() == 1) {
				std::cout << " Invalid type of Ship" << std::endl;
				return 0;
			}
			else
				return (*it).second->DamageAllPlanes();
	}*/

	//------------------------------------------------------------

	/*int Fleet::DamageAllShipWeapon(const std::string& ShipTmp) {
		Const_Iterator it;
		it = find(ShipTmp);
		if (it == end()) {
			std::cout << "The Ship with Name \"" << ShipTmp << "\" is absent in container" << std::endl;
			return 0;
		}
		else
			if ((*it).second->TypeShip() == 2) {
				std::cout << " Invalid type of Ship" << std::endl;
				return 0;
			}
			else
				return (*it).second->DamageAllWeapons();
	}*/

	//------------------------------------------------------------

	/*double Fleet::TimeFireAllWeapons(const std::string& ShipTmp) {
		Const_Iterator it;
		it = find(ShipTmp);
		if (it == end()) {
			std::cout << "The Ship with Name \"" << ShipTmp << "\" is absent in container" << std::endl;
			return 0;
		}
		else
			if ((*it).second->TypeShip() == 2) {
				std::cout << " Invalid type of Ship" << std::endl;
				return 0;
			}
			else
				return (*it).second->TimeFireAllWeapons();
	}*/

	//------------------------------------------------------------

	/*double Fleet::MaxRangeShip(const std::string& ShipTmp) {
		Const_Iterator it;
		it = find(ShipTmp);
		if (it == end()) {
			std::cout << "The Ship with Name \"" << ShipTmp << "\" is absent in container" << std::endl;
			return -1;
		}
		else {
			std::cout << " Max Range Ttransition of Ship --> " << (*it).second->maxRangeTtransition();
			return 0;
		}
	}*/

	//------------------------------------------------------------

	void Fleet::clear() {
		Admiral = Captain();
		ArrShip.clear();
	}

	//------------------------------------------------------------

	void Fleet::Show() {
		if (SizeFleet() == 0)
			std::cout << " Navy is empty!" << std::endl;
		else {
			Const_Iterator it;
			for (it = begin(); it != end(); ++it)
				std::cout << *((*it).second);
		}
	}
};