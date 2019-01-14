// Header file
#include "Kernel.hpp"


namespace engine
{
	void Kernel::Add(Task & task)
	{
		tasks.insert(&task);
	}

	void Kernel::Run()
	{
		do
		{
			for (Task * task : tasks)
			{
				task->Run();
			}
		}
		while (running);
	}

	void Kernel::Stop()
	{
		running = false;
	}
}
