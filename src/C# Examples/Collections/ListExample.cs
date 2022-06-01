
// https://docs.microsoft.com/en-us/dotnet/api/system.collections.generic.list-1?view=netcore-3.1
using System;
using System.Collections.Generic;
using System.Collections.ObjectModel;
using System.Diagnostics;
using System.Linq;

namespace CollectionsNamespace {
    public class ListExample {
        static void Main(string[] args) {
            List<Int32> intList = new List<Int32>(10);
            IEnumerable<int> intRange = Enumerable.Range(start: 1, count: 5); // {1, 2, 3, 4, 5}
            intList.AddRange(intRange);

            // Properties
            Console.WriteLine("Capacity = {0}", intList.Capacity);
            Console.WriteLine("Count = {0}", intList.Count);
            for (int i = 0; i < intList.Count; i++) { Console.Write("Item[{0}] = {1}, ", i, intList[i]); }
            Console.WriteLine();
            intList.Clear();
            
            // Methods
            intList.Add(item: 0); // {0}
            intList.AddRange(intRange); // {0, 1, 2, 3, 4, 5}
            
            ReadOnlyCollection<int> intListReadOnly = intList.AsReadOnly(); // {0, 1, 2, 3, 4, 5}
            
            intList.BinarySearch(item: 4); // 4
            intList.Clear();
            Debug.Assert (intList.Count == 0);
            intList.AddRange(Enumerable.Range(0, intList.Capacity)); // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
            
            Console.WriteLine("contains 5? {0}", intList.Contains(item: 5)); // true
            
            List<string> strList = intList.ConvertAll(converter: new Converter<int, string>(x => x.ToString())); // {"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}
            Console.Write("strList = ");
            foreach (string str in strList) { Console.Write("{0}, ", str); }
            Console.WriteLine();
            
            int[] intArray = new int[5];
            intList.CopyTo(index: 5, array: intArray, arrayIndex: 0, count: 5); // {5, 6, 7, 8, 9}
            foreach (int num in intArray) { Console.Write("{0}, ", num); }
            Console.WriteLine();
            intArray = new int[intList.Count];
            intList.CopyTo(intArray);
            Console.Write("intArray = ");
            foreach (int num in intArray) { Console.Write("{0}, ", num); } // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
            Console.WriteLine();
            intArray = new int[intList.Count + 5];
            intList.CopyTo(array: intArray, arrayIndex: 5);
            Console.Write("intArray = ");
            foreach (int num in intArray) { Console.Write("{0}, ", num); } // {0, 1, 2, 3, 4, 5, 6, 7, 8, 9}
            Console.WriteLine();

            List<int> intListClone = intList.Select(x => x).ToList();
            Debug.Assert(intList.Equals(obj: intListClone));
            
            Console.WriteLine("Even numbers exist? {0}", intList.Exists(match: new Predicate<int>(x => x % 2 == 0))); // true
            
            Console.WriteLine("Find first factor of 9 greater than 1 = {0}", intList.Find(match: new Predicate<int>(x => x > 1 ? 9 % x == 0 : false))); // 3
            Console.Write("Find all square numbers = ");
            List<int> squareList = intList.FindAll(match: new Predicate<int>(x => Math.Sqrt(d: (double) x) % 1 == 0)); // {1, 4, 9}
            foreach (int num in squareList) { Console.Write("{0}, ", num); }
            Console.WriteLine();

            intList.ForEach(action: new Action<int>(x => Console.Write("{0}, ", x >= 5 ? x : 0))); // {5, 6, 7, 8, 9}

            List<int> firstHalf = intList.GetRange(index: 0, count: intList.Count / 2);
            Console.Write("first half from GetRange = ");
            foreach (int num in firstHalf) { Console.Write("{0}, ", num); } // {0, 1, 2, 3, 4}
            Console.WriteLine();

            Type t = intList.GetType();
            Console.WriteLine("Type = {0}", t);
            
            intList.IndexOf(item: 4); // 4
            intList.IndexOf(item: 4, index: 0); // 4
            intList.IndexOf(item: 4, index: 5, count: 5); // -1

            intList.Remove(item: 9);
            intList.Insert(index: 2, item: 1000); // {0, 1, 1000, 2, 3, 4, 5, 6, 7, 8}
            Console.Write("intList = ");
            foreach (int num in intList) { Console.Write("{0}, ", num); } // {0, 1, 2, 3, 4}
            Console.WriteLine();

            intList.RemoveRange(index: 5, count: 5);
            intList.InsertRange(index: 5, collection: Enumerable.Range(start: 0, count: 5));
            Console.Write("intList = ");
            foreach (int num in intList) { Console.Write("{0}, ", num); } // {0, 1, 2, 3, 4, 0, 1, 2, 3, 4}
            Console.WriteLine();


            Console.WriteLine("index of 1 = {0}", intList.LastIndexOf(item: 1)); // 1
            Console.WriteLine("index of 1 since index 1 = {0}", intList.LastIndexOf(item: 1, index: 1)); // 1
            Console.WriteLine("index of 1 since index 1 for count of 5 = {0}", intList.LastIndexOf(item: 1, index: 1, count: 2)); // 1

            intList.Remove(item: 4); // {0, 1, 2, 3, 0, 1, 2, 3, 4}
            intList.RemoveAll(match: new Predicate<int>(x => x % 2 == 0)); // {1, 3, 1, 3}
            Console.Write("intList = ");
            foreach (int num in intList) { Console.Write("{0}, ", num); } // {0, 1, 2, 3, 4, 0, 1, 2, 3, 4}
            Console.WriteLine();

            intList.Reverse(); // {3, 1, 3, 1}
            Console.Write("Reversed intList = ");
            foreach (int num in intList) { Console.Write("{0}, ", num); } // {0, 1, 2, 3, 4, 0, 1, 2, 3, 4}
            Console.WriteLine();
            intList.Reverse(index: 1, count: 2); // {3, 3, 1, 1}
            Console.Write("Partly reversed intList = ");
            foreach (int num in intList) { Console.Write("{0}, ", num); } // {0, 1, 2, 3, 4, 0, 1, 2, 3, 4}
            Console.WriteLine();

            intList.Sort(); // {1, 1, 3, 3}
            Console.Write("Sorted intList = ");
            foreach (int num in intList) { Console.Write("{0}, ", num); } // {0, 1, 2, 3, 4, 0, 1, 2, 3, 4}
            Console.WriteLine();

            intList.TrimExcess();
            Console.WriteLine("Trimmed capacity = {0}", intList.Capacity);

            Console.WriteLine("All elements are nonnegative? {0}", intList.TrueForAll(match: new Predicate<int>(x => x >= 0)));

        }
    }
}