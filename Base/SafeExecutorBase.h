#pragma once
#include <functional>

namespace gui_component
{
	class SafeExecutorBase
	{
	public:
		explicit SafeExecutorBase() = default;
		virtual ~SafeExecutorBase() = default;
		SafeExecutorBase(const SafeExecutorBase& other) = default;
		SafeExecutorBase(SafeExecutorBase&& other) noexcept = default;
		SafeExecutorBase& operator=(const SafeExecutorBase& other) = default;
		SafeExecutorBase& operator=(SafeExecutorBase&& other) noexcept = default;

		virtual void ExecuteSafe(std::function<void()> callback) = 0;
	}; 
}

