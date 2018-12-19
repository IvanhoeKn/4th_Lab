/**
@file Aircraft.h
@brief Заголовочный файл с описанием класса
@detailed Данный файл содержит в себе определение класса Aircraft
*/
#ifndef _AIRCRAFT_H_
#define _AIRCRAFT_H_

#include <iostream>
#include <fstream>
#include "Weapon.h"
#include "MilitaryCharacteristics.h"

/**
namespace AircraftCarrierGroup
@brief Пространство имен AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
/**
@brief Класс для описания самолета
@detailed Осуществляет хранение всех параметров самолета и содержит функции, обрабатывающие эти параметры
*/
	class Aircraft : public MilitaryCharacteristics {
	protected:
		static const int QUOTA = 3;
		int Amount;
		Weapon *Arr;
	public:
/**
@brief Конструктор по умолчанию
*/
		Aircraft() : MilitaryCharacteristics(), Amount(0), Arr(nullptr) {}
/**
@brief Инициализирующий конструктор
@param SpeedTmp Скорость
@param FuelReserveTmp Запас топлива
@param FuelConsumptionTmp Расход топлива
@throw InvalidQuota Если количество передаваемых орудий превышает QUOTA
*/
		Aircraft(int SpeedTmp, int FuelReserveTmp, int FuelConsumptionTmp) : MilitaryCharacteristics(SpeedTmp, FuelConsumptionTmp, FuelReserveTmp), Amount(0), Arr(nullptr) {}
/**
@brief Инициализирующий конструктор
@param SpeedTmp Скорость
@param FuelReserveTmp Запас топлива
@param FuelConsumptionTmp Расход топлива
@param AmountTmp Количество оружия
@param ArrTmp Массив, в котором хранится описатель каждого оружия
@throw InvalidQuota Если количество передаваемых орудий превышает QUOTA
*/
		Aircraft(int SpeedTmp, int FuelReserveTmp, int FuelConsumptionTmp, int AmountTmp, Weapon* ArrTmp);
/**
@brief Инициализирующий конструктор
@param Military Хранит общие характеристики техники
@param AmountTmp Количество вооружения
@param ArrTmp Массив, в котором хрнаится описатель каждого оружия
@throw InvalidQuota Если количество передаваемых орудий превышает QUOTA
*/
		Aircraft(const MilitaryCharacteristics& Military, int AmountTmp, Weapon* ArrTmp);
/**
@brief Копирующий конструктор
@param Plane Описатель самолета
*/
		Aircraft(const Aircraft& Plane);
/**
@brief Деструктор
*/
		~Aircraft() {
			delete [] Arr;
		}	
/**
@brief Возвращает описатель оружия по его номеру
@param Number Номер оружия
@throw InvalidNumberWeapon Есди был задан неверный номер оружия
*/
		Weapon& getWeaponAircraft(int Number) const;
/**
@brief Возвращает количество вооружения в самолете
*/
		int getAmountWeapon() const { return Amount; }

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream& os, const Aircraft& Plane);
		friend std::istream& operator >> (std::istream& is, Aircraft& Plane);

		//Потоковый ввод/вывод из файла
		friend std::ofstream& operator << (std::ofstream& os, const Aircraft& Plane);
		friend std::ifstream& operator >> (std::ifstream& is, Aircraft& Plane);

		//Перегруженные операторы
		Aircraft& operator = (const Aircraft& Plane);
		Aircraft& operator = (Aircraft&& Plane);
		Aircraft* operator * () { return this; }
	};
}
#endif //_AIRCRAFT_H_
