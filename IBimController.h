#pragma once
#include "EBimIfcType.h"

using namespace System;

namespace CwAPI3D_CLI
{
public
	interface class IBimController
	{
		EBimIfcType getIfcType(int aElementId);

		String ^ getIfcTypeDisplayString(int aElementId);

		int getElementIdFromIfcBase64Guid(String ^ aIfcBase64Guid);

		String ^ getIfcBase64Guid(int aElementId);
	};
} // namespace CwAPI3D_CLI
