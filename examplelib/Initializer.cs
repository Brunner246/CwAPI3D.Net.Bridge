using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace examplelib
{
  public class Initializer
  {
    private static CwAPI3D_CLI.ICwApi3DFactory _mControllerFactory;
    public static bool Initialize(IntPtr aFactoryPointer)
    {
      if (aFactoryPointer == IntPtr.Zero)
      {
        return false;
      }
      _mControllerFactory = new CwAPI3D_CLI.CwApi3DFactory(aFactoryPointer);

      var lActiveElementIds = _mControllerFactory.getElementController().getActiveIdentifiableElementIDs();

      lActiveElementIds?.ForEach(PrintElementNameToConsole);


      return true;
    }

    public static void PrintElementNameToConsole(int elementId)
    {
      var name = _mControllerFactory.getAttributeController().getName(elementId);
      Console.WriteLine(name);
    }
  }
}
