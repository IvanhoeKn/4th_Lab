/**
@file Weapon.h
@brief Заголовочный файл с описанием класса
@detailed Данный файл содержит в себе определение класса Weapon
*/
#ifndef _WEAPON_H_
#define _WEAPON_H_

#include <iostream>
#include <fstream>
#include <string>

/**
namespace AircraftCarrierGroup
@brief Пространство имен AircraftCarrierGroup
*/
namespace AircraftCarrierGroup {
/**
@brief Класс для описания вооружения
@detailed Осуществляет хранение всех параметров авианесущего крейсера и содержит функции, обрабатывающие эти параметры
*/
	class Weapon {
	protected:
		std::string NameWeapon;
		std::string NameAmmunition;
		int RateFire, QuantityAmmunition, Damage;
	public:
/**
@brief Конструктор по умолчанию
*/
		Weapon() : NameWeapon("Name default"), NameAmmunition("Name ammo default"), RateFire(0), QuantityAmmunition(0), Damage(0) {}
/**
@brief Инициализирующий конструктор
@param Weapon Название оружия
@param Munition Название боеприпаса
@param RateFireTmp Скорострельность орудия
@param QuantityAmmunitionTmp Количество боеприпасов
@param DamageTmp Разрушения, наносимые цели при одном удачном попадании
*/
		Weapon(std::string Weapon, std::string Munition, int RateFireTmp, int QuantityAmmunitionTmp, int DamageTmp);
/**
@brief Копирующий конструктор
@param Arsenal Описатель копируемого оружия
*/
		Weapon(const Weapon& Arsenal);
/**
@brief Деструктор
*/
		virtual ~Weapon() {}
/**
@brief Устанавливает названия оружия
@param[in] Weapon Новое название оружия
@return Возвращает измененные параметры оружия
*/
		Weapon& SetWeapon(std::string Weapon) { NameWeapon = Weapon; return *this; }
/**
@brief Устанавливает название боеприпаса
@param[in] Munition Новое название боеприпаса, применимого для этого орудия
@return Возвращает измененные параметры оружия
*/
		Weapon& SetMunition(std::string Munition) { NameAmmunition = Munition; return *this; }
/**
@brief Устанавливает скорострельность орудия
@param[in] RateFireTmp Новый параметр скорострельности
@return Возвращает измененные параметры оружия
*/
		Weapon& SetRateFire(int RateFireTmp) { RateFire = RateFireTmp; return *this; }
/**
@brief Устанавливает новое количество боеприпасов
@param[in] QuantityAmmunitionTmp Новое количество боеприпасов
@return Возвращает измененные параметры оружия
*/
		Weapon& SetQuantityAmmunition(int QuantityAmmunitionTmp) { QuantityAmmunition = QuantityAmmunitionTmp; return *this; }
/**
@brief Устанавливает урон орудия, наносимого по цели за попадание
@param[in] DamageTmp Обновленный урон
@return Возвращает измененные параметры оружия
*/
		Weapon& SetDamage(int DamageTmp) { Damage = DamageTmp; return *this; }
/**
@brief Возвращает название оружия
*/
		std::string GetWeapon() const { return NameWeapon; }
/**
@brief Возвращает название боеприпаса
*/
		std::string GetMunition() const { return NameAmmunition; }
/**
@brief Возвращает скорострельность орудия
*/
		int GetRateFire() const { return RateFire; }
/**
@brief Возвращает количество боеприпасов для данного орудия
*/
		int GetQuantityAmmunition() const { return QuantityAmmunition; }
/**
@brief Возвращает урон, наносимый цели при одном удачном попадании
*/
		int GetDamage() const { return Damage; }

		//Потоковый ввод/вывод
		friend std::ostream& operator << (std::ostream&, const Weapon&);
		friend std::istream& operator >> (std::istream&, Weapon&);

		//Потоковый ввод/вывод из файла
		friend std::ofstream& operator << (std::ofstream&, const Weapon&);
		friend std::ifstream& operator >> (std::ifstream&, Weapon&);

		//Перегруженные операторы
		Weapon& operator = (const Weapon& Arsenal);
		Weapon& operator = (Weapon&& Arsenal);
		Weapon* operator *() { return this; }
	};
}
#endif //_WEAPON_H_