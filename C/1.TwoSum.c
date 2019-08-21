/*
    Title:          1.TwoSum.c
    Update date:    2019/08/21
    Author:         Zhuofan Zhang
    Latest Method:  Use Hash(uthash package)
*/

/*
 * Note: The returned array must be malloced, assume caller calls free().
 */



/* Method1: */

// int* twoSum(int* nums, int numsSize, int target,int *returnSize)
// {
//     int *result = (int *)malloc(sizeof(int)*2);
//     *returnSize = 2;
//     result[0]=result[1]=0;
//     for(int i=0;i < numsSize;++i)
//     {
//         int temp = target - nums[i];
//         for(int j=i+1;j < numsSize;++j)
//             if(nums[j]==temp)
//             {
//                 result[0]=i;
//                 result[1]=j;
//                 return result;
//             }
//     }
    
//     return result;
// }

/* Method2: */
struct hmap
{
    int id;
    int index;
    UT_hash_handle hh;
};


int* twoSum(int* nums, int numsSize, int target,int *returnSize)
{
    *returnSize = 2;
    int *result = (int *)malloc(sizeof(int)*2);
    struct hmap *users = NULL;
    
    for(int i=0;i < numsSize;++i)
    {
        struct hmap *s;
        HASH_FIND_INT( users, &(nums[i]), s);
        if(s!=NULL)
        {
            result[0]=s->index;
            result[1]=i;
            return result;
        }
        struct hmap *add = malloc(sizeof(struct hmap));
        add->id = target-nums[i];
        add->index = i;
        HASH_ADD_INT( users, id, add );
    }
    
    return result;
}
