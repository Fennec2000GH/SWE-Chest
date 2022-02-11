// Check Permutation: Given two strings, write a method to decide if one is a permutation of the other
using System;
using System.Linq;

class Program {
    public static void Main() {
        string s_1 = Console.ReadLine();
        string s_2 = Console.ReadLine();
        Console.WriteLine(String.Concat(s_1.OrderBy(x => x)));
        Console.WriteLine(String.Concat(s_2.OrderBy(x => x)));
        Console.WriteLine(String.Concat(s_1.OrderBy(x => x)) == String.Concat(s_2.OrderBy(x => x)));
    }
}
