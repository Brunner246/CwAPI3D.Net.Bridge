#pragma once

#include "CwAPI3D.h"
#include "cwapi3d.net.iattribute-controller.h"
#include "cwapi3d.net.ibim-controller.h"
#include "cwapi3d.net.icamera-data.h"
#include "cwapi3d.net.ifactory.h"
#include "cwapi3d.net.ielement-controller.h"
#include "cwapi3d.net.ivisualization-controller.h"

namespace CwAPI3D::Net::Bridge
{
	// clang-format off
	public ref class CwApi3DFactory : public ICwApi3DFactory
	// clang-format on
	{
		CwAPI3D::ControllerFactory* mControllerFactory{nullptr};

		IElementController ^ mElementController { nullptr };

		IAttributeController ^ mAttributeController { nullptr };

		IUtilityController ^ mUtilityController { nullptr };

		IVisualizationController ^ mVisualizationController { nullptr };

		IBimController ^ mBimController { nullptr };

		ICameraData ^ mCameraData { nullptr };

	public:
		explicit CwApi3DFactory(System::IntPtr aFactoryPtr);

		virtual IElementController ^ getElementController();

		virtual IAttributeController ^ getAttributeController();

		virtual IUtilityController ^ getUtilityController();

		virtual IVisualizationController ^ getVisualizationController();

		virtual IBimController ^ getBimController();

		virtual ICameraData ^ getCameraData();
	};
} // namespace CwAPI3D::Net::Bridge
