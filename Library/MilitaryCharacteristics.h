/**
@file MilitaryCharacteristics.h
@brief Заголовочный файл с описанием класса
@detailed Данный файл содержит в себе определение класса MilitaryCharacteristics
*/
#ifndef _CHARACTERISTICS_H_
#define _CHARACTERISTICS_H_

#include <iostream>
#include <fstream>

/**
namespace AircraftCarrierGroup
@brief Пространство имен AircraftCarrierGroup
*/
namespace AircraftCarrierGroup{

/**
@brief Класс для описания некоторых парметров техники
@detailed Осуществляет хранение и обработку некоторых характеристик техники
*/
	class MilitaryCharacteristics {
	protected:
		int Speed;
		int FuelReserve;
		int FuelConsumption;
	public:
/**
@brief Конструктор по умолчанию
*/
		MilitaryCharacteristics() : Speed(0), FuelReserve(0), FuelConsumption(0) {}
/**
@brief Инициализирующий конструктор
@param SpeedTmp Скорость
@param FuelReserveTmp Запас топлива
@param FuelConsumptionTmp Расход топлива
*/
		MilitaryCharacteristics(int SpeedTmp, int FuelConsumptionTmp, int FuelReserveTmp);
/**
@brief Копирующий конструктор
@param Military Объект класса, для которого будет произведено копирование
*/
		MilitaryCharacteristics(const MilitaryCharacteristics& Military);
/**
@brief Деструктор
*/
		virtual ~MilitaryCharacteristics() {}
/**
@brief Устанавливает скорость техники
@param[in] SpeedTmp Скорость, на которую нужно поменять
@return Возвращает измененные параметры техники
*/
		MilitaryCharacteristics& SetSpeed(int SpeedTmp) { Speed = SpeedTmp; return *this; }
/**
@brief Устанавливает запас топлива в технике
@param[in] FuelReserveTmp Запас топлива
@return Возвращает измененные параметры техники
*/
		MilitaryCharacteristics& SetFuelReserve(int FuelReserveTmp) { FuelReserve = FuelReserveTmp; return *this; }
/**
@brief Устанавливает расход топлива в технике
@param[in] FuelConsumptionTmp Запас топлива
@return Возвращает измененные параметры техники
*/
		MilitaryCharacteristics& SetFuelConsumption(int FuelConsumptionTmp) { FuelConsumption = FuelConsumptionTmp;  return *this; }
/**
@brief Возвращает скорость техники
*/
		int GetSpeed() const { return Speed; }
/**
@brief Возвращает запас топлива
*/
		int GetFuelReserve() const { return FuelReserve; }
/**
@brief Возвращает расход топлива
*/
		int GetFuelConsumption() const { return FuelConsumption; }

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream& os, const MilitaryCharacteristics& Military);
		friend std::istream& operator >> (std::istream& is, MilitaryCharacteristics& Military);

		//Потоковый ввод/вывод из файла
		friend std::ofstream& operator << (std::ofstream& os, const MilitaryCharacteristics& Military);
		friend std::ifstream& operator >> (std::ifstream& is, MilitaryCharacteristics& Military);

		//Перегруженные операторы
		MilitaryCharacteristics& operator = (const MilitaryCharacteristics& Military);
		MilitaryCharacteristics& operator = (MilitaryCharacteristics&& Military);
	};
}
#endif //_CHARACTERISTICS_H_