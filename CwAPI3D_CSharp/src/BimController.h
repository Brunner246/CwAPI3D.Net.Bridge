#pragma once
#include "CwAPI3D.h"
#include "IBimController.h"

namespace CwAPI3D_Net
{
public
	ref class BimController sealed : public IBimController
	{
		CwAPI3D::BimController* mBimController{nullptr};

	public:
		explicit BimController(System::IntPtr aFactoryPtr);

		virtual String ^ getIfcTypeDisplayString(elementId aElementId);

		virtual elementId getElementIdFromIfcBase64Guid(String ^ aIfcBase64Guid);

		virtual String ^ getIfcBase64Guid(elementId aElementId);

		virtual EBimIfcType getIfcType(elementId aElementId);
	};
} // namespace CwAPI3D_Net
