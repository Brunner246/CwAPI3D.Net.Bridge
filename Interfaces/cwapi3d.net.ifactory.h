#pragma once


namespace CwAPI3D::Net::Bridge
{
	interface class IElementController;
	interface class IAttributeController;
	interface class IUtilityController;
	interface class ICameraData;
	interface class IBimController;
	interface class IVisualizationController;

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
