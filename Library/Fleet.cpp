#include "stdafx.h"
#include "Fleet.h"

namespace AircraftСarrierGroup {


	std::ostream& operator <<(std::ostream& os, const std::pair<const std::string, Ship*> &ptr) {
		return os << '"' << ptr.first << '"' << " - " << (*ptr.second);
	}

	/////////////////////////////////////////
	Fleet::Fleet(const Fleet& FleetTmp) {
		_map<std::string, Ship*>::_map_const_it ptr;
		for (ptr = FleetTmp.ArrShip.begin(); ptr != FleetTmp.ArrShip.end(); ++ptr)
			ArrShip.insert(ptr.get()->first, ptr.get()->second);
	}
	/////////////////////////////////////////

	Fleet::~Fleet() {
		_map<std::string, Ship*>::_map_const_it ptr;
		for (ptr = ArrShip.begin(); ptr != ArrShip.end(); ++ptr) {
			delete ptr->second;
			ptr.get()->second = nullptr;
		}
	}

	/////////////////////////////////////////
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
	/////////////////////////////////////////

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

	Fleet::Const_Iterator Fleet::find(const std::string& CallTmp) const {
		_map<std::string, Ship*>::_map_const_it ptr = ArrShip.find(CallTmp);
		return ConstFleetIt(ptr);
	}

	Fleet::Const_Iterator Fleet::begin() const {
		return ConstFleetIt(ArrShip.begin());
	}

	Fleet::Const_Iterator Fleet::end() const {
		return ConstFleetIt(ArrShip.end());
	}
	

	//Методы класса AssocIt??
	int ConstFleetIt::operator != (const ConstFleetIt& it) const {
		return cur != it.cur;
	}

	int ConstFleetIt::operator == (const ConstFleetIt& it) const {
		return cur == it.cur;
	}

	const _pair<std::string, Ship*>& ConstFleetIt::operator * () {
		return *cur;
	}

	const _pair<std::string, Ship*>* ConstFleetIt::operator -> () {
		return &*cur;
	}

	ConstFleetIt& ConstFleetIt::operator ++ () {
		++cur;
		return *this;
	}

	ConstFleetIt ConstFleetIt::operator ++ (int) {
		ConstFleetIt res(*this);
		++cur;
		return res;
	}

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

	std::ostream& operator << (std::ostream& os, const Fleet& FleetTmp) {
		std::cout << "  ***Navy***" << std::endl;
		Fleet::Const_Iterator it;
		for (it = FleetTmp.begin(); it != FleetTmp.end(); ++it) {
			std::cout << " Callsign of Ship: \"" << (*it).first << "\"" << std::endl;
			std::cout << *(*it).second;
		}
		return os;
	}
};