class CfgPatches
{
	class Admin_RepairKit
	{
		units[] = {"Admin_WeaponRepairKit","Admin_ItemRepairKit"};
		weapons[] = {};
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
		name = "Admin Repair Kit";
		dependencies[] = {"World"};

		class defs
		{
			class worldScriptModule
			{
				value = "";
				files[] = {"Admin_RepairKit/scripts/4_World"};
			};
		};
	};
};

class CfgVehicles
{
	class Inventory_Base;

	// Keep two kits: vanilla repair recipes match the kit's parent class, not only repairKitType.
	// Weapon + Ammo repair
	class WeaponCleaningKit: Inventory_Base{};
	class Admin_WeaponRepairKit: WeaponCleaningKit
	{
		scope = 2;
		displayName = "$STR_ARK_ADMIN_WEAPON_REPAIR_KIT";
		descriptionShort = "$STR_ARK_ADMIN_WEAPON_REPAIR_KIT_DESC";
		model = "\dz\gear\tools\cleaning_kit_wood.p3d";
		itemSize[] = {2,3};
		repairKitType = 999;
	};

	// Clothing + Gear repair
	class ElectronicRepairKit: Inventory_Base{};
	class Admin_ItemRepairKit: ElectronicRepairKit
	{
		scope = 2;
		displayName = "$STR_ARK_ADMIN_ITEM_REPAIR_KIT";
		descriptionShort = "$STR_ARK_ADMIN_ITEM_REPAIR_KIT_DESC";
		model = "\dz\gear\tools\electronicCase.p3d";
		itemSize[] = {1,2};
		repairKitType = 998;
	};
};
