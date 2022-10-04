#include "Boatplane.h"

namespace assignment2
{
	Boatplane::Boatplane(unsigned int maxPassengersCount)
		: Vehicle(maxPassengersCount)
	{
	}

	Boatplane::~Boatplane()
	{
	}

	unsigned int Boatplane::GetMaxSpeed() const
	{
		unsigned int flySpeed = GetFlySpeed();
		unsigned int sailSpeed = GetSailSpeed();

		return (flySpeed > sailSpeed ? flySpeed : sailSpeed);
	}

	unsigned int Boatplane::GetFlySpeed() const
	{
		return static_cast<unsigned int>(150 * exp((-1 * static_cast<int>(GetTotalWeight()) + 500.0) / 300) + 0.5);
	}

	unsigned int Boatplane::GetSailSpeed() const
	{
		int speed = static_cast<int>(800 - 1.7 * GetTotalWeight() + 0.5);

		return (speed > MIN_SPEED ? speed : MIN_SPEED);
	}

	bool Boatplane::Move()
	{
		if (mCallMoveCount % UNIT_MOVEMENT != 0)
		{
			++mCallMoveCount;
			return false;
		}

		mTraveledKilometers += GetMaxSpeed();
		++mCallMoveCount;

		return true;
	}
}