class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        // Method1: Simple Algorithm(19.12%,77.32%)
        // int Most_Water = 0;
        // int Now_Max_Height = 0;
        // for(size_t x = 0;x<height.size();++x)
        // {
        //     if(height[x] < Now_Max_Height)
        //         continue;
        //     else if(height[x] > Now_Max_Height)
        //         Now_Max_Height = height[x];
            
        //     for(size_t y = x+1;y<height.size();++y)
        //     {
        //         int max_height = height[x] < height[y] ? height[x] : height[y];
        //         int Water = max_height * (y-x);
        //         if(Water > Most_Water)
        //             Most_Water = Water;
        //     }
        // }
             
        // return Most_Water;
        
        // Method2:Two Pointers Algorithm(95.45%,68.04%)
        int Most_Water = 0;
        size_t p=0,q=height.size()-1;
        while(p<q)
        {
            size_t Min_height_idx; 
            if(height[p] < height[q])
                Min_height_idx = p++; 
            else
                Min_height_idx = q--;
            
            int Water = height[Min_height_idx]*(q-p+1);
            if(Water > Most_Water)
                Most_Water = Water;
        }
        
        return Most_Water;
    }
};