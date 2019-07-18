using System;
using System.Collections.Generic;

namespace Chammpion_c_
{
    public class Champion
    {
        //properties
        public int Health;
        public int Mana;
        string Name;
        //constructor
        public Champion(string name, int health, int mana)
        {
            this.Name = name;
            this.Health = health;
            this.Mana = mana;
        }
    }


    class Program
    {
        
        public static void Swap(ref int a, ref int b)
        {
            int temp = a;
            a = b;
            b = temp;
        }

        public static void Swap<T> (ref T a, ref T b)
        {
            T temp = a;
            a = b;
            b = temp;
        }

        public delegate void someMethodPointer();

        static void Main(string[] args)
        {

            int a = int.Parse(Console.ReadLine());
            int b = int.Parse(Console.ReadLine());
            Swap(ref a, ref b);
            Console.WriteLine(a);
            Console.WriteLine(b);

            someMethodPointer obj = new someMethodPointer(someMeThod);
            obj.Invoke();
            Console.WriteLine("Hello World!");
        }

        public static void someMeThod()
        {
            Console.WriteLine("Alooooo");
        }
    }
}
