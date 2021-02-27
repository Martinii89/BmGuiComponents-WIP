#pragma once
#include "../Base/GuiComponent.h"

namespace gui_component
{
	class AnonymousComponent: public GuiComponent
	{
	public:
		explicit AnonymousComponent(std::function<void()> callback);
		void Render() override;
	private:
		std::function<void()> callback_;

	};
}