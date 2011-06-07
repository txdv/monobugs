using System;
using System.Reflection;
using System.Diagnostics;

public class Test
{
  public static void Main(string[] args)
  {
    Console.WriteLine("(AppDomain.CurrentDomain.BaseDirectory == null) == {0}", AppDomain.CurrentDomain.BaseDirectory == null);
  }
}
