#pragma once

#include "typedefs.h"

using namespace System;

namespace CwAPI3D_Net
{
public
	interface class IAttributeController
	{
		String ^ getName(elementId aElementID);
	};
} // namespace CwAPI3D_Net
