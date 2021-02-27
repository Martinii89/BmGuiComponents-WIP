#pragma once
#include <string>
#include <memory>
#include <vector>

namespace gui_component
{
	class GuiComponent
	{
	public:
		explicit GuiComponent(std::string label);
		GuiComponent() = default;
		virtual ~GuiComponent() = default;
		GuiComponent(const GuiComponent& other) = default;
		GuiComponent(GuiComponent&& other) noexcept = default;
		GuiComponent& operator=(const GuiComponent& other) = default;
		GuiComponent& operator=(GuiComponent&& other) noexcept = default;
	protected:
		std::string label_;
		std::vector<std::shared_ptr<GuiComponent>> components_;
	public:
		/// <summary>
		/// Returns self
		/// </summary>
		/// <param name="component"></param>
		/// <returns>Returns self</returns>
		GuiComponent* AddComponent(std::shared_ptr<GuiComponent> component);
		std::shared_ptr<GuiComponent> FindComponent(const std::string& label);
		std::shared_ptr<GuiComponent> FindComponent(std::vector<std::string>& path);
		virtual void Render();
	};
}


