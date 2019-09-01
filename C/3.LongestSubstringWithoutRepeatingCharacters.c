/*
    Title:          3.LongestSubstringWithoutRepeatingCharacters.c
    Update date:    2019/09/01
    Author:         Zhuofan Zhang
    Latest Method:  Use Bool-Bucket
*/


// Method1: utHash
// struct hmap
// {
//     char name[2];
//     int id;
//     int index;
//     UT_hash_handle hh;
// };

// int lengthOfLongestSubstring(char * s)
// {
//     if(s[0]=='\0')return 0;
//     struct hmap *users = NULL;
//     size_t Longest_len = 1;
//     size_t start_idx = 0;
//     size_t i=0;
//     for(; s[i] ;++i)
//     {
//         struct hmap *duplicate;
//         char str[2] = {0};
//         str[0] = s[i];
//         HASH_FIND_STR( users, str, duplicate );
        
//         if(duplicate)
//         {
//             Longest_len = ((i-start_idx) > Longest_len?(i-start_idx):Longest_len);
//             struct hmap *del_temp;
//             for(size_t j=start_idx;j<(duplicate->index);++j)
//             {   
//                 char del_str[2] = {0};
//                 del_str[0]=s[j];
//                 HASH_FIND_STR( users, del_str , del_temp );
//                 HASH_DEL(users,del_temp);
//                 free(del_temp);
//             }
//             start_idx = (duplicate->index)+1;
//             // Clear the HASH_TABLE
//             HASH_DEL(users,duplicate);
//             free(duplicate);

//         }

//         struct hmap *add = malloc(sizeof(struct hmap));
//         strcpy(add->name,str);
//         add->index = i;
//         HASH_ADD_STR( users, name, add );
        
//     }
//     struct hmap *current_user, *tmp;
//     HASH_ITER(hh, users, current_user, tmp)
//     {
//         HASH_DEL(users,current_user);  /* delete; users advances to next */
//         free(current_user);            /* optional- if you want to free  */
//     }
    
//     Longest_len = ((i-start_idx) > Longest_len?(i-start_idx):Longest_len);
//     return Longest_len;
    
// }



// Method2: Normal Method
// int lengthOfLongestSubstring(char * s)
// {
//     if(s[0]=='\0')return 0;
//     size_t start_idx = 0;
//     size_t Longest_len = 1;
//     size_t i=0;
//     for(;s[i];++i)
//     {   
//         size_t j=start_idx;
//         for(;j<i;++j)
//             if(s[j]==s[i])break;
//         if(j<i)
//         {
//             Longest_len = (Longest_len > (i-start_idx)?Longest_len:(i-start_idx));
//             start_idx = j+1;
//         }
        
//     }
    
//     return (Longest_len > (i-start_idx)?Longest_len:(i-start_idx));
// }

// Method3: Bool-Bucket
int lengthOfLongestSubstring(char * s)
{
    if(s[0]=='\0')return 0;
    bool Char_Bucket[128] = {0};
    size_t Longest_len = 1;
    size_t start_idx = 0;
    size_t alpha_idx = 0;
    size_t i=0;
    for(;s[i];++i)
    {
        alpha_idx = s[i];
        if(Char_Bucket[alpha_idx])
        {
            size_t j = start_idx;
            size_t del_idx;
            for(;s[j]!=s[i];++j)
            {    
                // Delete the char tag whose index is 
                // before the duplicated one
                del_idx = s[j];
                Char_Bucket[del_idx] = false;
            }
            Longest_len = (Longest_len > (i-start_idx)?Longest_len:(i-start_idx));
            // Update the Processing-Substring's start index
            start_idx = j+1;
        }
        else
        {
            size_t add_idx = s[i];
            Char_Bucket[add_idx] = true;
        }
    }
    
    return (Longest_len > (i-start_idx)?Longest_len:(i-start_idx));
}

// Method4:
// int lengthOfLongestSubstring(char * s)
// {
//     if(s[0]=='\0')return 0;
//     int Char_idx_Bucket[128];
//     for(size_t i=0;i<128;++i)Char_idx_Bucket[i]=-1;
//     int Longest_len = 1;
//     int start_idx = 0;
//     int i=0;
//     for(;s[i];++i)
//     {
//         if(Char_idx_Bucket[s[i]]!=-1 && Char_idx_Bucket[s[i]]>= start_idx)
//         {
//             Longest_len = (Longest_len > (i-start_idx)?Longest_len:(i-start_idx));
//             start_idx = Char_idx_Bucket[s[i]]+1;
//         }
//         Char_idx_Bucket[s[i]] = i;
//     }
    
//     return (Longest_len > (i-start_idx)?Longest_len:(i-start_idx));
// }