#pragma once
#include <string>
#include "../Base/GuiComponent.h"

namespace gui_component
{
	class CVarComponentBase;
	
	class TextInputComponent: public GuiComponent
	{
	public:
		TextInputComponent(std::string label, std::shared_ptr<CVarComponentBase> cvar);

		void Render() override;
	private:
		std::shared_ptr<CVarComponentBase> cvar_;
		char text_buffer_[1024];
	};
}