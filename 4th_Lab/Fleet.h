#ifndef _FLEET_H_
#define _FLEET_H
#include <map>
#include <iostream>
#include <fstream>
#include "Ship.h"
#include "CoverShip.h"
#include "Carrier.h"
#include "AircraftCarrier.h"

namespace Aircraft—arrierGroup {

	std::ostream& operator << (std::ostream&, const std::pair<const std::string, Ship*> &);

	class ConstFleetIt {
	private:
		std::map<const std::string, Ship*>::const_iterator cur;
	public:
		ConstFleetIt() {};
		ConstFleetIt(std::map<const std::string, Ship*>::iterator it) :cur(it) {};
		ConstFleetIt(std::map<const std::string, Ship*>::const_iterator it) :cur(it) {}
		int operator != (const ConstFleetIt&) const;
		int operator == (const ConstFleetIt&) const;
		const std::pair<const std::string, Ship*>& operator * ();
		const std::pair<const std::string, Ship*>* operator -> ();
		ConstFleetIt& operator ++ ();
		ConstFleetIt operator ++ (int);
	};

	class Fleet {
	private:
		Captain Admiral;
		std::map<const std::string, Ship*> ArrShip;
	public:
		Fleet() {};
		Fleet(const Fleet&);
		~Fleet();
		Fleet& operator = (const Fleet&);

		friend class ConstFleetIt;
		typedef ConstFleetIt Const_Iterator;
		Const_Iterator find(const std::string&) const;
		Const_Iterator begin() const;
		Const_Iterator end() const;

		friend std::ostream& operator << (std::ostream&, const Fleet&);

		friend std::ifstream& operator >> (std::ifstream&, Fleet&);
		friend std::ofstream& operator << (std::ofstream&, const Fleet&);

		int SizeFleet() const;
		bool insert (const std::string&, const Ship*);
		bool remove(const std::string&);
		int transferFuel(Fleet::Const_Iterator& itFr, Fleet::Const_Iterator& itTo, const int Fuel) {
			int FuelTmp = (*itFr).second->GetFuelReserve() - Fuel;
			(*itFr).second->SetFuelReserve(FuelTmp);
			FuelTmp = (*itTo).second->GetFuelReserve() + Fuel;
			(*itTo).second->SetFuelReserve(FuelTmp);
			return true;
		}
		int TypeCoverShip(){
			Const_Iterator it;
			int Sum = 0;
			for (it = begin(); it != end(); ++it) {
				if ((*it).second->TypeShip() == 1)
					Sum++;
			}
			return Sum;
		}
		int TypeCarrier(){
			Const_Iterator it;
			int Sum = 0;
			for (it = begin(); it != end(); ++it) {
				if ((*it).second->TypeShip() == 2)
					Sum++;
			}
			return Sum;
		}
		int TypeAircraftCarrier(){
			Const_Iterator it;
			int Sum = 0;
			for (it = begin(); it != end(); ++it) {
				if ((*it).second->TypeShip() == 3)
					Sum++;
			}
			return Sum;
		}
		bool AddPlane(const Aircraft& Plane, const std::string& ShipTmp) {
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
		bool DeletePlane(const std::string& ShipTmp) {
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
		double MaxDurationPlaneFligth() {
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
				std::cout << " ≈here are no ships that can carry aircrafts! --> " << std::endl;
				return 0;
			}
		}
		double MaxRadiusPlaneFligth() {
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
				std::cout << " ≈here are no ships that can carry aircrafts! --> " << std::endl;
				return 0;
			}
		}
		int TransferAircraft(Fleet::Const_Iterator& From, Fleet::Const_Iterator& To) {
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

		int DamageAllShipAircraft(const std::string& ShipTmp) {
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
		}

		int DamageAllShipWeapon(const std::string& ShipTmp) {
			Const_Iterator it;
			it = find(ShipTmp);
			if(it == end()) {
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
		}

		double TimeFireAllWeapons(const std::string& ShipTmp) {
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
		}

		double MaxRangeShip(const std::string& ShipTmp) {
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
		}

		void clear() {
			Admiral = Captain();
			ArrShip.clear();
		}

		void Show() {
			if (SizeFleet() == 0)
				std::cout << " Navy is empty!" << std::endl;
			else {
				Const_Iterator it;
				for (it = begin(); it != end(); ++it)
					std::cout << (*it).second;
			}
		}
	};
}
#endif