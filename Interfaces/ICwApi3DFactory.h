#pragma once

#include "IBimController.h"
#include "IVisualizationController.h"

namespace CwAPI3D_Net
{
	interface class IElementController;
	interface class IAttributeController;
	interface class IUtilityController;
	interface class ICameraData;

public
	interface class ICwApi3DFactory
	{
		IElementController ^ getElementController();

		IAttributeController ^ getAttributeController();

		IUtilityController ^ getUtilityController();

		IVisualizationController ^ getVisualizationController();

		IBimController ^ getBimController();

		ICameraData ^ getCameraData();
	};
} // namespace CwAPI3D_Net
