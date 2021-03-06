/* Flotsam.h
Copyright (c) 2016 by Michael Zahniser

Endless Sky is free software: you can redistribute it and/or modify it under the
terms of the GNU General Public License as published by the Free Software
Foundation, either version 3 of the License, or (at your option) any later version.

Endless Sky is distributed in the hope that it will be useful, but WITHOUT ANY
WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A
PARTICULAR PURPOSE.  See the GNU General Public License for more details.
*/

#ifndef FLOTSAM_H_
#define FLOTSAM_H_

#include "Angle.h"
#include "Body.h"
#include "Point.h"

#include <list>
#include <string>

class Effect;
class Outfit;
class Ship;



class Flotsam : public Body {
public:
	// Constructors for flotsam carrying either a commodity or an outfit.
	Flotsam(const std::string &commodity, int count);
	Flotsam(const Outfit *outfit, int count);
	
	/* Functions provided by the Body base class:
	Frame GetFrame(int step = -1) const;
	const Point &Position() const;
	const Point &Velocity() const;
	const Angle &Facing() const;
	Point Unit() const;
	*/
	
	// Place this flotsam, and set the given ship as its source. This is a
	// separate function because a ship may queue up flotsam to dump but take
	// several frames before it finishes dumping it all.
	void Place(const Ship &source);
	
	// Move the object one time-step forward.
	bool Move(std::list<Effect> &effects);
	
	// This is the one ship that cannot pick up this flotsam.
	const Ship *Source() const;
	// This is what the flotsam contains:
	const std::string &CommodityType() const;
	const Outfit *OutfitType() const;
	int Count() const;
	// This is how big one "unit" of the flotsam is (in tons). If a ship has
	// less than this amount of space, it can't pick up anything here.
	int UnitSize() const;
	
	
private:
	Angle spin;
	int lifetime = 0;
	
	const Ship *source = nullptr;
	std::string commodity;
	const Outfit *outfit = nullptr;
	int count = 0;
};



#endif
