
using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

namespace ThreadingNamespace {
    public class ThreadingExample {
        public static void Range(int start, int end, uint step = 1) {
            // Error checking
            try { if (start >= end) { throw new ArgumentException("start must be less than end"); } }
            catch (ArgumentException error) { Console.WriteLine("{0}: {1}", error.GetType().Name, error.Message); }
            for (int i = start; i < end; i += (int)step) { Console.Write("{0}, ", i); }
            Console.WriteLine();
        }
        static void Main(string[] args) {
            //CONSTRUCTORS
            Thread thread = new Thread(() => {
                foreach (int num in Enumerable.Range(start: 40, count: 20)) { Console.Write("{0}, ", num); }
            });

            thread.Start();
            
            thread = new Thread(new ThreadStart);
            // PROPERTIES
            Thread mt = Thread.CurrentThread;
            mt.Name = "MainThread";
            Console.WriteLine("Main thread name = {0}", mt.Name);

        }
    }

    class Employee {
        // MEMBER VARIABLES
        private static List<ulong> employeeID;
        private string firstName;
        private string lastName;
        private uint age;
        private ulong id;
        
        // MEMBER FUNCTIONS
        // CONSTRUCTORS
        public Employee(string firstName, string lastName, uint age, ulong id) {
            // Error checking
            try {
                if (firstName.Length == 0) { throw new ArgumentException("firstName cannot be empty"); }
                if (lastName.Length == 0) { throw new ArgumentException("lastName cannot be empty"); }
                if (Employee.employeeID.Exists(el => el == id;)) { throw new ArgumentException("id is not unique"); }
            } catch (ArgumentException error) { Console.WriteLine("{0}: {1}", error.GetType().Name, error.Message); }
            
            this.firstName = firstName;
            this.lastName = lastName;
        }
        
        // ACCESSORS
        public static void Work() { Console.WriteLine("Employees are working..."); }

        public void GetInfo() {
            Console.WriteLine("First Name: {0}", this.firstName);
            Console.WriteLine("Last Name: {0}", this.lastName);
            Console.WriteLine("age: {0}", this.age);
            Console.WriteLine("id: {0}", this.id);
        }

    }
}