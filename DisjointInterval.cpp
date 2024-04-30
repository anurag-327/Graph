#include <bits/stdc++.h>
class DisjointIntervals
{
        vector<vector<int>> intervals;

public:
        DisjointIntervals()
        {
                // Intialise your data structure here.
        }

        void addInteger(int val)
        {
                if (intervals.size() == 0)
                {
                        intervals.push_back({val, val});
                        return;
                }
                int index = intervals.size(); // default at end
                for (int i = 0; i < intervals.size(); i++)
                {
                        if (val < intervals[i][0])
                        {
                                index = i;
                                break;
                        }
                        else if (val >= intervals[i][0] && val <= intervals[i][1])
                        {
                                return;
                        }
                }
                if (index == 0)
                {
                        if (intervals[0][0] == val + 1)
                        {
                                intervals[0][0] = val;
                        }
                        else
                        {
                                intervals.insert(intervals.begin(), {val, val});
                        }
                }
                else if (index == intervals.size())
                {
                        if (val == intervals[index - 1][1] + 1)
                        {
                                intervals[index - 1][1] = val;
                        }
                        else
                        {
                                intervals.push_back({val, val});
                        }
                }
                else
                {
                        intervals.insert(intervals.begin() + index, {val, val});
                        if (intervals[index + 1][0] - intervals[index][1] == 1)
                        {
                                intervals[index][1] = intervals[index + 1][1];
                                intervals.erase(intervals.begin() + index + 1);
                        }

                        // Interval previous to optimalIndex position.
                        if (intervals[index][0] - intervals[index - 1][1] == 1)
                        {
                                intervals[index - 1][1] = intervals[index][1];
                                intervals.erase(intervals.begin() + index);
                        }
                }
        }

        vector<vector<int>> getDisjointIntervals()
        {
                // Return the disjoint intervals.
                return intervals;
        }
};