#pragma once
#include "CwAPI3D.h"

#include "IElementController.h"

using namespace System::Collections::Generic;

namespace CwAPI3D_Net
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

		virtual List<elementId> ^ getAllIdentifiableElementIDs();

		virtual List<elementId> ^ getActiveIdentifiableElementIDs();

		virtual List<elementId> ^ getVisibleIdentifiableElementIDs();

		virtual void addElementsToUndo(List<elementId> ^ aElementIDs, Utils::undoType aUndoType);
	};
} // namespace CwAPI3D_Net
