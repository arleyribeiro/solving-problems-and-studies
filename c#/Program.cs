using System;
using System.Collections.Generic;

namespace Program
{
    class Program
    {
        public static Tuple<int, int> FindTwoSum(IList<int> list, int target)
        {
            Dictionary<int, List<Tuple<int, int>>> dic1 = new Dictionary<int, List<Tuple<int, int>>>();
            int i = 0;
            foreach(var x in list) {
                int j = 0;
                foreach(var y in list){
                    var sum = x + y;
                    var tuples = dic1.GetValueOrDefault(sum);
                    if (tuples == null) {
                        dic1.Add(sum, new List<Tuple<int, int>> { new Tuple<int, int>(i, j), new Tuple<int, int>(j, i) });
                    } else {
                        tuples.Add(new Tuple<int, int>(i, j));
                        tuples.Add(new Tuple<int, int>(j, i));
                        dic1[sum] = tuples;
                    }
                    j++;
                }          
                i++;
            }
            var valores = dic1.GetValueOrDefault(target);
            if (valores == null) {
                return null;
            } else {
                return valores[0];
            }
        }
        static void Main(string[] args)
        {          
            var list = new List<int>() { 3, 1, 5, 7, 5, 9, 4, 8,3,47,85,9,6,25,96,9,332,7,89,62,74,1,78,3,9,3,4,9, 4,6,12,13,11,18,90 };
            foreach(var x in list) {
                var item = FindTwoSum(new List<int>() { 3, 1, 5, 7, 5, 9, 4, 8,3,47,85,9,6,25,96,9,332,7,89,62,74,1,78,3,9,3,4,9 }, x);
                if (item == null) {
                    Console.WriteLine("Não existe");

                } else {
                    Console.WriteLine("chave: ({0}, {1}), soma {2}", item.Item1, item.Item2, x);
                }
            }
        }
    }
}
