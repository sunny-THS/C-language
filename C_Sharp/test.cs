using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace HelloWorld
{
  class Program
  {
    static void Main(string[] args)
    {
      String str = "animal";
      String toFind = "aal";
      int index = str.IndexOf(toFind);
      Console.WriteLine("Found '{0}' in '{1}' at position {2}", toFind, str, index);
      Console.ReadKey();
    }
  }
}
