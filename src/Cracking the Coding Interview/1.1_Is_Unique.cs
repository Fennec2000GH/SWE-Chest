// URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
// has sufficient space at the end to hold the additional characters, and that you are given the "true"
// length of the string. (Note: If implementing in Java, please use a character array so that you can
// perform this operation in place.) 
using System.Collections.Generic;

class Program {
    public static void Main(string[] args) {
        string s = Console.ReadLine();
        int unique_count = (new HashSet<char>(s.ToCharArray())).Count;
        Console.WriteLine($"unique_count = {unique_count}");
        Console.WriteLine(s.Length == unique_count);
    }
}
