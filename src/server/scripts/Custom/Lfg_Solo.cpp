/*
** Created by Relyks
*/

#include "ScriptMgr.h"
#include "Player.h"
#include "Configuration/Config.h"
#include "World.h"
#include "LFGMgr.h"
#include "Chat.h"
#include "Opcodes.h"

class lfg_solo_announce : public PlayerScript
{
public:
	lfg_solo_announce() : PlayerScript("lfg_solo_announce") {}

	void OnLogin(Player* player, bool /*firstLogin*/) override
	{
		// Annuonce Module
		if (sConfigMgr->GetBoolDefault("SoloLFG.Announce", true))
		{
			ChatHandler(player->GetSession()).SendSysMessage("This server is running a |cff4CFF00Solo Dungeon Finder|r script.");
		}
	}
};

class lfg_solo : public PlayerScript
{
public:
	lfg_solo() : PlayerScript("lfg_solo") { }

	void OnLogin(Player* /*player*/, bool /*firstLogin*/) override
	{
		if (sConfigMgr->GetIntDefault("SoloLFG.Enable", true))
		{
			if (!sLFGMgr->isSoloLFG())
			{
				sLFGMgr->ToggleSoloLFG();
			}
		}
	}
};

void AddLfgSoloScripts()
{
	new lfg_solo_announce();
	new lfg_solo();
}
