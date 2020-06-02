using System;
using System.Collections.Generic;

namespace Program
{
    class Program
    {
        public static Tuple<int, int> FindTwoSum(IList<int> list, int target)
        {
            Dictionary<int, Tuple<int, int>> dic1 = new Dictionary<int, Tuple<int, int>>();
            for(int i=0; i< list.Count(); i++) {
                var x = list[i];
                for(int j=0; j< list.Count(); j++){
                    var y = list[j];
                    var sum = x + y;
                    if (sum == target && i != j) {
                        if (dic1.ContainsKey(sum)) {
                            return dic1[target];
                        } else {
                            return new Tuple<int, int>(i, j);
                        }
                    } else if (!dic1.ContainsKey(sum) && i != j) {
                        dic1.Add(sum, new Tuple<int, int>(i, j));
                    } 
                }          
            }
            return null;
        }
        
        public static Tuple<int, int> FindTwoSumFaster(IList<int> list, int sum)
        {
            if (list == null)
                return null;

            var listSet = new Dictionary<int, int>();
            int i = 0;
            // O(n)
            foreach (var elem in list)
            {
                if (listSet.Count > 0) {
                    var search = sum - elem;
                    if (listSet.ContainsKey(search)) {
                        var index = listSet[search];
                        if (i != index) {
                            return new Tuple<int, int>(i, index);
                        }
                    }
                }
                listSet[elem] = i++;
            }
            return null;
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
