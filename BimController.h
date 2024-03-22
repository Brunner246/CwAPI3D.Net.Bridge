#pragma once
#include "CwAPI3D.h"
#include "IBimController.h"

namespace CwAPI3D_CLI
{
public
	ref class BimController sealed : public IBimController
	{
		CwAPI3D::BimController* mBimController{nullptr};

	public:
		explicit BimController(System::IntPtr aFactoryPtr);

		virtual String ^ getIfcTypeDisplayString(int aElementId);

		virtual int getElementIdFromIfcBase64Guid(String ^ aIfcBase64Guid);

		virtual String ^ getIfcBase64Guid(int aElementId);

		virtual EBimIfcType getIfcType(int aElementId);
	};
} // namespace CwAPI3D_CLI
