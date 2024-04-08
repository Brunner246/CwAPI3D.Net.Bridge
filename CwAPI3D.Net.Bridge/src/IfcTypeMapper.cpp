#include "IfcTypeMapper.h"

#include <stdexcept>

CwAPI3D::Net::Bridge::EBimIfcType CwAPI3D_Net::Utils::mapIfcType(CwAPI3D::Interfaces::ICwAPI3DIfc2x3ElementType* aIfcType)
{
	if(aIfcType->isNone())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::none;
	}
	if(aIfcType->isIfcBeam())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcBeam;
	}
	if(aIfcType->isIfcColumn())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcColumn;
	}
	if(aIfcType->isIfcCurtainWall())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcCurtainWall;
	}
	if(aIfcType->isIfcDoor())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcDoor;
	}
	if(aIfcType->isIfcMember())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcMember;
	}
	if(aIfcType->isIfcPlate())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcPlate;
	}
	if(aIfcType->isIfcRailing())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcRailing;
	}
	if(aIfcType->isIfcRamp())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcRamp;
	}
	if(aIfcType->isIfcRampFlight())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcRampFlight;
	}
	if(aIfcType->isIfcRoof())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcRoof;
	}
	if(aIfcType->isIfcSlab())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcSlab;
	}
	if(aIfcType->isIfcStair())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcStair;
	}
	if(aIfcType->isIfcStairFlight())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcStairFlight;
	}
	if(aIfcType->isIfcWall())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcWall;
	}
	if(aIfcType->isIfcWallStandardCase())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcWallStandardCase;
	}
	if(aIfcType->isIfcWindow())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcWindow;
	}
	if(aIfcType->isIfcBuildingElementProxy())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcBuildingElementProxy;
	}
	if(aIfcType->isIfcChimney())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcChimney;
	}
	if(aIfcType->isIfcCovering())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcCovering;
	}
	if(aIfcType->isIfcFooting())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcFooting;
	}
	if(aIfcType->isIfcFurnishingElement())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcFurnishingElement;
	}
	if(aIfcType->isIfcOpeningElement())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcOpeningElement;
	}
	if(aIfcType->isIfcSpace())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcSpace;
	}
	if(aIfcType->isIfcFlowSegment())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcFlowSegment;
	}
	if(aIfcType->isIfcBuildingElementPart())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcBuildingElementPart;
	}
	if(aIfcType->isIfcDiscreteAccessory())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcDiscreteAccessory;
	}
	if(aIfcType->isIfcFastener())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcFastener;
	}
	if(aIfcType->isIfcMechanicalFastener())
	{
		return CwAPI3D::Net::Bridge::EBimIfcType::ifcMechanicalFastener;
	}
	// throw std::runtime_error("Unknown IFC type");
	return CwAPI3D::Net::Bridge::EBimIfcType::none;
}
