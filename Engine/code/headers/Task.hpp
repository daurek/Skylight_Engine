/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::Task
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

namespace skylight
{
	/// Base class for every Task
	class Task
	{

	public:

		/// Base Task Constructor
		Task() {};

		/// Creates a Task with the given priority
		Task(int priority) :priority(priority) {}

		/// Base Task Loop
		virtual void Run() = 0;

		/// Comparing Task priority
		bool operator < (const Task & other) const
		{
			return this->priority < other.priority;
		}

	protected:

		/// Priority Task (Order on the Kernel Set)
		int priority;
	};
}

