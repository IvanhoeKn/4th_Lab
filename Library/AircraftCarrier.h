/**
@file AircraftCarrier.h
@brief Заголовочный файл с описанием класса
@detailed Данный файл содержит в себе определение класса AircraftCarrier
*/
#ifndef _AIRCRAFT_CARRIER_H_
#define _AIRCRAFT_CARRIER_H_

#include <iostream>
#include "Carrier.h"

/**
namespace AircraftCarrierGroup
@brief Пространство имен AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
/**
@brief Класс для описания авианесущего крейсера
@detailed Осуществляет хранение всех параметров авианесущего крейсера и содержит функции, обрабатывающие эти параметры
*/
	class AircraftCarrier : public Carrier {
	protected:
		int AmountW;
		Weapon *ArrW;
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
		AircraftCarrier() : Carrier(), AmountW(0), ArrW(nullptr) {}
/**
@brief Инициализирующий конструктор
@param CallTmp Название корабля
@param ComanderTmp Капитан судна
@param CrewTmp Количество человек в команде
@param MilitaryTmp Хранит общие характеристики техники
@param AmountPTmp Количество самолетов на палубе корабля
@param PlaneTmp Содержит описатели каждого из самолетов
@param AmountWTmp Количество вооружения на корабле
@param ArrWTmp Хранит описатели каждого оружия на корабле
*/
		AircraftCarrier(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp, int AmountPTmp, Aircraft* PlaneTmp, int AmountWTmp, Weapon* ArrWTmp);
/**
@brief Копирующий конструктор
@param AerocarrierTmp Описатель авианесущего крейсера
*/
		AircraftCarrier(const AircraftCarrier& AerocarrierTmp);
/**
@brief Деструктор
*/
		~AircraftCarrier() {
			delete[] ArrW;
		}
/**
@brief Выводит всю информацию обо всех орудиях на судне
*/
		std::ostream& printInfoWeapon(std::ostream& os) const;
/**
@brief Производит расчет разрушений, которые могут нанести все орудия судна условной цели за единицу времени
*/
		int DamageAllWeapons() const;
/**
@brief Производит рассчет времени ведения огня всеми орудиями судна с полной скорострельностью
*/
		double TimeFireAllWeapons() const;
/**
@brief Функция модифицирует выбранное, из имеющихся на корабле, орудие
@param NameWeaponTmp Названия орудия, которое надо модифицировать
@param WeaponTmp Новое орудие
*/
		AircraftCarrier& WeaponModification(std::string NameWeaponTmp, Weapon& WeaponTmp);
/**
@brief Клонирует данный корабль
@return Возвращает указатель на область памяти, в котором хранится копия этого корабля
*/
		AircraftCarrier* clone() const { return new AircraftCarrier(*this); }
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
		int TypeShip() const { return 3; }
/**
@brief Функция возвращет названия прикрываемого корабля
@throw InvalidShipType При попытке получить названия прикрываемого корабля, поскольку этот тип кораблей не может иметь прикрываемого корабля
*/
		std::string GetDisguised() const { throw std::exception("This type of ship can't have Disguised ships\n"); }

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream&, const AircraftCarrier&);
		friend std::istream& operator >> (std::istream&, AircraftCarrier&);

		//Потоковый ввод/вывод из файла
		friend std::ofstream& operator << (std::ofstream& os, const AircraftCarrier& ShipTmp) { return ShipTmp.fprint(os); }
		friend std::ifstream& operator >> (std::ifstream& is, AircraftCarrier& ShipTmp) { return ShipTmp.fread(is); }
	};
}
#endif //_AIRCRAFT_CARRIER_H_

