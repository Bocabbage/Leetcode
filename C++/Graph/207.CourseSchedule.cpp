/*
    Title:          207.CourseSchedule.cpp
    Update date:    2022/04/27
    Author:         Zhuofan Zhang
*/
class Solution {
public:
    bool finishCourse(
        int courseId,
        const vector<vector<int>>& preCourses,
        vector<int>& statusArray
    )
    {
        // if(statusArray[courseId] == 1)
        //     return true;
        if(statusArray[courseId] == -1)
            return false;
            
        statusArray[courseId] = -1;
        for(auto &pre: preCourses[courseId])
        {
            if(statusArray[pre] == 1)
                continue;
            else if(!finishCourse(pre, preCourses, statusArray))
                return false;
        }
        statusArray[courseId] = 1;
        return true;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> preCourses(numCourses, vector<int>());
        vector<int> statusArray(numCourses, 0);
        
        for(auto &p: prerequisites)
            preCourses[p[0]].push_back(p[1]);
        
        for(int i = 0; i < numCourses; ++i)
        {
            if(statusArray[i] == 1)
                continue;
            if(!finishCourse(i, preCourses, statusArray))
                return false;
        }

        return true;
    }
};