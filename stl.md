### vector pair sorting 


---

### **All 8 Sorting Cases for `vector<pair<int, int>>`**

| #  | Sorting Order                         | Full C++ Sorting Code |
|----|--------------------------------------|----------------------|
| 1  | 1st Ascending, 2nd Ascending  | sort(vec.begin(), vec.end()) |
| 2  | 1st Ascending, 2nd Descending | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first || (a.first == b.first && a.second > b.second); }) |
| 3  | 1st Descending, 2nd Ascending | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first || (a.first == b.first && a.second < b.second); }) |
| 4  | 1st Descending, 2nd Descending | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first || (a.first == b.first && a.second > b.second); }) |
| 5  | 2nd Ascending, 1st Ignored  | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; })  |
| 6  | 2nd Descending, 1st Ignored | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; }) |
| 7  | 1st Ascending, 2nd Ignored  | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first; }) |
| 8  | 1st Descending, 2nd Ignored | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; }) |



