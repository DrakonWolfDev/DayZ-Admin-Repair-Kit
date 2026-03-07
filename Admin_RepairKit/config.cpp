#define _ARMA_

class CfgPatches
{
	class Admin_RepairKit
	{
		requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Gear_Tools"};
	};
};

class CfgMods
{
	class Admin_RepairKit
	{
		type = "mod";
		author = "DrakonWolf";
		name = "Admin_RepairKit";
		dependencies[] = {"Game", "World", "Mission"};

		class defs
		{
			class gameScriptModule
			{
				value = "";
				files[] = {"Admin_RepairKit/scripts/3_Game"};
			};
			class worldScriptModule
			{
				value = "";
				files[] = {"Admin_RepairKit/scripts/4_World"};
			};
			class missionScriptModule
			{
				value = "";
				files[] = {"Admin_RepairKit/scripts/5_Mission"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;

	// Weapon + Ammo repair
	class WeaponCleaningKit: Inventory_Base{};
	class Admin_WeaponRepairKit: WeaponCleaningKit
	{
		scope = 2;
		displayName = "Admin Weapon Repair Kit";
		descriptionShort = "An admin kit that repairs any weapon or ammo to pristine condition.";
		model = "\dz\gear\tools\cleaning_kit_wood.p3d";
		itemSize[] = {2,3};
		repairKitType = 999;
	};

	// Clothing + Gear repair
	class ElectronicRepairKit: Inventory_Base{};
	class Admin_ItemRepairKit: ElectronicRepairKit
	{
		scope = 2;
		displayName = "Admin Item Repair Kit";
		descriptionShort = "An admin kit that repairs any clothing or gear to pristine condition.";
		model = "\dz\gear\tools\electronicCase.p3d";
		itemSize[] = {1,2};
		repairKitType = 998;
	};
};
