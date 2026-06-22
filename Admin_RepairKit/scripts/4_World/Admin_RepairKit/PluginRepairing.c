modded class PluginRepairing
{
	override bool CanRepair(ItemBase repair_kit, Object item, string damage_zone = "")
	{
		if (!ARK_IsAdminRepairKit(repair_kit))
		{
			return super.CanRepair(repair_kit, item, damage_zone);
		}

		if (!item)
		{
			return false;
		}

		int state = item.GetHealthLevel(damage_zone);
		return state != GameConstants.STATE_RUINED && state != GameConstants.STATE_PRISTINE;
	}

	override bool Repair(PlayerBase player, ItemBase repair_kit, Object item, float specialty_weight, string damage_zone = "", bool use_kit_qty = true)
	{
		if (!ARK_IsAdminRepairKit(repair_kit))
		{
			return super.Repair(player, repair_kit, item, specialty_weight, damage_zone, use_kit_qty);
		}

		if (!item || !CanRepair(repair_kit, item, damage_zone))
		{
			return false;
		}

		item.SetHealth(damage_zone, "Health", item.GetMaxHealth(damage_zone, "Health"));
		return true;
	}

	protected bool ARK_IsAdminRepairKit(ItemBase repair_kit)
	{
		return repair_kit && (repair_kit.IsKindOf("Admin_ItemRepairKit") || repair_kit.IsKindOf("Admin_WeaponRepairKit"));
	}
}
