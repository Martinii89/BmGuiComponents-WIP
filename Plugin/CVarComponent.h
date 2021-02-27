#pragma once
#include "../Base/CVarComponentBase.h"

namespace gui_component::plugin
{
	class CVarComponent: public CVarComponentBase
	{
	public:
		CVarComponent(const std::string& cvar_name, CVarManagerWrapper* cvar_manager, std::shared_ptr<SafeExecutorBase> safe_executor);
		CVarComponent(CVarWrapper cvar, std::shared_ptr<SafeExecutorBase> safe_executor);
		
		bool IsValid() override;
		int GetIntValue() override;
		float GetFloatValue() override;
		bool GetBoolValue() override;
		LinearColor GetColorValue() override;
		std::string GetStringValue() override;

		void SetIntValue(int value) override;
		void SetFloatValue(float value) override;
		void SetBoolValue(bool value) override;
		void SetColorValue(LinearColor value) override;
		void SetStringValue(std::string value) override;
	private:
		CVarWrapper cvar_;
	};
}