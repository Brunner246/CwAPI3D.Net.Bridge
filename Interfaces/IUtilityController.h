#pragma once

namespace CwAPI3D::Net::Bridge
{
	ref class vector3D;
public
	interface class IUtilityController
	{
		System::String ^ getPluginPath();

		bool getUseOfGlobalCoordinates();

		vector3D ^ getGlobalOrigin();

		System::String ^ createSnapshot(System::String ^ aFormat, int aQuality, bool aWhiteBackground);

		void disableAutoDisplayRefresh();

		void enableAutoDisplayRefresh();

		System::Tuple<int, int> ^ get3dGuiUpperLeftScreenCoordinates();

		System::String ^ getLanguage();
	};
} // namespace CwAPI3D_Net
