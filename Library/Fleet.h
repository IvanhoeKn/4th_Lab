/**
@file Fleet.h
@brief Заголовочный файл с описанием класса и его итератора
@detailed Данный файл содержит в себе определение класса Fleet
*/
#ifndef _FLEET_H_
#define _FLEET_H

#include "_map.h"
#include <iostream>
#include <fstream>
#include "Ship.h"
#include "CoverShip.h"
#include "Carrier.h"
#include "AircraftCarrier.h"

/**
namespace AircraftCarrierGroup
@brief Пространство имен AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
/**
@brief Класс-итератор для класса Fleet
@detailed При его помощи осуществляется доступ к элементам контейнера класса Fleet
*/
	class ConstFleetIt {
	private:
		_map<std::string, Ship*>::_map_const_it cur;
	public:
/**
@brief Конструктор по умолчанию
*/
		ConstFleetIt() {}
/**
@brief Инициализирующий конструктор
@param it Константный итератор класса Fleet
*/
		ConstFleetIt(_map<std::string, Ship*>::_map_const_it it) :cur(it) {}
		//Перегруженные операторы
		int operator != (const ConstFleetIt&) const;
		int operator == (const ConstFleetIt&) const;
		const _pair<std::string, Ship*>& operator * ();
		const _pair<std::string, Ship*>* operator -> ();
		ConstFleetIt& operator ++ ();
		ConstFleetIt operator ++ (int);
	};

/**
@brief Класс для описания флота
@detailed Осуществляет хранение описателей всех кораблей флота и содержит функции, позволяющие взаимодействовать с кораблями флота
*/
	class Fleet {
	private:
		Captain Admiral;
		_map<std::string, Ship*> ArrShip;
	public:
/**
@brief Конструктор по умолчанию
*/
		Fleet() {}
/**
@brief Копирующий конструктор
@param CoverShipTmp Описатель корабля прикрытия
*/
		Fleet(const Fleet& Navy);
/**
@brief Деструктор
*/
		~Fleet();
		//------------------------------------------------------------
		friend class ConstFleetIt;
		typedef ConstFleetIt Const_Iterator;
		Const_Iterator find(const std::string&) const;
		Const_Iterator begin() const;
		Const_Iterator end() const;
		//------------------------------------------------------------
/**
@brief Возвращает количество кораблей во флоте
*/
		int SizeFleet() const { return ArrShip.size(); }
/**
@brief Добавляет новый корабль во флот
@param CallTmp Позывной нового корабля
@param ShipTmp Указатель на область памяти, в котором хранится вся информация о корабле
*/
		bool insert (std::string& CallTmp, Ship* ShipTmp);
/**
@brief Удаляет корабль из флота
@param CallTmp Позывной удаляемого корабля
*/
		bool remove(std::string& CallTmp);
/**
@brief Осуществляет перенос топлива с одного корабля на другой
@param itFr Корабль, с которого берется топливо
@param itTo Корабль, на который переносится топливо
@param Fuel Количество топлива, которое необходимо перенести
*/
		int transferFuel(Fleet::Const_Iterator& itFr, Fleet::Const_Iterator& itTo, const int Fuel);
/**
@brief Возвращает количество кораблей прикрытия в группе
*/
		int TypeCoverShip();
/**
@brief Возвращает количество авианесущих кораблей в группе
*/
		int TypeCarrier();
/**
@brief Возвращает количество авианесущих крейсеров в группе
*/
		int TypeAircraftCarrier();
/**
@brief Добавление самолета в авианесущую группу
@param Plane Самолет, информацию о котором необходимо внести в группу
@param ShipTmp Корабль, на который будет добавляться самолте
*/
		bool AddPlane(const Aircraft& Plane, const std::string& ShipTmp);
/**
@brief Удаление самолета с корабля
@param ShipTmp Корабль, с которого будет производиться удаление самолета
*/
		bool DeletePlane(const std::string& ShipTmp);
/**
@brief Производит рассчет максимального времени полета всех самолетов авиагруппы
*/
		double MaxDurationPlaneFligth();
/**
@brief Производит рассчет максимального радуса полета всех самолетов авиагруппы
*/
		double MaxRadiusPlaneFligth();
/**
@brief Осуществляет перенос самолета с одного корабля на другой
@param From Корабль, с которого берется самолет
@param To Корабль, на который переносится самолет
*/		
		int TransferAircraft(Fleet::Const_Iterator& From, Fleet::Const_Iterator& To);
/**
@brief Очистка контейнера, в котором хранится информация обо всех кораблях авианесущей группы
*/
		void clear();
/**
@brief Вывод информации обо всех кораблях флота
*/
		void Show();

		//double MaxRangeShip(const std::string& ShipTmp);
		//double TimeFireAllWeapons(const std::string& ShipTmp);
		//int DamageAllShipWeapon(const std::string& ShipTmp);
		//int DamageAllShipAircraft(const std::string& ShipTmp);

		//Потоковый вывод
		friend std::ostream& operator << (std::ostream&, const Fleet&);

		//Потоковый ввод/вывод из файла
		friend std::ifstream& operator >> (std::ifstream&, Fleet&);
		friend std::ofstream& operator << (std::ofstream&, const Fleet&);

		//Перегрузка операторов
		Fleet& operator = (const Fleet&);
	};
}
#endif //_FLEET_H_