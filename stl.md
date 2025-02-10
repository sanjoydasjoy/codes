### vector pair sorting 


---

### **All 8 Sorting Cases for `vector<pair<int, int>>`**
<br>
| #  | Sorting Order                         | Full C++ Sorting Code |
|----|--------------------------------------|----------------------|
| 1  | First Ascending, Second Ascending  | sort(vec.begin(), vec.end()) |
| 2  | First Ascending, Second Descending | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first || (a.first == b.first && a.second > b.second); }) |
| 3  | First Descending, Second Ascending | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first || (a.first == b.first && a.second < b.second); }) |
| 4  | First Descending, Second Descending | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first || (a.first == b.first && a.second > b.second); }) |
| 5  | Second Ascending, First Ignored  | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; })  |
| 6  | Second Descending, First Ignored | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; }) |
| 7  | First Ascending, Second Ignored  | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first; }) |
| 8  | First Descending, Second Ignored | sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; }) |



