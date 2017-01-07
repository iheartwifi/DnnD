#ifndef GENERATOR_H
#define GENERATOR_H
#include "CharacterBuilder.h"
#include "Character.h"

class Generator {
public:
    void setCharacterBuilder(CharacterBuilder* characterBuilder);
    Character* getCharacter();
    void createCharacter(string charType, int level);

private:
    CharacterBuilder* characterBuilder;
};

#endif /* GENERATOR_H */

