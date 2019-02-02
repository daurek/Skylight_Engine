/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Kernel
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// System
#include <set>

// Project
#include "Task.hpp"

namespace skylight
{
	/// Handles Engine and Task game loop 
	class Kernel
	{

	public:

		/// Kernel singleton instance
		static Kernel & instance()
		{
			static Kernel kernel;
			return kernel;
		}

		/// Adds the given task to the Task set
		void Add(Task & task);

		/// Loops through every Task
		void Run();

		/// Stops the main loop
		void Stop();

		/// Returns if the kernel is running
		bool is_running() { return running; }

	private:

		/// Default Constructor
		Kernel() = default;

		/// Task Loop state
		bool running = true;

		/// Task set
		std::multiset<Task *> tasks;

	};
}

