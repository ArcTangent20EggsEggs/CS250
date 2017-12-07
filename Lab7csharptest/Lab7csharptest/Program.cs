using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab7csharptest
{
    class Program
    {
        static void Main(string[] args)
        {
            int n = 0;
            for (int x = 0; x < 10; x++)
            {
                for (int y = x + 1; y < 10; y++)
                {
                    for (int z = y + 1; z < 10; z++)
                    {
                        n++;
                    }
                    if (y + 1 >= 10)
                    {
                        n++;
                    }
                }
                if (x + 1 >= 10)
                {
                    n++;
                }
            }
            Console.WriteLine(n);
        }
    }
}
