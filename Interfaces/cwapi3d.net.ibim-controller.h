#pragma once
#include "cwapi3d.net.bim.ifc.type.h"
#include "typedefs.h"

namespace CwAPI3D::Net::Bridge
{
public
	interface class IBimController
	{
		EBimIfcType getIfcType(elementId aElementId);

		System::String ^ getIfcTypeDisplayString(elementId aElementId);

		elementId getElementIdFromIfcBase64Guid(System::String ^ aIfcBase64Guid);

		System::String ^ getIfcBase64Guid(elementId aElementId);
	};
} // namespace CwAPI3D_Net
