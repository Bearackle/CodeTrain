class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            int n = nums.size();
            map<int, int> s;
            for (int i = 0; i < n; i++)
            {
                s[nums[i]] = i;
            }
            vector<int> x;
            for (int i = 0; i < n; i++)
            {
                int t = target - nums[i];
                if (s.count(t) > 0 && s[t] != i)
                {
                    x.push_back(i);
                    x.push_back(s[t]);
                    break;
                }
            }
            return x;
        }
    };

int main()
{ ... }