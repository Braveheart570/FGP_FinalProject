#include "Door.h"

Room* Door::getTargetRoom() const {
	return m_TargetRoom;
}

Door::Door(string name = "door", Room* targetRoom) : Interaction(name,"The door opened") {
	m_TargetRoom = targetRoom;
}