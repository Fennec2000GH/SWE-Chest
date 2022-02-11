// URLify: Write a method to replace all spaces in a string with '%20'. You may assume that the string
// has sufficient space at the end to hold the additional characters, and that you are given the "true"
// length of the string. (Note: If implementing in Java, please use a character array so that you can
// perform this operation in place.)
using System;
using System.Collections.Generic;

class Program {
    public static void Main(string[] args) {
        string s = Console.ReadLine();
        char[] arr = new char[s.Length * 2];
        uint offset = 0;
        for(int i = 0; i < s.Length; i++) {
            arr[i] = s[i];
            if (s[i] == ' ') {
                offset += 2;
            }
        }

        // Debugging
        Console.WriteLine(arr);

        uint j = (uint)s.Length + offset - 1; 
        while(offset > 0) {
            uint idx = j - offset;
            Console.WriteLine($"{idx} -> {j}");
            if (arr[idx] == ' ') {
                arr[j] = '0';
                arr[j - 1] = '2';
                arr[j - 2] = '%';
                offset -= 2;
                j -= 3;
                Console.WriteLine("%20");
                continue;
            }
            arr[j] = arr[idx];
            Console.WriteLine(arr[j]);
            j--;
        }

        Console.WriteLine(arr);
    }
}
