#pragma once
#include "ApiUtils.h"

using namespace System::Collections::Generic;

namespace CwAPI3D_CLI
{
public
	interface class IElementController
	{
		List<int> ^ getAllIdentifiableElementIDs();

		List<int> ^ getVisibleIdentifiableElementIDs();

		List<int> ^ getActiveIdentifiableElementIDs();

		void addElementsToUndo(List<int> ^ aElementIDs, Utils::undoType aUndoType);
	};
} // namespace CwAPI3D_CLI
