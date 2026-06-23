/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        // The most brute force method to accomplish this is to take
        // each time and compare it against every other interval in the vector
        // and compare against each other such that none of the value ranges overlap

        // However, we could sort these values by their start times,
        // and as we traverse the values, we can see if we've come by any
        // 'end' times that are larger than the current interval
        // This is because if we come across an end time later than the
        // start time of the next element in the sorted vector, this is
        // a guarantee that that time is blocked off.

        sort(intervals.begin(), intervals.end(), [](Interval a, Interval b) {
            return a.start < b.start;
        });
        
        int currMax = 0;
        for (auto interval : intervals) {
            if (interval.start < currMax) {
                return false;
            }

            if (interval.end > currMax) {
                currMax = interval.end;
            }
        }

        return true;
    }
};
