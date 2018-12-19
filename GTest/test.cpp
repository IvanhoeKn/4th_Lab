#include "pch.h"
#include "..\Library\_map.h"
#include "..\Library\MilitaryCharacteristics.h"
#include "..\Library\Weapon.h"
#include "..\Library\Aircraft.h"
#include "..\Library\Ship.h"
#include "..\Library\CoverShip.h"
#include "..\Library\Carrier.h"
#include "..\Library\AircraftCarrier.h"
#include "..\Library\Fleet.h"

//------------------------------------------------------------------------------------------------------------------------

using namespace std;
using namespace AircraftCarrierGroup;

//------------------------------------------------------------------------------------------------------------------------

/**
Testing Class MilitaryCharacteristics
*/

TEST(ClassMilitaryConstructor, DefaultConstructorMilitary) {
	MilitaryCharacteristics Military_D;
	ASSERT_EQ(0, Military_D.GetSpeed());
	ASSERT_EQ(0, Military_D.GetFuelReserve());
	ASSERT_EQ(0, Military_D.GetFuelConsumption());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassMilitaryConstructor, InitialConstructorMilitary) {
	MilitaryCharacteristics Military_I{ 7, 14, 28 };
	ASSERT_EQ(7, Military_I.GetSpeed());
	ASSERT_EQ(28, Military_I.GetFuelReserve());
	ASSERT_EQ(14, Military_I.GetFuelConsumption());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassMilitaryConstructor, CopyConstructorMilitary) {
	MilitaryCharacteristics Military{ 7, 14, 28 };
	MilitaryCharacteristics Military_C(Military);
	ASSERT_EQ(7, Military_C.GetSpeed());
	ASSERT_EQ(28, Military_C.GetFuelReserve());
	ASSERT_EQ(14, Military_C.GetFuelConsumption());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassMilitaryMethods, SetterMilitary) {
	MilitaryCharacteristics Military;
	Military.SetSpeed(7);
	Military.SetFuelReserve(14);
	Military.SetFuelConsumption(28);
	ASSERT_EQ(7, Military.GetSpeed());
	ASSERT_EQ(14, Military.GetFuelReserve());
	ASSERT_EQ(28, Military.GetFuelConsumption());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassMilitaryMethods, EqualMilitary) {
	MilitaryCharacteristics Military{ 7, 14, 28 };
	MilitaryCharacteristics Military_E;
	Military_E = Military;
	ASSERT_EQ(7, Military_E.GetSpeed());
	ASSERT_EQ(28, Military_E.GetFuelReserve());
	ASSERT_EQ(14, Military_E.GetFuelConsumption());
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

/**
Testing Class Weapon
*/

TEST(ClassWeaponConstructor, DefaultConstructorWeapon) {
	Weapon Arsenal_D;
	ASSERT_EQ("Name default", Arsenal_D.GetWeapon());
	ASSERT_EQ("Name ammo default", Arsenal_D.GetMunition());
	ASSERT_EQ(0, Arsenal_D.GetRateFire());
	ASSERT_EQ(0, Arsenal_D.GetQuantityAmmunition());
	ASSERT_EQ(0, Arsenal_D.GetDamage());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassWeaponConstructor, InitialConstructorWeapon) {
	Weapon Arsenal_I{ "Caliber", "Landmine", 17, 5, 2017 };
	ASSERT_EQ("Caliber", Arsenal_I.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_I.GetMunition());
	ASSERT_EQ(17, Arsenal_I.GetRateFire());
	ASSERT_EQ(5, Arsenal_I.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_I.GetDamage());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassWeaponConstructor, CopyConstructorWeapon) {
	Weapon Arsenal{ "Caliber", "Landmine", 17, 5, 2017 };
	Weapon Arsenal_C(Arsenal);
	ASSERT_EQ("Caliber", Arsenal_C.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_C.GetMunition());
	ASSERT_EQ(17, Arsenal_C.GetRateFire());
	ASSERT_EQ(5, Arsenal_C.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_C.GetDamage());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassWeaponMethods, SetterWeapon) {
	Weapon Arsenal;
	Arsenal.SetWeapon("Caliber");
	Arsenal.SetMunition("Landmine");
	Arsenal.SetRateFire(17);
	Arsenal.SetQuantityAmmunition(5);
	Arsenal.SetDamage(2017);
	ASSERT_EQ("Caliber", Arsenal.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal.GetMunition());
	ASSERT_EQ(17, Arsenal.GetRateFire());
	ASSERT_EQ(5, Arsenal.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal.GetDamage());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassWeaponMethods, EqualWeapon) {
	Weapon Arsenal{ "Caliber", "Landmine", 17, 5, 2017 };
	Weapon Arsenal_E;
	Arsenal_E = Arsenal;
	ASSERT_EQ("Caliber", Arsenal.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal.GetMunition());
	ASSERT_EQ(17, Arsenal.GetRateFire());
	ASSERT_EQ(5, Arsenal.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal.GetDamage());
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

/**
Testing Class Aircraft
*/

TEST(ClassAircraftConstructor, DefaultConstructorAircraft) {
	Aircraft Plane_D;
	ASSERT_EQ(0, Plane_D.GetSpeed());
	ASSERT_EQ(0, Plane_D.GetFuelReserve());
	ASSERT_EQ(0, Plane_D.GetFuelConsumption());
	ASSERT_EQ(0, Plane_D.getAmountWeapon());
	ASSERT_ANY_THROW(Plane_D.getWeaponAircraft(2));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftConstructor, 1_InitialConstructorAircraft) {
	Aircraft Plane_I{ 117, 256, 13 };
	ASSERT_EQ(117, Plane_I.GetSpeed());
	ASSERT_EQ(256, Plane_I.GetFuelReserve());
	ASSERT_EQ(13, Plane_I.GetFuelConsumption());
	ASSERT_EQ(0, Plane_I.getAmountWeapon());
	try {
		Plane_I.getWeaponAircraft(3);
	}
	catch (exception& ex) {
		ASSERT_STREQ("Invalid Number of Weapon\n", ex.what());
	}
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftConstructor, 2_InitialConstructorAircraft) {
	Weapon Arsenal_I[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	Aircraft Plane_I{ 117, 256, 13, 2, Arsenal_I };
	//------------------------------------------------------------
	ASSERT_EQ(117, Plane_I.GetSpeed());
	ASSERT_EQ(256, Plane_I.GetFuelReserve());
	ASSERT_EQ(13, Plane_I.GetFuelConsumption());
	ASSERT_EQ(2, Plane_I.getAmountWeapon());
	//------------------------------------------------------------
	try {
		Plane_I.getWeaponAircraft(3);
	}
	catch (exception& ex) {
		ASSERT_STREQ("Invalid Number of Weapon\n", ex.what());
	}
	//------------------------------------------------------------
	Weapon Arsenal_1 = Plane_I.getWeaponAircraft(1);
	//------------------------------------------------------------
	ASSERT_EQ("Name default", Arsenal_1.GetWeapon());
	ASSERT_EQ("Name ammo default", Arsenal_1.GetMunition());
	ASSERT_EQ(0, Arsenal_1.GetRateFire());
	ASSERT_EQ(0, Arsenal_1.GetQuantityAmmunition());
	ASSERT_EQ(0, Arsenal_1.GetDamage());
	//------------------------------------------------------------
	Weapon Arsenal_2 = Plane_I.getWeaponAircraft(2);
	//------------------------------------------------------------
	ASSERT_EQ("Caliber", Arsenal_2.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2.GetMunition());
	ASSERT_EQ(17, Arsenal_2.GetRateFire());
	ASSERT_EQ(5, Arsenal_2.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2.GetDamage());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftConstructor, 2_InitialConstructorAircraft_with_exception) {
	Weapon Arsenal_I[4] = { {}, {}, {}, {} };
	try {
		Aircraft Plane_I{ 117, 256, 13, 2, Arsenal_I };
	}
	catch (exception& ex) {
		ASSERT_STREQ("Exceeded the maximum number of weapons\n", ex.what());
	}
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftConstructor, 3_InitialConstructorAircraft) {
	MilitaryCharacteristics Military{ 7, 14, 28 };
	Weapon Arsenal_I[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	Aircraft Plane_I{ Military, 2, Arsenal_I };
	//------------------------------------------------------------
	ASSERT_EQ(7, Plane_I.GetSpeed());
	ASSERT_EQ(28, Plane_I.GetFuelReserve());
	ASSERT_EQ(14, Plane_I.GetFuelConsumption());
	ASSERT_EQ(2, Plane_I.getAmountWeapon());
	//------------------------------------------------------------
	try {
		Plane_I.getWeaponAircraft(3);
	}
	catch (exception& ex) {
		ASSERT_STREQ("Invalid Number of Weapon\n", ex.what());
	}
	//------------------------------------------------------------
	Weapon Arsenal_1 = Plane_I.getWeaponAircraft(1);
	//------------------------------------------------------------
	ASSERT_EQ("Name default", Arsenal_1.GetWeapon());
	ASSERT_EQ("Name ammo default", Arsenal_1.GetMunition());
	ASSERT_EQ(0, Arsenal_1.GetRateFire());
	ASSERT_EQ(0, Arsenal_1.GetQuantityAmmunition());
	ASSERT_EQ(0, Arsenal_1.GetDamage());
	//------------------------------------------------------------
	Weapon Arsenal_2 = Plane_I.getWeaponAircraft(2);
	//------------------------------------------------------------
	ASSERT_EQ("Caliber", Arsenal_2.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2.GetMunition());
	ASSERT_EQ(17, Arsenal_2.GetRateFire());
	ASSERT_EQ(5, Arsenal_2.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2.GetDamage());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftConstructor, 3_InitialConstructorAircraft_with_exception) {
	MilitaryCharacteristics Military{ 7, 14, 28 };
	Weapon Arsenal_I[4] = { {}, {}, {}, {} };
	try {
		Aircraft Plane_I{ Military, 2, Arsenal_I };
	}
	catch (exception& ex) {
		ASSERT_STREQ("Exceeded the maximum number of weapons\n", ex.what());
	}
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftConstructor, CopyConstructorAircraft) {
	Weapon Arsenal[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	Aircraft Plane{ 117, 256, 13, 2, Arsenal };
	Aircraft Plane_C(Plane);
	//------------------------------------------------------------
	ASSERT_EQ(117, Plane_C.GetSpeed());
	ASSERT_EQ(256, Plane_C.GetFuelReserve());
	ASSERT_EQ(13, Plane_C.GetFuelConsumption());
	ASSERT_EQ(2, Plane_C.getAmountWeapon());
	//------------------------------------------------------------
	try {
		Plane_C.getWeaponAircraft(3);
	}
	catch (exception& ex) {
		ASSERT_STREQ("Invalid Number of Weapon\n", ex.what());
	}
	//------------------------------------------------------------
	Weapon Arsenal_1 = Plane_C.getWeaponAircraft(1);
	//------------------------------------------------------------
	ASSERT_EQ("Name default", Arsenal_1.GetWeapon());
	ASSERT_EQ("Name ammo default", Arsenal_1.GetMunition());
	ASSERT_EQ(0, Arsenal_1.GetRateFire());
	ASSERT_EQ(0, Arsenal_1.GetQuantityAmmunition());
	ASSERT_EQ(0, Arsenal_1.GetDamage());
	//------------------------------------------------------------
	Weapon Arsenal_2 = Plane_C.getWeaponAircraft(2);
	//------------------------------------------------------------
	ASSERT_EQ("Caliber", Arsenal_2.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2.GetMunition());
	ASSERT_EQ(17, Arsenal_2.GetRateFire());
	ASSERT_EQ(5, Arsenal_2.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2.GetDamage());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftMethods, SetterAircraft) {
	Aircraft Plane;
	Plane.SetSpeed(7);
	Plane.SetFuelReserve(14);
	Plane.SetFuelConsumption(28);
	ASSERT_EQ(7, Plane.GetSpeed());
	ASSERT_EQ(14, Plane.GetFuelReserve());
	ASSERT_EQ(28, Plane.GetFuelConsumption());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftMethods, EqualAircraft) {
	Weapon Arsenal[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	Aircraft Plane{ 117, 256, 13, 2, Arsenal };
	Aircraft Plane_E;
	Plane_E = Plane;
	//------------------------------------------------------------
	ASSERT_EQ(117, Plane_E.GetSpeed());
	ASSERT_EQ(256, Plane_E.GetFuelReserve());
	ASSERT_EQ(13, Plane_E.GetFuelConsumption());
	ASSERT_EQ(2, Plane_E.getAmountWeapon());
	//------------------------------------------------------------
	try {
		Plane_E.getWeaponAircraft(3);
	}
	catch (exception& ex) {
		ASSERT_STREQ("Invalid Number of Weapon\n", ex.what());
	}
	//------------------------------------------------------------
	Weapon Arsenal_1 = Plane_E.getWeaponAircraft(1);
	//------------------------------------------------------------
	ASSERT_EQ("Name default", Arsenal_1.GetWeapon());
	ASSERT_EQ("Name ammo default", Arsenal_1.GetMunition());
	ASSERT_EQ(0, Arsenal_1.GetRateFire());
	ASSERT_EQ(0, Arsenal_1.GetQuantityAmmunition());
	ASSERT_EQ(0, Arsenal_1.GetDamage());
	//------------------------------------------------------------
	Weapon Arsenal_2 = Plane_E.getWeaponAircraft(2);
	//------------------------------------------------------------
	ASSERT_EQ("Caliber", Arsenal_2.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2.GetMunition());
	ASSERT_EQ(17, Arsenal_2.GetRateFire());
	ASSERT_EQ(5, Arsenal_2.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2.GetDamage());
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

/**
Testing Struct Captain
*/

TEST(StructCaptainConstructor, DefaultConstructorWeapon) {
	Captain Commander_D;
	ASSERT_EQ("Captain default", Commander_D.Name);
	ASSERT_EQ("Ordinary", Commander_D.Rank);
	ASSERT_EQ(0, Commander_D.Experience);
}

//------------------------------------------------------------------------------------------------------------------------

TEST(StructCaptainConstructor, InitialConstructorCaptain) {
	Captain Commander_I{ "Nakhimov", "Admiral", 81 };
	ASSERT_EQ("Nakhimov", Commander_I.Name);
	ASSERT_EQ("Admiral", Commander_I.Rank);
	ASSERT_EQ(81, Commander_I.Experience);
}

//------------------------------------------------------------------------------------------------------------------------

TEST(StructCaptainConstructor, CopyConstructorCaptain) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	Captain Commander_C(Commander);
	ASSERT_EQ("Nakhimov", Commander_C.Name);
	ASSERT_EQ("Admiral", Commander_C.Rank);
	ASSERT_EQ(81, Commander_C.Experience);
}

//------------------------------------------------------------------------------------------------------------------------

TEST(StructCaptainMethods, EqualCaptain) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	Captain Commander_E;
	Commander_E = Commander;
	ASSERT_EQ("Nakhimov", Commander_E.Name);
	ASSERT_EQ("Admiral", Commander_E.Rank);
	ASSERT_EQ(81, Commander_E.Experience);
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

/**
Testing Class CoverShip
*/

TEST(ClassCoverShipConstructor, DefaultConstructorCoverShip) {
	CoverShip Cover_D;
	ASSERT_EQ("Ship default", Cover_D.getCall());
	//------------------------------------------------------------
	ASSERT_EQ("Captain default", Cover_D.getCommander().Name);
	ASSERT_EQ("Ordinary", Cover_D.getCommander().Rank);
	ASSERT_EQ(0, Cover_D.getCommander().Experience);
	//------------------------------------------------------------
	ASSERT_EQ(0, Cover_D.getCrew());
	//------------------------------------------------------------
	ASSERT_EQ(0, Cover_D.GetSpeed());
	ASSERT_EQ(0, Cover_D.GetFuelReserve());
	ASSERT_EQ(0, Cover_D.GetFuelConsumption());
	//------------------------------------------------------------
	ASSERT_EQ("Covered Ship default", Cover_D.GetDisguised());
	//------------------------------------------------------------
	ASSERT_EQ(0, Cover_D.AmountWeapon());
	//------------------------------------------------------------
	ASSERT_EQ(nullptr, Cover_D.getWeapon("Caliber"));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCoverShipConstructor, InitialConstructorCoverShip) {
	Captain Commander_I{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military_I{ 63, 17, 563 };
	Weapon Arsenal_I[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	CoverShip Cover_I{ "Admiral Kuznetsov", Commander_I, 256, Military_I, "Varangian", 2, Arsenal_I };
	//------------------------------------------------------------
	ASSERT_EQ("Admiral Kuznetsov", Cover_I.getCall());
	//------------------------------------------------------------
	ASSERT_EQ("Nakhimov", Cover_I.getCommander().Name);
	ASSERT_EQ("Admiral", Cover_I.getCommander().Rank);
	ASSERT_EQ(81, Cover_I.getCommander().Experience);
	//------------------------------------------------------------
	ASSERT_EQ(256, Cover_I.getCrew());
	//------------------------------------------------------------
	ASSERT_EQ(63, Cover_I.GetSpeed());
	ASSERT_EQ(563, Cover_I.GetFuelReserve());
	ASSERT_EQ(17, Cover_I.GetFuelConsumption());
	//------------------------------------------------------------
	ASSERT_EQ("Varangian", Cover_I.GetDisguised());
	//------------------------------------------------------------
	ASSERT_EQ(2, Cover_I.AmountWeapon());
	//------------------------------------------------------------
	Weapon* Default_I = Cover_I.getWeapon("Name default");
	ASSERT_EQ("Name default", Default_I->GetWeapon());
	ASSERT_EQ("Name ammo default", Default_I->GetMunition());
	ASSERT_EQ(0, Default_I->GetRateFire());
	ASSERT_EQ(0, Default_I->GetQuantityAmmunition());
	ASSERT_EQ(0, Default_I->GetDamage());
	//------------------------------------------------------------
	Weapon* Caliber_I = Cover_I.getWeapon("Caliber");
	ASSERT_EQ("Caliber", Caliber_I->GetWeapon());
	ASSERT_EQ("Landmine", Caliber_I->GetMunition());
	ASSERT_EQ(17, Caliber_I->GetRateFire());
	ASSERT_EQ(5, Caliber_I->GetQuantityAmmunition());
	ASSERT_EQ(2017, Caliber_I->GetDamage());
	//------------------------------------------------------------
	ASSERT_EQ(nullptr, Cover_I.getWeapon("Search"));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCoverShipConstructor, CopyConstructorCoverShip) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	CoverShip Cover{ "Admiral Kuznetsov", Commander, 256, Military, "Varangian", 2, Arsenal };
	CoverShip Cover_C(Cover);
	//------------------------------------------------------------
	ASSERT_EQ("Admiral Kuznetsov", Cover_C.getCall());
	//------------------------------------------------------------
	ASSERT_EQ("Nakhimov", Cover_C.getCommander().Name);
	ASSERT_EQ("Admiral", Cover_C.getCommander().Rank);
	ASSERT_EQ(81, Cover_C.getCommander().Experience);
	//------------------------------------------------------------
	ASSERT_EQ(256, Cover_C.getCrew());
	//------------------------------------------------------------
	ASSERT_EQ(63, Cover_C.GetSpeed());
	ASSERT_EQ(563, Cover_C.GetFuelReserve());
	ASSERT_EQ(17, Cover_C.GetFuelConsumption());
	//------------------------------------------------------------
	ASSERT_EQ("Varangian", Cover_C.GetDisguised());
	//------------------------------------------------------------
	ASSERT_EQ(2, Cover_C.AmountWeapon());
	//------------------------------------------------------------
	Weapon* Default_C = Cover_C.getWeapon("Name default");
	ASSERT_EQ("Name default", Default_C->GetWeapon());
	ASSERT_EQ("Name ammo default", Default_C->GetMunition());
	ASSERT_EQ(0, Default_C->GetRateFire());
	ASSERT_EQ(0, Default_C->GetQuantityAmmunition());
	ASSERT_EQ(0, Default_C->GetDamage());
	//------------------------------------------------------------
	Weapon* Caliber_C = Cover_C.getWeapon("Caliber");
	ASSERT_EQ("Caliber", Caliber_C->GetWeapon());
	ASSERT_EQ("Landmine", Caliber_C->GetMunition());
	ASSERT_EQ(17, Caliber_C->GetRateFire());
	ASSERT_EQ(5, Caliber_C->GetQuantityAmmunition());
	ASSERT_EQ(2017, Caliber_C->GetDamage());
	//------------------------------------------------------------
	ASSERT_EQ(nullptr, Cover_C.getWeapon("Search"));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCoverShipMethods, SetterCoverShip) {
	CoverShip Cover;
	//------------------------------------------------------------
	Cover.setNewCall("Admiral Kuznetsov");
	ASSERT_EQ("Admiral Kuznetsov", Cover.getCall());
	//------------------------------------------------------------
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	Cover.setNewCommander(Commander);
	ASSERT_EQ("Nakhimov", Cover.getCommander().Name);
	ASSERT_EQ("Admiral", Cover.getCommander().Rank);
	ASSERT_EQ(81, Cover.getCommander().Experience);
	//------------------------------------------------------------
	Cover.setNewCrew(256);
	ASSERT_EQ(256, Cover.getCrew());
	//------------------------------------------------------------
	Cover.SetSpeed(63);
	Cover.SetFuelReserve(563);
	Cover.SetFuelConsumption(17);
	ASSERT_EQ(63, Cover.GetSpeed());
	ASSERT_EQ(563, Cover.GetFuelReserve());
	ASSERT_EQ(17, Cover.GetFuelConsumption());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCoverShipMethods, TypeShipCoverShip) {
	CoverShip Cover;
	ASSERT_EQ(1, Cover.TypeShip());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCoverShipMethods, CloneCoverShip) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {"Poplar", "Landmine", 13, 81, 1017}, {"Caliber", "Landmine", 3, 23, 2017} };
	CoverShip Cover{ "Admiral Kuznetsov", Commander, 256, Military, "Varangian", 2, Arsenal };
	CoverShip* Cover_Clone;
	Cover_Clone = Cover.clone();
	//------------------------------------------------------------
	ASSERT_EQ("Admiral Kuznetsov", Cover_Clone->getCall());
	//------------------------------------------------------------
	ASSERT_EQ("Nakhimov", Cover_Clone->getCommander().Name);
	ASSERT_EQ("Admiral", Cover_Clone->getCommander().Rank);
	ASSERT_EQ(81, Cover_Clone->getCommander().Experience);
	//------------------------------------------------------------
	ASSERT_EQ(256, Cover_Clone->getCrew());
	//------------------------------------------------------------
	ASSERT_EQ(63, Cover_Clone->GetSpeed());
	ASSERT_EQ(563, Cover_Clone->GetFuelReserve());
	ASSERT_EQ(17, Cover_Clone->GetFuelConsumption());
	//------------------------------------------------------------
	ASSERT_EQ("Varangian", Cover_Clone->GetDisguised());
	//------------------------------------------------------------
	ASSERT_EQ(2, Cover_Clone->AmountWeapon());
	//------------------------------------------------------------
	Weapon* Poplar_C = Cover_Clone->getWeapon("Poplar");
	ASSERT_EQ("Poplar", Poplar_C->GetWeapon());
	ASSERT_EQ("Landmine", Poplar_C->GetMunition());
	ASSERT_EQ(13, Poplar_C->GetRateFire());
	ASSERT_EQ(81, Poplar_C->GetQuantityAmmunition());
	ASSERT_EQ(1017, Poplar_C->GetDamage());
	//------------------------------------------------------------
	Weapon* Caliber_C = Cover_Clone->getWeapon("Caliber");
	ASSERT_EQ("Caliber", Caliber_C->GetWeapon());
	ASSERT_EQ("Landmine", Caliber_C->GetMunition());
	ASSERT_EQ(3, Caliber_C->GetRateFire());
	ASSERT_EQ(23, Caliber_C->GetQuantityAmmunition());
	ASSERT_EQ(2017, Caliber_C->GetDamage());
	//------------------------------------------------------------
	ASSERT_EQ(nullptr, Cover_Clone->getWeapon("Search"));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCoverShipMethods, CalculationParametersCoverShip) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {"Poplar", "Landmine", 13, 81, 1017}, {"Caliber", "Landmine", 3, 23, 2017} };
	CoverShip Cover{ "Admiral Kuznetsov", Commander, 256, Military, "Varangian", 2, Arsenal };
	//------------------------------------------------------------
	ASSERT_NEAR(2086.4, Cover.maxRangeTtransition(), 0.1);
	//------------------------------------------------------------
	ASSERT_NEAR(6.2, Cover.TimeFireAllWeapons(), 0.1);
	//------------------------------------------------------------
	try {
		Cover.DamageAllPlanes();
	}
	catch (exception& ex) {
		ASSERT_STREQ("No Planes on Cover Ship\n", ex.what());
	}
	//------------------------------------------------------------
	ASSERT_EQ(3034, Cover.DamageAllWeapons());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCoverShipMethods, AircraftCoverShip) {
	CoverShip Cover;
	try {
		Cover.DamageAllPlanes();
	}
	catch (exception& ex) {
		ASSERT_STREQ("No Planes on Cover Ship\n", ex.what());
	}
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCoverShipMethods, WeaponCoverShip) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {"Poplar", "Landmine", 13, 81, 1017}, {"Caliber", "Landmine", 3, 23, 2017} };
	CoverShip Cover{ "Admiral Kuznetsov", Commander, 256, Military, "Varangian", 2, Arsenal };
	//------------------------------------------------------------
	ASSERT_EQ(2, Cover.AmountWeapon());
	//------------------------------------------------------------
	Weapon* Arsenal_1 = Cover.getWeapon("Poplar");
	ASSERT_EQ("Poplar", Arsenal_1->GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_1->GetMunition());
	ASSERT_EQ(13, Arsenal_1->GetRateFire());
	ASSERT_EQ(81, Arsenal_1->GetQuantityAmmunition());
	ASSERT_EQ(1017, Arsenal_1->GetDamage());
	//------------------------------------------------------------
	Weapon* Arsenal_2 = Cover.getWeapon("Caliber");
	ASSERT_EQ("Caliber", Arsenal_2->GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2->GetMunition());
	ASSERT_EQ(3, Arsenal_2->GetRateFire());
	ASSERT_EQ(23, Arsenal_2->GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2->GetDamage());
	//------------------------------------------------------------
	ASSERT_EQ(nullptr, Cover.getWeapon("Default"));
	//------------------------------------------------------------
	Weapon Arsenal_3{ "Ballistic", "Water-Land", 7, 69, 593 };
	Cover.WeaponModification("Caliber", Arsenal_3);
	Weapon* Check = Cover.getWeapon("Ballistic");
	ASSERT_EQ("Ballistic", Check->GetWeapon());
	ASSERT_EQ("Water-Land", Check->GetMunition());
	ASSERT_EQ(7, Check->GetRateFire());
	ASSERT_EQ(69, Check->GetQuantityAmmunition());
	ASSERT_EQ(593, Check->GetDamage());
	//------------------------------------------------------------
	Cover.WeaponModification("Caliber", Arsenal_3);
	ASSERT_EQ(nullptr, Cover.getWeapon("Caliber"));
}

//------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------

/**
Testing Class Carrier
*/

TEST(ClassCarrierConstructor, DefaultConstructorCarrier) {
	Carrier Carrier_D;
	ASSERT_EQ("Ship default", Carrier_D.getCall());
	//------------------------------------------------------------
	ASSERT_EQ("Captain default", Carrier_D.getCommander().Name);
	ASSERT_EQ("Ordinary", Carrier_D.getCommander().Rank);
	ASSERT_EQ(0, Carrier_D.getCommander().Experience);
	//------------------------------------------------------------
	ASSERT_EQ(0, Carrier_D.getCrew());
	//------------------------------------------------------------
	ASSERT_EQ(0, Carrier_D.GetSpeed());
	ASSERT_EQ(0, Carrier_D.GetFuelReserve());
	ASSERT_EQ(0, Carrier_D.GetFuelConsumption());
	//------------------------------------------------------------
	ASSERT_EQ(0, Carrier_D.AmountAircraft());
	//---------------------------------
	ASSERT_EQ(nullptr, Carrier_D.getAir(5));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCarrierConstructor, InitialConstructorCarrier) {
	Captain Commander_I{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military_I{ 63, 17, 563 };
	Weapon Arsenal_I[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	Aircraft Plane_I[2] = { {}, {Military_I, 2, Arsenal_I} };
	Carrier Carrier_I{ "Admiral Kuznetsov", Commander_I, 256, Military_I, 2, Plane_I };
	//------------------------------------------------------------
	ASSERT_EQ("Admiral Kuznetsov", Carrier_I.getCall());
	//------------------------------------------------------------
	ASSERT_EQ("Nakhimov", Carrier_I.getCommander().Name);
	ASSERT_EQ("Admiral", Carrier_I.getCommander().Rank);
	ASSERT_EQ(81, Carrier_I.getCommander().Experience);
	//------------------------------------------------------------
	ASSERT_EQ(256, Carrier_I.getCrew());
	//------------------------------------------------------------
	ASSERT_EQ(63, Carrier_I.GetSpeed());
	ASSERT_EQ(563, Carrier_I.GetFuelReserve());
	ASSERT_EQ(17, Carrier_I.GetFuelConsumption());
	//------------------------------------------------------------
	ASSERT_EQ(2, Carrier_I.AmountAircraft());
	//------------------------------------------------------------
	Aircraft* Plane_1 = Carrier_I.getAir(1);
	ASSERT_EQ(0, Plane_1->GetSpeed());
	ASSERT_EQ(0, Plane_1->GetFuelReserve());
	ASSERT_EQ(0, Plane_1->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(0, Plane_1->getAmountWeapon());
	//------------------------------------------------------------
	Aircraft* Plane_2 = Carrier_I.getAir(2);
	ASSERT_EQ(63, Plane_2->GetSpeed());
	ASSERT_EQ(563, Plane_2->GetFuelReserve());
	ASSERT_EQ(17, Plane_2->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(2, Plane_2->getAmountWeapon());
	//---------------------------------
	Weapon Arsenal_1 = Plane_2->getWeaponAircraft(1);
	ASSERT_EQ("Name default", Arsenal_1.GetWeapon());
	ASSERT_EQ("Name ammo default", Arsenal_1.GetMunition());
	ASSERT_EQ(0, Arsenal_1.GetRateFire());
	ASSERT_EQ(0, Arsenal_1.GetQuantityAmmunition());
	ASSERT_EQ(0, Arsenal_1.GetDamage());
	//---------------------------------
	Weapon Arsenal_2 = Plane_2->getWeaponAircraft(2);
	ASSERT_EQ("Caliber", Arsenal_2.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2.GetMunition());
	ASSERT_EQ(17, Arsenal_2.GetRateFire());
	ASSERT_EQ(5, Arsenal_2.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2.GetDamage());
	//---------------------------------
	try {
		Plane_2->getWeaponAircraft(5);
	}
	catch (exception& ex) {
		ASSERT_STREQ("Invalid Number of Weapon\n", ex.what());
	}
	//---------------------------------
	ASSERT_EQ(nullptr, Carrier_I.getAir(5));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCarrierConstructor, CopyConstructorCarrier) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	Aircraft Plane[2] = { {}, {Military, 2, Arsenal} };
	Carrier CarrierTmp{ "Admiral Kuznetsov", Commander, 256, Military, 2, Plane };
	Carrier Carrier_C(CarrierTmp);
	//------------------------------------------------------------
	ASSERT_EQ("Admiral Kuznetsov", Carrier_C.getCall());
	//------------------------------------------------------------
	ASSERT_EQ("Nakhimov", Carrier_C.getCommander().Name);
	ASSERT_EQ("Admiral", Carrier_C.getCommander().Rank);
	ASSERT_EQ(81, Carrier_C.getCommander().Experience);
	//------------------------------------------------------------
	ASSERT_EQ(256, Carrier_C.getCrew());
	//------------------------------------------------------------
	ASSERT_EQ(63, Carrier_C.GetSpeed());
	ASSERT_EQ(563, Carrier_C.GetFuelReserve());
	ASSERT_EQ(17, Carrier_C.GetFuelConsumption());
	//------------------------------------------------------------
	ASSERT_EQ(2, Carrier_C.AmountAircraft());
	//------------------------------------------------------------
	Aircraft* Plane_1 = Carrier_C.getAir(1);
	ASSERT_EQ(0, Plane_1->GetSpeed());
	ASSERT_EQ(0, Plane_1->GetFuelReserve());
	ASSERT_EQ(0, Plane_1->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(0, Plane_1->getAmountWeapon());
	//------------------------------------------------------------
	Aircraft* Plane_2 = Carrier_C.getAir(2);
	ASSERT_EQ(63, Plane_2->GetSpeed());
	ASSERT_EQ(563, Plane_2->GetFuelReserve());
	ASSERT_EQ(17, Plane_2->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(2, Plane_2->getAmountWeapon());
	//---------------------------------
	Weapon Arsenal_1 = Plane_2->getWeaponAircraft(1);
	ASSERT_EQ("Name default", Arsenal_1.GetWeapon());
	ASSERT_EQ("Name ammo default", Arsenal_1.GetMunition());
	ASSERT_EQ(0, Arsenal_1.GetRateFire());
	ASSERT_EQ(0, Arsenal_1.GetQuantityAmmunition());
	ASSERT_EQ(0, Arsenal_1.GetDamage());
	//---------------------------------
	Weapon Arsenal_2 = Plane_2->getWeaponAircraft(2);
	ASSERT_EQ("Caliber", Arsenal_2.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2.GetMunition());
	ASSERT_EQ(17, Arsenal_2.GetRateFire());
	ASSERT_EQ(5, Arsenal_2.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2.GetDamage());
	//---------------------------------
	try {
		Plane_2->getWeaponAircraft(5);
	}
	catch (exception& ex) {
		ASSERT_STREQ("Invalid Number of Weapon\n", ex.what());
	}
	//---------------------------------
	ASSERT_EQ(nullptr, Carrier_C.getAir(5));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCarrierMethods, SetterCarrier) {
	Carrier Carrier_S;
	//------------------------------------------------------------
	Carrier_S.setNewCall("Admiral Kuznetsov");
	ASSERT_EQ("Admiral Kuznetsov", Carrier_S.getCall());
	//------------------------------------------------------------
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	Carrier_S.setNewCommander(Commander);
	ASSERT_EQ("Nakhimov", Carrier_S.getCommander().Name);
	ASSERT_EQ("Admiral", Carrier_S.getCommander().Rank);
	ASSERT_EQ(81, Carrier_S.getCommander().Experience);
	//------------------------------------------------------------
	Carrier_S.setNewCrew(256);
	ASSERT_EQ(256, Carrier_S.getCrew());
	//------------------------------------------------------------
	Carrier_S.SetSpeed(63);
	Carrier_S.SetFuelReserve(563);
	Carrier_S.SetFuelConsumption(17);
	ASSERT_EQ(63, Carrier_S.GetSpeed());
	ASSERT_EQ(563, Carrier_S.GetFuelReserve());
	ASSERT_EQ(17, Carrier_S.GetFuelConsumption());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCarrierMethods, TypeShipCarrier) {
	Carrier Carrier_T;
	ASSERT_EQ(2, Carrier_T.TypeShip());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCarrierMethods, CloneCarrier) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	Aircraft Plane[2] = { {}, {Military, 2, Arsenal} };
	Carrier CarrierTmp{ "Admiral Kuznetsov", Commander, 256, Military, 2, Plane };
	Carrier* Carrier_Copy = CarrierTmp.clone();
	//------------------------------------------------------------
	ASSERT_EQ("Admiral Kuznetsov", Carrier_Copy->getCall());
	//------------------------------------------------------------
	ASSERT_EQ("Nakhimov", Carrier_Copy->getCommander().Name);
	ASSERT_EQ("Admiral", Carrier_Copy->getCommander().Rank);
	ASSERT_EQ(81, Carrier_Copy->getCommander().Experience);
	//------------------------------------------------------------
	ASSERT_EQ(256, Carrier_Copy->getCrew());
	//------------------------------------------------------------
	ASSERT_EQ(63, Carrier_Copy->GetSpeed());
	ASSERT_EQ(563, Carrier_Copy->GetFuelReserve());
	ASSERT_EQ(17, Carrier_Copy->GetFuelConsumption());
	//------------------------------------------------------------
	ASSERT_EQ(2, Carrier_Copy->AmountAircraft());
	//------------------------------------------------------------
	Aircraft* Plane_1 = Carrier_Copy->getAir(1);
	ASSERT_EQ(0, Plane_1->GetSpeed());
	ASSERT_EQ(0, Plane_1->GetFuelReserve());
	ASSERT_EQ(0, Plane_1->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(0, Plane_1->getAmountWeapon());
	//------------------------------------------------------------
	Aircraft* Plane_2 = Carrier_Copy->getAir(2);
	ASSERT_EQ(63, Plane_2->GetSpeed());
	ASSERT_EQ(563, Plane_2->GetFuelReserve());
	ASSERT_EQ(17, Plane_2->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(2, Plane_2->getAmountWeapon());
	//---------------------------------
	Weapon Arsenal_1 = Plane_2->getWeaponAircraft(1);
	ASSERT_EQ("Name default", Arsenal_1.GetWeapon());
	ASSERT_EQ("Name ammo default", Arsenal_1.GetMunition());
	ASSERT_EQ(0, Arsenal_1.GetRateFire());
	ASSERT_EQ(0, Arsenal_1.GetQuantityAmmunition());
	ASSERT_EQ(0, Arsenal_1.GetDamage());
	//---------------------------------
	Weapon Arsenal_2 = Plane_2->getWeaponAircraft(2);
	ASSERT_EQ("Caliber", Arsenal_2.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2.GetMunition());
	ASSERT_EQ(17, Arsenal_2.GetRateFire());
	ASSERT_EQ(5, Arsenal_2.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2.GetDamage());
	//---------------------------------
	try {
		Plane_2->getWeaponAircraft(5);
	}
	catch (exception& ex) {
		ASSERT_STREQ("Invalid Number of Weapon\n", ex.what());
	}
	//---------------------------------
	ASSERT_EQ(nullptr, Carrier_Copy->getAir(5));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCarrierMethods, CalculationParametersCarrier) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	Aircraft Plane[2] = { {}, {Military, 2, Arsenal} };
	Carrier CarrierTmp{ "Admiral Kuznetsov", Commander, 256, Military, 2, Plane };
	//------------------------------------------------------------
	ASSERT_NEAR(2086.4, CarrierTmp.maxRangeTtransition(), 0.1);
	//------------------------------------------------------------
	try {
		CarrierTmp.TimeFireAllWeapons();
	}
	catch (exception& ex) {
		ASSERT_STREQ("No Weapons on Carrier\n", ex.what());
	}
	//------------------------------------------------------------
	ASSERT_EQ(2017, CarrierTmp.DamageAllPlanes());
	//------------------------------------------------------------
	try {
		CarrierTmp.DamageAllWeapons();
	}
	catch (exception& ex) {
		ASSERT_STREQ("No Weapons on Carrier\n", ex.what());
	}
	//------------------------------------------------------------
	ASSERT_NEAR(33.1, CarrierTmp.MaxAircraftFlyght(), 0.1);
	//------------------------------------------------------------
	ASSERT_NEAR(2086.4, CarrierTmp.MaxRadiusFlyght(), 0.1);
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCarrierMethods, AircraftCarrierShip) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	Aircraft Plane[1] = { {Military, 2, Arsenal} };
	Carrier CarrierTmp{ "Admiral Kuznetsov", Commander, 256, Military, 0 };
	//------------------------------------------------------------
	CarrierTmp.AddAircraft(Plane[0]);
	ASSERT_EQ(1, CarrierTmp.AmountAircraft());
	//------------------------------------------------------------
	Aircraft* Plane_1 = CarrierTmp.getAir(1);
	ASSERT_EQ(63, Plane_1->GetSpeed());
	ASSERT_EQ(563, Plane_1->GetFuelReserve());
	ASSERT_EQ(17, Plane_1->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(2, Plane_1->getAmountWeapon());
	//---------------------------------
	Weapon Arsenal_1 = Plane_1->getWeaponAircraft(1);
	ASSERT_EQ("Name default", Arsenal_1.GetWeapon());
	ASSERT_EQ("Name ammo default", Arsenal_1.GetMunition());
	ASSERT_EQ(0, Arsenal_1.GetRateFire());
	ASSERT_EQ(0, Arsenal_1.GetQuantityAmmunition());
	ASSERT_EQ(0, Arsenal_1.GetDamage());
	//---------------------------------
	Weapon Arsenal_2 = Plane_1->getWeaponAircraft(2);
	ASSERT_EQ("Caliber", Arsenal_2.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2.GetMunition());
	ASSERT_EQ(17, Arsenal_2.GetRateFire());
	ASSERT_EQ(5, Arsenal_2.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2.GetDamage());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassCarrierMethods, WeaponCarrier) {
	Carrier CarrierTmp;
	try {
		CarrierTmp.AmountWeapon();
	}
	catch (exception& ex) {
		ASSERT_STREQ("No Weapons on Carrier\n", ex.what());
	}
	try {
		CarrierTmp.getWeapon("Search");
	}
	catch (exception& ex) {
		ASSERT_STREQ("No Weapons on Carrier\n", ex.what());
	}
	Weapon Arsenal;
	try {
		CarrierTmp.WeaponModification("New", Arsenal);
	}
	catch (exception& ex) {
		ASSERT_STREQ("No Weapons on Carrier\n", ex.what());
	}
}

/**
Testing Class AircraftCarrier
*/

TEST(ClassAircraftCarrierConstructor, DefaultConstructorAircraftCarrier) {
	AircraftCarrier AircraftCarrier_D;
	ASSERT_EQ("Ship default", AircraftCarrier_D.getCall());
	//------------------------------------------------------------
	ASSERT_EQ("Captain default", AircraftCarrier_D.getCommander().Name);
	ASSERT_EQ("Ordinary", AircraftCarrier_D.getCommander().Rank);
	ASSERT_EQ(0, AircraftCarrier_D.getCommander().Experience);
	//------------------------------------------------------------
	ASSERT_EQ(0, AircraftCarrier_D.getCrew());
	//------------------------------------------------------------
	ASSERT_EQ(0, AircraftCarrier_D.GetSpeed());
	ASSERT_EQ(0, AircraftCarrier_D.GetFuelReserve());
	ASSERT_EQ(0, AircraftCarrier_D.GetFuelConsumption());
	//------------------------------------------------------------
	ASSERT_EQ(0, AircraftCarrier_D.AmountWeapon());
	//------------------------------------------------------------
	ASSERT_EQ(nullptr, AircraftCarrier_D.getWeapon("Caliber"));
	//------------------------------------------------------------
	ASSERT_EQ(0, AircraftCarrier_D.AmountAircraft());
	//---------------------------------
	ASSERT_EQ(nullptr, AircraftCarrier_D.getAir(5));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftCarrierConstructor, InitialConstructorAircraftCarrier) {
	Captain Commander_I{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military_I{ 63, 17, 563 };
	Weapon Arsenal_I[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	Aircraft Plane_I[2] = { {}, {Military_I, 2, Arsenal_I} };
	AircraftCarrier AircraftCarrier_I{ "Admiral Kuznetsov", Commander_I, 256, Military_I, 2, Plane_I, 2, Arsenal_I };
	//------------------------------------------------------------
	ASSERT_EQ("Admiral Kuznetsov", AircraftCarrier_I.getCall());
	//------------------------------------------------------------
	ASSERT_EQ("Nakhimov", AircraftCarrier_I.getCommander().Name);
	ASSERT_EQ("Admiral", AircraftCarrier_I.getCommander().Rank);
	ASSERT_EQ(81, AircraftCarrier_I.getCommander().Experience);
	//------------------------------------------------------------
	ASSERT_EQ(256, AircraftCarrier_I.getCrew());
	//------------------------------------------------------------
	ASSERT_EQ(63, AircraftCarrier_I.GetSpeed());
	ASSERT_EQ(563, AircraftCarrier_I.GetFuelReserve());
	ASSERT_EQ(17, AircraftCarrier_I.GetFuelConsumption());
	//------------------------------------------------------------
	ASSERT_EQ(2, AircraftCarrier_I.AmountWeapon());
	//------------------------------------------------------------
	Weapon* Default_I = AircraftCarrier_I.getWeapon("Name default");
	ASSERT_EQ("Name default", Default_I->GetWeapon());
	ASSERT_EQ("Name ammo default", Default_I->GetMunition());
	ASSERT_EQ(0, Default_I->GetRateFire());
	ASSERT_EQ(0, Default_I->GetQuantityAmmunition());
	ASSERT_EQ(0, Default_I->GetDamage());
	//------------------------------------------------------------
	Weapon* Caliber_I = AircraftCarrier_I.getWeapon("Caliber");
	ASSERT_EQ("Caliber", Caliber_I->GetWeapon());
	ASSERT_EQ("Landmine", Caliber_I->GetMunition());
	ASSERT_EQ(17, Caliber_I->GetRateFire());
	ASSERT_EQ(5, Caliber_I->GetQuantityAmmunition());
	ASSERT_EQ(2017, Caliber_I->GetDamage());
	//------------------------------------------------------------
	ASSERT_EQ(nullptr, AircraftCarrier_I.getWeapon("Search"));
	//------------------------------------------------------------
	ASSERT_EQ(2, AircraftCarrier_I.AmountAircraft());
	//------------------------------------------------------------
	Aircraft* Plane_1 = AircraftCarrier_I.getAir(1);
	ASSERT_EQ(0, Plane_1->GetSpeed());
	ASSERT_EQ(0, Plane_1->GetFuelReserve());
	ASSERT_EQ(0, Plane_1->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(0, Plane_1->getAmountWeapon());
	//------------------------------------------------------------
	Aircraft* Plane_2 = AircraftCarrier_I.getAir(2);
	ASSERT_EQ(63, Plane_2->GetSpeed());
	ASSERT_EQ(563, Plane_2->GetFuelReserve());
	ASSERT_EQ(17, Plane_2->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(2, Plane_2->getAmountWeapon());
	//---------------------------------
	Weapon Arsenal_1 = Plane_2->getWeaponAircraft(1);
	ASSERT_EQ("Name default", Arsenal_1.GetWeapon());
	ASSERT_EQ("Name ammo default", Arsenal_1.GetMunition());
	ASSERT_EQ(0, Arsenal_1.GetRateFire());
	ASSERT_EQ(0, Arsenal_1.GetQuantityAmmunition());
	ASSERT_EQ(0, Arsenal_1.GetDamage());
	//---------------------------------
	Weapon Arsenal_2 = Plane_2->getWeaponAircraft(2);
	ASSERT_EQ("Caliber", Arsenal_2.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2.GetMunition());
	ASSERT_EQ(17, Arsenal_2.GetRateFire());
	ASSERT_EQ(5, Arsenal_2.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2.GetDamage());
	//---------------------------------
	ASSERT_EQ(nullptr, AircraftCarrier_I.getAir(5));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftCarrierConstructor, CopyConstructorAircraftCarrier) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	Aircraft Plane[2] = { {}, {Military, 2, Arsenal} };
	AircraftCarrier AircraftCarrierTmp{ "Admiral Kuznetsov", Commander, 256, Military, 2, Plane, 2, Arsenal };
	AircraftCarrier AircraftCarrier_C(AircraftCarrierTmp);
	//------------------------------------------------------------
	ASSERT_EQ("Admiral Kuznetsov", AircraftCarrier_C.getCall());
	//------------------------------------------------------------
	ASSERT_EQ("Nakhimov", AircraftCarrier_C.getCommander().Name);
	ASSERT_EQ("Admiral", AircraftCarrier_C.getCommander().Rank);
	ASSERT_EQ(81, AircraftCarrier_C.getCommander().Experience);
	//------------------------------------------------------------
	ASSERT_EQ(256, AircraftCarrier_C.getCrew());
	//------------------------------------------------------------
	ASSERT_EQ(63, AircraftCarrier_C.GetSpeed());
	ASSERT_EQ(563, AircraftCarrier_C.GetFuelReserve());
	ASSERT_EQ(17, AircraftCarrier_C.GetFuelConsumption());
	//------------------------------------------------------------
	ASSERT_EQ(2, AircraftCarrier_C.AmountWeapon());
	//------------------------------------------------------------
	Weapon* Default_C = AircraftCarrier_C.getWeapon("Name default");
	ASSERT_EQ("Name default", Default_C->GetWeapon());
	ASSERT_EQ("Name ammo default", Default_C->GetMunition());
	ASSERT_EQ(0, Default_C->GetRateFire());
	ASSERT_EQ(0, Default_C->GetQuantityAmmunition());
	ASSERT_EQ(0, Default_C->GetDamage());
	//------------------------------------------------------------
	Weapon* Caliber_C = AircraftCarrier_C.getWeapon("Caliber");
	ASSERT_EQ("Caliber", Caliber_C->GetWeapon());
	ASSERT_EQ("Landmine", Caliber_C->GetMunition());
	ASSERT_EQ(17, Caliber_C->GetRateFire());
	ASSERT_EQ(5, Caliber_C->GetQuantityAmmunition());
	ASSERT_EQ(2017, Caliber_C->GetDamage());
	//------------------------------------------------------------
	ASSERT_EQ(nullptr, AircraftCarrier_C.getWeapon("Search"));
	//------------------------------------------------------------
	ASSERT_EQ(2, AircraftCarrier_C.AmountAircraft());
	//------------------------------------------------------------
	Aircraft* Plane_1 = AircraftCarrier_C.getAir(1);
	ASSERT_EQ(0, Plane_1->GetSpeed());
	ASSERT_EQ(0, Plane_1->GetFuelReserve());
	ASSERT_EQ(0, Plane_1->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(0, Plane_1->getAmountWeapon());
	//------------------------------------------------------------
	Aircraft* Plane_2 = AircraftCarrier_C.getAir(2);
	ASSERT_EQ(63, Plane_2->GetSpeed());
	ASSERT_EQ(563, Plane_2->GetFuelReserve());
	ASSERT_EQ(17, Plane_2->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(2, Plane_2->getAmountWeapon());
	//---------------------------------
	Weapon Arsenal_1 = Plane_2->getWeaponAircraft(1);
	ASSERT_EQ("Name default", Arsenal_1.GetWeapon());
	ASSERT_EQ("Name ammo default", Arsenal_1.GetMunition());
	ASSERT_EQ(0, Arsenal_1.GetRateFire());
	ASSERT_EQ(0, Arsenal_1.GetQuantityAmmunition());
	ASSERT_EQ(0, Arsenal_1.GetDamage());
	//---------------------------------
	Weapon Arsenal_2 = Plane_2->getWeaponAircraft(2);
	ASSERT_EQ("Caliber", Arsenal_2.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2.GetMunition());
	ASSERT_EQ(17, Arsenal_2.GetRateFire());
	ASSERT_EQ(5, Arsenal_2.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2.GetDamage());
	//---------------------------------
	try {
		Plane_2->getWeaponAircraft(5);
	}
	catch (exception& ex) {
		ASSERT_STREQ("Invalid Number of Weapon\n", ex.what());
	}
	//---------------------------------
	ASSERT_EQ(nullptr, AircraftCarrier_C.getAir(5));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftCarrierMethods, SetterAircraftCarrier) {
	AircraftCarrier AircraftCarrierTmp;
	//------------------------------------------------------------
	AircraftCarrierTmp.setNewCall("Admiral Kuznetsov");
	ASSERT_EQ("Admiral Kuznetsov", AircraftCarrierTmp.getCall());
	//------------------------------------------------------------
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	AircraftCarrierTmp.setNewCommander(Commander);
	ASSERT_EQ("Nakhimov", AircraftCarrierTmp.getCommander().Name);
	ASSERT_EQ("Admiral", AircraftCarrierTmp.getCommander().Rank);
	ASSERT_EQ(81, AircraftCarrierTmp.getCommander().Experience);
	//------------------------------------------------------------
	AircraftCarrierTmp.setNewCrew(256);
	ASSERT_EQ(256, AircraftCarrierTmp.getCrew());
	//------------------------------------------------------------
	AircraftCarrierTmp.SetSpeed(63);
	AircraftCarrierTmp.SetFuelReserve(563);
	AircraftCarrierTmp.SetFuelConsumption(17);
	ASSERT_EQ(63, AircraftCarrierTmp.GetSpeed());
	ASSERT_EQ(563, AircraftCarrierTmp.GetFuelReserve());
	ASSERT_EQ(17, AircraftCarrierTmp.GetFuelConsumption());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftCarrierMethods, TypeShipAircraftCarrier) {
	AircraftCarrier AircraftCarrierTmp;
	ASSERT_EQ(3, AircraftCarrierTmp.TypeShip());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftCarrierMethods, CloneAircraftCarrier) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {"Poplar", "Landmine", 13, 81, 1017}, {"Caliber", "Landmine", 3, 23, 2017} };
	Aircraft Plane[2] = { {}, {Military, 2, Arsenal} };
	AircraftCarrier AircraftCarrierTmp{ "Admiral Kuznetsov", Commander, 256, Military, 2, Plane, 2, Arsenal };
	AircraftCarrier* AircraftCarrier_Clone;
	AircraftCarrier_Clone = AircraftCarrierTmp.clone();
	//------------------------------------------------------------
	ASSERT_EQ("Admiral Kuznetsov", AircraftCarrier_Clone->getCall());
	//------------------------------------------------------------
	ASSERT_EQ("Nakhimov", AircraftCarrier_Clone->getCommander().Name);
	ASSERT_EQ("Admiral", AircraftCarrier_Clone->getCommander().Rank);
	ASSERT_EQ(81, AircraftCarrier_Clone->getCommander().Experience);
	//------------------------------------------------------------
	ASSERT_EQ(256, AircraftCarrier_Clone->getCrew());
	//------------------------------------------------------------
	ASSERT_EQ(63, AircraftCarrier_Clone->GetSpeed());
	ASSERT_EQ(563, AircraftCarrier_Clone->GetFuelReserve());
	ASSERT_EQ(17, AircraftCarrier_Clone->GetFuelConsumption());
	//------------------------------------------------------------
	ASSERT_EQ(2, AircraftCarrier_Clone->AmountWeapon());
	//------------------------------------------------------------
	Weapon* Default_C = AircraftCarrier_Clone->getWeapon("Poplar");
	ASSERT_EQ("Poplar", Default_C->GetWeapon());
	ASSERT_EQ("Landmine", Default_C->GetMunition());
	ASSERT_EQ(13, Default_C->GetRateFire());
	ASSERT_EQ(81, Default_C->GetQuantityAmmunition());
	ASSERT_EQ(1017, Default_C->GetDamage());
	//------------------------------------------------------------
	Weapon* Caliber_C = AircraftCarrier_Clone->getWeapon("Caliber");
	ASSERT_EQ("Caliber", Caliber_C->GetWeapon());
	ASSERT_EQ("Landmine", Caliber_C->GetMunition());
	ASSERT_EQ(3, Caliber_C->GetRateFire());
	ASSERT_EQ(23, Caliber_C->GetQuantityAmmunition());
	ASSERT_EQ(2017, Caliber_C->GetDamage());
	//------------------------------------------------------------
	ASSERT_EQ(nullptr, AircraftCarrier_Clone->getWeapon("Search"));
	//------------------------------------------------------------
	ASSERT_EQ(2, AircraftCarrier_Clone->AmountAircraft());
	//------------------------------------------------------------
	Aircraft* Plane_1 = AircraftCarrier_Clone->getAir(1);
	ASSERT_EQ(0, Plane_1->GetSpeed());
	ASSERT_EQ(0, Plane_1->GetFuelReserve());
	ASSERT_EQ(0, Plane_1->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(0, Plane_1->getAmountWeapon());
	//------------------------------------------------------------
	Aircraft* Plane_2 = AircraftCarrier_Clone->getAir(2);
	ASSERT_EQ(63, Plane_2->GetSpeed());
	ASSERT_EQ(563, Plane_2->GetFuelReserve());
	ASSERT_EQ(17, Plane_2->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(2, Plane_2->getAmountWeapon());
	//---------------------------------
	Weapon Arsenal_1 = Plane_2->getWeaponAircraft(1);
	ASSERT_EQ("Poplar", Arsenal_1.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_1.GetMunition());
	ASSERT_EQ(13, Arsenal_1.GetRateFire());
	ASSERT_EQ(81, Arsenal_1.GetQuantityAmmunition());
	ASSERT_EQ(1017, Arsenal_1.GetDamage());
	//---------------------------------
	Weapon Arsenal_2 = Plane_2->getWeaponAircraft(2);
	ASSERT_EQ("Caliber", Arsenal_2.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2.GetMunition());
	ASSERT_EQ(3, Arsenal_2.GetRateFire());
	ASSERT_EQ(23, Arsenal_2.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2.GetDamage());
	//---------------------------------
	try {
		Plane_2->getWeaponAircraft(5);
	}
	catch (exception& ex) {
		ASSERT_STREQ("Invalid Number of Weapon\n", ex.what());
	}
	//---------------------------------
	ASSERT_EQ(nullptr, AircraftCarrier_Clone->getAir(5));
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftCarrierMethods, CalculationParametersAircraftCarrier) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {"Poplar", "Landmine", 13, 81, 1017}, {"Caliber", "Landmine", 3, 23, 2017} };
	Aircraft Plane[2] = { {}, {Military, 2, Arsenal} };
	AircraftCarrier AircraftCarrierTmp{ "Admiral Kuznetsov", Commander, 256, Military, 2, Plane, 2, Arsenal };
	//------------------------------------------------------------
	ASSERT_NEAR(2086.4, AircraftCarrierTmp.maxRangeTtransition(), 0.1);
	//------------------------------------------------------------
	ASSERT_NEAR(6.2, AircraftCarrierTmp.TimeFireAllWeapons(), 0.1);
	//------------------------------------------------------------
	ASSERT_EQ(3034, AircraftCarrierTmp.DamageAllPlanes());
	//------------------------------------------------------------
	ASSERT_EQ(3034, AircraftCarrierTmp.DamageAllWeapons());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftCarrierMethods, AircraftAircraftCarrier) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {}, {"Caliber", "Landmine", 17, 5, 2017} };
	Aircraft Plane[1] = { {Military, 2, Arsenal} };
	AircraftCarrier AircraftCarrierTmp{ "Admiral Kuznetsov", Commander, 256, Military, 0, nullptr, 2, Arsenal };
	//------------------------------------------------------------
	AircraftCarrierTmp.AddAircraft(Plane[0]);
	ASSERT_EQ(1, AircraftCarrierTmp.AmountAircraft());
	//------------------------------------------------------------
	Aircraft* Plane_1 = AircraftCarrierTmp.getAir(1);
	ASSERT_EQ(63, Plane_1->GetSpeed());
	ASSERT_EQ(563, Plane_1->GetFuelReserve());
	ASSERT_EQ(17, Plane_1->GetFuelConsumption());
	//---------------------------------
	ASSERT_EQ(2, Plane_1->getAmountWeapon());
	//---------------------------------
	Weapon Arsenal_1 = Plane_1->getWeaponAircraft(1);
	ASSERT_EQ("Name default", Arsenal_1.GetWeapon());
	ASSERT_EQ("Name ammo default", Arsenal_1.GetMunition());
	ASSERT_EQ(0, Arsenal_1.GetRateFire());
	ASSERT_EQ(0, Arsenal_1.GetQuantityAmmunition());
	ASSERT_EQ(0, Arsenal_1.GetDamage());
	//---------------------------------
	Weapon Arsenal_2 = Plane_1->getWeaponAircraft(2);
	ASSERT_EQ("Caliber", Arsenal_2.GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2.GetMunition());
	ASSERT_EQ(17, Arsenal_2.GetRateFire());
	ASSERT_EQ(5, Arsenal_2.GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2.GetDamage());
}

//------------------------------------------------------------------------------------------------------------------------

TEST(ClassAircraftCarrierMethods, WeaponAircraftCarrier) {
	Captain Commander{ "Nakhimov", "Admiral", 81 };
	MilitaryCharacteristics Military{ 63, 17, 563 };
	Weapon Arsenal[2] = { {"Poplar", "Landmine", 13, 81, 1017}, {"Caliber", "Landmine", 3, 23, 2017} };
	Aircraft Plane[2] = { {}, {Military, 2, Arsenal} };
	AircraftCarrier AircraftCarrierTmp{ "Admiral Kuznetsov", Commander, 256, Military, 2, Plane, 2, Arsenal };
	//------------------------------------------------------------
	ASSERT_EQ(2, AircraftCarrierTmp.AmountWeapon());
	//------------------------------------------------------------
	Weapon* Arsenal_1 = AircraftCarrierTmp.getWeapon("Poplar");
	ASSERT_EQ("Poplar", Arsenal_1->GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_1->GetMunition());
	ASSERT_EQ(13, Arsenal_1->GetRateFire());
	ASSERT_EQ(81, Arsenal_1->GetQuantityAmmunition());
	ASSERT_EQ(1017, Arsenal_1->GetDamage());
	//------------------------------------------------------------
	Weapon* Arsenal_2 = AircraftCarrierTmp.getWeapon("Caliber");
	ASSERT_EQ("Caliber", Arsenal_2->GetWeapon());
	ASSERT_EQ("Landmine", Arsenal_2->GetMunition());
	ASSERT_EQ(3, Arsenal_2->GetRateFire());
	ASSERT_EQ(23, Arsenal_2->GetQuantityAmmunition());
	ASSERT_EQ(2017, Arsenal_2->GetDamage());
	//------------------------------------------------------------
	ASSERT_EQ(nullptr, AircraftCarrierTmp.getWeapon("Default"));
	//------------------------------------------------------------
	Weapon Arsenal_3{ "Ballistic", "Water-Land", 7, 69, 593 };
	AircraftCarrierTmp.WeaponModification("Caliber", Arsenal_3);
	Weapon* Check = AircraftCarrierTmp.getWeapon("Ballistic");
	ASSERT_EQ("Ballistic", Check->GetWeapon());
	ASSERT_EQ("Water-Land", Check->GetMunition());
	ASSERT_EQ(7, Check->GetRateFire());
	ASSERT_EQ(69, Check->GetQuantityAmmunition());
	ASSERT_EQ(593, Check->GetDamage());
	//------------------------------------------------------------
	AircraftCarrierTmp.WeaponModification("Caliber", Arsenal_3);
	ASSERT_EQ(nullptr, AircraftCarrierTmp.getWeapon("Caliber"));
}