#include "NimbleBuilder.h"
#include "CharacterBuilder.h"
#include "Character.h"

//Distributes points according to Nimble preferences
void NimbleBuilder::createAttributes() {
	character->setType("Nimble");
	character->setDexterity(character->rollsDice[0]);
	character->setConstitution(character->rollsDice[1]);
	character->setStrength(character->rollsDice[2]);
	character->setIntelligence(character->rollsDice[3]);
	character->setWisdom(character->rollsDice[4]);
	character->setCharisma(character->rollsDice[5]);

}