#include<bits/stdc++.h>

using namespace std;

bool comparator(pair<int,int> x, pair<int,int>y)
{
    return x.second > y.second;  // Sắp xếp theo lợi nhuận giảm dần
}

struct job {
    int id, deadline, profit;

    job() : id(0), deadline(0), profit(0) {}
};

void nhapJob(job &a) {
    cin >> a.id;
    cin >> a.deadline;
    cin >> a.profit;
}

int main() {
    int n; cin >> n;
    vector<job> jobs(n);
    vector<pair<int,int>> p(n);

    // Nhập các công việc và lưu vào vector
    for(int i = 0; i < n; i++) {
        nhapJob(jobs[i]);
        p[i].first = jobs[i].deadline;
        p[i].second = jobs[i].profit;
    }

    // Sắp xếp theo lợi nhuận giảm dần
    sort(p.begin(), p.end(), comparator);

    int res = 0;
    int max_deadline = 0;

    // Tìm deadline lớn nhất để xác định số lượng slot thời gian
    for (auto &j : jobs) {
        max_deadline = max(max_deadline, j.deadline);
    }

    // Tạo một mảng timeSlot để kiểm tra slot thời gian đã bị chiếm hay chưa
    vector<bool> timeSlot(max_deadline + 1, false); 

    // Duyệt qua các công việc đã sắp xếp theo lợi nhuận giảm dần
    for (int i = 0; i < n; i++) {
        // Tìm một slot thời gian trống bắt đầu từ deadline của công việc
        for (int j = p[i].first; j > 0; j--) {
            if (!timeSlot[j]) {  // Nếu chưa có công việc nào thực hiện tại slot này
                timeSlot[j] = true;  // Đánh dấu slot này đã được sử dụng
                cout << p[i].second << endl;
                res += p[i].second;   // Thêm lợi nhuận của công việc này
                break;
            }
        }
    }

    cout << res;  // In ra tổng lợi nhuận
    return 0;
}
