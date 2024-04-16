#pragma once
#include "cwapi3d.net.utils.h"
#include "cwapi3d.net.vector3d.h"
#include "typedefs.h"

using namespace System::Collections::Generic;

namespace CwAPI3D::Net::Bridge
{
public
	interface class IElementController
	{
		List<elementId> ^ getAllIdentifiableElementIDs();

		List<elementId> ^ getVisibleIdentifiableElementIDs();

		List<elementId> ^ getActiveIdentifiableElementIDs();

		void addElementsToUndo(List<elementId> ^ aElementIDs, Utils::undoType aUndoType);

		elementId createRectangularBeamPoints(double aWidth, double aHeight, vector3D^ aP1, vector3D^ aP2, vector3D^ aP3);
	};
} // namespace CwAPI3D_Net
