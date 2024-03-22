#pragma once
#include "CwAPI3D.h"

#include "IElementController.h"

using namespace System::Collections::Generic;

namespace CwAPI3D_CLI
{
public
	ref class ElementController sealed : public IElementController
	{
		CwAPI3D::ElementController* mElementController{nullptr};
		CwAPI3D::ControllerFactory* mControllerFactory{nullptr};

	public:
		explicit ElementController(System::IntPtr aFactoryPtr);

		~ElementController();

		!ElementController();

		virtual List<int> ^ getAllIdentifiableElementIDs();

		virtual List<int> ^ getActiveIdentifiableElementIDs();

		virtual List<int> ^ getVisibleIdentifiableElementIDs();

		virtual void addElementsToUndo(List<int> ^ aElementIDs, Utils::undoType aUndoType);
	};
} // namespace CwAPI3D_CLI
