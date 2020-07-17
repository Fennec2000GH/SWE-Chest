
// https://www.tutorialspoint.com/csharp/csharp_regular_expressions.htm
using System.Text.RegularExpressions;
using System;

namespace RegExApplication {
    class Program {
        private static void showMatch(string text, string expr) {
            Console.WriteLine("The Expression: " + expr);
            MatchCollection mc = Regex.Matches(text, expr);

            foreach (Match m in mc) { Console.WriteLine(m); }
        }

        static void Main(string[] args) {
            string str = "A Thousand Splendid Suns";
            Console.WriteLine("Matching words that start with 'S': ");
            showMatch(str, @"\bS\S");
            Console.ReadKey();
        }
    }
}
