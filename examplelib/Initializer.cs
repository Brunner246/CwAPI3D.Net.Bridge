using System;
using System.Linq;
using CwAPI3D.Net.Bridge;

namespace examplelib
{

  public delegate void OnSomeOperation(String aString);
  public class Initializer
  {
    private static CwAPI3D.Net.Bridge.ICwApi3DFactory _mControllerFactory;
    public static bool Initialize(IntPtr aFactoryPointer)
    {
      if (aFactoryPointer == IntPtr.Zero)
      {
        return false;
      }
      _mControllerFactory = new CwAPI3D.Net.Bridge.CwApi3DFactory(aFactoryPointer);

      var lActiveElementIds = _mControllerFactory.getElementController().getActiveIdentifiableElementIDs();
      if (lActiveElementIds == null)
      {
        return false;
      }

      lActiveElementIds.ForEach(PrintElementNameToConsole);

      Action<string> action = name =>
      {
        string greeting = $"Hello, {name}!";
        Console.WriteLine(greeting);
      };
      action(lActiveElementIds.Any() ?
        _mControllerFactory.getAttributeController().getName(lActiveElementIds[0])
        : "World");

      OnSomeOperation handler = (String aString) => { Console.WriteLine(aString); };
      handler("delegate method");

      Func<int, int, bool> function = (a, b) => a > b;
      Console.WriteLine(function(1, 2));

      var lStartPoint = new vector3D(0, 0, 0);
      var lEndPoint = new vector3D(1000, 0, 0);
      var lHeightPoint = new vector3D(0, 0, 1);
      double lWidth = 120.0;
      double lHeight = 240.0;

      _mControllerFactory.getElementController().createRectangularBeamPoints(lWidth, lHeight,
                                                                                  lStartPoint,
                                                                                  lEndPoint,
                                                                                  lHeightPoint);


      return true;
    }

    public static void PrintElementNameToConsole(ulong elementId)
    {
      var name = _mControllerFactory.getAttributeController().getName(elementId);
      Console.WriteLine(name);
    }
  }
}
