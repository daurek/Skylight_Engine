// Header file
#include "RenderModule.hpp"

// System files
#include <memory>

// Libraries .h files
#include "Camera.hpp"
#include "Model_Obj.hpp"
#include "Light.hpp"
// Project .h files
#include "RendererComponent.hpp"
#include "Window.hpp"

namespace engine
{

	RenderModule::RenderModuleFactory RenderModule::factory;

	RenderModule::RenderModule()//Window * _window) : window(_window)
	{
		window = Window{ 1080,720 };
		std::shared_ptr< glt::Camera > camera(new glt::Camera(20.f, 1.f, 50.f, 1.f));
		std::shared_ptr< glt::Light  > light(new glt::Light);
		graphics_scene.add("camera", camera);
		graphics_scene.add("light", light);
		task = RenderTask{ *this };
	}

	std::shared_ptr< Component > RenderModule::CreateComponent(const rapidxml::xml_node<>& node)
	{
		std::string obj_file_path = node.first_node()->value();

		std::shared_ptr< RendererComponent > renderComponent(new RendererComponent("../../assets/meshes/sphere.obj"));
		
		graphics_scene.add(obj_file_path,renderComponent->get_model());

		return renderComponent;
	}
	
}
