using System;
using System.Linq;

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

      return true;
    }

    public static void PrintElementNameToConsole(int elementId)
    {
      var name = _mControllerFactory.getAttributeController().getName(elementId);
      Console.WriteLine(name);
    }
  }
}
