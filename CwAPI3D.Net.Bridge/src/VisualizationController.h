#pragma once
#include "CwAPI3D.h"
#include "IVisualizationController.h"

namespace CwAPI3D_Net
{
public
	ref class VisualizationController sealed : public IVisualizationController
	{
	public:
		explicit VisualizationController(System::IntPtr aFactoryPtr);

		~VisualizationController();

		!VisualizationController();

		virtual bool isActive(int aElementID);

		virtual void setActive(List<int> ^ aElementIDs);

		virtual void setInActive(List<int> ^ aElementIDs);

		virtual bool isVisible(int aElementID);

		virtual void setVisible(List<int> ^ aElementIDs);

		virtual void hideAllElements();

		virtual void showAllElements();

		virtual bool isPlane2D();

		virtual void setCamera(ICameraData ^ aCameraData);

		virtual ICameraData ^ getCamera();

		virtual void refresh();

	private:
		CwAPI3D::ControllerFactory* mControllerFactory{nullptr};

		CwAPI3D::VisualizationController* mVisualizationController{nullptr};

	public:
	};
} // namespace CwAPI3D_Net
