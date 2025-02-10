### vector pair sorting 

Got it! Here’s the updated table with just the **sorting order** and **full C++ sorting code** for each of the **8 cases**. 🚀  

---

### **All 8 Sorting Cases for `vector<pair<int, int>>`**
| #  | Sorting Order                         | Full C++ Sorting Code |
|----|--------------------------------------|----------------------|
| 1  | First **Ascending**, Second **Ascending**  | ```cpp std::sort(vec.begin(), vec.end()); ``` |
| 2  | First **Ascending**, Second **Descending** | ```cpp std::sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first || (a.first == b.first && a.second > b.second); }); ``` |
| 3  | First **Descending**, Second **Ascending** | ```cpp std::sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first || (a.first == b.first && a.second < b.second); }); ``` |
| 4  | First **Descending**, Second **Descending** | ```cpp std::sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first || (a.first == b.first && a.second > b.second); }); ``` |
| 5  | **Second Ascending**, First Ignored  | ```cpp std::sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second < b.second; }); ``` |
| 6  | **Second Descending**, First Ignored | ```cpp std::sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.second > b.second; }); ``` |
| 7  | **First Ascending**, Second Ignored  | ```cpp std::sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first < b.first; }); ``` |
| 8  | **First Descending**, Second Ignored | ```cpp std::sort(vec.begin(), vec.end(), [](const pair<int, int>& a, const pair<int, int>& b) { return a.first > b.first; }); ``` |

---

### **How to Use?**
- **Use Case #1** if you want the default sorting order (first ascending, second ascending).  
- **Pick Cases #5 & #6** if you only care about sorting by `second`.  
- **Pick Cases #7 & #8** if you only care about sorting by `first`.  
- **Use Cases #2, #3, & #4** if you need a custom sort order with both `first` and `second`.  

Hope this helps! Let me know if you need anything else. 🚀🔥
