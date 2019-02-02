/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::AudioComponent
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "AudioComponent.hpp"

// Libraries
#include "SDL_log.h"
// Project
#include "Entity.hpp"

namespace skylight
{
	AudioComponent::AudioComponent(const std::string & path)
	{
		// Load the WAV
		if (SDL_LoadWAV(path.c_str(), &wav_spec, &wav_buffer, &wav_length) == NULL) 
			SDL_Log("				WAV not loaded ");
		else 
			SDL_Log("				  WAV loaded");
		
		// Open device
		device = SDL_OpenAudioDevice(NULL, 0, &wav_spec, NULL, 0);

	}

	void AudioComponent::Play()
	{
		// Queue audio and play it
		SDL_QueueAudio(device, wav_buffer, wav_length);
		SDL_PauseAudioDevice(device, 0);
	}
}
