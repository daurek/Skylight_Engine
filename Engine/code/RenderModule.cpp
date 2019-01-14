// Header file
#include "RenderModule.hpp"

// System files
#include <memory>

// Libraries .h files
#include "Camera.hpp"
#include "Model_Obj.hpp"
#include "Light.hpp"
#include "Cube.hpp"
// Project .h files
#include "RendererComponent.hpp"
#include "Scene.hpp"
#include "Window.hpp"

namespace engine
{

	RenderModule::RenderModuleFactory RenderModule::factory;

	RenderModule::RenderModule(Scene & _scene) : scene (&_scene)
	{
		// Create nodes
		//std::shared_ptr< glt::Model  > cube(new glt::Model);
		std::shared_ptr< glt::Camera > camera(new glt::Camera(20.f, 1.f, 50.f, 1.f));
		std::shared_ptr< glt::Light  > light(new glt::Light);
		//cube->add(std::shared_ptr < glt::Drawable >(new glt::Cube), glt::Material::default_material());

		// Add nodes to the scene
		//graphics_scene.add("cube", cube);
		graphics_scene.add("camera", camera);
		graphics_scene.add("light", light);

		// Set initial positions
		graphics_scene.get("camera")->translate(glt::Vector3(0.f, 0.f, 5.f));
		graphics_scene.get("light")->translate(glt::Vector3(10.f, 10.f, 10.f));

		task = RenderTask{ *this };
	}

	std::shared_ptr< Component > RenderModule::CreateComponent(const rapidxml::xml_node<>& node)
	{
		// Get the obj path
		std::string obj_file_path = node.first_node()->value();
		std::string obj_name = obj_file_path.substr(0, obj_file_path.find("."));
		
		// Create component with that path
		std::shared_ptr< RendererComponent > renderComponent(new RendererComponent("../../assets/meshes/" + obj_file_path));
		
		graphics_scene.add(obj_name,renderComponent->get_model());
		graphics_scene.get(obj_name)->translate(glt::Vector3(1.f, 1, 1.f));

		return renderComponent;
	}
	
	void RenderModule::RenderTask::Run()
	{
		GLsizei width = GLsizei(module->scene->window->get_window_width());
		GLsizei height = GLsizei(module->scene->window->get_window_height());
		module->graphics_scene.get_active_camera()->set_aspect_ratio(float(width) / height);

		glViewport(0, 0, width, height);

		/*auto cube = module->graphics_scene.get("cube");

		cube->rotate_around_x(0.01f);
		cube->rotate_around_y(0.02f);
		cube->rotate_around_z(0.03f);*/


		/*auto cube2 = module->graphics_scene.get("sphere");

		cube2->rotate_around_x(0.01f);
		cube2->rotate_around_y(0.02f);
		cube2->rotate_around_z(0.03f);
*/

		module->scene->window->Clear();
		module->graphics_scene.render();
		module->scene->window->Display();
	}

}
