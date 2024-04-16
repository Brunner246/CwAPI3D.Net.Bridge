#pragma once

#include "CwAPI3D.h"

#include "cwapi3d.net.iutility-controller.h"

namespace CwAPI3D::Net::Bridge
{
		ref class windowGeometry;

	public
		ref class UtilityController sealed : public IUtilityController
		{
				CwAPI3D::UtilityController* mUtilityController{nullptr};

			public:
				explicit UtilityController(System::IntPtr aFactoryPtr);
				~UtilityController();

				!UtilityController();

				virtual System::String ^ getPluginPath();
				virtual bool getUseOfGlobalCoordinates();
				virtual vector3D ^ getGlobalOrigin();
				virtual System::String ^ createSnapshot(System::String ^ aFormat, int aQuality, bool aWhiteBackground);
				virtual void disableAutoDisplayRefresh();
				virtual void enableAutoDisplayRefresh();
				virtual windowGeometry ^ get3dMainWindowGeometry();
				virtual System::String ^ getLanguage();
		};
} // namespace CwAPI3D::Net::Bridge
