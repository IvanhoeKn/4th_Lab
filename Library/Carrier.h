/**
@file Carrier.h
@brief Заголовочный файл с описанием класса
@detailed Данный файл содержит в себе определение класса Carrier
*/
#ifndef _CARRIER_H_
#define _CARRIER_H_

#include <iostream>
#include "Ship.h"
#include "Aircraft.h"

/**
namespace AircraftCarrierGroup
@brief Пространство имен AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
/**
@brief Класс для описания авианосца
@detailed Осуществляет хранение всех параметров авиносца и содержит функции, обрабатывающие эти параметры
*/
	class Carrier : public Ship {
	protected:
		int AmountP;
		Aircraft* Plane;
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
		Carrier() : Ship(), AmountP(0), Plane(nullptr) {}
/**
@brief Инициализирующий конструктор
@param CallTmp Название корабля
@param ComanderTmp Капитан судна
@param CrewTmp Количество человек в команде
@param MilitaryTmp Хранит общие характеристики техники
@param AmountPTmp Количество самолетов на палубе корабля
@param PlaneTmp Содержит описатели каждого из самолетов
*/
		Carrier(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp, int AmountPTmp = 0, Aircraft* PlaneTmp = nullptr);
/**
@brief Копирующий конструктор
@param CarrierTmp Описатель авианосца
*/
		Carrier(const Carrier& CarrierTmp);
/**
@brief Деструктор
*/
		virtual ~Carrier() {
			delete[] Plane;
		}
/**
@brief Выводит всю информацию обо всех орудиях на судне
*/
		std::ostream& printInfoWeapon(std::ostream& os) const;
/**
@brief Производит расчет разрушений, которые могут нанести все самолеты судна условной цели за единицу времени
*/
		int DamageAllPlanes() const;
/**
@brief Производит расчет разрушений, которые могут нанести все орудия судна условной цели за единицу времени
@throw InvalidOperation При попытке рассчета урона, наносимого всеми орудиями судна, поскольку этот тип кораблей 
не может иметь вооружения на борту
*/
		virtual int DamageAllWeapons() const { throw std::exception("No Weapons on Carrier\n"); }
/**
@brief Производит рассчет времени ведения огня всеми орудиями судна с полной скорострельностью
@throw InvalidOperation При попытке рассчета врмени ведения всеми орудиями судна, поскольку этот тип кораблей
не может иметь вооружения на борту
*/
		virtual double TimeFireAllWeapons() const { throw std::exception("No Weapons on Carrier\n"); }
/**
@brief Функция модифицирует выбранное, из имеющихся на корабле, орудие
@param NameWeaponTmp Названия орудия, которое надо модифицировать
@param WeaponTmp Новое орудие
@throw InvalidOperation При попытке модификации орудия судна, поскольку этот тип кораблей
не может иметь вооружения на борту
*/
		virtual Carrier& WeaponModification(std::string NameWeaponTmp, const Weapon& WeaponTmp) { throw std::exception("No Weapons on Carrier\n"); }
/**
@brief Клонирует данный корабль
@return Возвращает указатель на область памяти, в котором хранится копия этого корабля
*/
		virtual Carrier* clone() const { return new Carrier(*this); }
/**
@brief Функция получает описатель оружия по его названию
@param Name Название оружия
@return Возвращает указатель на область памяти, в котором хранится описатель найденного оружия
@throw InvalidOperation При попытке получить описатель орудия корабля по его названию, поскольку этот тип кораблей 
не может иметь вооружения на борту
*/
		virtual Weapon* getWeapon(std::string Name) const { throw std::exception("No Weapons on Carrier\n"); }
/**
@brief Возвращает количество вооружения на судне
@throw InvalidOperation При попытке получить количество орудий на корабле, поскольку этот тип кораблей
не может иметь вооружения на борту
*/
		virtual int AmountWeapon() const { throw std::exception("No Weapons on Carrier\n"); }
/**
@brief Тип данного корабля
*/
		virtual int TypeShip() const { return 2; }
/**
@brief Возвращет указатель на описатель самолета по его номеру
*/
		Aircraft* getAir(int Number) const;
/**
@brief Возвращет количество самолетов на палубе
*/
		int AmountAircraft() const { return AmountP; }
/**
@brief Производит добавление самолета на данный корабль
@param PlaneTmp Описатель самолета
*/
		Carrier& AddAircraft(const Aircraft& PlaneTmp);
/**
@brief Производит удаление самолета с корабль
@detailed Данная функция производит поиск поиск самолета по его номеру, в случае успеха копирует в буферную переменную
(это необходимо для функции переноса самолета с одного корабля на другой), а затем производит его удаление с этого корабля
@param[out] DeletedAircraft Копия удаленного самолета
*/
		Carrier& DeleteAircraft(Aircraft* DeletedAircraft = nullptr);
/**
@brief Производит рассчет времени одновременного полета всех самолетов корабля
*/
		double MaxAircraftFlyght() const;
/**
@brief Производит рассчет радиуса действия всех самолетов корабля
*/
		double MaxRadiusFlyght() const;
/**
@brief Функция возвращет названия прикрываемого корабля
@throw InvalidShipType При попытке получить названия прикрываемого корабля, поскольку этот тип кораблей не может иметь прикрываемого корабля
*/
		std::string GetDisguised() const { throw std::exception("This type of ship can't have Disguised ships\n"); }

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream&, const Carrier&);
		friend std::istream& operator >> (std::istream&, Carrier&);

		//Потоковый ввод/вывод из файла
		friend std::ofstream& operator << (std::ofstream& os, const Carrier& ShipTmp) { return ShipTmp.fprint(os); }
		friend std::ifstream& operator >> (std::ifstream& is, Carrier& ShipTmp) { return ShipTmp.fread(is); }
	};

}
#endif //_CARRIER_H_

