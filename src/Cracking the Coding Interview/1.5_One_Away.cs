// One Away: There are three types of edits that can be performed on strings: insert a character,
// remove a character, or replace a character. Given two strings, write a function to check if they are
// one edit (or zero edits) away. 
using System;
using System.Collections.Generic;

class Program {
    public static void Main(string[] args) {
        string s_1 = Console.ReadLine();
        string s_2 = Console.ReadLine();
        List<List<uint>> matrix = new List<List<uint>>();
        for(int i = 0; i < s_1.Length + 1; i++) {
            List<uint> row = new List<uint>();
            for(int j = 0; j < s_2.Length + 1; j++) {
                row[j] = 0;
            }
            matrix.Add(row);
        }

        // debugging
        Console.WriteLine($"num rows = {matrix.Count}");
        Console.WriteLine($"num cols = {matrix[0].Count}");
        Console.WriteLine(matrix);

    }
}