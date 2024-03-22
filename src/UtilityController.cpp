#include "UtilityController.h"
#include <stdexcept>
#include <msclr/marshal_cppstd.h>

CwAPI3D_CLI::UtilityController::UtilityController(System::IntPtr aFactoryPtr)
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

CwAPI3D_CLI::UtilityController::~UtilityController()
{
	this->!UtilityController();
}

CwAPI3D_CLI::UtilityController::!UtilityController() { }

String ^ CwAPI3D_CLI::UtilityController::getPluginPath()
{
	const auto lPath = mUtilityController->getPluginPath();
	return gcnew String(lPath->data());
}

bool CwAPI3D_CLI::UtilityController::getUseOfGlobalCoordinates()
{
	return mUtilityController->getUseOfGlobalCoordinates();
}

CwAPI3D_CLI::vector3D ^ CwAPI3D_CLI::UtilityController::getGlobalOrigin()
{
	const auto [mX, mY, mZ] = mUtilityController->getGlobalOrigin();
	return gcnew vector3D(mX, mY, mZ);
}

String ^ CwAPI3D_CLI::UtilityController::createSnapshot(String ^ aFormat, int aQuality, bool aWhiteBackground)
{
	const std::wstring lNativeString = msclr::interop::marshal_as<std::wstring>(aFormat);
	const auto lSnapshot = mUtilityController->createSnapshot(lNativeString.c_str(), aQuality, aWhiteBackground);
	return gcnew String(lSnapshot->data());
}

void CwAPI3D_CLI::UtilityController::disableAutoDisplayRefresh()
{
	mUtilityController->disableAutoDisplayRefresh();
}

void CwAPI3D_CLI::UtilityController::enableAutoDisplayRefresh()
{
	mUtilityController->enableAutoDisplayRefresh();
}

Tuple<int, int> ^ CwAPI3D_CLI::UtilityController::get3dGuiUpperLeftScreenCoordinates()
{
	const auto [mX, mY] = mUtilityController->get3dGuiUpperLeftScreenCoordinates();
	return gcnew Tuple<int, int>(static_cast<int>(mX), static_cast<int>(mY));
}

String ^ CwAPI3D_CLI::UtilityController::getLanguage()
{
	const auto lLanguageString = mUtilityController->getLanguage();
	return gcnew String(lLanguageString->data());
}
