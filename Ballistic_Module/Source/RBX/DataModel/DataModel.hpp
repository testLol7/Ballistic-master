#pragma once
#include <iostream>

#include "../Graphics/Graphics.hpp"

namespace RBX
{
	class CDataModel
	{
	public:
		uintptr_t Get();
		std::vector<uintptr_t> GetChildren(uintptr_t parent);
		std::string GetName(uintptr_t instance);
	};

	inline auto DataModel = std::make_unique<CDataModel>();
}