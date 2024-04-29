#pragma once
#include "cwapi3d.net.icamera-data.h"
#include "typedefs.h"

using namespace System::Collections::Generic;

namespace CwAPI3D::Net::Bridge
{
public
	interface class IVisualizationController
	{
		bool isActive(elementId aElementID);

		void setActive(List<elementId> ^ aElementIDs);

		void setInActive(List<elementId> ^ aElementIDs);

		bool isVisible(elementId aElementID);

		void setVisible(List<elementId> ^ aElementIDs);

		void setInVisible(List<elementId> ^ aElementIDs);

		void hideAllElements();

		void showAllElements();

		bool isPlane2D();

		void setCamera(ICameraData ^ aCameraData);

		ICameraData ^ getCamera();

		void refresh();
	};
} // namespace CwAPI3D_Net
