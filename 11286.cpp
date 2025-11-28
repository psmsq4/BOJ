#include <iostream>
#include <vector>

using namespace std;

class priority_queue {
private:
    vector<int> container;
    int size;
    int last_idx;

    void swap(int &a, int &b) {
        int tmp = a;
        a = b;
        b = tmp;
    }

    void siftdown(int target_idx) {
        int left_child = target_idx * 2 + 1;
        int right_child = target_idx * 2 + 2;
        if (left_child > last_idx) {
            return;
        } else if (left_child <= last_idx && right_child > last_idx) {
            right_child = -1;
        }

        int norm_left = container[left_child];
        int norm_parent = container[target_idx];
        int abs_left = abs(container[left_child]);
        int abs_parent = abs(container[target_idx]);

        if (right_child != -1) { // 부모 밑에 왼쪽 자식과 오른쪽 자식이 모두 존재한다면
            int norm_right = container[right_child];
            int abs_right = abs(container[right_child]);

            if (abs_left < abs_parent) {
                if (abs_left < abs_right || (abs_left == abs_right && norm_left <= norm_right)) {
                    swap(container[left_child], container[target_idx]);
                    siftdown(left_child);
                } else if (abs_left > abs_right || (abs_left == abs_right && norm_left > norm_right)) {
                    swap(container[right_child], container[target_idx]);
                    siftdown(right_child);
                }
            } else if (abs_left == abs_parent) {
                if ((abs_left < abs_right && norm_parent > 0 && norm_left < 0) || (abs_left == abs_right && norm_parent > 0 && norm_left < 0)) {
                    swap(container[left_child], container[target_idx]);
                    siftdown(left_child);
                } else if ((abs_left > abs_right) || (abs_left == abs_right && norm_parent > 0 && norm_right < 0)) {
                    swap(container[right_child], container[target_idx]);
                    siftdown(right_child);
                }
            } else if (abs_right < abs_parent) { // && abs_left > abs_parent (implict)
                swap(container[right_child], container[target_idx]);
                siftdown(right_child);
            } else if (abs_right == abs_parent) { // && abs_left > abs_parent (implict)
                if (norm_parent > 0 && norm_right < 0) {
                    swap(container[right_child], container[target_idx]);
                    siftdown(right_child);
                }
            }

            /*  1. 왼쪽 자식 절대값 < 부모 절대값
                   -> 왼쪽 자식 절대값 < 오른쪽 자식 절대값
                   -> 왼쪽 자식과 부모 스왑

                   -> 왼쪽 자식 절대값 > 오른쪽 자식 절대값
                   -> 오른쪽 자식과 부모 스왑

                   -> 왼쪽 자식 절대값 == 오른쪽 자식 절대값 && 왼쪽 자식 <= 오른쪽 자식
                   -> 왼쪽 자식과 부모 스왑

                   -> 왼쪽 자식 절대값 == 오른쪽 자식 절대값 && 왼쪽 자식 > 오른쪽 자식
                   -> 오른쪽 자식과 부모 스왑

                2. 왼쪽 자식 절대값(|-4|) == 부모 절대값(|4|)
                   -> 왼쪽 자식 절대값(|-4|) < 오른쪽 자식 절대값(|-5|) && 왼쪽 자식(-4) < 0 && 부모(4) > 0
                   -> 왼쪽 자식과 부모 스왑

                   -> 왼쪽 자식 절대값 < 오른쪽 자식 절대값 && 왼쪽 자식 >= 부모
                   -> 어떤 자식과도 스왑하지 않음.

                   -> 왼쪽 자식 절대값 > 오른쪽 자식 절대값
                   -> 오른쪽 자식과 부모 스왑

                   -> 왼쪽 자식 절대값 == 오른쪽 자식 절대값 && 부모 >= 0 && 왼쪽 자식 < 0
                   -> 왼쪽 자식과 부모 스왑

                   -> 왼쪽 자식 절대값 == 오른쪽 자식 절대값 && 부모 >= 0 && 오른쪽 자식 < 0
                   -> 오른쪽 자식과 부모 스왑

                3. 오른쪽 자식 절대값 < 부모 절대값 (왼쪽 자식은 위 조건들로 인해 반드시 [왼쪽 자식 절대값 > 부모 절대값]인 상태이다.)
                   -> 오른쪽 자식과 부모 스왑

                4. 오른쪽 자식 절대값 == 부모 절대값
                   -> 부모 > 0 && 오른쪽 자식 < 0
                   -> 오른쪽 자식과 부모 스왑
            */
        } else {
            if (abs_parent > abs_left || (abs_parent == abs_left && norm_parent > 0 && norm_left < 0)) {
                int tmp = container[target_idx];
                container[target_idx] = container[left_child];
                container[left_child] = tmp;

                siftdown(left_child);
            }
        }
    }

    void siftup(int target_idx) {
        if (target_idx == 0)
            return;

        int parent_idx = (target_idx - 1) / 2;

        int abs_parent = abs(container[parent_idx]);
        int abs_child = abs(container[target_idx]);
        int norm_parent = container[parent_idx];
        int norm_child = container[target_idx];

        if (abs_parent > abs_child || (abs_parent == abs_child && norm_parent > 0 && norm_child < 0)) {
            int tmp = container[parent_idx];
            container[parent_idx] = container[target_idx];
            container[target_idx] = tmp;

            siftup(parent_idx);
        } else {
            return;
        }
    }

public:
    priority_queue() {
        size = 0;
    }
    int get_size() {
        return size;
    }
    void push(int input) {
        container.push_back(input);
        size = container.size();
        last_idx = size - 1;
        siftup(last_idx);
    }

    int pop() {
        if (size == 0)
            return 0;

        int ret = container[0];
        container[0] = container[last_idx];
        size--;
        last_idx--;

        siftdown(0);
        container.resize(size);

        return ret;
    }
};

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue pq;

    int op;
    for (int i = 0; i < N; ++i) {
        cin >> op;

        if (op == 0) {
            cout << pq.pop() << "\n";
        } else {
            pq.push(op);
        }
    }

    return 0;
}