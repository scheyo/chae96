#include <vector>
#include <stdio.h>
#include <queue>
using namespace std;

int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0, index = 0, sum = 0;
    queue<int> q;

    while (index != truck_weights.size()) {

        if (sum + truck_weights[index] <= weight) {
            q.push(truck_weights[index]);
            sum += truck_weights[index];
            index++;
        }
        else {
            q.push(0);              //���Ը� ���� ������ 0���� �־� ī��Ʈ
        }

        if (q.size() == bridge_length) {
            sum = sum - q.front();
            q.pop();
        }

        answer++;
    }

    return answer + bridge_length;      //�� ������ �ٸ��� �� �ö�� ���̶�, �� �ٸ����̸� ���ؾ� ��
}
int main() {
    int bridge_length, weight, N, x;
    vector<int> truck_weights;

    scanf("%d%d%d", &bridge_length, &weight, &N);

    for (int i = 0; i < N; i++) {
        scanf("%d", &x);
        truck_weights.push_back(x);
    }
    printf("%d", solution(bridge_length, weight, truck_weights));
}