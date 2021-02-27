﻿#pragma once
#include "../Base/GuiComponent.h"
#include "../Base/CVarComponentBase.h"

namespace gui_component
{
	class CheckBoxComponent : public GuiComponent
	{
	public:
		CheckBoxComponent(std::string label, std::shared_ptr<CVarComponentBase> cvar)
			: GuiComponent(std::move(label)),
			  cvar_(std::move(cvar))
		{
		}

		void Render() override;
	private:
		std::shared_ptr<CVarComponentBase> cvar_;
	};
}


