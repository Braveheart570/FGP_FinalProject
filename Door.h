#pragma once
#include "Interaction.h"
#include "Room.h"

class Door : public Interaction {
public:
	Door(string name = "door", Room* targetRoom);

	Room* getTargetRoom() const;

protected:
	Room* m_TargetRoom;
};