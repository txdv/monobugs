using System;
using System.Collections.Generic;
using System.Runtime.InteropServices;

unsafe public class MainApp
{

  public struct strarray
  {
    public sbyte **strarr;
    public int length;
  }

  [DllImport("test")]
  public static extern void outfunction(strarray *arr);

  [DllImport("test")]
  public static extern void strarray_free(strarray *arr);

  public static string[] marshalled_outfunction()
  {
    strarray arr;
    outfunction(&arr);
    string[] list = new string[arr.length];
    for (int i = 0; i < arr.length; i++) {
      list[i] = new string(arr.strarr[i]);
    }
    strarray_free(&arr);
    return list;
  }

  public static void Main(string[] args)
  {
    var list = marshalled_outfunction();
    foreach (string element in list) {
      Console.WriteLine(element);
    }
  }
}
