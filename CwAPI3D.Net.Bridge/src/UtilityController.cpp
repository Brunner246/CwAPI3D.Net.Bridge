#include "UtilityController.h"
#include <stdexcept>
#include <msclr/marshal_cppstd.h>

#include "vector3D.h"
#include "windowGeometry.h"

CwAPI3D::Net::Bridge::UtilityController::UtilityController(System::IntPtr aFactoryPtr)
{
	if(aFactoryPtr == System::IntPtr::Zero)
	{
		throw std::invalid_argument("ControllerFactory pointer is null");
	}
	const auto lControllerFactory = static_cast<CwAPI3D::ControllerFactory*>(aFactoryPtr.ToPointer());
	if(!lControllerFactory)
	{
		throw std::invalid_argument("ControllerFactory pointer is null");
	}
	mUtilityController = lControllerFactory->getUtilityController();
}

CwAPI3D::Net::Bridge::UtilityController::~UtilityController()
{
	this->!UtilityController();
}

CwAPI3D::Net::Bridge::UtilityController::!UtilityController() { }

System::String ^ CwAPI3D::Net::Bridge::UtilityController::getPluginPath()
{
	const auto lPath = mUtilityController->getPluginPath();
	return gcnew System::String(lPath->data());
}

bool CwAPI3D::Net::Bridge::UtilityController::getUseOfGlobalCoordinates()
{
	return mUtilityController->getUseOfGlobalCoordinates();
}

CwAPI3D::Net::Bridge::vector3D ^ CwAPI3D::Net::Bridge::UtilityController::getGlobalOrigin()
{
	const auto [mX, mY, mZ] = mUtilityController->getGlobalOrigin();
	return gcnew vector3D(mX, mY, mZ);
}

System::String ^ CwAPI3D::Net::Bridge::UtilityController::createSnapshot(System::String ^ aFormat, const int aQuality, const bool aWhiteBackground)
{
	const std::wstring lNativeString = msclr::interop::marshal_as<std::wstring>(aFormat);
	const auto lSnapshot = mUtilityController->createSnapshot(lNativeString.c_str(), aQuality, aWhiteBackground);
	return gcnew System::String(lSnapshot->data());
}

void CwAPI3D::Net::Bridge::UtilityController::disableAutoDisplayRefresh()
{
	mUtilityController->disableAutoDisplayRefresh();
}

void CwAPI3D::Net::Bridge::UtilityController::enableAutoDisplayRefresh()
{
	mUtilityController->enableAutoDisplayRefresh();
}

CwAPI3D::Net::Bridge::windowGeometry ^ CwAPI3D::Net::Bridge::UtilityController::get3dMainWindowGeometry()
{
	const auto [mBottomLeft, mBottomRight, mTopLeft, mTopRight] = mUtilityController->get3dMainWindowGeometry();
	auto lWindowGeometryWrapper = gcnew CwAPI3D::Net::Bridge::windowGeometry();
	lWindowGeometryWrapper->BottomLeft = gcnew CwAPI3D::Net::Bridge::windowGeometry::point(mBottomLeft.mX, mBottomLeft.mY);
	lWindowGeometryWrapper->BottomRight = gcnew CwAPI3D::Net::Bridge::windowGeometry::point(mBottomRight.mX, mBottomRight.mY);
	lWindowGeometryWrapper->TopLeft = gcnew CwAPI3D::Net::Bridge::windowGeometry::point(mTopLeft.mX, mTopLeft.mY);
	lWindowGeometryWrapper->TopRight = gcnew CwAPI3D::Net::Bridge::windowGeometry::point(mTopRight.mX, mTopRight.mY);
	return lWindowGeometryWrapper;
}

System::String ^ CwAPI3D::Net::Bridge::UtilityController::getLanguage()
{
	const auto lLanguageString = mUtilityController->getLanguage();
	return gcnew System::String(lLanguageString->data());
}
