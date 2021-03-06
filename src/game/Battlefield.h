/*
 * Copyright (C) 2010-2012 Strawberry-Pr0jcts <http://strawberry-pr0jcts.com/>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 */

#ifndef __BATTLEFIELD_H
#define __BATTLEFIELD_H

#include "BattlefieldMgr.h"
#include "MapManager.h"
#include "Group.h"

enum Battlefields
{
    BATTLEFIELD_WG = 1,
    BATTLEFIELD_TB = 21
};

enum Teams
{
    TEAM_ALLIANCE,
    TEAM_HORDE
};

typedef std::list<Player *> PlayerList;

class Map;

class Battlefield
{
    friend class BattlefieldMgr;

    public:

        Battlefield(uint8 BattleId,uint32 zoneId, uint32 WarTime,uint32 NoWarTime);
        ~Battlefield();
        
        virtual void Update(uint32 uiDiff);
        virtual void BattleStart();
        virtual void BattleEnd();

        void PlayerJoin(Player* player);
        void PlayerLeave(Player* player);
        bool IsBattleInProgress() const { return m_battleInProgress; } ;

    protected:
        uint8           m_defenderTeam;
        uint8           m_attackerTeam;
        uint8           m_controlledByTeam;
        uint8           m_battleId;
        uint32          m_nextBattleTimer;
        uint32          m_battleDurationTimer;
        uint32          m_zoneId;
        bool            m_battleInProgress;
        PlayerList      m_queuedPlayers[2];
        Group*          m_raidGroup;
        Map*            m_map;

    private:
        void InvitePlayersInZone();
};

#endif