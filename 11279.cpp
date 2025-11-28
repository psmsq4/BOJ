#include <iostream>
#include <vector>

using namespace std;

class priority_queue {
private:
    vector<int> container;
    int size;
    int last_idx;

    void siftdown(int target_idx) {
        int left_child = target_idx * 2 + 1;
        int right_child = target_idx * 2 + 2;
        if (left_child > last_idx) {
            return;
        } else if (left_child <= last_idx && right_child > last_idx) {
            right_child = -1;
        }

        if (right_child != -1) {
            int MAX = max(container[left_child], container[right_child]);
            if (container[target_idx] < MAX && MAX == container[left_child]) {
                int tmp = container[target_idx];
                container[target_idx] = container[left_child];
                container[left_child] = tmp;

                siftdown(left_child);
            } else if (container[target_idx] < MAX && MAX == container[right_child]) {
                int tmp = container[target_idx];
                container[target_idx] = container[right_child];
                container[right_child] = tmp;

                siftdown(right_child);
            } else {
                return;
            }
        } else {
            if (container[target_idx] < container[left_child]) {
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
        if (container[parent_idx] < container[target_idx]) {
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
/*
    HEAP PUSH 설계
    1. 원소가 들어오면 트리의 잎 단계의 가장 오른쪽에 붙인다.
    2. 부모 원소와 비교하여 크면 값을 교체한다.
    3. 재귀적으로 루트까지 반복한다.

    HEAP POP 설계
    1. 루트노드 값을 반환한다.
    2. 트리의 잎 단계의 가장 오른쪽 원소를 루트로 올린다.
    3. 루트에 있는 값과 자식 값을 비교하여 자식보다 작으면 자식과 값을 교체한다.
*/

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