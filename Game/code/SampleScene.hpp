/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class SampleScene
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

#include "Scene.hpp"
#include <vector>

using namespace skylight;

/// Example of Game Scene
class SampleScene : public skylight::Scene
{

public:

	SampleScene(const std::string & scene_content_xml, Window & given_window) : Scene(scene_content_xml, given_window) 
	{
		InitializeScene();
	}

	void InitializeScene() override;

	void Handle(const Message & message) override;

private:

	std::shared_ptr<Entity> player;
	std::map< int, std::shared_ptr< Entity >> numbers;
	std::vector< std::shared_ptr< Entity >> walls;
	int currentNumber = 1;
	float playerSpeed = 2;
	bool playerInside = true;
};
