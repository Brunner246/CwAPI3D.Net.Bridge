#pragma once
#include "CwAPI3D.h"
#include "cwapi3d.net.ibim-controller.h"

namespace CwAPI3D::Net::Bridge
{
public
	ref class BimController sealed : public IBimController
	{
		CwAPI3D::BimController* mBimController{nullptr};

	public:
		explicit BimController(System::IntPtr aFactoryPtr);

		virtual System::String ^ getIfcTypeDisplayString(elementId aElementId);

		virtual elementId getElementIdFromIfcBase64Guid(System::String ^ aIfcBase64Guid);

		virtual System::String ^ getIfcBase64Guid(elementId aElementId);

		virtual EBimIfcType getIfcType(elementId aElementId);
	};
} // namespace CwAPI3D::Net::Bridge
