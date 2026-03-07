modded class PluginRepairing
{
	// Determines if an item can be repaired by the provided repair kit. 
	// Extends base logic to allow Admin repair kits to function on any non-ruined, non-pristine item regardless of standard item compatibility.
	override bool CanRepair(ItemBase repair_kit, Object item, string damage_zone = "")
	{
		// Logic check: Admin kits bypass standard restrictions but require item to not be ruined or already perfect.
		if (repair_kit && (repair_kit.IsKindOf("Admin_ItemRepairKit") || repair_kit.IsKindOf("Admin_WeaponRepairKit")))
		{
			int state = item.GetHealthLevel(damage_zone);
			if (state == GameConstants.STATE_RUINED || state == GameConstants.STATE_PRISTINE)
				return false;

			return true;
		}

		return super.CanRepair(repair_kit, item, damage_zone);
	}

	// Executes the repair logic to restore item health. If an Admin kit is used, this restores the item to its maximum possible health in a single action.
	override bool Repair(PlayerBase player, ItemBase repair_kit, Object item, float specialty_weight, string damage_zone = "", bool use_kit_qty = true)
	{
		if (repair_kit && (repair_kit.IsKindOf("Admin_ItemRepairKit") || repair_kit.IsKindOf("Admin_WeaponRepairKit")))
		{
			int state = item.GetHealthLevel(damage_zone);
			if (state != GameConstants.STATE_RUINED && state != GameConstants.STATE_PRISTINE)
			{
				ItemBase item_base = ItemBase.Cast(item);
				if (item_base)
				{
					// Restores target to 100% health.
					item_base.SetHealth("", "", item_base.GetMaxHealth("", ""));
				}
			}
			return true;
		}

		return super.Repair(player, repair_kit, item, specialty_weight, damage_zone, use_kit_qty);
	}

	// Validates compatibility between a kit type and a repairable item type.
	override bool IsRepairValid(int repair_kit_type, int repairable_with_type)
	{
		// 998 and 999 represent custom Admin kit types defined in the mod's configs.
		if (repair_kit_type == 998 || repair_kit_type == 999)
			return true;

		return super.IsRepairValid(repair_kit_type, repairable_with_type);
	}
};
