#pragma once

// System files
#include <map>

// Project .h files
#include "Task.hpp"

namespace skylight
{
	class InputTask : public Task
	{

		std::map< int, uint32_t > keyboard_mapping;

	public:
		InputTask() = default;
		void Run() override;
	};
}

