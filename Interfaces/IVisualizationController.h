#pragma once
#include "ICameraData.h"

using namespace System::Collections::Generic;

namespace CwAPI3D_Net
{
public
	interface class IVisualizationController
	{
		bool isActive(int aElementID);

		void setActive(List<int> ^ aElementIDs);

		void setInActive(List<int> ^ aElementIDs);

		bool isVisible(int aElementID);

		void setVisible(List<int> ^ aElementIDs);

		void hideAllElements();

		void showAllElements();

		bool isPlane2D();

		void setCamera(ICameraData ^ aCameraData);

		ICameraData ^ getCamera();

		void refresh();
	};
} // namespace CwAPI3D_Net
