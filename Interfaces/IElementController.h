#pragma once
#include "ApiUtils.h"
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

		void addElementsToUndo(List<elementId> ^ aElementIDs, CwAPI3D_Net::Utils::undoType aUndoType);
	};
} // namespace CwAPI3D_Net
