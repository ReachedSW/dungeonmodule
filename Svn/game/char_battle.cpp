bool CHARACTER::Damage(LPCHARACTER pAttacker, int dam, EDamageType type) // returns true if dead
{
	if (!pAttacker)
		return false;

#ifdef NEW_DUNGEON_STAGE_SYSTEM
	if (pAttacker)
	{
		if (pAttacker->GetDungeonState() == EDungeonStages::DUNGEON_STAGE_METINSTONE && IsStone() && (GetHP() - dam <= GetMaxHP()/2))
		{
			SendDamagePacket(pAttacker, 0, DAMAGE_BLOCK);
			return false;
		}
	}
#endif