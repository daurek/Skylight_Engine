/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::RenderModule
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

// Header
#include "RenderModule.hpp"

// Libraries
#include "Model_Obj.hpp"
#include "SDL_log.h"
// Project
#include "RendererComponent.hpp"
#include "Scene.hpp"
#include "Window.hpp"

namespace skylight
{
	RenderModule::RenderModuleFactory RenderModule::factory;

	std::shared_ptr< Component > RenderModule::CreateComponent(const rapidxml::xml_node<>& node)
	{
		// Get the obj path
		std::string obj_file_path = node.first_node()->value();
		std::string obj_name = obj_file_path.substr(0, obj_file_path.find("."));
		// Log
		SDL_Log("			Component __ Renderer");
		std::string log_component = "				Model Path: " + obj_file_path;
		SDL_Log(log_component.c_str());
		// Create component with that path
		std::shared_ptr< RendererComponent > renderComponent(new RendererComponent("../../assets/meshes/" + obj_file_path));

		int counter = 1;
		while (scene->graphics_scene[obj_name])
		{
			obj_name += std::to_string(counter);
		}

		scene->graphics_scene.add(obj_name, renderComponent->get_model());

		components.push_back(renderComponent);

		return renderComponent;
	}
	
	void RenderModule::RenderTask::Run()
	{
		// Update viewport and aspect ratio
		GLsizei width = GLsizei(module->scene->window->get_window_width());
		GLsizei height = GLsizei(module->scene->window->get_window_height());
		module->scene->graphics_scene.get_active_camera()->set_aspect_ratio(float(width) / height);
		glViewport(0, 0, width, height);

		for (auto component : module->components)
		{
			component->Update();
		}

		//auto camera = module->scene->graphics_scene.get("camera");
		//camera->translate({ 0, 0.001, 0.001 });
		//camera->rotate_around_y(0.02f);


		/*auto cube2 = module->graphics_scene.get("sphere");

		cube2->rotate_around_x(0.01f);
		cube2->rotate_around_y(0.02f);
		cube2->rotate_around_z(0.03f);
		*/

		module->scene->window->Clear();
		module->scene->graphics_scene.render();
		module->scene->window->Display();
	}

}
