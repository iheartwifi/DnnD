#ifndef CHARACTERBUILDER_H
#define CHARACTERBUILDER_H

#include <string>
#include "Character.h"

class CharacterBuilder {
   
public:
    Character* getCharacter();
    
    void createNewCharacter(string charType, int level);
    void buildAttributes();
 
protected:
    Character* character;
    
};

#endif /* CHARACTERBUILDER_H */

