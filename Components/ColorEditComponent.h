#pragma once

#include "GuiComponents/Base/GuiComponent.h"

namespace gui_component
{
	class CVarComponentBase;
	class ColorEditComponent : public GuiComponent
	{
	public:

		ColorEditComponent(std::string label, std::shared_ptr<CVarComponentBase> cvar);
		void Render() override;
	private:
		std::shared_ptr<CVarComponentBase> cvar_;
	};
}