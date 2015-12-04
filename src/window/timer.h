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
