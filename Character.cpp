#include "Character.h"
#include <iostream>
#include <istream>
#include <fstream>
#include <ostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <time.h>
//#include "Item.h"
//#include "ItemContainer.h"
#include <vector>
using namespace std;

//default construtor
Character::Character(){
}

//constructor thats takes 2 attributes:  name and level
Character::Character(string name, int level){
    strength=0;
    dexterity=0;
    constitution=0;
    intelligence=0;
    wisdom=0;
    charisma=0;
    hitPoints=0;
    level=1;
    meleeBonus=0;
    rangedBonus=0;
    damageBonus=0;
    
}

Character::Character(int level){
    strength=0;
    dexterity=0;
    constitution=0;
    intelligence=0;
    wisdom=0;
    charisma=0;
    hitPoints=0;
    level=1;
    meleeBonus=0;
    rangedBonus=0;
    damageBonus=0;
    
    setLevel(level);
    randomAbilityScores();
    chooseAbilityScores();
    setArmorClass(); 
}

//setters for character's attributes
void Character::setName(string name){
    cout << "Enter a name for your character: " << name << "." << endl;
    charName = name;
}

void Character::setLevel(int level){
    cout << "Enter level of character: " << level << "." << endl;
    this->level = level;
}

void Character::setType(std::string type){
    charType = type;
}

void Character::assignScores(){
    if (rollsDice.size() > 0 && rollsDice.size()<=6){
        setStrength(rollsDice.at(0));
        setDexterity(rollsDice.at(1));
        setConstitution(rollsDice.at(2));
        setIntelligence(rollsDice.at(3));
        setWisdom(rollsDice.at(4));
        setCharisma(rollsDice.at(5));
    }
}

// randomly generate 6 ability scores
void Character::randomAbilityScores(){
    int rollCounter = 0; 
    srand(time(NULL));    
    while (rollCounter < 6){ 
        int sum = 0, min = 7;
        for (int i = 0; i < 4; i++) { //
            int num = rand() % 6 + 1; 
            if (num < min) min = num; 
            sum += num; 
        }
        sum -= min; 
        rollsDice.push_back(sum);
        rollCounter++;
    }
}


//return the highest ability scores
int Character::getHighestAbilityScore(){
    int high = 0;
    vector<int>::iterator it, highScore;
    highScore = max_element(rollsDice.begin(),rollsDice.end());
    high = *highScore;
    rollsDice.erase(highScore);
    return high;
}

//setters for abilities scores
void Character::setStrength(int str){
    strength = str;
}
void Character::setDexterity(int dex){
    dexterity = dex;
}
void Character::setConstitution(int con){
    constitution = con;
}
void Character::setIntelligence(int intel){
    intelligence = intel;
}
void Character::setWisdom(int wis){
    wisdom = wis;
}
void Character::setCharisma(int cha){
    charisma = cha;
}

//setters for abilities scores modifiers
void Character::setStrengthMod(int str){
    strengthMod = getAbilityModifier((double)str);
}
void Character::setDexterityMod(int dex){
    dexterityMod = getAbilityModifier((double)dex);
}
void Character::setConstitutionMod(int con){
    constitutionMod = getAbilityModifier((double)con);
}
void Character::setIntelligenceMod(int intel){
    intelligenceMod = getAbilityModifier((double)intel);
}
void Character::setWisdomMod(int wis){
    wisdomMod = getAbilityModifier((double)wis);
}
void Character::setCharismaMod(int cha){
    charismaMod = getAbilityModifier((double)cha);
}


//useful function
void Character::setArmorClass(){ 
    armorClass = 10 + getAbilityModifier(getDexterity()); 
}


//getters for character's attributes
string Character::getName() {
    return charName;
}
int Character::getLevel() {
    return level;
}

//getters functions for abilities scores
int Character::getStrength() {
    return strength;
}
int Character::getDexterity() {
    return dexterity;
}
int Character::getConstitution() {
    return constitution;
}
int Character::getIntelligence() {
    return intelligence;
}
int Character::getWisdom() {
    return wisdom;
}
int Character::getCharisma() {
    return charisma;
}

//getters functions for abilities scores modifiers
int Character::getStrengthMod(){
    return strengthMod;
}
int Character::getDexterityMod(){
    return dexterityMod;
}
int Character::getConstitutionMod(){
    return constitutionMod;
}
int Character::getIntelligenceMod(){
    return intelligenceMod;
}
int Character::getWisdomMod(){
    return wisdomMod;
}
int Character::getCharismaMod(){
    return charismaMod;
}


//function to find the ability modifier of ability score
int Character::getAbilityModifier(double score){
    int mod;
    score = score-10.0;
    mod = (int)floor(score/2.0); 
    return mod;
}

//getters for hit points
int Character::getHP() {
    return hitPoints;
}
int Character::getArmorClass() {
    return armorClass;
}


int Character::rollD20() {
    srand(time(NULL));
    return (rand() % 20+1);
}

int Character::rollD10(int numb) {
    return (rand() %numb+1);
}


vector<int> Character::getRollsDice(){
	return rollsDice;
}

bool validateRoll(int rollCount, vector<int> rolls){
    if ((rollCount>0 || rollCount<7) & (rollCount<=rolls.size())){
        return true;
    }
    else {
        return false;
    }
}

//As a character goes up levels, the following are increasing: (1) his hit points go
//up by (1d10+constitution modifier),
void Character::levelUp() {
    setLevel(getLevel() + 1);
    int hp = getHP() + rollD10(10) + (getConstitutionMod()); //hitpoints
    setHP(hp);
   

    //Armor Class
    armorClass = 10 + armorBonus + shieldBonus;

    //Attack Bonus
    
    baseBonus = 1;

    meleeBonus = baseBonus + strengthMod;

    rangedBonus = baseBonus + dexterityMod;
    
    cout << "LEVEL UP TO " << level << endl; 
    
}
    
    
int Character::attack1() {
    return rollD20() + getBaseAttackBonus1() + getStrengthMod(); 
}
int Character::attack2() {
    return rollD20() + getBaseAttackBonus2() + getStrengthMod();
}
int Character::attack3() {
    return rollD20() + getBaseAttackBonus3() + getStrengthMod();
}
int Character::attack4() {
    return rollD20() + getBaseAttackBonus4() + getStrengthMod();
}


int Character::getBaseAttackBonus1() {
    return baseAttackBonus1;
}
int Character::getBaseAttackBonus2() {
    return baseAttackBonus2;
}
int Character::getBaseAttackBonus3() {
    return baseAttackBonus3;
}
int Character::getBaseAttackBonus4() {
    return baseAttackBonus4;
}


void Character:: save(Character& ch){
    std::ofstream file("save.txt");
    string str = " ";
    str += ("Name= " + ch.getName() + '\n');
    str += ("Level= " + ch.getLevel() + '\n');
    str += ("Strength= " + ch.getStrength() + '\n');
    str += ("Dexterity= " + ch.getDexterity() + '\n');
    str += ("Constitution= " + ch.getConstitution() + '\n');
    str += ("Intelligence= " + ch.getIntelligence() + '\n');
    str += ("Wisdom= " + ch.getWisdom() + '\n');
    str += ("Charisma= " + ch.getCharisma() + '\n');
 
}

void Character:: load(){
    ifstream file("save.txt");
    string in = " ";
    string str = " ";
    if(file.is_open()){
        while(!file.eof()){
            getline(file, str);
            in += str;
            in += "\n";
        }
    }
}

void Character::equipItems(int slot){
   
}

void Character:: showInfo(){
    cout << "Class: Fighter" << endl;
    cout << endl;
	
    cout << "Type: " << charType << endl;
    cout << "Level: " << level << endl;
}
