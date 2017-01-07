#include "Character.h"
#include "Character.cpp"
#include <iostream>
#include "Generator.h"
#include "BullyBuilder.h"
#include "NimbleBuilder.h"
#include "TankBuilder.h"
#include <list>

int main(){
    string charType, fighterType;
    int level;
    Generator gen;
    CharacterBuilder* bullyBuilder = new BullyBuilder();
    CharacterBuilder* nimbleBuilder = new NimbleBuilder();
    CharacterBuilder* tankBuilder = new TankBuilder();
    
    cout << "What type of fighter your caracter will be:? 1-Bully, 2-Nimble, 3-Tank ";
    cin >> fighterType;

    cout << "Please enter level for your character ";
    cin >> level;
 
    if(fighterType=="bully"){
        gen.setCharacterBuilder(bullyBuilder);
    } else if(fighterType=="nimble"){
        gen.setCharacterBuilder(nimbleBuilder);
    }else if(fighterType=="tank") {
        gen.setCharacterBuilder(tankBuilder);
    }else {
        cout << "invalid input for fighter type, plz try again";
    }
    gen.createCharacter(charType, level);
 
    Character* character = gen.getCharacter();
    character->showInfo();
    
    
}
