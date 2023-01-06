//Search
	BYTE			GetChatCounter() const;


//Add Under
#ifdef NEW_DUNGEON_STAGE_SYSTEM
	BYTE 			GetDungeonStage() const { return m_bDungeonStage; }
	void 			SetDungeonStage(BYTE bStage) { m_bDungeonStage = bStage; }
#endif


//Search
	BYTE			m_bCharType;


//Add Under
#ifdef NEW_DUNGEON_STAGE_SYSTEM
	BYTE			m_bDungeonStage; // enum EDungeonStages
#endif