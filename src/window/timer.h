#ifndef CRAGMOOR_WINDOW_TIMER_H
#define CRAGMOOR_WINDOW_TIMER_H

//----STANDARD----
#include "chrono"

namespace Cragmoor
{
	namespace Window
	{
		struct Timer
		{
			private:
				std::chrono::high_resolution_clock::time_point timestamp;
			public:
				Timer();
				void reset();
				double getLap();
				double getTime();
		};
	}
}

#endif
