#include "SampleScene.hpp"
#include "InputTask.hpp"
#include "Kernel.hpp"

using namespace skylight;


int main()
{
	// Create window
	Window window{ "Skylight Engine Demo", 1080, 720, false };

	// Load scene with window
	SampleScene scene{ "../../assets/scene.xml", window };
	// Prepare input
	InputTask inputTask{ 1 };
	inputTask.LoadInputMapping("../../assets/input_mapping.xml");
	Kernel::instance().Add(inputTask);

	// Start kernel loop
	Kernel::instance().Run();

	return 0;
}