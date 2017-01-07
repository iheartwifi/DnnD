#ifndef CHARACTER_H
#define CHARACTER_H
#include <string>
#include <vector>

using namespace std;

class Character {
private:
    Character* ch;
    
protected:
        string charName;
        string charType;

        int level;
        int hitPoints;
        int armorClass;


        //ability scores
        int strength;
        int dexterity;
        int constitution;
        int intelligence;
        int wisdom;
        int charisma;

        //ability modifiers
        int strengthMod;
        int dexterityMod;
        int constitutionMod;
        int intelligenceMod;
        int wisdomMod;
        int charismaMod;

        //others
        int baseAttackBonus1;
        int baseAttackBonus2;
        int baseAttackBonus3;
        int baseAttackBonus4;
        
        int baseBonus;
        int meleeBonus;
        int rangedBonus;
        int damageBonus;
        int armorBonus;
        int shieldBonus;

    public:
        Character();
        Character(int level);
        Character(string name, int level);
  
      
         //setters character's attributes
        void setName(string name);
        void setLevel(int level);
        void setType(string charType); // fighter type
        
        //setter for abilities scores
        void setArmorClass();
        void setStrength(int str);
        void setDexterity(int dex);
        void setConstitution(int con);
        void setIntelligence(int intel);
        void setWisdom(int wis);
        void setCharisma(int cha);
        
        //setters for abilities scores modifiers
        void setStrengthMod(int str);
        void setDexterityMod(int dex);
        void setConstitutionMod(int con);
        void setIntelligenceMod(int intel);
        void setWisdomMod(int wis);
        void setCharismaMod(int cha);
           
        //getters character's attributes 
        string getName();
        int getLevel();
        int getHP();
        virtual int getArmorClass();

        //getters for abilities scores
        int getStrength();
        int getDexterity();
        int getConstitution();
        int getIntelligence();
        int getWisdom();
        int getCharisma();

        //getters for abilities scores modifiers
        int getStrengthMod();
        int getDexterityMod();
        int getConstitutionMod();
        int getIntelligenceMod();
        int getWisdomMod();
        int getCharismaMod();
         
        //Useful methods
        void assignScores();
        void randomAbilityScores();
        void chooseAbilityScores();
        virtual void setHP(int hp);
        void levelUp();
        
        int getHighestAbilityScore();
        int getAbilityModifier(double score);
        int rollD20();
        int rollD10(int num);
        
        //Dice rolls for ability
        vector<int> rollsDice; 
        vector<int> getRollsDice();
       
        //setters and getters functions for attack bonus
        virtual int getBaseAttackBonus1();
        virtual int getBaseAttackBonus2();
        virtual int getBaseAttackBonus3();
        virtual int getBaseAttackBonus4();
                
        virtual int attack1();
        virtual int attack2();
        virtual int attack3();
        virtual int attack4();
      
        void save(Character& ch);
        void load();
        
        int equipArmor(int armor);
	int equipShield(int shield);
	int equipWeapon(int weapon);
	int equipBoots(int boots);
	int equipRing(int ring);
	int equipHelmet(int helmet);

	void getArmor();
	void getShield();
	void getWeapon();
	void getBoots();
	void getRing();
	void getHelmet();
        
        void equipItems(int slot);
        void showInfo();
        
};


#endif /* CHARACTER_H */

