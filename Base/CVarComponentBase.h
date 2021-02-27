#pragma once
#include <string>
#include "bakkesmod/wrappers/wrapperstructs.h"

namespace gui_component
{
	class SafeExecutorBase;

	class CVarComponentBase
	{
	public:
		explicit CVarComponentBase(const std::string& cvar_name, std::shared_ptr<SafeExecutorBase> safe_executor);
		virtual ~CVarComponentBase() = default;
		CVarComponentBase(const CVarComponentBase& other) = default;
		CVarComponentBase(CVarComponentBase&& other) noexcept = default;
		CVarComponentBase& operator=(const CVarComponentBase& other) = default;
		CVarComponentBase& operator=(CVarComponentBase&& other) noexcept = default;

		_NODISCARD const std::string& GetCvarName() const;

		virtual bool IsValid() = 0;
		virtual int GetIntValue() = 0;
		virtual float GetFloatValue() = 0;
		virtual bool GetBoolValue() = 0;
		virtual LinearColor GetColorValue() = 0;
		virtual std::string GetStringValue() = 0;
		virtual void SetIntValue(int value) = 0;
		virtual void SetFloatValue(float value) = 0;
		virtual void SetBoolValue(bool value) = 0;
		virtual void SetColorValue(LinearColor value) = 0;
		virtual void SetStringValue(std::string value) = 0;
	protected:
		std::string cvar_name_;
		std::shared_ptr<SafeExecutorBase> safe_executor_;
	};

}

