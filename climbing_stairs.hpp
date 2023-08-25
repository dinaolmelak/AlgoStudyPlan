#ifndef CLIMBING_STAIRS_HPP
#define CLIMBING_STAIRS_HPP
#include <unordered_map>
#include <iostream>
using namespace std;
/*
1 -> 1
2 -> 1 -> 1
       -> 2
------------------
3 -> 1 -> 1 -> 1
  -> 2 -> 1
  -> 1 -> 2

4 -> 1 -> 1 -> 1 -> 1
  -> 2 -> 1 -> 1
  -> 1 -> 2 -> 1
  -> 1 -> 1 -> 2
  -> 2 -> 2

5 -> 1 -> 1 -> 1 -> 1 -> 1
  -> 2 -> 1 -> 1 -> 1
  -> 1 -> 2 -> 1 -> 1
  -> 1 -> 1 -> 2 -> 1
  -> 2 -> 2 -> 1
  -> 1 -> 1 -> 1 -> 2
  -> 2 -> 1 -> 2
  -> 1 -> 2 -> 2


# Algorithm 
base:
 1 -> 1
 2 -> 2
   -> 1 -> 1

n -> cs(n-1) + cs(n-2)


*/
int climbStairsHelper(int n, unordered_map<int,int> &memo){
    if(n == 1){
    return 1;
    }else if(n == 2){
    return 2;
    }else if(memo.find(n) != memo.end()){
    return memo[n];
    }
    memo[n] = climbStairsHelper(n-1, memo) + climbStairsHelper(n-2, memo);
    return memo[n];
}
int climbStairs(int n) {
    unordered_map<int,int> memo;
    return  climbStairsHelper(n,memo);
}

#endif
