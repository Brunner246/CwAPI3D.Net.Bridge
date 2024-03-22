#pragma once
#include "ApiUtils.h"
#include "typedefs.h"

using namespace System::Collections::Generic;

namespace CwAPI3D_CLI
{
public
	interface class IElementController
	{
		List<elementId> ^ getAllIdentifiableElementIDs();

		List<elementId> ^ getVisibleIdentifiableElementIDs();

		List<elementId> ^ getActiveIdentifiableElementIDs();

		void addElementsToUndo(List<elementId> ^ aElementIDs, Utils::undoType aUndoType);
	};
} // namespace CwAPI3D_CLI
