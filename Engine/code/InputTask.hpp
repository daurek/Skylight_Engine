#pragma once

// Project .h files
#include "Task.hpp"

namespace engine
{
	class InputTask : public Task
	{

	public:
		InputTask() = default;
		void Run() override;
	};
}

