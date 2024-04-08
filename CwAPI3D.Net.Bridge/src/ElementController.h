#pragma once
#include "CwAPI3D.h"
#include "IElementController.h"

using namespace System::Collections::Generic;

namespace CwAPI3D::Net::Bridge
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

		virtual elementId createRectangularBeamPoints(double aWidth, double aHeight, vector3D^ aP1, vector3D^ aP2, vector3D^ aP3);
	};
} // namespace CwAPI3D::Net::Bridge
