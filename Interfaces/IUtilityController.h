#pragma once

using namespace System;

namespace CwAPI3D_Net
{
	ref class vector3D;
public
	interface class IUtilityController
	{
		String ^ getPluginPath();

		bool getUseOfGlobalCoordinates();

		vector3D ^ getGlobalOrigin();

		String ^ createSnapshot(String ^ aFormat, int aQuality, bool aWhiteBackground);

		void disableAutoDisplayRefresh();

		void enableAutoDisplayRefresh();

		Tuple<int, int> ^ get3dGuiUpperLeftScreenCoordinates();

		String ^ getLanguage();
	};
} // namespace CwAPI3D_Net
