#include <stdio.h>
#include <limits.h>

// 반환 구조체 정의
typedef struct {
    int low;
    int high;
    int sum;
} SubarrayResult;

// mid를 걸치는 최대 부분 배열 찾기
SubarrayResult find_max_crossing_subarray(int* arr, int low, int mid, int high) {
    int left_sum = INT_MIN;
    int sum = 0;
    int max_left = mid;

    printf("\n[Crossing-Left] mid=%d\n", mid);

    // 왼쪽 탐색 (mid → low)
    for(int i = mid; i >= low; i--) {
        sum += arr[i];
        printf("  i=%d, sum=%d\n", i, sum);
        if(sum > left_sum) {
            left_sum = sum;
            max_left = i;
            printf("  >> 새로운 left_sum=%d (시작 인덱스=%d)\n", left_sum, max_left);
        }
    }

    int right_sum = INT_MIN;
    sum = 0;
    int max_right = mid + 1;

    printf("[Crossing-Right] mid+1=%d\n", mid+1);

    // 오른쪽 탐색 (mid+1 → high)
    for(int j = mid + 1; j <= high; j++) {
        sum += arr[j];
        printf("  j=%d, sum=%d\n", j, sum);
        if(sum > right_sum) {
            right_sum = sum;
            max_right = j;
            printf("  >> 새로운 right_sum=%d (끝 인덱스=%d)\n", right_sum, max_right);
        }
    }

    SubarrayResult result = {max_left, max_right, left_sum + right_sum};
    printf("[Crossing Done] 구간=(%d..%d), 합=%d\n", result.low, result.high, result.sum);
    return result;
}

// 전체 최대 부분 배열 찾기 (Divide and Conquer)
SubarrayResult find_maximum_subarray(int* arr, int low, int high) {
    if(high == low) {
        printf("[Base Case] 인덱스 %d 하나만 선택: 값=%d\n", low, arr[low]);
        SubarrayResult base = {low, high, arr[low]};
        return base;
    } else {
        int mid = (low + high) / 2;
        printf("\n[Divide] low=%d, mid=%d, high=%d\n", low, mid, high);

        SubarrayResult left  = find_maximum_subarray(arr, low, mid);
        SubarrayResult right = find_maximum_subarray(arr, mid + 1, high);
        SubarrayResult cross = find_max_crossing_subarray(arr, low, mid, high);

        printf("[Conquer] left_sum=%d, right_sum=%d, cross_sum=%d\n",
               left.sum, right.sum, cross.sum);

        if(left.sum >= right.sum && left.sum >= cross.sum) {
            printf("[Choose Left] 구간=(%d..%d), 합=%d\n", left.low, left.high, left.sum);
            return left;
        } else if(right.sum >= left.sum && right.sum >= cross.sum) {
            printf("[Choose Right] 구간=(%d..%d), 합=%d\n", right.low, right.high, right.sum);
            return right;
        } else {
            printf("[Choose Cross] 구간=(%d..%d), 합=%d\n", cross.low, cross.high, cross.sum);
            return cross;
        }
    }
}

// 테스트
int main() {
    int arr[] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    SubarrayResult res = find_maximum_subarray(arr, 0, n-1);

    printf("\n=== 최종 결과 ===\n");
    printf("최대 부분 배열: [%d..%d], 합 = %d\n", res.low, res.high, res.sum);

    return 0;
}
