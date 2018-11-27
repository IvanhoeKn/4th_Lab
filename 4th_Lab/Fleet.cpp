#include "pch.h"
#include "Fleet.h"

namespace AircraftСarrierGroup {


	std::ostream& operator <<(std::ostream& os, const std::pair<const std::string, Ship*> &ptr) {
		return os << '"' << ptr.first << '"' << " - " << (*ptr.second);
	}

	/////////////////////////////////////////
	Fleet::Fleet(const Fleet& FleetTmp) {
		std::map<const std::string, Ship*>::const_iterator ptr;
		for (ptr = FleetTmp.ArrShip.begin(); ptr != FleetTmp.ArrShip.end(); ++ptr)
			ArrShip.insert(std::make_pair(ptr->first, ptr->second->clone()));
	}
	/////////////////////////////////////////

	Fleet::~Fleet() {
		std::map<const std::string, Ship*>::iterator ptr;
		for (ptr = ArrShip.begin(); ptr != ArrShip.end(); ++ptr) {
			delete ptr->second;
			ptr->second = nullptr;
		}
	}

	/////////////////////////////////////////
	Fleet& Fleet::operator = (const Fleet& FleetTmp){
		std::map<const std::string, Ship*>::iterator ptr;
		if (this != &FleetTmp) {
			//Освобождение памяти, занятой объектом слева
			for (ptr = ArrShip.begin(); ptr != ArrShip.end(); ++ptr)
				delete ptr->second;
			ArrShip.clear();
			//копирование кораблей из контейнера справа от присваивания в контейнер слева из присваивания
			std::map<const std::string, Ship*>::const_iterator pptr;
			for (pptr = ArrShip.begin(); pptr != ArrShip.end(); ++pptr)
				ArrShip.insert(std::make_pair(pptr->first, pptr->second->clone()));
		}
		return *this;
	}
	/////////////////////////////////////////

	int Fleet::SizeFleet() {
		return ArrShip.size();
	}

	bool Fleet::insert(const std::string& CallTmp,const Ship* ShipTmp) {
		bool res = false;
		std::map<const std::string, Ship*>::iterator ptr = ArrShip.find(CallTmp);
		//Поиск неуспешен
		if (ptr == ArrShip.end()) { 
			std::pair<std::map<const std::string, Ship*>::iterator, bool> pptr = ArrShip.insert(std::make_pair(CallTmp, ShipTmp->clone()));////
			if (!pptr.second)
				throw std::exception("can't insert new item into map");
			res = true;
		}
		return res;
	}

	bool Fleet::remove(const std::string& CallTmp) {
		bool res = false;
		std::map<const std::string, Ship*>::iterator ptr = ArrShip.find(CallTmp); //arr.erase(s);
		//Поиск успешен
		if (ptr != ArrShip.end()) {
			delete ptr->second;
			ptr->second = nullptr;
			ArrShip.erase(ptr); //Удаление элемента из контейнера
			res = true;
		}
		return res;
	}
	/*
	bool Table::replace(const std::string &s, const Shapes::Shape *f) {
		bool res = false;
		std::map<const std::string, Shapes::Shape *>::iterator p = arr.find(s);
			if (p != arr.end()) { 
				delete p->second;
				p->second = f->clone();
				res = true;
			}
		return res;
	}*/

	Fleet::Const_Iterator Fleet::find(const std::string& CallTmp) const {
		std::map<const std::string, Ship*>::const_iterator ptr = ArrShip.find(CallTmp);
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

	const std::pair<const std::string, Ship*>& ConstFleetIt::operator * () {
		return *cur;
	}

	const std::pair<const std::string, Ship*>* ConstFleetIt::operator -> () {
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
};