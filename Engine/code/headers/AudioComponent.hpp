/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::AudioComponent
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// System
#include <string>

// Libraries
#include "SDL_audio.h"
// Project
#include "Component.hpp"

namespace skylight
{	
	/// Component that loads and plays audio files
	class AudioComponent : public Component
	{

	public:

		/// Loads an audio file with the given path
		AudioComponent(const std::string & path);

		/// ---
		void Update() override {};

		/// Plays the current audio file
		void Play();

	private:

		/// DeviceID in which sound will play
		SDL_AudioDeviceID device;

		/// Audio structure to play
		SDL_AudioSpec wav_spec;

		/// Audio file length
		Uint32 wav_length;

		/// Audio file buffer
		Uint8 *wav_buffer;
	};
}

