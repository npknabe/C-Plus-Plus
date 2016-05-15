/*
 * FightMath.h
 *
 *  Created on: Oct 16, 2015
 *      Author: Nick Knabe
 */

#ifndef FIGHTMATH_H_
#define FIGHTMATH_H_

//class
class Orc
{
	public:

	//constructors (member functions)
	Orc();

	// Member functions
	void strikeOrc(int amt);
	bool orcDie();///if orcHP <= 0 then this is true boolean statement is true/false
	double getOrcHP();///this will be

	private:

	//Data Members

	double orcHP;


};

class Human
{
	public :

	Human();

	void strikeHuman(int amt);
	bool humanDie();
	double getHumanHP;

	private:


	double humanHP;


};

class Troll
{
	public:

	Troll();

	void strikeTroll(int amt);
	bool trollDie();
	double getTrollHP;

	private:


	double trollHP;


};



#endif /* FIGHTMATH_H_ */
