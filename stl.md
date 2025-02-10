### vector pair sorting 


---

### **All 8 Sorting Cases for `vector<pair<int, int>>`**

| #  | Sorting Order                         | Full C++ Sorting Code |
|----|--------------------------------------|----------------------|
| 1  | 1st Asc, 2nd Asc  | sort (vec.begin(), vec.end()) |
| 2  | 1st Asc, 2nd Desc | sort (vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first == b.first ? a.second > b.second : a.first < b.first; }) |
| 3  | 1st Desc, 2nd Asc | sort (vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {  return a.first == b.first ? a.second < b.second : a.first > b.first; })  |
| 4  | 1st Desc, 2nd Desc |  sort (vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) {  return a.first == b.first ? a.second > b.second : a.first > b.first; }) |
| 5  | 2nd Asc, 1st Ignored  | sort (vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; })  |
| 6  | 2nd Desc, 1st Ignored | sort (vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; }) |
| 7  | 1st Asc, 2nd Ignored  | sort (vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first; }) |
| 8  | 1st Desc, 2nd Ignored | sort (vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; }) |



