#ifndef FIGHTER_H
#define FIGHTER_H
#include "Character.h"



class Fighter: public Character
{
	public:		
            Fighter();
            Fighter(string name);
           
            void stats(int, int, int, int, int, int);
            void levelUp();
	
            int getAttackBonus1();
            int getAttackBonus2();
            int getAttackBonus3();
            int getAttackBonus4();
            
};

#endif /* FIGHTER_H */

