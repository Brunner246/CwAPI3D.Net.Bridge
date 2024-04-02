#pragma once

#include "CwAPI3D.h"

#include "IUtilityController.h"

using namespace System;

namespace CwAPI3D_Net
{

public
	ref class UtilityController sealed : public IUtilityController
	{
		CwAPI3D::UtilityController* mUtilityController{nullptr};

	public:
		explicit UtilityController(System::IntPtr aFactoryPtr);
		~UtilityController();

		!UtilityController();

		virtual String ^ getPluginPath();
		virtual bool getUseOfGlobalCoordinates();
		virtual vector3D ^ getGlobalOrigin();
		virtual String ^ createSnapshot(String ^ aFormat, int aQuality, bool aWhiteBackground);
		virtual void disableAutoDisplayRefresh();
		virtual void enableAutoDisplayRefresh();
		virtual Tuple<int, int> ^ get3dGuiUpperLeftScreenCoordinates();
		virtual String ^ getLanguage();
	};
} // namespace CwAPI3D_Net
