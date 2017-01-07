#include "CharacterBuilder.h"
#include "Generator.h"
#include "Character.h"

void Generator::setCharacterBuilder(CharacterBuilder* charBuild) {
    characterBuilder = charBuild;
}

//Returns the character created by the CharacterBuilder
Character* Generator::getCharacter() {
    return characterBuilder->getCharacter();
}
 
//Tells the CharacterBuilder to create a new character
void Generator::createCharacter(string charType, int level) {
    characterBuilder->createNewCharacter(charType, level);
    characterBuilder->buildAttributes();
}