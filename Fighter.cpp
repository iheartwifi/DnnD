
#include "Fighter.h"
#include "Character.h"

Fighter::Fighter(){}



void Fighter::levelUp(){
	this -> level++;
        int hp = getHP() + rollD10(10) + (getConstitutionMod());
        setHP(hp);
}


int Fighter::getAttackBonus1(){
        if(level <=20) return level;
        else
            return 20;

}

int Fighter::getAttackBonus2(){
    
        if (getAttackBonus1() <=5) return 0;
        else 
            return getAttackBonus1()-5;
        
}

int Fighter::getAttackBonus3(){
	
	if (getAttackBonus2() <=5) return 0;
        else 
            return getAttackBonus2()-5;
}

int Fighter::getAttackBonus4(){
	if (getAttackBonus2() <=5) return 0;
        else 
            return getAttackBonus2()-5;
}