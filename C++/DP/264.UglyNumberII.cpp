/*
    Title:          264.UglyNumberII.cpp
    Update date:    2022/08/17
    Author:         Zhuofan Zhang
*/

/*
	Method1: Min-Heap
	Time: O(nlgn)
	Space: O(n)
*/
class Solution {
public:
    int nthUglyNumber(int n) 
    {
        priority_queue<long long, vector<long long>, greater<long long>> minHeap;
        long long currNumber = 1;
        int currN = 1;

        while(currN < n)
        {
            minHeap.push(currNumber*2);
            minHeap.push(currNumber*3);
            minHeap.push(currNumber*5);

            while(minHeap.top() <= currNumber)
                minHeap.pop();

            currNumber = minHeap.top();
            minHeap.pop();
            currN++;
        }

        return currNumber;
    }
};


/*
	Method2: Dynamic-Programming
	Time: O(n)
	Space: O(n)
*/
class Solution {
public:
    int nthUglyNumber(int n) 
    {
        vector<int> res(n+1);
        res[1] = 1;
        int p2 = 1, p3 = 1, p5 = 1;
        for(int i = 2; i <= n; ++i)
        {
            int mult2 = res[p2] * 2;
            int mult3 = res[p3] * 3;
            int mult5 = res[p5] * 5;

            res[i] = min(mult2, min(mult3, mult5));

            // check all of the 3: DON'T USE else-if
            if(res[i] == mult2)
                p2++;
            if(res[i] == mult3)
                p3++;
            if(res[i] == mult5)
                p5++;
        }

        return res.back();
    }
};

