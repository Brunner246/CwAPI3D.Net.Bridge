#pragma once

#include "CwAPI3D.h"
#include "cwapi3d.net.iattribute-controller.h"

namespace CwAPI3D::Net::Bridge
{
public
	ref class AttributeController sealed : public IAttributeController
	{
		CwAPI3D::AttributeController* mAttributeController{nullptr};

	public:
		explicit AttributeController(System::IntPtr aFactoryPtr);

		~AttributeController();

		!AttributeController();

		virtual System::String ^ getName(elementId aElementId);
	};
} // namespace CwAPI3D::Net::Bridge
