#pragma once

#include "typedefs.h"

namespace CwAPI3D::Net::Bridge
{
public
	interface class IAttributeController
	{
		System::String ^ getName(elementId aElementID);
	};
} // namespace CwAPI3D_Net
