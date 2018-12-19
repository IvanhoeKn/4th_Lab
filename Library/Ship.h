/**
@file Ship.h
@brief Заголовочный файл с описанием класса
@detailed Данный файл содержит в себе определение класса CoverShip
*/
#ifndef _SHIP_H_
#define _SHIP_H_

#include <string>
#include <iostream>
#include "stdio.h"
#include "Weapon.h"
#include "MilitaryCharacteristics.h"

/**
namespace AircraftCarrierGroup
@brief Пространство имен AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
	const double eps = 1e-9;

/**
@brief Структура для описания капитана
@detailed Осуществляет хранение всех параметров командира судна или флота
*/
	struct Captain {
		std::string Name;
		std::string Rank;
		int Experience;
/**
@brief Конструктор по умолчанию
*/
		Captain() : Name("Captain default"), Rank("Ordinary"), Experience(0) {};
/**
@brief Инициализирующий конструктор
@param NameTmp Имя капитана
@param RankTmp Ранг капитана
@param ExperienceTmp Стаж
*/
		Captain(std::string NameTmp, std::string RankTmp, int ExperienceTmp);
/**
@brief Копирующий конструктор
@param CommanderTmp Информация о командире, подлежащая копированию
*/
		Captain(const Captain& CommanderTmp);
/**
@brief Деструктор
*/
		~Captain() {}

		//Потоковый ввод/вывод
		friend std::istream& operator >> (std::istream& is, Captain& Commander);
		friend std::ostream& operator << (std::ostream& os, const Captain& Commander);

		//Потоковый ввод/вывод из файла
		friend std::ifstream& operator >> (std::ifstream& is, Captain& Commander);
		friend std::ofstream& operator << (std::ofstream& os, const Captain& Commander);

		//Перегруженные операторы
		Captain& operator = (const Captain&);
		Captain& operator = (Captain&&);
	};

/**
@brief Абстрактный класс для описания кораблей
@detailed Осуществляет хранение общих параметров кораблей и содержит функции, обрабатывающие эти параметры
*/
	class Ship : public MilitaryCharacteristics {
	protected:
		Captain Commander;
		std::string Call;
		int Crew;
		//---------------------------------
		virtual std::istream& get(std::istream&) = 0;
		virtual std::ostream& show(std::ostream&) const = 0;
		//---------------------------------
		virtual std::ofstream& fprint(std::ofstream&) const = 0;
		virtual std::ifstream& fread(std::ifstream&) = 0;
	public:
/**
@brief Конструктор по умолчанию
*/
		Ship() : MilitaryCharacteristics(), Call("Ship default"), Commander(), Crew(0) {}
/**
@brief Инициализирующий конструктор
@param CallTmp Название корабля
@param ComanderTmp Капитан судна
@param CrewTmp Количество человек в команде
@param MilitaryTmp Хранит общие характеристики техники
*/
		Ship(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp);
/**
@brief Инициализирующий конструктор
@param CallTmp Название корабля
@param NameTmp Имя капитана
@param RankTmp Ранг капитана
@param ExperienceTmp Стаж командира судна
@param CrewTmp Количество человек в команде
@param MilitaryTmp Хранит общие характеристики техники
*/
		Ship(std::string CallTmp, std::string NameTmp, std::string RankTmp, int ExperienceTmp, int CrewTmp, const MilitaryCharacteristics& MilitaryTmp);
/**
@brief Инициализирующий конструктор
@param CallTmp Название корабля
@param CommanderTmp Информация о командире судна
@param CrewTmp Количество человек в команде
@param SpeedTmp Скорость корабля
@param FuelReserveTmp Запас топлива судна
@param FuelConsumptionTmp Расход топлива корабля
*/
		Ship(std::string CallTmp, const Captain& CommanderTmp, int CrewTmp, int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp);
/**
@brief Инициализирующий конструктор
@param CallTmp Название корабля
@param NameTmp Имя капитана
@param RankTmp Ранг капитана
@param ExperienceTmp Стаж командира судна
@param CrewTmp Количество человек в команде
@param SpeedTmp Скорость корабля
@param FuelReserveTmp Запас топлива судна
@param FuelConsumptionTmp Расход топлива корабля
*/
		Ship(std::string CallTmp, std::string NameTmp, std::string RankTmp, int ExperienceTmp, int CrewTmp, int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp);
/**
@brief Копирующий конструктор
@param ShipTmp Описатель корабля
*/
		Ship(const Ship& ShipTmp);
/**
@brief Деструктор
*/
		virtual ~Ship() {}
/**
@brief Устанавливает нового капитана для корабля
@param[in] CommanderTmp Информация о новом командующим
@return Возвращает измененные параметры техники
*/
		Ship& setNewCommander(const Captain& CommanderTmp) { Commander = CommanderTmp; return *this; }
/**
@brief Устанавливает нового названия для корабля
@param[in] CallTmp Название корабля
@return Возвращает измененные параметры техники
*/
		Ship& setNewCall(std::string CallTmp) { Call = CallTmp; return *this; }
/**
@brief Устанавливает количество членов экипажа
@param[in] CrewTmp Количество человек в экипаже
@return Возвращает измененные параметры техники
*/
		Ship& setNewCrew(int CrewTmp) { Crew = CrewTmp; return *this; }
/**
@brief Возвращает информацию о капитане судна
*/
		Captain getCommander() const { return Commander; }
/**
@brief Возвращает название корабля
*/
		std::string getCall() const { return Call; }
/**
@brief Возвращает количество членов экипажа судна
*/
		int getCrew() const { return Crew; }
/**
@brief Производит рассчет максимальной дальности перехода при имеющемся количестве топлива
*/
		double maxRangeTtransition() const;
/**
@brief Производит рассчет времени ведения огня всеми орудиями судна
*/
		virtual double TimeFireAllWeapons() const = 0;
/**
@brief Подсчет всех разрушениий, наносимых всеми самолетами корабля за единицу времени
*/
		virtual int DamageAllPlanes() const = 0;
/**
@brief Подсчет всех разрушениий, наносимых всем вооружением корабля за едниницу времени
*/
		virtual int DamageAllWeapons() const = 0;
/**
@brief Возвращет количество вооружения на корабле
*/		
		virtual int AmountWeapon() const = 0;
/**
@brief Возвращет указатель на область памяти, в которой хранится вся информация о выбранном оружии
@param NameTmp Название оружия, по которому будет производиться поиск
*/
		virtual Weapon* getWeapon(std::string NameTmp) const = 0;
/**
@brief Функция модифицирует выбранное, из имеющихся на корабле, орудие
@param NameWeaponTmp Названия орудия, которое надо модифицировать
@param WeaponTmp Новое орудие
*/
		virtual Ship& WeaponModification(std::string NameWeaponTmp, const Weapon& WeaponTmp) = 0;
/**
@brief Возвращет тип корабля
*/
		virtual int TypeShip() const = 0;
/**
@brief Возвращет количество самолетов на судне
*/
		virtual int AmountAircraft() const = 0;
/**
@brief Возвращет название прикрываемого корабля
*/
		virtual std::string GetDisguised() const = 0;
/**
@brief Клонирует данные о корабле
*/
		virtual Ship* clone() const = 0;
/**
@brief Вывод всей информации об имеющемся вооружении на судне
*/
		virtual std::ostream& printInfoWeapon(std::ostream&) const = 0;

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream& os, const Ship& ShipTmp) { return ShipTmp.show(os); }
		friend std::istream& operator >> (std::istream& is, Ship& ShipTmp) { return ShipTmp.get(is); }

		//Потоковый ввод/вывод из файла
		friend std::ofstream& operator << (std::ofstream& os, const Ship& ShipTmp) { return ShipTmp.fprint(os); }
		friend std::ifstream& operator >> (std::ifstream& is, Ship& ShipTmp) { return ShipTmp.fread(is); }
	};
}
#endif //_SHIP_H_