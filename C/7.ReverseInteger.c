/*
    Title:          7.ReverseInteger.c
    Update date:    2019/10/01
    Author:         Zhuofan Zhang
    Attention:      Be attention to the input range: [-2^31,2^31-1]
*/
int reverse(int x)
{
    if(x == INT_MIN)return 0;
    
    bool IsMinus = false;
    if(x<0)
    {
        IsMinus = true;
        x = -x;
    }
    int64_t res = 0;
    while(x>0)
    {
        res = res*10 + x%10;
        x /= 10;
    }
    
    if(res > INT_MAX)return 0;
    
    return (IsMinus)?(-res):res;
}