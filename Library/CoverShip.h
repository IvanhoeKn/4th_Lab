/**
@file CoverShip.h
@brief Заголовочный файл с описанием класса
@detailed Данный файл содержит в себе определение класса CoverShip
*/
#ifndef _COVER_H_
#define _COVER_H_

#include <iostream>
#include <fstream>
#include "Ship.h"

/**
namespace AircraftCarrierGroup
@brief Пространство имен AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
/**
@brief Класс для описания судна прикрытия
@detailed Осуществляет хранение всех параметров судна прикрытия и содержит функции, обрабатывающие эти параметры
*/
	class CoverShip : public Ship {
	protected:
		int AmountW;
		Weapon *ArrW;
		std::string Disguised;
		//---------------------------------
		virtual std::ostream& show(std::ostream& os) const;
		virtual std::istream& get(std::istream&);
		//---------------------------------
		virtual std::ofstream& fprint(std::ofstream&) const;
		virtual std::ifstream& fread(std::ifstream&);
	public:
/**
@brief Конструктор по умолчанию
*/
		CoverShip() : Ship(), Disguised("Covered Ship default"), AmountW(0), ArrW(nullptr) {}
/**
@brief Инициализирующий конструктор
@param CallTmp Название корабля
@param ComanderTmp Капитан судна
@param CrewTmp Количество человек в команде
@param MilitaryTmp Хранит общие характеристики техники
@param DisguisedTmp Название прикрываемого корабля
@param AmountTmp Количество вооружения на корабле
@param ArrTmp Хранит описатели каждого оружия на корабле
*/
		CoverShip(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp, std::string DisguisedTmp, int AmountTmp, Weapon *ArrTmp);
/**
@brief Копирующий конструктор
@param CoverShipTmp Описатель корабля прикрытия
*/
		CoverShip(const CoverShip &CoverShipTmp);
/**
@brief Деструктор
*/
		~CoverShip() {
			delete[] ArrW;
		}
/**
@brief Выводит всю информацию обо всех орудиях на судне
*/
		std::ostream& printInfoWeapon(std::ostream& os) const;
/**
@brief Функция модифицирует выбранное, из имеющихся на корабле, орудие
@param NameWeaponTmp Названия орудия, которое надо модифицировать
@param WeaponTmp Новое орудие
*/
		CoverShip& WeaponModification(std::string NameWeaponTmp, const Weapon& WeaponTmp);
/**
@brief Производит рассчет времени ведения огня всеми орудиями судна с полной скорострельностью
*/
		double TimeFireAllWeapons() const;
/**
@brief Производит расчет разрушений, которые могут нанести все самолеты судна условной цели за единицу времени
@throw InvalidShipType При попытке рассчета урона всеми самолетам по условным целям, 
поскольку этот тип кораблей не может иметь самолетов на палубе
*/
		int DamageAllPlanes() const { throw std::exception("No Planes on Cover Ship\n"); }
/**
@brief Производит расчет разрушений, которые могут нанести все орудия судна условной цели за единицу времени
*/
		int DamageAllWeapons() const;
/**
@brief Клонирует данный корабль
@return Возвращает указатель на область памяти, в котором хранится копия этого корабля
*/
		CoverShip* clone() const { return new CoverShip(*this); }
/**
@brief Функция получает описатель оружия по его названию
@param Name Название оружия
@return Возвращает указатель на область памяти, в котором хранится описатель найденного оружия
*/
		Weapon* getWeapon(std::string Name) const;
/**
@brief Возвращает количество вооружения на судне
*/
		int AmountWeapon() const { return AmountW; }
/**
@brief Тип данного корабля
*/
		int TypeShip() const { return 1; }
/**
@brief Возвращет количество самолетов на палубе
@throw InvalidShipType При попытке получить количество самолетов, поскольку этот тип кораблей не может иметь самолетов на палубе
*/
		int AmountAircraft() const { throw std::exception("No Aircrafts on Cover Ship\n"); }
/**
@brief Возвращет название прикрываемого корабля
*/
		std::string GetDisguised() const { return Disguised; }

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream&, const CoverShip&);
		friend std::istream& operator >> (std::istream&, CoverShip&);

		//Потоковый ввод/вывод из файла
		friend std::ofstream& operator << (std::ofstream& os, const CoverShip& ShipTmp) { return ShipTmp.fprint(os); }
		friend std::ifstream& operator >> (std::ifstream& is, CoverShip& ShipTmp) { return ShipTmp.fread(is); }
	};
}
#endif //_COVER_H_
