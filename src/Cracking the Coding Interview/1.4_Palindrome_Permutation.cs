// Palindrome Permutation: Given a string, write a function to check if it is a permutation of a palindrome. A palindrome is a word or phrase that is the same forwards and backwards. A permutation
// is a rearrangement of letters. The palindrome does not need to be limited to just dictionary words. 
using System;
using System.Linq;

class Program {
    public static void Main(string[] args) {
        string s = Console.ReadLine();
        uint[] alphabet = new uint[26];

        // debug
        Console.WriteLine(s);
        s.ToLower().ToCharArray().Select(x => (uint)x - 97).ToList().ForEach(x => {
            if (x < 26) {
                alphabet[x]++;
            }
        });

        alphabet.ToList().ForEach(x => Console.WriteLine(x));
        uint num_odds = (uint)alphabet.ToList().FindAll(x => x % 2 == 1).Count;

        Console.WriteLine(num_odds);
        Console.WriteLine(num_odds <= 1);
    }
}
