#include "Character.h"
#include "CharacterBuilder.h"

Character* CharacterBuilder::getCharacter() {
        return character;
}

//Creates a new character
void CharacterBuilder::createNewCharacter(string charType, int level) {
        character = new Character(charType, level);
}