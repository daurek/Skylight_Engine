/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class SampleScene
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#include "SampleScene.hpp"

#include "InputTask.hpp"
#include "AudioComponent.hpp"
#include "RendererComponent.hpp"
#include "Kernel.hpp"
#include "SDL_log.h"

void SampleScene::InitializeScene()
{
	// Suscribing to events
	MessageHandler::instance().multicast_targets["key_pressed"].push_back(this);
	MessageHandler::instance().multicast_targets["mouse_motion"].push_back(this);

	// Get some entities
	player = entities["player"];
	numbers[1] = entities["number1"];
	numbers[2] = entities["number2"];
	numbers[3] = entities["number3"];
	numbers[4] = entities["number4"];
	numbers[5] = entities["number5"];

	walls.push_back(entities["ground"]);
	walls.push_back(entities["wall1"]);
	walls.push_back(entities["wall2"]);
	walls.push_back(entities["wall3"]);
	walls.push_back(entities["wall4"]);
	walls.push_back(entities["ceiling"]);

	// Background audio disabled
	//std::dynamic_pointer_cast<AudioComponent>(entities["bunny"]->get_component("audio"))->Play();
}

void SampleScene::Handle(const Message & message)
{
	// If the user pressed a key
	if (message.get_id() == "key_pressed")
	{
		// Get the input keycode
		Message::Variant variant = message.properties.find("key_code")->second;

		InputTask::Key_Code keycode = static_cast<InputTask::Key_Code>(std::get<int>(variant));

		glm::vec3 movement;

		// Check key to make movement
		switch (keycode)
		{
		case InputTask::KEY_W:
			movement.z = -0.1f;
			break;
		case InputTask::KEY_S:
			movement.z = 0.1f;
			break;
		case InputTask::KEY_D:
			movement.x = 0.1f;
			break;
		case InputTask::KEY_A:
			movement.x = -0.1f;
			break;
		case InputTask::KEY_ESCAPE:
			Kernel::instance().Stop();
			break;
		default:
			break;
		}

		// If the player is pressing the movement keys the move him
		if (movement.z != 0 || movement.x != 0)
			player->transform->Move(movement * playerSpeed);

		// Scene boundaries
		auto player_pos = player->transform->get_position();
		if (playerInside && (player_pos.x > 14 || player_pos.z > 14 || player_pos.x < -14 || player_pos.z < -14))
		{
			std::dynamic_pointer_cast<AudioComponent>(player->get_component("audio"))->Play();
			player->transform->set_position({ 0,0,5 });
		}
	}
	// Camera movement
	else if (message.get_id() == "mouse_motion")
	{
		// Get the relative mouse position
		Message::Variant mouse_position_x = message.properties.find("position_x")->second;
		Message::Variant mouse_position_y = message.properties.find("position_y")->second;

		// Get the values
		int x = std::get<int>(mouse_position_x);
		int y = std::get<int>(mouse_position_y);

		// Rotate camera if it's moving
		if (x != 0 || y != 0)
		{
			player->transform->Rotate(x * -0.03f, { 0,1,0 });
			// Vertical Camera Disabled
			//player->transform->Rotate(y * -0.01f, { 1,0,0 });
		}
	}

	// Looping through the numbers
	for (auto const&[number, entity] : numbers)
	{
		// Rotate them (this should be done on ScriptComponent)
		entity->transform->Rotate(1, { 0,0,1 });

		// If that number is visible and close to the player
		if (graphics_scene[entity->name]->is_visible() && glm::distance(player->transform->get_position(), numbers[number]->transform->get_position()) < 1.5f)
		{
			// If the order is correct
			if (number == currentNumber)
			{
				// Hide that number and go to the next
				currentNumber++;
				std::dynamic_pointer_cast<RendererComponent>(entity->get_component("render3d"))->set_visible(false);

				// If we reached the last number
				if (currentNumber > numbers.size() )
				{
					playerInside = false;
					// Hide the walls
					for (auto & wall : walls) 
					{
						std::dynamic_pointer_cast<RendererComponent>(wall->get_component("render3d"))->set_visible(false);
					}
				}
			}
			// Otherwise play a wrong audio and reset the player's position
			else
			{
				std::dynamic_pointer_cast<AudioComponent>(player->get_component("audio"))->Play();
				player->transform->set_position({ 0,0,5 });
			}
		}
	}

	
}

