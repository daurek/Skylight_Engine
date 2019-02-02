/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::AudioModule
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "AudioModule.hpp"

// System
#include <memory>

// Libraries
#include "SDL.h"
// Project
#include "AudioComponent.hpp"
#include "Scene.hpp"

namespace skylight
{

	AudioModule::AudioModuleFactory AudioModule::factory;

	std::shared_ptr< Component > AudioModule::CreateComponent(const rapidxml::xml_node<>& node)
	{
		// Get audio path
		std::string audio_path = node.first_node()->value();

		// Audio logging
		SDL_Log("			Component __ Audio");
		// Path logging
		std::string log_path =	"				Path: " + audio_path;
		SDL_Log(log_path.c_str());

		// Create component with the data
		std::shared_ptr< AudioComponent > audioComponent(new AudioComponent("../../assets/sounds/" + audio_path));
		
		components.push_back(audioComponent);
		return audioComponent;
	}
	
	void AudioModule::AudioTask::Run()
	{
		// Nothing to Update currently
		/*for (auto component : module->components)
		{
			component->Update();
		}*/
	}

}
