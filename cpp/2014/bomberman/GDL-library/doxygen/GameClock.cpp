#include "GameClock.hpp"
#include "GameClockImpl.hpp"

namespace gdl
{
	GameClock::GameClock(void)
		: clock_(GameClockImpl::getInstance()), isActiv_(false), elapsedTime_(0), totalGameTime_(0)
	{
	}

	GameClock::~GameClock(void) { }

	void		GameClock::play(void)
	{
		isActiv_ = true;
		this->clock_.sfClock.Reset();
	}

	void		GameClock::pause(void)
	{
		isActiv_ = false;
	}

	void		GameClock::update(void)
	{
		if (this->isActiv_)
		{
			this->elapsedTime_ = clock_.sfClock.GetElapsedTime();
			this->clock_.sfClock.Reset();
		}
	}

	void		GameClock::reset(void)
	{
		this->elapsedTime_ = 0;
		this->clock_.sfClock.Reset();
	}

	float		GameClock::getElapsedTime(void) const
	{
		return (this->elapsedTime_);
	}

	float		GameClock::getTotalGameTime(void) const
	{
		return (this->clock_.sfClockGlobal.GetElapsedTime());
	}
}
