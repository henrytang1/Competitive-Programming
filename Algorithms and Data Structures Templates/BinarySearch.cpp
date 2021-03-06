#include <bits/stdc++.h>
using namespace std;
typedef pair <int,int> pii;

int n; //number of elements in list
pii lists[105]; //elements are from 1 to 100
vector <int> arr;

//Time Complexity: O(logn)
int binarySearch(int key){
    int l=0, r=arr.size(); //r must be initialized to larger than the maximum index
    int m;
    while(r-l>1){
        m = l+(r-l)/2; //prevents overflow
        arr[m] <= key ? l=m : r=m;
    }
    if(arr[l] == key) return l;
    //if the key doesn't exist, l will point to the index
    //of the first element smaller than key unless key < arr[0]
    return -1;
}

//Time Complexity: O(logn)
int binarySearchLow(int key){
    int l = 0, r = arr.size();
    int m;
    while (l < r){
        m = (l+r)/2;
        if (arr[m] < key){
            l = m+1;
        } else {
            r = m;
        }
    }
    //if the key exists, returns the lowest occurrence of the key
    //if the key doesn't exist, returns the index
    //of the first element bigger than key
    return l;
}

//Time Complexity: O(logn)
int binarySearchHigh(int key){
    int l = 0, r = arr.size();
    int m;
    while (l < r){
        m = (l+r)/2;
        if (arr[m] <= key){
            l = m+1;
        } else {
            r = m;
        }
    }
    //if the key exists, returns the highest occurrence of the key
    //if the key doesn't exist, returns the index
    //of the first element smaller than key
    return l-1;
}

//Finds first element b such that condition is true
bool cmp1(int a, pii b){
    return a < b.second;
}

bool cmp2(int a, pii b){
    return a <= b.second;
}

//Time Complexity: O(logn)
void arrSearch(int k){ //k represents element with index k
    //returns index of first element with second value <= list[k].first
    int a = upper_bound(lists+1, lists+n+1, lists[k].first, cmp1)-lists-1;
    //returns index of first element with second value < list[k].first
    int b = upper_bound(lists+1, lists+n+1, lists[k].first, cmp2)-lists-1;
}
