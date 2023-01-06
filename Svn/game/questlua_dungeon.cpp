#ifdef NEW_DUNGEON_STAGE_SYSTEM
	ALUA(dungeon_set_stage)
	{
		if (!lua_isnumber(L, 1))
			return 0;

		CQuestManager& q = CQuestManager::instance();
		LPDUNGEON pDungeon = q.GetCurrentDungeon();

		if (pDungeon)
			pDungeon->SetDungeonStage((BYTE)lua_tonumber(L, 1));

		return 0;
	}
#endif


#ifdef NEW_DUNGEON_STAGE_SYSTEM
		{"set_dungeon_state", dungeon_set_stage},
#endif

