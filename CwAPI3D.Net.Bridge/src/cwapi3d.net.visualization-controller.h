#pragma once
#include "CwAPI3D.h"
#include "cwapi3d.net.ivisualization-controller.h"

namespace CwAPI3D::Net::Bridge
{
public
	ref class VisualizationController sealed : public IVisualizationController
	{
	public:
		explicit VisualizationController(System::IntPtr aFactoryPtr);

		~VisualizationController();

		!VisualizationController();

		virtual bool isActive(elementId aElementID);

		virtual void setActive(List<elementId> ^ aElementIDs);

		virtual void setInActive(List<elementId> ^ aElementIDs);

		virtual bool isVisible(elementId aElementID);

		virtual void setVisible(List<elementId> ^ aElementIDs);

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
} // namespace CwAPI3D::Net::Bridge
