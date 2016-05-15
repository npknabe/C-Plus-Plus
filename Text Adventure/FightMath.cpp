#include "FightMath.h"



Orc::Orc():orcHP(12)
{}

void Orc::strikeOrc(int amt)
{
	if(amt >= orcHP)////this needs to say that if you strike the orc an amt (set by weapon) >= orcHP
	{
		orcDie = true;
	}
	else
	{
		orcDie = false;
	}


}


/*
void Human::strikeHuman(int amt)
{
	if(amt >= 0)
	{
		humanKilled = false;
	}
	else
	{
		humanKilled = true;
	}

}



void Troll::strikeTroll(int amt)
{
	if(amt >= 0)
	{
		trollKilled = false;
	}
	else
	{
		trollKilled = true;
	}

}
*/
