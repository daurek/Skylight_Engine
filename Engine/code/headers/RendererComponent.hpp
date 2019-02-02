/// ----------------------------------------------------------------------------------------------------------------------
/// SKYLIGHT ENGINE
/// \class skylight::RendererComponent
///
/// \author Ilyass Sofi Hlimi
/// \date 27/01/2019
///
/// Contact: ilyassgame@gmail.com
/// ----------------------------------------------------------------------------------------------------------------------

#pragma once

// Libraries
#include "Model.hpp"
// Project
#include "Component.hpp"

namespace skylight
{	
	/// Component that renders a 3D mesh
	class RendererComponent : public Component
	{

	public:

		/// Creates a model with the given obj path
		RendererComponent(const std::string & path);
		
		/// Updates it's Transform with the entity's Transform
		void Update() override;

		/// Returns the Component model
		std::shared_ptr< glt::Model > get_model() { return model; }

		/// Sets the model visibility as the given state
		void set_visible(bool state) { model->set_visible(state); }

	private:

		/// Model Reference
		std::shared_ptr< glt::Model > model;
	};
}

