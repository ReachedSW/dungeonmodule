#ifdef NEW_DUNGEON_STAGE_SYSTEM
struct FSetDungeonStage
{
	FSetDungeonStage(BYTE bStage) : m_bStage(bStage) {}

	void operator()(LPENTITY ent)
	{
		if (ent->IsType(ENTITY_CHARACTER))
		{
			LPCHARACTER ch = (LPCHARACTER)ent;
			if (ch)
				ch->SetDungeonStage(m_bStage);
		}
	}

	BYTE m_bStage;
};

void CDungeon::SetDungeonStage(BYTE bStage)
{
	LPSECTREE_MAP pMap = SECTREE_MANAGER::instance().GetMap(m_lMapIndex);

	if (!pMap)
	{
		sys_err("cannot find map by index %d", m_lMapIndex);
		return;
	}

	FSetDungeonStage f(bStage);
	pMap->for_each(f);
}
#endif