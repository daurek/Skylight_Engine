#pragma once

// System files
#include <set>

// Project .h files
#include "Task.hpp"

namespace engine
{
	class Kernel
	{
	private: 

		bool running = true;
		std::multiset<Task *> tasks;

	public:

		static Kernel & instance()
		{
			static Kernel kernel;
			return kernel;
		}

	private:

		Kernel() = default;

	public:

		bool is_running() { return running; }
		void Add(Task & task);
		void Run();
		void Stop();
	};
}

