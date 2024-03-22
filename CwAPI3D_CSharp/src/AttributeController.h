#pragma once

#include "CwAPI3D.h"
#include "IAttributeController.h"

using namespace System;

namespace CwAPI3D_CLI
{
public
	ref class AttributeController sealed : public IAttributeController
	{
		CwAPI3D::AttributeController* mAttributeController{nullptr};

	public:
		explicit AttributeController(System::IntPtr aFactoryPtr);

		~AttributeController();

		!AttributeController();

		virtual String ^ getName(elementId aElementId);
	};
} // namespace CwAPI3D_CLI
