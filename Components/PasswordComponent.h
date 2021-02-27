#pragma once
#include "GuiComponents/Base/GuiComponent.h"

namespace gui_component
{
	class CVarComponentBase;
	class PasswordComponent: public GuiComponent
	{
	public:
		PasswordComponent(std::string label, std::shared_ptr<CVarComponentBase> cvar);

		void Render() override;
	private:
		bool visible_ = false;
		std::shared_ptr<CVarComponentBase> cvar_;
		char text_buffer_[1024];
	};
}
