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

namespace engine
{
	RenderModule::RenderModule(Window * _window) : window(_window)
	{
		//ComponentFactory::RegisterFactory("render3d", RenderModule::CreateComponent);

		std::shared_ptr< glt::Camera > camera(new glt::Camera(20.f, 1.f, 50.f, 1.f));
		std::shared_ptr< glt::Light  > light(new glt::Light);
		
		graphics_scene.add("Camera", camera);
		graphics_scene.add("light", light);
		
		task = RenderTask{ *this };
	}

	std::shared_ptr< Component > RenderModule::CreateComponent(const rapidxml::xml_node<>& node)
	{
		std::string obj_file_path = node.first_node()->value();

		std::shared_ptr< RendererComponent > renderComponent(new RendererComponent("../../assets/meshes/" + obj_file_path));
		
		graphics_scene.add("a",renderComponent->get_model());

		return renderComponent;
	}
}
