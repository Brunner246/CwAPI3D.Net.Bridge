#include "IfcTypeMapper.h"

#include <stdexcept>

CwAPI3D_Net::EBimIfcType CwAPI3D_Net::Utils::mapIfcType(CwAPI3D::Interfaces::ICwAPI3DIfc2x3ElementType* aIfcType)
{
	if(aIfcType->isNone())
	{
		return EBimIfcType::none;
	}
	if(aIfcType->isIfcBeam())
	{
		return EBimIfcType::ifcBeam;
	}
	if(aIfcType->isIfcColumn())
	{
		return EBimIfcType::ifcColumn;
	}
	if(aIfcType->isIfcCurtainWall())
	{
		return EBimIfcType::ifcCurtainWall;
	}
	if(aIfcType->isIfcDoor())
	{
		return EBimIfcType::ifcDoor;
	}
	if(aIfcType->isIfcMember())
	{
		return EBimIfcType::ifcMember;
	}
	if(aIfcType->isIfcPlate())
	{
		return EBimIfcType::ifcPlate;
	}
	if(aIfcType->isIfcRailing())
	{
		return EBimIfcType::ifcRailing;
	}
	if(aIfcType->isIfcRamp())
	{
		return EBimIfcType::ifcRamp;
	}
	if(aIfcType->isIfcRampFlight())
	{
		return EBimIfcType::ifcRampFlight;
	}
	if(aIfcType->isIfcRoof())
	{
		return EBimIfcType::ifcRoof;
	}
	if(aIfcType->isIfcSlab())
	{
		return EBimIfcType::ifcSlab;
	}
	if(aIfcType->isIfcStair())
	{
		return EBimIfcType::ifcStair;
	}
	if(aIfcType->isIfcStairFlight())
	{
		return EBimIfcType::ifcStairFlight;
	}
	if(aIfcType->isIfcWall())
	{
		return EBimIfcType::ifcWall;
	}
	if(aIfcType->isIfcWallStandardCase())
	{
		return EBimIfcType::ifcWallStandardCase;
	}
	if(aIfcType->isIfcWindow())
	{
		return EBimIfcType::ifcWindow;
	}
	if(aIfcType->isIfcBuildingElementProxy())
	{
		return EBimIfcType::ifcBuildingElementProxy;
	}
	if(aIfcType->isIfcChimney())
	{
		return EBimIfcType::ifcChimney;
	}
	if(aIfcType->isIfcCovering())
	{
		return EBimIfcType::ifcCovering;
	}
	if(aIfcType->isIfcFooting())
	{
		return EBimIfcType::ifcFooting;
	}
	if(aIfcType->isIfcFurnishingElement())
	{
		return EBimIfcType::ifcFurnishingElement;
	}
	if(aIfcType->isIfcOpeningElement())
	{
		return EBimIfcType::ifcOpeningElement;
	}
	if(aIfcType->isIfcSpace())
	{
		return EBimIfcType::ifcSpace;
	}
	if(aIfcType->isIfcFlowSegment())
	{
		return EBimIfcType::ifcFlowSegment;
	}
	if(aIfcType->isIfcBuildingElementPart())
	{
		return EBimIfcType::ifcBuildingElementPart;
	}
	if(aIfcType->isIfcDiscreteAccessory())
	{
		return EBimIfcType::ifcDiscreteAccessory;
	}
	if(aIfcType->isIfcFastener())
	{
		return EBimIfcType::ifcFastener;
	}
	if(aIfcType->isIfcMechanicalFastener())
	{
		return EBimIfcType::ifcMechanicalFastener;
	}
	// throw std::runtime_error("Unknown IFC type");
	return EBimIfcType::none;
}
