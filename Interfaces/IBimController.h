#pragma once
#include "EBimIfcType.h"
#include "typedefs.h"

using namespace System;

namespace CwAPI3D_Net
{
public
	interface class IBimController
	{
		EBimIfcType getIfcType(elementId aElementId);

		String ^ getIfcTypeDisplayString(elementId aElementId);

		elementId getElementIdFromIfcBase64Guid(String ^ aIfcBase64Guid);

		String ^ getIfcBase64Guid(elementId aElementId);
	};
} // namespace CwAPI3D_Net
