#ifndef _FLEET_H_
#define _FLEET_H
#include <map>
#include <iostream>
#include "Ship.h"

namespace Aircraft—arrierGroup {

	std::ostream& operator << (std::ostream&, const std::pair<const std::string, Ship*> &);

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

		int SizeFleet();
		bool insert (const std::string&, const Ship*);
		bool remove(const std::string&);
	};

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
}
#endif