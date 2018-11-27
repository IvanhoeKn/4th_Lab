#ifndef _SHIP_H_
#define _SHIP_H_
#include <string>
#include <iostream>
#include "Weapon.h"
#include "MilitaryCharacteristics.h"


namespace AircraftСarrierGroup
{
	const double eps = 1e-9;

	struct Captain {
		std::string Name;
		std::string Rank;
		int Experience;

		//Констукторы
		Captain();

		Captain(std::string, std::string, int);

		//Копирующий конструктор
		Captain(Captain&);

		//------------------------------------------------------------

		//Деструктор
		~Captain();

		//------------------------------------------------------------

		//Перегруженные операторы
		Captain& operator = (Captain&);

	};

	//------------------------------------------------------------
	//------------------------------------------------------------

	class Ship : public MilitaryCharacteristics {
	protected:
		Captain* Commander;
		std::string Call;
		int Crew;
	public:
		//Конструкторы
		Ship();

		Ship(Captain&, std::string, int, MilitaryCharacteristics&);

		Ship(std::string, std::string, int, std::string, int, MilitaryCharacteristics&);

		Ship(Captain&, std::string, int, int, int, int);

		Ship(std::string, std::string, int, std::string, int, int, int, int);

		//Копирующий конструктор
		Ship(Ship&);

		//------------------------------------------------------------

		//Деструктор
		~Ship();

		//------------------------------------------------------------

		//Другие методы класса
		virtual Ship* clone() const = 0;

		Ship& setNewCommander(Captain&);

		Ship& setNewCall(std::string);

		Ship& setNewCrew(int);

		Captain getCommander() const { return* Commander; };

		std::string getCall() const { return Call; };

		int getCrew() const { return Crew; };

		//Максимальный переход
		double maxRangeTtransition() const ;

		//Время ведения огня всеми орудиями
		virtual double TimeFireAllWeapons() const = 0;

		//Разрушения, наносимые всеми самолетами корабля за единицу времени
		virtual int DamageAllPlanes() const = 0;

		//Разрушения, наносимые всем вооружением корабля за едниницу времени
		virtual int DamageAllWeapons() const = 0;

		//Вывод полной информации о судне в поток
		virtual std::ostream& printInfoShip(std::ostream&) const = 0;

		//Вывод информации о вооружении
		virtual std::ostream& printInfoWeapon(std::ostream&) const = 0;

		//Модификация вооружения корабля
		virtual Ship& WeaponModification(std::string, Weapon&) = 0;
	};
}
#endif